#!/usr/bin/env bash

# ver.h has no CCXXVER_* as every macro is public
# this renames CCXXVER_* prefix to the project one
# values are populated at build time by script/versioning.sh

#   -p PREFIX   project name macro prefix
#   -o OUTFILE

set -euo pipefail


SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT_DIR="$(cd "$SCRIPT_DIR/.." && pwd)"
CORE_HEADER="$ROOT_DIR/include/ver.h"


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

gen() {
    echo "#pragma once"
    sed -e '/^#pragma once/d' -e "s/CCXXVER_/${PREFIX}_/g" "$CORE_HEADER"
}

if [[ -n "$OUTFILE" ]]; then
    gen > "$OUTFILE"
else
    gen
fi
