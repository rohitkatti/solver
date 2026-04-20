# ─────────────────────────────────────────────────────────────
# Config
# ─────────────────────────────────────────────────────────────
CMAKE      ?= cmake
BUILD_DIR  ?= out
TMP_DIR    ?= tmp
LOG_DIR    ?= $(TMP_DIR)/logs
BUILD_TYPE ?= Debug

# ─────────────────────────────────────────────────────────────
# Targets
# ─────────────────────────────────────────────────────────────
.PHONY: help init configure build run clean test rebuild env-check bootstrap configure

help:
	@echo "Available commands:"
	@echo "  make init       - create folders"
	@echo "  make configure  - run cmake configure"
	@echo "  make build      - build project"
	@echo "  make run      - run project"
	@echo "  make test       - run tests"
	@echo "  make clean      - clean build artifacts"
	@echo "  make rebuild    - clean + build"

env-check:
	../scripts/env_check.sh

bootstrap:
	../scripts/bootstrap.sh

configure:
	../scripts/configure.sh

# Create required directories
init:
	@echo "Initializing directories..."
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(TMP_DIR)
	@mkdir -p $(LOG_DIR)

# Configure CMake (IMPORTANT step)
configure: init
	@echo "Configuring project..."
	$(CMAKE) -S . -B $(BUILD_DIR) -DCMAKE_BUILD_TYPE=$(BUILD_TYPE)

# Build project
build: configure
	@echo "Building project..."
	$(CMAKE) --build $(BUILD_DIR)

# Run the executable
run: build
	@echo "Running Workspace..."
	./$(BUILD_DIR)/Workspace

# Run tests
test: build
	@echo "Running tests..."
	cd $(BUILD_DIR) && ctest --output-on-failure

# Clean build artifacts
clean:
	@echo "Cleaning..."
	@rm -rf $(BUILD_DIR)
# 	@rm -rf $(TMP_DIR)
	@rm -rf $(LOG_DIR)/*.log

# Full rebuild
rebuild: clean build

clang-format: ## Format C++ code
	find src -name "*.hpp" -o -name "*.cpp" | xargs clang-format -i
