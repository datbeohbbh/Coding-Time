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
CMAKE_SOURCE_DIR = /home/datbeohbbh/Desktop/MY_PROJECT/codechef/KOL15B

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/datbeohbbh/Desktop/MY_PROJECT/codechef/KOL15B/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/KOL15B.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/KOL15B.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/KOL15B.dir/flags.make

CMakeFiles/KOL15B.dir/main.cpp.o: CMakeFiles/KOL15B.dir/flags.make
CMakeFiles/KOL15B.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/datbeohbbh/Desktop/MY_PROJECT/codechef/KOL15B/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/KOL15B.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/KOL15B.dir/main.cpp.o -c /home/datbeohbbh/Desktop/MY_PROJECT/codechef/KOL15B/main.cpp

CMakeFiles/KOL15B.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/KOL15B.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/datbeohbbh/Desktop/MY_PROJECT/codechef/KOL15B/main.cpp > CMakeFiles/KOL15B.dir/main.cpp.i

CMakeFiles/KOL15B.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/KOL15B.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/datbeohbbh/Desktop/MY_PROJECT/codechef/KOL15B/main.cpp -o CMakeFiles/KOL15B.dir/main.cpp.s

# Object files for target KOL15B
KOL15B_OBJECTS = \
"CMakeFiles/KOL15B.dir/main.cpp.o"

# External object files for target KOL15B
KOL15B_EXTERNAL_OBJECTS =

KOL15B: CMakeFiles/KOL15B.dir/main.cpp.o
KOL15B: CMakeFiles/KOL15B.dir/build.make
KOL15B: CMakeFiles/KOL15B.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/datbeohbbh/Desktop/MY_PROJECT/codechef/KOL15B/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable KOL15B"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/KOL15B.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/KOL15B.dir/build: KOL15B

.PHONY : CMakeFiles/KOL15B.dir/build

CMakeFiles/KOL15B.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/KOL15B.dir/cmake_clean.cmake
.PHONY : CMakeFiles/KOL15B.dir/clean

CMakeFiles/KOL15B.dir/depend:
	cd /home/datbeohbbh/Desktop/MY_PROJECT/codechef/KOL15B/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/datbeohbbh/Desktop/MY_PROJECT/codechef/KOL15B /home/datbeohbbh/Desktop/MY_PROJECT/codechef/KOL15B /home/datbeohbbh/Desktop/MY_PROJECT/codechef/KOL15B/cmake-build-debug /home/datbeohbbh/Desktop/MY_PROJECT/codechef/KOL15B/cmake-build-debug /home/datbeohbbh/Desktop/MY_PROJECT/codechef/KOL15B/cmake-build-debug/CMakeFiles/KOL15B.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/KOL15B.dir/depend
