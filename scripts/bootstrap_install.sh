#!/usr/bin/env bash
set -e

echo "🔍 Checking system dependencies..."

# ─────────────────────────────────────────────
# Helper: check brew
# ─────────────────────────────────────────────
if ! command -v brew &> /dev/null; then
    echo "❌ Homebrew not found. Installing..."

    /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

    echo "⚠️ Restart your terminal after brew install"
    exit 1
fi

# ─────────────────────────────────────────────
# Helper function
# ─────────────────────────────────────────────
install_if_missing() {
    PKG=$1

    if brew list --versions "$PKG" > /dev/null; then
        echo "✅ $PKG already installed"
    else
        echo "⬇️ Installing $PKG..."
        brew install "$PKG"
    fi
}

# ─────────────────────────────────────────────
# Core dependencies
# ─────────────────────────────────────────────
install_if_missing cmake
install_if_missing ninja
install_if_missing cgal
install_if_missing eigen
install_if_missing postgresql@18
install_if_missing qt

# Optional but recommended
install_if_missing protobuf
install_if_missing grpc
install_if_missing pkg-config

echo "🎉 All dependencies satisfied!"