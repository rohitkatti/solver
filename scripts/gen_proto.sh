#!/usr/bin/env bash
set -euo pipefail

REPO_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
PROTO_SRC="${REPO_ROOT}/protos"
PROTO_FILES=$(find "${PROTO_SRC}" -name "*.proto")

# ── C++ ──────────────────────────────────────────────────────────────────────
gen_cpp() {
    for f in ${PROTO_FILES}; do
        # Extract package line, e.g. "dynamics.v1"
        pkg=$(grep -m1 '^package ' "${f}" | sed 's/^package //;s/;//;s/ //')

        if [[ -z "${pkg}" ]]; then
            echo "ERROR: ${f} has no package declaration" >&2
            exit 1
        fi

        # Split into name and version: dynamics.v1 → "dynamics" and "v1"
        pkg_name="${pkg%%.*}"       # everything before first dot
        pkg_version="${pkg##*.}"    # everything after last dot

        local OUT="${REPO_ROOT}/backend/src/${pkg_name}/generated/${pkg_version}"
        mkdir -p "${OUT}"

        protoc \
            --proto_path="${PROTO_SRC}" \
            --cpp_out="${OUT}" \
            --grpc_out="${OUT}" \
            --plugin=protoc-gen-grpc="$(which grpc_cpp_plugin)" \
            "${f}"
    done
    echo "[proto] C++ → src/<package>/generated/<version>/"
}

# # ── Go (future) ───────────────────────────────────────────────────────────────
# gen_go() {
#     local OUT="${REPO_ROOT}/testbed/protos"
#     mkdir -p "${OUT}"
#     for f in ${PROTO_FILES}; do
#         protoc \
#             --proto_path="${PROTO_SRC}" \
#             --go_out="${OUT}" \
#             --go-grpc_out="${OUT}" \
#             "${f}"
#     done
#     echo "[proto] Go → testbed/protos/"
# }

# # ── TypeScript (future) ───────────────────────────────────────────────────────
# gen_ts() {
#     local OUT="${REPO_ROOT}/frontend/protos"
#     mkdir -p "${OUT}"
#     for f in ${PROTO_FILES}; do
#         protoc \
#             --proto_path="${PROTO_SRC}" \
#             --plugin=protoc-gen-ts_proto="$(which protoc-gen-ts_proto)" \
#             --ts_proto_out="${OUT}" \
#             "${f}"
#     done
#     echo "[proto] TS → frontend/protos/"
# }

# ── Dispatch ──────────────────────────────────────────────────────────────────
TARGET="${1:-all}"

case "${TARGET}" in
    cpp)    gen_cpp ;;
    go)     gen_go ;;
    ts)     gen_ts ;;
    all)    gen_cpp ;;   # expand as layers are added
    *)      echo "Usage: $0 [cpp|go|ts|all]"; exit 1 ;;
esac