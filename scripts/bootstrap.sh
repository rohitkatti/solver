#!/usr/bin/env bash
set -e

echo "🚀 Bootstrapping Project..."

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

# 1. Install system deps
"$SCRIPT_DIR/bootstrap_install.sh"

# 2. Setup env
PROJECT_ROOT=$(pwd)
PROJECT_BACKEND_ROOT=${PROJECT_ROOT}/backend

mkdir -p ${PROJECT_BACKEND_ROOT}/out
mkdir -p ${PROJECT_BACKEND_ROOT}/tmp

if [ ! -f ${PROJECT_BACKEND_ROOT}/.env ]; then
    if [ -f ${PROJECT_BACKEND_ROOT}/.env.example ]; then
        cp ${PROJECT_BACKEND_ROOT}/.env.example ${PROJECT_BACKEND_ROOT}/.env
    fi
fi

echo "✅ Bootstrap complete"
echo " That's all folks !!! "