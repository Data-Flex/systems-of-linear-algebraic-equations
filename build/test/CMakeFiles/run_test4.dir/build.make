# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/programming/SLAE/systems-of-linear-algebraic-equations

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/programming/SLAE/systems-of-linear-algebraic-equations/build

# Include any dependencies generated for this target.
include test/CMakeFiles/run_test4.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/CMakeFiles/run_test4.dir/compiler_depend.make

# Include the progress variables for this target.
include test/CMakeFiles/run_test4.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/run_test4.dir/flags.make

test/CMakeFiles/run_test4.dir/test4.cpp.o: test/CMakeFiles/run_test4.dir/flags.make
test/CMakeFiles/run_test4.dir/test4.cpp.o: ../test/test4.cpp
test/CMakeFiles/run_test4.dir/test4.cpp.o: test/CMakeFiles/run_test4.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/programming/SLAE/systems-of-linear-algebraic-equations/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/run_test4.dir/test4.cpp.o"
	cd /mnt/c/programming/SLAE/systems-of-linear-algebraic-equations/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/run_test4.dir/test4.cpp.o -MF CMakeFiles/run_test4.dir/test4.cpp.o.d -o CMakeFiles/run_test4.dir/test4.cpp.o -c /mnt/c/programming/SLAE/systems-of-linear-algebraic-equations/test/test4.cpp

test/CMakeFiles/run_test4.dir/test4.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/run_test4.dir/test4.cpp.i"
	cd /mnt/c/programming/SLAE/systems-of-linear-algebraic-equations/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/programming/SLAE/systems-of-linear-algebraic-equations/test/test4.cpp > CMakeFiles/run_test4.dir/test4.cpp.i

test/CMakeFiles/run_test4.dir/test4.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/run_test4.dir/test4.cpp.s"
	cd /mnt/c/programming/SLAE/systems-of-linear-algebraic-equations/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/programming/SLAE/systems-of-linear-algebraic-equations/test/test4.cpp -o CMakeFiles/run_test4.dir/test4.cpp.s

# Object files for target run_test4
run_test4_OBJECTS = \
"CMakeFiles/run_test4.dir/test4.cpp.o"

# External object files for target run_test4
run_test4_EXTERNAL_OBJECTS =

test/run_test4: test/CMakeFiles/run_test4.dir/test4.cpp.o
test/run_test4: test/CMakeFiles/run_test4.dir/build.make
test/run_test4: src/libSlae.a
test/run_test4: /usr/lib/x86_64-linux-gnu/libgtest_main.a
test/run_test4: /usr/lib/x86_64-linux-gnu/libgtest.a
test/run_test4: test/CMakeFiles/run_test4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/programming/SLAE/systems-of-linear-algebraic-equations/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable run_test4"
	cd /mnt/c/programming/SLAE/systems-of-linear-algebraic-equations/build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/run_test4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/run_test4.dir/build: test/run_test4
.PHONY : test/CMakeFiles/run_test4.dir/build

test/CMakeFiles/run_test4.dir/clean:
	cd /mnt/c/programming/SLAE/systems-of-linear-algebraic-equations/build/test && $(CMAKE_COMMAND) -P CMakeFiles/run_test4.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/run_test4.dir/clean

test/CMakeFiles/run_test4.dir/depend:
	cd /mnt/c/programming/SLAE/systems-of-linear-algebraic-equations/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/programming/SLAE/systems-of-linear-algebraic-equations /mnt/c/programming/SLAE/systems-of-linear-algebraic-equations/test /mnt/c/programming/SLAE/systems-of-linear-algebraic-equations/build /mnt/c/programming/SLAE/systems-of-linear-algebraic-equations/build/test /mnt/c/programming/SLAE/systems-of-linear-algebraic-equations/build/test/CMakeFiles/run_test4.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/run_test4.dir/depend

