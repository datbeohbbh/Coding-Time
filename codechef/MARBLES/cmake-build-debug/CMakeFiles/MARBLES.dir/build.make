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
CMAKE_SOURCE_DIR = /home/datbeohbbh/Desktop/MY_PROJECT/codechef/MARBLES

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/datbeohbbh/Desktop/MY_PROJECT/codechef/MARBLES/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/MARBLES.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MARBLES.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MARBLES.dir/flags.make

CMakeFiles/MARBLES.dir/main.cpp.o: CMakeFiles/MARBLES.dir/flags.make
CMakeFiles/MARBLES.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/datbeohbbh/Desktop/MY_PROJECT/codechef/MARBLES/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MARBLES.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MARBLES.dir/main.cpp.o -c /home/datbeohbbh/Desktop/MY_PROJECT/codechef/MARBLES/main.cpp

CMakeFiles/MARBLES.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MARBLES.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/datbeohbbh/Desktop/MY_PROJECT/codechef/MARBLES/main.cpp > CMakeFiles/MARBLES.dir/main.cpp.i

CMakeFiles/MARBLES.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MARBLES.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/datbeohbbh/Desktop/MY_PROJECT/codechef/MARBLES/main.cpp -o CMakeFiles/MARBLES.dir/main.cpp.s

# Object files for target MARBLES
MARBLES_OBJECTS = \
"CMakeFiles/MARBLES.dir/main.cpp.o"

# External object files for target MARBLES
MARBLES_EXTERNAL_OBJECTS =

MARBLES: CMakeFiles/MARBLES.dir/main.cpp.o
MARBLES: CMakeFiles/MARBLES.dir/build.make
MARBLES: CMakeFiles/MARBLES.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/datbeohbbh/Desktop/MY_PROJECT/codechef/MARBLES/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable MARBLES"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MARBLES.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MARBLES.dir/build: MARBLES

.PHONY : CMakeFiles/MARBLES.dir/build

CMakeFiles/MARBLES.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MARBLES.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MARBLES.dir/clean

CMakeFiles/MARBLES.dir/depend:
	cd /home/datbeohbbh/Desktop/MY_PROJECT/codechef/MARBLES/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/datbeohbbh/Desktop/MY_PROJECT/codechef/MARBLES /home/datbeohbbh/Desktop/MY_PROJECT/codechef/MARBLES /home/datbeohbbh/Desktop/MY_PROJECT/codechef/MARBLES/cmake-build-debug /home/datbeohbbh/Desktop/MY_PROJECT/codechef/MARBLES/cmake-build-debug /home/datbeohbbh/Desktop/MY_PROJECT/codechef/MARBLES/cmake-build-debug/CMakeFiles/MARBLES.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MARBLES.dir/depend

