# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /home/datbeohbbh/Clion-2019.2.3/CLion-2019.2.3/clion-2019.2.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/datbeohbbh/Clion-2019.2.3/CLion-2019.2.3/clion-2019.2.3/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/datbeohbbh/Desktop/MY_PROJECT/codeforces/1228C

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/datbeohbbh/Desktop/MY_PROJECT/codeforces/1228C/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/1228C.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/1228C.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/1228C.dir/flags.make

CMakeFiles/1228C.dir/main.cpp.o: CMakeFiles/1228C.dir/flags.make
CMakeFiles/1228C.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/datbeohbbh/Desktop/MY_PROJECT/codeforces/1228C/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/1228C.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/1228C.dir/main.cpp.o -c /home/datbeohbbh/Desktop/MY_PROJECT/codeforces/1228C/main.cpp

CMakeFiles/1228C.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/1228C.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/datbeohbbh/Desktop/MY_PROJECT/codeforces/1228C/main.cpp > CMakeFiles/1228C.dir/main.cpp.i

CMakeFiles/1228C.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/1228C.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/datbeohbbh/Desktop/MY_PROJECT/codeforces/1228C/main.cpp -o CMakeFiles/1228C.dir/main.cpp.s

# Object files for target 1228C
1228C_OBJECTS = \
"CMakeFiles/1228C.dir/main.cpp.o"

# External object files for target 1228C
1228C_EXTERNAL_OBJECTS =

1228C: CMakeFiles/1228C.dir/main.cpp.o
1228C: CMakeFiles/1228C.dir/build.make
1228C: CMakeFiles/1228C.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/datbeohbbh/Desktop/MY_PROJECT/codeforces/1228C/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 1228C"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/1228C.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/1228C.dir/build: 1228C

.PHONY : CMakeFiles/1228C.dir/build

CMakeFiles/1228C.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/1228C.dir/cmake_clean.cmake
.PHONY : CMakeFiles/1228C.dir/clean

CMakeFiles/1228C.dir/depend:
	cd /home/datbeohbbh/Desktop/MY_PROJECT/codeforces/1228C/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/datbeohbbh/Desktop/MY_PROJECT/codeforces/1228C /home/datbeohbbh/Desktop/MY_PROJECT/codeforces/1228C /home/datbeohbbh/Desktop/MY_PROJECT/codeforces/1228C/cmake-build-debug /home/datbeohbbh/Desktop/MY_PROJECT/codeforces/1228C/cmake-build-debug /home/datbeohbbh/Desktop/MY_PROJECT/codeforces/1228C/cmake-build-debug/CMakeFiles/1228C.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/1228C.dir/depend

