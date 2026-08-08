#!/usr/bin/env bash

# populate a <prefix>_ver.h with git/build metadata
# this script runs on every build


set -euo pipefail


TARGET="${1:-}"
if [[ -z "$TARGET" ]]; then
    echo "usage: $(basename "$0") PATH_TO_GENERATED_VER_HEADER" >&2
    exit 1
fi
[[ -f "$TARGET" ]] || { echo "error: file not found: $TARGET" >&2; exit 1; }


PREFIX="$(grep -m1 -E '^#define[[:space:]]+[A-Za-z0-9_]+_VERSION_BUILD_COUNT[[:space:]]' "$TARGET" \
    | sed -E 's/^#define[[:space:]]+([A-Za-z0-9_]+)_VERSION_BUILD_COUNT[[:space:]].*/\1/')"
if [[ -z "$PREFIX" ]]; then
    echo "error: couldn't find a *_VERSION_BUILD_COUNT macro in $TARGET, generate ver.h with gen_ver.sh" >&2
    exit 1
fi


if git rev-parse --is-inside-work-tree >/dev/null 2>&1; then
    COUNT="$(git rev-list --count HEAD 2>/dev/null || echo 0)"
    HASH="$(git rev-parse --short=12 HEAD 2>/dev/null || echo unknown)"
    BRANCH="$(git branch --show-current 2>/dev/null || echo unknown)"
    LAST_TAG="$(git describe --tags --abbrev=0 2>/dev/null || true)"
    if [[ -n "$LAST_TAG" ]]; then
        OFFSET="$(git rev-list --count "${LAST_TAG}"..HEAD 2>/dev/null || echo 0)"
    else
        OFFSET=0
    fi
    if [[ -n "$(git status --porcelain 2>/dev/null)" ]]; then
        DIRTY="+dirty"
    else
        DIRTY=""
    fi
else
    COUNT=0
    HASH="unknown"
    BRANCH="unknown"
    OFFSET=0
    DIRTY=""
fi
TIMESTAMP="$(date -u +%Y%m%d%H%M%S)"


esc() { printf '%s' "$1" | sed -e 's/[&\@]/\\&/g'; }


set_val() {
    local name="$1" value="$2"
    local esc_value
    esc_value="$(esc "$value")"
    sed -i.bak -E "s@^(#define[[:space:]]+${PREFIX}_${name})[[:space:]].*@\1   ${esc_value}@" "$TARGET"
    rm -f "${TARGET}.bak"
}

set_val "VERSION_BUILD_COUNT"                  "${COUNT}"
set_val "VERSION_BUILD_COUNT_STR"               "\"${COUNT}\""
set_val "VERSION_BUILD_HASH"                    "\"${HASH}\""
set_val "VERSION_BUILD_BRANCH"                  "\"${BRANCH}\""
set_val "VERSION_BUILD_COUNT_OFFSET_LAST"       "${OFFSET}"
set_val "VERSION_BUILD_COUNT_OFFSET_LAST_STR"   "\"${OFFSET}\""
set_val "VERSION_BUILD_TIMESTAMP"               "${TIMESTAMP}"
set_val "VERSION_BUILD_TIMESTAMP_STR"           "\"${TIMESTAMP}\""
set_val "VERSION_BUILD_DIRTY"                   "\"${DIRTY}\""

echo "updated versioning.sh: $TARGET (${PREFIX}_, rev ${COUNT}, ${HASH}${DIRTY})" >&2
