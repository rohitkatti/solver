#!/usr/bin/env bash

set -e

echo "⚙️ Configuring backend..."

cmake -S backend -B backend/out \
  -G Ninja \
  -DCMAKE_BUILD_TYPE=Debug

echo "✔ CMake configured"