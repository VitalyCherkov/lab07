# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = /home/vcherkov/clion-2016.3.5/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/vcherkov/clion-2016.3.5/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/vcherkov/prep/lab07_01

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vcherkov/prep/lab07_01/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/lab07_01.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lab07_01.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab07_01.dir/flags.make

CMakeFiles/lab07_01.dir/main.cpp.o: CMakeFiles/lab07_01.dir/flags.make
CMakeFiles/lab07_01.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vcherkov/prep/lab07_01/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lab07_01.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab07_01.dir/main.cpp.o -c /home/vcherkov/prep/lab07_01/main.cpp

CMakeFiles/lab07_01.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab07_01.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vcherkov/prep/lab07_01/main.cpp > CMakeFiles/lab07_01.dir/main.cpp.i

CMakeFiles/lab07_01.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab07_01.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vcherkov/prep/lab07_01/main.cpp -o CMakeFiles/lab07_01.dir/main.cpp.s

CMakeFiles/lab07_01.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/lab07_01.dir/main.cpp.o.requires

CMakeFiles/lab07_01.dir/main.cpp.o.provides: CMakeFiles/lab07_01.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/lab07_01.dir/build.make CMakeFiles/lab07_01.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/lab07_01.dir/main.cpp.o.provides

CMakeFiles/lab07_01.dir/main.cpp.o.provides.build: CMakeFiles/lab07_01.dir/main.cpp.o


CMakeFiles/lab07_01.dir/String.cpp.o: CMakeFiles/lab07_01.dir/flags.make
CMakeFiles/lab07_01.dir/String.cpp.o: ../String.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vcherkov/prep/lab07_01/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/lab07_01.dir/String.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab07_01.dir/String.cpp.o -c /home/vcherkov/prep/lab07_01/String.cpp

CMakeFiles/lab07_01.dir/String.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab07_01.dir/String.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vcherkov/prep/lab07_01/String.cpp > CMakeFiles/lab07_01.dir/String.cpp.i

CMakeFiles/lab07_01.dir/String.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab07_01.dir/String.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vcherkov/prep/lab07_01/String.cpp -o CMakeFiles/lab07_01.dir/String.cpp.s

CMakeFiles/lab07_01.dir/String.cpp.o.requires:

.PHONY : CMakeFiles/lab07_01.dir/String.cpp.o.requires

CMakeFiles/lab07_01.dir/String.cpp.o.provides: CMakeFiles/lab07_01.dir/String.cpp.o.requires
	$(MAKE) -f CMakeFiles/lab07_01.dir/build.make CMakeFiles/lab07_01.dir/String.cpp.o.provides.build
.PHONY : CMakeFiles/lab07_01.dir/String.cpp.o.provides

CMakeFiles/lab07_01.dir/String.cpp.o.provides.build: CMakeFiles/lab07_01.dir/String.cpp.o


# Object files for target lab07_01
lab07_01_OBJECTS = \
"CMakeFiles/lab07_01.dir/main.cpp.o" \
"CMakeFiles/lab07_01.dir/String.cpp.o"

# External object files for target lab07_01
lab07_01_EXTERNAL_OBJECTS =

lab07_01: CMakeFiles/lab07_01.dir/main.cpp.o
lab07_01: CMakeFiles/lab07_01.dir/String.cpp.o
lab07_01: CMakeFiles/lab07_01.dir/build.make
lab07_01: CMakeFiles/lab07_01.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vcherkov/prep/lab07_01/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable lab07_01"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab07_01.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab07_01.dir/build: lab07_01

.PHONY : CMakeFiles/lab07_01.dir/build

CMakeFiles/lab07_01.dir/requires: CMakeFiles/lab07_01.dir/main.cpp.o.requires
CMakeFiles/lab07_01.dir/requires: CMakeFiles/lab07_01.dir/String.cpp.o.requires

.PHONY : CMakeFiles/lab07_01.dir/requires

CMakeFiles/lab07_01.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lab07_01.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lab07_01.dir/clean

CMakeFiles/lab07_01.dir/depend:
	cd /home/vcherkov/prep/lab07_01/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vcherkov/prep/lab07_01 /home/vcherkov/prep/lab07_01 /home/vcherkov/prep/lab07_01/cmake-build-debug /home/vcherkov/prep/lab07_01/cmake-build-debug /home/vcherkov/prep/lab07_01/cmake-build-debug/CMakeFiles/lab07_01.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lab07_01.dir/depend

