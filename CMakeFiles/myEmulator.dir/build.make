# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.25.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.25.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/nestorcortes/Desktop/GH/chip8

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/nestorcortes/Desktop/GH/chip8

# Include any dependencies generated for this target.
include CMakeFiles/myEmulator.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/myEmulator.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/myEmulator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/myEmulator.dir/flags.make

CMakeFiles/myEmulator.dir/src/Unit_Tests/chip8_Test.cpp.o: CMakeFiles/myEmulator.dir/flags.make
CMakeFiles/myEmulator.dir/src/Unit_Tests/chip8_Test.cpp.o: src/Unit\ Tests/chip8_Test.cpp
CMakeFiles/myEmulator.dir/src/Unit_Tests/chip8_Test.cpp.o: CMakeFiles/myEmulator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nestorcortes/Desktop/GH/chip8/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/myEmulator.dir/src/Unit_Tests/chip8_Test.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/myEmulator.dir/src/Unit_Tests/chip8_Test.cpp.o -MF CMakeFiles/myEmulator.dir/src/Unit_Tests/chip8_Test.cpp.o.d -o CMakeFiles/myEmulator.dir/src/Unit_Tests/chip8_Test.cpp.o -c "/Users/nestorcortes/Desktop/GH/chip8/src/Unit Tests/chip8_Test.cpp"

CMakeFiles/myEmulator.dir/src/Unit_Tests/chip8_Test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/myEmulator.dir/src/Unit_Tests/chip8_Test.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/nestorcortes/Desktop/GH/chip8/src/Unit Tests/chip8_Test.cpp" > CMakeFiles/myEmulator.dir/src/Unit_Tests/chip8_Test.cpp.i

CMakeFiles/myEmulator.dir/src/Unit_Tests/chip8_Test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/myEmulator.dir/src/Unit_Tests/chip8_Test.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/nestorcortes/Desktop/GH/chip8/src/Unit Tests/chip8_Test.cpp" -o CMakeFiles/myEmulator.dir/src/Unit_Tests/chip8_Test.cpp.s

CMakeFiles/myEmulator.dir/src/chip8.cpp.o: CMakeFiles/myEmulator.dir/flags.make
CMakeFiles/myEmulator.dir/src/chip8.cpp.o: src/chip8.cpp
CMakeFiles/myEmulator.dir/src/chip8.cpp.o: CMakeFiles/myEmulator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nestorcortes/Desktop/GH/chip8/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/myEmulator.dir/src/chip8.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/myEmulator.dir/src/chip8.cpp.o -MF CMakeFiles/myEmulator.dir/src/chip8.cpp.o.d -o CMakeFiles/myEmulator.dir/src/chip8.cpp.o -c /Users/nestorcortes/Desktop/GH/chip8/src/chip8.cpp

CMakeFiles/myEmulator.dir/src/chip8.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/myEmulator.dir/src/chip8.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/nestorcortes/Desktop/GH/chip8/src/chip8.cpp > CMakeFiles/myEmulator.dir/src/chip8.cpp.i

CMakeFiles/myEmulator.dir/src/chip8.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/myEmulator.dir/src/chip8.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/nestorcortes/Desktop/GH/chip8/src/chip8.cpp -o CMakeFiles/myEmulator.dir/src/chip8.cpp.s

CMakeFiles/myEmulator.dir/src/cpu.cpp.o: CMakeFiles/myEmulator.dir/flags.make
CMakeFiles/myEmulator.dir/src/cpu.cpp.o: src/cpu.cpp
CMakeFiles/myEmulator.dir/src/cpu.cpp.o: CMakeFiles/myEmulator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nestorcortes/Desktop/GH/chip8/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/myEmulator.dir/src/cpu.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/myEmulator.dir/src/cpu.cpp.o -MF CMakeFiles/myEmulator.dir/src/cpu.cpp.o.d -o CMakeFiles/myEmulator.dir/src/cpu.cpp.o -c /Users/nestorcortes/Desktop/GH/chip8/src/cpu.cpp

CMakeFiles/myEmulator.dir/src/cpu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/myEmulator.dir/src/cpu.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/nestorcortes/Desktop/GH/chip8/src/cpu.cpp > CMakeFiles/myEmulator.dir/src/cpu.cpp.i

CMakeFiles/myEmulator.dir/src/cpu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/myEmulator.dir/src/cpu.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/nestorcortes/Desktop/GH/chip8/src/cpu.cpp -o CMakeFiles/myEmulator.dir/src/cpu.cpp.s

CMakeFiles/myEmulator.dir/src/keyboard.cpp.o: CMakeFiles/myEmulator.dir/flags.make
CMakeFiles/myEmulator.dir/src/keyboard.cpp.o: src/keyboard.cpp
CMakeFiles/myEmulator.dir/src/keyboard.cpp.o: CMakeFiles/myEmulator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nestorcortes/Desktop/GH/chip8/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/myEmulator.dir/src/keyboard.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/myEmulator.dir/src/keyboard.cpp.o -MF CMakeFiles/myEmulator.dir/src/keyboard.cpp.o.d -o CMakeFiles/myEmulator.dir/src/keyboard.cpp.o -c /Users/nestorcortes/Desktop/GH/chip8/src/keyboard.cpp

