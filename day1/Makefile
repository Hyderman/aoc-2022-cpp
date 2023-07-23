BUILD_DIR := build

C_COMPILER := clang
CXX_COMPILER := clang++
# C_COMPILER := gcc
# CXX_COMPILER := g++

BUILD_SYSTEM := Ninja
# BUILD_SYSTEM := MinGW Makefiles

BUILD_TYPE := Debug
# BUILD_TYPE := Release

configure:
	cmake \
		--no-warn-unused-cli \
		-G$(BUILD_SYSTEM) \
		-B$(BUILD_DIR) \
		-DCMAKE_EXPORT_COMPILE_COMMANDS=TRUE \
		-DCMAKE_BUILD_TYPE=$(BUILD_TYPE) \
		-DCMAKE_C_COMPILER=$(C_COMPILER) \
		-DCMAKE_CXX_COMPILER=$(CXX_COMPILER) \
		-DCMAKE_TOOLCHAIN_FILE=/opt/vcpkg/scripts/buildsystems/vcpkg.cmake # vcpkg archlinux

build: configure
	cmake --build $(BUILD_DIR) --verbose
run: build
	build/myProject

clean:
	rm -rf build
