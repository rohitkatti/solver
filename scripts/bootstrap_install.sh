#!/usr/bin/env bash
set -e
echo "🚀 Installing missing dependencies..."

if [[ "$OSTYPE" == "darwin"* ]]; then
    echo "Detected macOS"
    if ! command -v brew >/dev/null; then
        echo "❌ Homebrew required"
        exit 1
    fi

    brew install \
        cmake \
        ninja \
        git \
        go \
        node \
        llvm \
        grpcurl \
        grpc \
        protobuf \
        postgresql \
        eigen \
        cgal \
        doxygen

elif [[ "$OSTYPE" == "linux-gnu"* ]]; then
    echo "Detected Linux"
    sudo apt-get update
    sudo apt-get install -y \
        build-essential \
        cmake \
        ninja-build \
        git \
        curl \
        clang \
        clangd \
        gdb \
        lldb \
        nodejs \
        npm \
        golang-go \
        libgrpc-dev \
        libprotobuf-dev \
        protobuf-compiler \
        protobuf-compiler-grpc \
        libpq-dev \
        libeigen3-dev \
        doxygen
else
    echo "Unsupported OS"
    exit 1
fi

echo "✔ Done installing base dependencies"