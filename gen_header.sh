#!/usr/bin/env bash

# gen headers with prefix project name
# -n    project name macro
# -o    output dir
# -s    single header
#

set -euo pipefail


SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

PROJ_NAME=""
OUT_DIR="."
MODE="multi"
SINGLE_STEM="metadata"


while [[ $# -gt 0 ]]; do
    case "$1" in
        -n|--name)
            [[ $# -ge 2 ]] || usage
            PROJ_NAME="$2"
            shift 2
            ;;
        -o|--outdir)
            [[ $# -ge 2 ]] || usage
            OUT_DIR="$2"
            shift 2
            ;;
        -s|--single)
            MODE="single"
            shift
            if [[ $# -gt 0 && "$1" != -* ]]; then
                SINGLE_STEM="$1"
                shift
            fi
            ;;
        *)
            echo "unknown argument: $1" >&2
            usage
            ;;
    esac
done

[[ -n "$PROJ_NAME" ]] || usage


PREFIX="$(printf '%s' "$PROJ_NAME" | tr '[:lower:]' '[:upper:]')"
LOWER="$(printf '%s' "$PROJ_NAME" | tr '[:upper:]' '[:lower:]')"

mkdir -p "$OUT_DIR"

if [[ "$MODE" == "multi" ]]; then
    "$SCRIPT_DIR/script/gen_comp.sh" -p "$PREFIX" -o "$OUT_DIR/${LOWER}_comp.h"
    "$SCRIPT_DIR/script/gen_lang.sh" -p "$PREFIX" -o "$OUT_DIR/${LOWER}_lang.h"
    "$SCRIPT_DIR/script/gen_ver.sh"  -p "$PREFIX" -o "$OUT_DIR/${LOWER}_ver.h"
    echo "generated:"
    echo "  $OUT_DIR/${LOWER}_comp.h"
    echo "  $OUT_DIR/${LOWER}_lang.h"
    echo "  $OUT_DIR/${LOWER}_ver.h"
else
    OUT_FILE="$OUT_DIR/${LOWER}_${SINGLE_STEM}.h"
    STEM_UPPER="$(printf '%s' "$SINGLE_STEM" | tr '[:lower:]' '[:upper:]')"
    {
        echo "#pragma once"
        echo
        echo "//////////////////////////////////////////////////////////"
        echo "// ${PREFIX}_${STEM_UPPER}.h"
        echo "//////////////////////////////////////////////////////////"
        echo
        "$SCRIPT_DIR/script/gen_comp.sh" -p "$PREFIX" | sed '/^#pragma once/d'
        echo
        "$SCRIPT_DIR/script/gen_lang.sh" -p "$PREFIX" | sed '/^#pragma once/d'
        echo
        "$SCRIPT_DIR/script/gen_ver.sh"  -p "$PREFIX" | sed '/^#pragma once/d'
    } > "$OUT_FILE"
    echo "generated: $OUT_FILE"
fi

cp "$SCRIPT_DIR/script/versioning.sh" "$OUT_DIR/versioning.sh"
chmod +x "$OUT_DIR/versioning.sh"
echo "  $OUT_DIR/versioning.sh"
