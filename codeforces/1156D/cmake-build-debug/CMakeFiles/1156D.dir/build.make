# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /home/datbeohbbh/Clion/clion-2019.1.2/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/datbeohbbh/Clion/clion-2019.1.2/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/datbeohbbh/Desktop/MY_PROJECT/codeforces/1156D

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/datbeohbbh/Desktop/MY_PROJECT/codeforces/1156D/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/1156D.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/1156D.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/1156D.dir/flags.make

CMakeFiles/1156D.dir/main.cpp.o: CMakeFiles/1156D.dir/flags.make
CMakeFiles/1156D.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/datbeohbbh/Desktop/MY_PROJECT/codeforces/1156D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/1156D.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/1156D.dir/main.cpp.o -c /home/datbeohbbh/Desktop/MY_PROJECT/codeforces/1156D/main.cpp

CMakeFiles/1156D.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/1156D.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/datbeohbbh/Desktop/MY_PROJECT/codeforces/1156D/main.cpp > CMakeFiles/1156D.dir/main.cpp.i

CMakeFiles/1156D.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/1156D.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/datbeohbbh/Desktop/MY_PROJECT/codeforces/1156D/main.cpp -o CMakeFiles/1156D.dir/main.cpp.s

# Object files for target 1156D
1156D_OBJECTS = \
"CMakeFiles/1156D.dir/main.cpp.o"

# External object files for target 1156D
1156D_EXTERNAL_OBJECTS =

1156D: CMakeFiles/1156D.dir/main.cpp.o
1156D: CMakeFiles/1156D.dir/build.make
1156D: CMakeFiles/1156D.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/datbeohbbh/Desktop/MY_PROJECT/codeforces/1156D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 1156D"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/1156D.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/1156D.dir/build: 1156D

.PHONY : CMakeFiles/1156D.dir/build

CMakeFiles/1156D.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/1156D.dir/cmake_clean.cmake
.PHONY : CMakeFiles/1156D.dir/clean

CMakeFiles/1156D.dir/depend:
	cd /home/datbeohbbh/Desktop/MY_PROJECT/codeforces/1156D/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/datbeohbbh/Desktop/MY_PROJECT/codeforces/1156D /home/datbeohbbh/Desktop/MY_PROJECT/codeforces/1156D /home/datbeohbbh/Desktop/MY_PROJECT/codeforces/1156D/cmake-build-debug /home/datbeohbbh/Desktop/MY_PROJECT/codeforces/1156D/cmake-build-debug /home/datbeohbbh/Desktop/MY_PROJECT/codeforces/1156D/cmake-build-debug/CMakeFiles/1156D.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/1156D.dir/depend

