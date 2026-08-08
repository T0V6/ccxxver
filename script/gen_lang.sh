#!/usr/bin/env bash


#   -p PREFIX   project name macro prefix
#   -o OUTFILE

set -euo pipefail


SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT_DIR="$(cd "$SCRIPT_DIR/.." && pwd)"
CORE_HEADER="$ROOT_DIR/include/lang.h"


source "$SCRIPT_DIR/_lib.sh"

usage() { echo "usage: $(basename "$0") -p PREFIX [-o OUTFILE]" >&2; exit 1; }


PREFIX="" OUTFILE=""
while getopts ":p:o:h" opt; do
    case "$opt" in
        p) PREFIX="$OPTARG" ;;
        o) OUTFILE="$OPTARG" ;;
        h) usage ;;
        *) usage ;;
    esac
done


[[ -z "$PREFIX" ]] && usage
[[ -f "$CORE_HEADER" ]] || { echo "error: core header not found: $CORE_HEADER" >&2; exit 1; }


PREFIX="${PREFIX%_}"

if [[ -n "$OUTFILE" ]]; then
    gen_prefixed_header "$CORE_HEADER" "$PREFIX" "lang" > "$OUTFILE"
else
    gen_prefixed_header "$CORE_HEADER" "$PREFIX" "lang"
fi
