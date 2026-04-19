#!/usr/bin/env bash
set -e
echo "🔍 Checking development environment..."
MISSING=()

check() {
    if ! command -v "$1" >/dev/null 2>&1; then
        MISSING+=("$1")
        echo "❌ missing: $1"
    else
        echo "✔ found: $1"
    fi
}

# Core
check cmake
check ninja
check git
check clang
check clangd
check go
check node
check qt

# gRPC / protobuf toolchain
check protoc
check grpc_cpp_plugin   # was missing — CMake needs this at codegen time
check grpcurl

# C++ libs (check headers exist, not just brew formula)
check_header() {
    local name="$1"
    local header="$2"
    local found=0

    # Build search paths dynamically from Homebrew
    local brew_prefix
    brew_prefix="$(brew --prefix)"

    local search_paths=(
        "${brew_prefix}/include"
        /usr/local/include
        /usr/include
    )

    # Add all opt/ subdirectory include paths (handles versioned formulae)
    while IFS= read -r opt_dir; do
        [[ -d "${opt_dir}/include" ]]             && search_paths+=("${opt_dir}/include")
        [[ -d "${opt_dir}/include/eigen3" ]]      && search_paths+=("${opt_dir}/include/eigen3")
        [[ -d "${opt_dir}/include/postgresql" ]]  && search_paths+=("${opt_dir}/include/postgresql")
    done < <(find "${brew_prefix}/opt" -maxdepth 1 -mindepth 1 -type d 2>/dev/null)

    # Also check Cellar directly for eigen3 layout
    while IFS= read -r cellar_inc; do
        search_paths+=("${cellar_inc}")
    done < <(find "${brew_prefix}/Cellar" -maxdepth 4 -name "eigen3" -type d 2>/dev/null)

    # Also check brew's non-standard postgresql@18 include layout
    while IFS= read -r pg_inc; do
        search_paths+=("${pg_inc}")
    done < <(find "${brew_prefix}/include" -maxdepth 1 -name "postgresql*" -type d 2>/dev/null)

    for p in "${search_paths[@]}"; do
        if [[ -f "${p}/${header}" ]]; then
            found=1
            break
        fi
    done

    if [[ $found -eq 0 ]]; then
        MISSING+=("${name} headers")
        echo "❌ missing headers: ${name} (${header})"
    else
        echo "✔ found headers: ${name}"
    fi
}

check_header "gRPC"       "grpc++/grpc++.h"
check_header "protobuf"   "google/protobuf/descriptor.h"
check_header "Eigen3"     "Eigen/Core"
check_header "PostgreSQL" "libpq-fe.h"

# Warn if CMAKE_PREFIX_PATH won't find Homebrew packages
if [[ "$OSTYPE" == "darwin"* ]]; then
    BREW_PREFIX="$(brew --prefix)"
    if [[ ":${CMAKE_PREFIX_PATH}:" != *":${BREW_PREFIX}:"* ]]; then
        echo ""
        echo "⚠️  CMAKE_PREFIX_PATH does not include Homebrew prefix (${BREW_PREFIX})."
        echo "   Add this to your shell profile (~/.zshrc or ~/.bashrc):"
        echo ""
        echo "   export CMAKE_PREFIX_PATH=\"${BREW_PREFIX}\""
        echo ""
    fi
fi

if [ ${#MISSING[@]} -ne 0 ]; then
    echo ""
    echo "⚠️  Missing tools detected:"
    printf '   %s\n' "${MISSING[@]}"
    echo ""
    echo "   Run: ./scripts/bootstrap_install.sh"
    exit 1
fi

echo ""
echo "🎉 Environment OK"