CMakeFiles/myEmulator.dir/src/keyboard.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/myEmulator.dir/src/keyboard.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/nestorcortes/Desktop/GH/chip8/src/keyboard.cpp > CMakeFiles/myEmulator.dir/src/keyboard.cpp.i

CMakeFiles/myEmulator.dir/src/keyboard.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/myEmulator.dir/src/keyboard.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/nestorcortes/Desktop/GH/chip8/src/keyboard.cpp -o CMakeFiles/myEmulator.dir/src/keyboard.cpp.s

CMakeFiles/myEmulator.dir/src/Renderer.cpp.o: CMakeFiles/myEmulator.dir/flags.make
CMakeFiles/myEmulator.dir/src/Renderer.cpp.o: src/Renderer.cpp
CMakeFiles/myEmulator.dir/src/Renderer.cpp.o: CMakeFiles/myEmulator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nestorcortes/Desktop/GH/chip8/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/myEmulator.dir/src/Renderer.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/myEmulator.dir/src/Renderer.cpp.o -MF CMakeFiles/myEmulator.dir/src/Renderer.cpp.o.d -o CMakeFiles/myEmulator.dir/src/Renderer.cpp.o -c /Users/nestorcortes/Desktop/GH/chip8/src/Renderer.cpp

CMakeFiles/myEmulator.dir/src/Renderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/myEmulator.dir/src/Renderer.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/nestorcortes/Desktop/GH/chip8/src/Renderer.cpp > CMakeFiles/myEmulator.dir/src/Renderer.cpp.i

CMakeFiles/myEmulator.dir/src/Renderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/myEmulator.dir/src/Renderer.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/nestorcortes/Desktop/GH/chip8/src/Renderer.cpp -o CMakeFiles/myEmulator.dir/src/Renderer.cpp.s

CMakeFiles/myEmulator.dir/src/Speaker.cpp.o: CMakeFiles/myEmulator.dir/flags.make
CMakeFiles/myEmulator.dir/src/Speaker.cpp.o: src/Speaker.cpp
CMakeFiles/myEmulator.dir/src/Speaker.cpp.o: CMakeFiles/myEmulator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nestorcortes/Desktop/GH/chip8/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/myEmulator.dir/src/Speaker.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/myEmulator.dir/src/Speaker.cpp.o -MF CMakeFiles/myEmulator.dir/src/Speaker.cpp.o.d -o CMakeFiles/myEmulator.dir/src/Speaker.cpp.o -c /Users/nestorcortes/Desktop/GH/chip8/src/Speaker.cpp

CMakeFiles/myEmulator.dir/src/Speaker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/myEmulator.dir/src/Speaker.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/nestorcortes/Desktop/GH/chip8/src/Speaker.cpp > CMakeFiles/myEmulator.dir/src/Speaker.cpp.i

CMakeFiles/myEmulator.dir/src/Speaker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/myEmulator.dir/src/Speaker.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/nestorcortes/Desktop/GH/chip8/src/Speaker.cpp -o CMakeFiles/myEmulator.dir/src/Speaker.cpp.s

# Object files for target myEmulator
myEmulator_OBJECTS = \
"CMakeFiles/myEmulator.dir/src/Unit_Tests/chip8_Test.cpp.o" \
"CMakeFiles/myEmulator.dir/src/chip8.cpp.o" \
"CMakeFiles/myEmulator.dir/src/cpu.cpp.o" \
"CMakeFiles/myEmulator.dir/src/keyboard.cpp.o" \
"CMakeFiles/myEmulator.dir/src/Renderer.cpp.o" \
"CMakeFiles/myEmulator.dir/src/Speaker.cpp.o"

# External object files for target myEmulator
myEmulator_EXTERNAL_OBJECTS =

myEmulator: CMakeFiles/myEmulator.dir/src/Unit_Tests/chip8_Test.cpp.o
myEmulator: CMakeFiles/myEmulator.dir/src/chip8.cpp.o
myEmulator: CMakeFiles/myEmulator.dir/src/cpu.cpp.o
myEmulator: CMakeFiles/myEmulator.dir/src/keyboard.cpp.o
myEmulator: CMakeFiles/myEmulator.dir/src/Renderer.cpp.o
myEmulator: CMakeFiles/myEmulator.dir/src/Speaker.cpp.o
myEmulator: CMakeFiles/myEmulator.dir/build.make
myEmulator: /usr/local/lib/libSDL2.dylib
myEmulator: CMakeFiles/myEmulator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/nestorcortes/Desktop/GH/chip8/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable myEmulator"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/myEmulator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/myEmulator.dir/build: myEmulator
.PHONY : CMakeFiles/myEmulator.dir/build

CMakeFiles/myEmulator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/myEmulator.dir/cmake_clean.cmake
.PHONY : CMakeFiles/myEmulator.dir/clean

CMakeFiles/myEmulator.dir/depend:
	cd /Users/nestorcortes/Desktop/GH/chip8 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/nestorcortes/Desktop/GH/chip8 /Users/nestorcortes/Desktop/GH/chip8 /Users/nestorcortes/Desktop/GH/chip8 /Users/nestorcortes/Desktop/GH/chip8 /Users/nestorcortes/Desktop/GH/chip8/CMakeFiles/myEmulator.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/myEmulator.dir/depend
