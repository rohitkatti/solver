#!/usr/bin/env bash

set -e

echo "⚙️ Configuring backend..."

cmake -S backend -B backend/out \
  -G Ninja \
  -DCMAKE_BUILD_TYPE=Debug \
  -DCMAKE_PREFIX_PATH=/opt/homebrew

echo "✔ CMake configured"