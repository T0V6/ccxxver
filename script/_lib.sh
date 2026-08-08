# shared helper
# needs a CCXXVER_* file with a CCXXVER_PUBLIC_LIST(X) macro at the bottom


extract_public_list() {
    local file="$1"
    awk '
        found == 0 && /#define[ \t]+CCXXVER_PUBLIC_LIST\(X\)/ { found = 1; next }
        found == 1 {
            line = $0
            if (match(line, /X\([A-Za-z0-9_]+\)/)) {
                tok = substr(line, RSTART, RLENGTH)
                sub(/^X\(/, "", tok)
                sub(/\)$/, "", tok)
                print tok
            }
            if (line !~ /\\[ \t]*$/) { found = 0 }
        }
    ' "$file"
}



strip_public_list_macro() {
    local file="$1"
    awk '
        /#define[ \t]+CCXXVER_PUBLIC_LIST\(X\)/ { skip = 1 }
        skip { if ($0 !~ /\\[ \t]*$/) { skip = 0 }; next }
        { print }
    ' "$file"
}


gen_prefixed_header() {
    local core="$1" prefix="$2" label="$3"
    local suffixes
    suffixes="$(extract_public_list "$core")"

    if [[ -z "$suffixes" ]]; then
        echo "error: no CCXXVER_PUBLIC_LIST(X) entries found in $core" >&2
        return 1
    fi

    echo "#pragma once"
    strip_public_list_macro "$core" | sed -e '/^#pragma once/d'
    echo
    echo "//////////////////////////////////////////////////////////"
    echo "// ${prefix} public aliases"
    echo "//////////////////////////////////////////////////////////"
    while IFS= read -r suffix; do
        [[ -z "$suffix" ]] && continue
        echo "#define ${prefix}_${suffix}   CCXXVER_${suffix}"
    done <<< "$suffixes"
}
