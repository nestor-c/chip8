# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/Admin/Desktop/GH/chip8

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Admin/Desktop/GH/chip8

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/Applications/CMake.app/Contents/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/Applications/CMake.app/Contents/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/Admin/Desktop/GH/chip8/CMakeFiles /Users/Admin/Desktop/GH/chip8//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/Admin/Desktop/GH/chip8/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named Test_Renderer

# Build rule for target.
Test_Renderer: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 Test_Renderer
.PHONY : Test_Renderer

# fast build rule for target.
Test_Renderer/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Test_Renderer.dir/build.make CMakeFiles/Test_Renderer.dir/build
.PHONY : Test_Renderer/fast

src/Renderer.o: src/Renderer.cpp.o
.PHONY : src/Renderer.o

# target to build an object file
src/Renderer.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Test_Renderer.dir/build.make CMakeFiles/Test_Renderer.dir/src/Renderer.cpp.o
.PHONY : src/Renderer.cpp.o

src/Renderer.i: src/Renderer.cpp.i
.PHONY : src/Renderer.i

# target to preprocess a source file
src/Renderer.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Test_Renderer.dir/build.make CMakeFiles/Test_Renderer.dir/src/Renderer.cpp.i
.PHONY : src/Renderer.cpp.i

src/Renderer.s: src/Renderer.cpp.s
.PHONY : src/Renderer.s

# target to generate assembly for a file
src/Renderer.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Test_Renderer.dir/build.make CMakeFiles/Test_Renderer.dir/src/Renderer.cpp.s
.PHONY : src/Renderer.cpp.s

src/Unit_Tests/Renderer_Test.o: src/Unit_Tests/Renderer_Test.cpp.o
.PHONY : src/Unit_Tests/Renderer_Test.o

# target to build an object file
src/Unit_Tests/Renderer_Test.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Test_Renderer.dir/build.make CMakeFiles/Test_Renderer.dir/src/Unit_Tests/Renderer_Test.cpp.o
.PHONY : src/Unit_Tests/Renderer_Test.cpp.o

src/Unit_Tests/Renderer_Test.i: src/Unit_Tests/Renderer_Test.cpp.i
.PHONY : src/Unit_Tests/Renderer_Test.i

# target to preprocess a source file
src/Unit_Tests/Renderer_Test.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Test_Renderer.dir/build.make CMakeFiles/Test_Renderer.dir/src/Unit_Tests/Renderer_Test.cpp.i
.PHONY : src/Unit_Tests/Renderer_Test.cpp.i

src/Unit_Tests/Renderer_Test.s: src/Unit_Tests/Renderer_Test.cpp.s
.PHONY : src/Unit_Tests/Renderer_Test.s

# target to generate assembly for a file
src/Unit_Tests/Renderer_Test.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Test_Renderer.dir/build.make CMakeFiles/Test_Renderer.dir/src/Unit_Tests/Renderer_Test.cpp.s
.PHONY : src/Unit_Tests/Renderer_Test.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... Test_Renderer"
	@echo "... src/Renderer.o"
	@echo "... src/Renderer.i"
	@echo "... src/Renderer.s"
	@echo "... src/Unit_Tests/Renderer_Test.o"
	@echo "... src/Unit_Tests/Renderer_Test.i"
	@echo "... src/Unit_Tests/Renderer_Test.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

