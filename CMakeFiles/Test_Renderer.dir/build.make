# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

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

# Include any dependencies generated for this target.
include CMakeFiles/Test_Renderer.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Test_Renderer.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Test_Renderer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Test_Renderer.dir/flags.make

CMakeFiles/Test_Renderer.dir/src/Unit_Tests/Renderer_Test.cpp.o: CMakeFiles/Test_Renderer.dir/flags.make
CMakeFiles/Test_Renderer.dir/src/Unit_Tests/Renderer_Test.cpp.o: src/Unit\ Tests/Renderer_Test.cpp
CMakeFiles/Test_Renderer.dir/src/Unit_Tests/Renderer_Test.cpp.o: CMakeFiles/Test_Renderer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Admin/Desktop/GH/chip8/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Test_Renderer.dir/src/Unit_Tests/Renderer_Test.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Test_Renderer.dir/src/Unit_Tests/Renderer_Test.cpp.o -MF CMakeFiles/Test_Renderer.dir/src/Unit_Tests/Renderer_Test.cpp.o.d -o CMakeFiles/Test_Renderer.dir/src/Unit_Tests/Renderer_Test.cpp.o -c "/Users/Admin/Desktop/GH/chip8/src/Unit Tests/Renderer_Test.cpp"

CMakeFiles/Test_Renderer.dir/src/Unit_Tests/Renderer_Test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Test_Renderer.dir/src/Unit_Tests/Renderer_Test.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/Admin/Desktop/GH/chip8/src/Unit Tests/Renderer_Test.cpp" > CMakeFiles/Test_Renderer.dir/src/Unit_Tests/Renderer_Test.cpp.i

CMakeFiles/Test_Renderer.dir/src/Unit_Tests/Renderer_Test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Test_Renderer.dir/src/Unit_Tests/Renderer_Test.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/Admin/Desktop/GH/chip8/src/Unit Tests/Renderer_Test.cpp" -o CMakeFiles/Test_Renderer.dir/src/Unit_Tests/Renderer_Test.cpp.s

CMakeFiles/Test_Renderer.dir/src/Renderer.cpp.o: CMakeFiles/Test_Renderer.dir/flags.make
CMakeFiles/Test_Renderer.dir/src/Renderer.cpp.o: src/Renderer.cpp
CMakeFiles/Test_Renderer.dir/src/Renderer.cpp.o: CMakeFiles/Test_Renderer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Admin/Desktop/GH/chip8/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Test_Renderer.dir/src/Renderer.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Test_Renderer.dir/src/Renderer.cpp.o -MF CMakeFiles/Test_Renderer.dir/src/Renderer.cpp.o.d -o CMakeFiles/Test_Renderer.dir/src/Renderer.cpp.o -c /Users/Admin/Desktop/GH/chip8/src/Renderer.cpp

CMakeFiles/Test_Renderer.dir/src/Renderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Test_Renderer.dir/src/Renderer.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Admin/Desktop/GH/chip8/src/Renderer.cpp > CMakeFiles/Test_Renderer.dir/src/Renderer.cpp.i

CMakeFiles/Test_Renderer.dir/src/Renderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Test_Renderer.dir/src/Renderer.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Admin/Desktop/GH/chip8/src/Renderer.cpp -o CMakeFiles/Test_Renderer.dir/src/Renderer.cpp.s

# Object files for target Test_Renderer
Test_Renderer_OBJECTS = \
"CMakeFiles/Test_Renderer.dir/src/Unit_Tests/Renderer_Test.cpp.o" \
"CMakeFiles/Test_Renderer.dir/src/Renderer.cpp.o"

# External object files for target Test_Renderer
Test_Renderer_EXTERNAL_OBJECTS =

Test_Renderer: CMakeFiles/Test_Renderer.dir/src/Unit_Tests/Renderer_Test.cpp.o
Test_Renderer: CMakeFiles/Test_Renderer.dir/src/Renderer.cpp.o
Test_Renderer: CMakeFiles/Test_Renderer.dir/build.make
Test_Renderer: /usr/local/lib/libSDL2.dylib
Test_Renderer: CMakeFiles/Test_Renderer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/Admin/Desktop/GH/chip8/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Test_Renderer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Test_Renderer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Test_Renderer.dir/build: Test_Renderer
.PHONY : CMakeFiles/Test_Renderer.dir/build

CMakeFiles/Test_Renderer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Test_Renderer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Test_Renderer.dir/clean

CMakeFiles/Test_Renderer.dir/depend:
	cd /Users/Admin/Desktop/GH/chip8 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Admin/Desktop/GH/chip8 /Users/Admin/Desktop/GH/chip8 /Users/Admin/Desktop/GH/chip8 /Users/Admin/Desktop/GH/chip8 /Users/Admin/Desktop/GH/chip8/CMakeFiles/Test_Renderer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Test_Renderer.dir/depend
