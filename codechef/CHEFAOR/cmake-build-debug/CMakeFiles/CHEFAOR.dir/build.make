# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/datbeohbbh/Desktop/MY_PROJECT/codechef/CHEFAOR

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/datbeohbbh/Desktop/MY_PROJECT/codechef/CHEFAOR/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/CHEFAOR.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CHEFAOR.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CHEFAOR.dir/flags.make

CMakeFiles/CHEFAOR.dir/main.cpp.o: CMakeFiles/CHEFAOR.dir/flags.make
CMakeFiles/CHEFAOR.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/datbeohbbh/Desktop/MY_PROJECT/codechef/CHEFAOR/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CHEFAOR.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CHEFAOR.dir/main.cpp.o -c /home/datbeohbbh/Desktop/MY_PROJECT/codechef/CHEFAOR/main.cpp

CMakeFiles/CHEFAOR.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CHEFAOR.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/datbeohbbh/Desktop/MY_PROJECT/codechef/CHEFAOR/main.cpp > CMakeFiles/CHEFAOR.dir/main.cpp.i

CMakeFiles/CHEFAOR.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CHEFAOR.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/datbeohbbh/Desktop/MY_PROJECT/codechef/CHEFAOR/main.cpp -o CMakeFiles/CHEFAOR.dir/main.cpp.s

# Object files for target CHEFAOR
CHEFAOR_OBJECTS = \
"CMakeFiles/CHEFAOR.dir/main.cpp.o"

# External object files for target CHEFAOR
CHEFAOR_EXTERNAL_OBJECTS =

CHEFAOR: CMakeFiles/CHEFAOR.dir/main.cpp.o
CHEFAOR: CMakeFiles/CHEFAOR.dir/build.make
CHEFAOR: CMakeFiles/CHEFAOR.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/datbeohbbh/Desktop/MY_PROJECT/codechef/CHEFAOR/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable CHEFAOR"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CHEFAOR.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CHEFAOR.dir/build: CHEFAOR

.PHONY : CMakeFiles/CHEFAOR.dir/build

CMakeFiles/CHEFAOR.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CHEFAOR.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CHEFAOR.dir/clean

CMakeFiles/CHEFAOR.dir/depend:
	cd /home/datbeohbbh/Desktop/MY_PROJECT/codechef/CHEFAOR/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/datbeohbbh/Desktop/MY_PROJECT/codechef/CHEFAOR /home/datbeohbbh/Desktop/MY_PROJECT/codechef/CHEFAOR /home/datbeohbbh/Desktop/MY_PROJECT/codechef/CHEFAOR/cmake-build-debug /home/datbeohbbh/Desktop/MY_PROJECT/codechef/CHEFAOR/cmake-build-debug /home/datbeohbbh/Desktop/MY_PROJECT/codechef/CHEFAOR/cmake-build-debug/CMakeFiles/CHEFAOR.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CHEFAOR.dir/depend

