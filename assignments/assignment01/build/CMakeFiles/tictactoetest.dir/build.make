# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jose-chung/Documents/school/lavc/cs236/assignments/assignment01

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jose-chung/Documents/school/lavc/cs236/assignments/assignment01/build

# Include any dependencies generated for this target.
include CMakeFiles/tictactoetest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tictactoetest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tictactoetest.dir/flags.make

CMakeFiles/tictactoetest.dir/test.cpp.o: CMakeFiles/tictactoetest.dir/flags.make
CMakeFiles/tictactoetest.dir/test.cpp.o: ../test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jose-chung/Documents/school/lavc/cs236/assignments/assignment01/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tictactoetest.dir/test.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tictactoetest.dir/test.cpp.o -c /home/jose-chung/Documents/school/lavc/cs236/assignments/assignment01/test.cpp

CMakeFiles/tictactoetest.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tictactoetest.dir/test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jose-chung/Documents/school/lavc/cs236/assignments/assignment01/test.cpp > CMakeFiles/tictactoetest.dir/test.cpp.i

CMakeFiles/tictactoetest.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tictactoetest.dir/test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jose-chung/Documents/school/lavc/cs236/assignments/assignment01/test.cpp -o CMakeFiles/tictactoetest.dir/test.cpp.s

CMakeFiles/tictactoetest.dir/test.cpp.o.requires:

.PHONY : CMakeFiles/tictactoetest.dir/test.cpp.o.requires

CMakeFiles/tictactoetest.dir/test.cpp.o.provides: CMakeFiles/tictactoetest.dir/test.cpp.o.requires
	$(MAKE) -f CMakeFiles/tictactoetest.dir/build.make CMakeFiles/tictactoetest.dir/test.cpp.o.provides.build
.PHONY : CMakeFiles/tictactoetest.dir/test.cpp.o.provides

CMakeFiles/tictactoetest.dir/test.cpp.o.provides.build: CMakeFiles/tictactoetest.dir/test.cpp.o


# Object files for target tictactoetest
tictactoetest_OBJECTS = \
"CMakeFiles/tictactoetest.dir/test.cpp.o"

# External object files for target tictactoetest
tictactoetest_EXTERNAL_OBJECTS =

tictactoetest: CMakeFiles/tictactoetest.dir/test.cpp.o
tictactoetest: CMakeFiles/tictactoetest.dir/build.make
tictactoetest: libassignment01_tictactoe.a
tictactoetest: CMakeFiles/tictactoetest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jose-chung/Documents/school/lavc/cs236/assignments/assignment01/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable tictactoetest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tictactoetest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tictactoetest.dir/build: tictactoetest

.PHONY : CMakeFiles/tictactoetest.dir/build

CMakeFiles/tictactoetest.dir/requires: CMakeFiles/tictactoetest.dir/test.cpp.o.requires

.PHONY : CMakeFiles/tictactoetest.dir/requires

CMakeFiles/tictactoetest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tictactoetest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tictactoetest.dir/clean

CMakeFiles/tictactoetest.dir/depend:
	cd /home/jose-chung/Documents/school/lavc/cs236/assignments/assignment01/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jose-chung/Documents/school/lavc/cs236/assignments/assignment01 /home/jose-chung/Documents/school/lavc/cs236/assignments/assignment01 /home/jose-chung/Documents/school/lavc/cs236/assignments/assignment01/build /home/jose-chung/Documents/school/lavc/cs236/assignments/assignment01/build /home/jose-chung/Documents/school/lavc/cs236/assignments/assignment01/build/CMakeFiles/tictactoetest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tictactoetest.dir/depend

