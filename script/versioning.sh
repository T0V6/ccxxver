#!/usr/bin/env bash
set -euo pipefail


ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
DST_HEADER="$ROOT_DIR/include/version.h"


# version info
VERSION_COUNT="$(git rev-list --count HEAD)"
VERSION_HASH="$(git rev-parse --short=12 HEAD)"
VERSION_BRANCH="$(git branch --show-current)"

LAST_TAG="$(git describe --tags --abbrev=0 2>/dev/null || true)"
if [[ -n "$LAST_TAG" ]]; then
    VERSION_COUNT_OFFSET_LAST="$(git rev-list --count "${LAST_TAG}"..HEAD)"
else
    VERSION_COUNT_OFFSET_LAST="0"
fi

VERSION_TIMESTAMP="$(date -u +%Y%m%d%H%M%S)"   # YYYYMMDDHHMMSS


# gen version header
cat > "$DST_HEADER" <<EOF
#pragma once


#define VERSION_COUNT   ${VERSION_COUNT}
    #define VERSION_COUNT_STR   "${VERSION_COUNT}"
#define VERSION_HASH    "${VERSION_HASH}"
#define VERSION_BRANCH  "${VERSION_BRANCH}"
#define VERSION_COUNT_OFFSET_LAST   ${VERSION_COUNT_OFFSET_LAST}
    #define VERSION_COUNT_OFFSET_LAST_STR   "${VERSION_COUNT_OFFSET_LAST}"
#define VERSION_TIMESTAMP   ${VERSION_TIMESTAMP}
    #define VERSION_TIMESTAMP_STR   "${VERSION_TIMESTAMP}"


#define VERSION_STR (\\
    VERSION_COUNT_STR \\
    "." \\
    VERSION_HASH \\
    "." \\
    VERSION_TIMESTAMP_STR \\
    "-" \\
    VERSION_BRANCH \\
    "." \\
    VERSION_COUNT_OFFSET_LAST_STR \\
)

#define VERSION_SHORT_STR (\\
    VERSION_COUNT_STR \\
    "-" \\
    VERSION_BRANCH \\
    "." \\
    VERSION_COUNT_OFFSET_LAST_STR \\
)
EOF
