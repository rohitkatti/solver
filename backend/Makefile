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
.PHONY: help init configure build run clean test rebuild env-check bootstrap configure test-all test-one test-module

help:
	@echo "Available commands:"
	@echo "  make init       	- create folders"
	@echo "  make configure  	- run cmake configure"
	@echo "  make build      	- build project"
	@echo "  make run        	- run project"
	@echo "  make test       	- run tests"
	@echo "  make clean      	- clean build artifacts"
	@echo "  make rebuild    	- clean + build"
	@echo "  make test-all   	- tests all the tests registered for the project"
	@echo "  make test-module 	- tests all the registered tests for a particular module i.e. make test-module MODULE=geometry"
	@echo "  make test-one 		- tests single test i.e. make test-one MODULE=geometry FILE=fileService TEST=GrpcClientTest.LoadPointsCheck"
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
	find src \( -name "*.hpp" -o -name "*.cpp" \) | xargs clang-format -i
	find tests \( -name "*.hpp" -o -name "*.cpp" \) | xargs clang-format -i

# Run every test via CTest
test-all:
	cd out && ctest --output-on-failure -j$(shell nproc 2>/dev/null || sysctl -n hw.logicalcpu)

# Run all tests for a single module
# Usage: make test-module MODULE=geometry
test-module:
	@if [ -z "$(MODULE)" ]; then echo "Usage: make test-module MODULE=<name>"; exit 1; fi
	cd out && ctest --output-on-failure -R "^test_$(MODULE)_"

# Run a single named test
# Usage: make test-one MODULE=geometry FILE=fileService TEST=GrpcClientTest.LoadPointsCheck
test-one:
	@if [ -z "$(MODULE)" ] || [ -z "$(FILE)" ] || [ -z "$(TEST)" ]; then \
		echo "Usage: make test-one MODULE=<name> FILE=<filename> TEST=<TestSuite.TestName>"; exit 1; fi
	cd out && ctest --output-on-failure -R "^test_$(MODULE)_$(FILE)\.$(TEST)$$"

