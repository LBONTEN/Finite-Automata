# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /home/teryjacky/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/183.5429.37/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/teryjacky/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/183.5429.37/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/teryjacky/FA

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/teryjacky/FA/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/DFA.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DFA.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DFA.dir/flags.make

CMakeFiles/DFA.dir/src/main.cpp.o: CMakeFiles/DFA.dir/flags.make
CMakeFiles/DFA.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/teryjacky/FA/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DFA.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DFA.dir/src/main.cpp.o -c /home/teryjacky/FA/src/main.cpp

CMakeFiles/DFA.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DFA.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/teryjacky/FA/src/main.cpp > CMakeFiles/DFA.dir/src/main.cpp.i

CMakeFiles/DFA.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DFA.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/teryjacky/FA/src/main.cpp -o CMakeFiles/DFA.dir/src/main.cpp.s

CMakeFiles/DFA.dir/src/DFA.cpp.o: CMakeFiles/DFA.dir/flags.make
CMakeFiles/DFA.dir/src/DFA.cpp.o: ../src/DFA.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/teryjacky/FA/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/DFA.dir/src/DFA.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DFA.dir/src/DFA.cpp.o -c /home/teryjacky/FA/src/DFA.cpp

CMakeFiles/DFA.dir/src/DFA.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DFA.dir/src/DFA.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/teryjacky/FA/src/DFA.cpp > CMakeFiles/DFA.dir/src/DFA.cpp.i

CMakeFiles/DFA.dir/src/DFA.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DFA.dir/src/DFA.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/teryjacky/FA/src/DFA.cpp -o CMakeFiles/DFA.dir/src/DFA.cpp.s

CMakeFiles/DFA.dir/src/Node.cpp.o: CMakeFiles/DFA.dir/flags.make
CMakeFiles/DFA.dir/src/Node.cpp.o: ../src/Node.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/teryjacky/FA/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/DFA.dir/src/Node.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DFA.dir/src/Node.cpp.o -c /home/teryjacky/FA/src/Node.cpp

CMakeFiles/DFA.dir/src/Node.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DFA.dir/src/Node.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/teryjacky/FA/src/Node.cpp > CMakeFiles/DFA.dir/src/Node.cpp.i

CMakeFiles/DFA.dir/src/Node.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DFA.dir/src/Node.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/teryjacky/FA/src/Node.cpp -o CMakeFiles/DFA.dir/src/Node.cpp.s

CMakeFiles/DFA.dir/src/helpers.cpp.o: CMakeFiles/DFA.dir/flags.make
CMakeFiles/DFA.dir/src/helpers.cpp.o: ../src/helpers.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/teryjacky/FA/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/DFA.dir/src/helpers.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DFA.dir/src/helpers.cpp.o -c /home/teryjacky/FA/src/helpers.cpp

CMakeFiles/DFA.dir/src/helpers.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DFA.dir/src/helpers.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/teryjacky/FA/src/helpers.cpp > CMakeFiles/DFA.dir/src/helpers.cpp.i

CMakeFiles/DFA.dir/src/helpers.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DFA.dir/src/helpers.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/teryjacky/FA/src/helpers.cpp -o CMakeFiles/DFA.dir/src/helpers.cpp.s

# Object files for target DFA
DFA_OBJECTS = \
"CMakeFiles/DFA.dir/src/main.cpp.o" \
"CMakeFiles/DFA.dir/src/DFA.cpp.o" \
"CMakeFiles/DFA.dir/src/Node.cpp.o" \
"CMakeFiles/DFA.dir/src/helpers.cpp.o"

# External object files for target DFA
DFA_EXTERNAL_OBJECTS =

DFA: CMakeFiles/DFA.dir/src/main.cpp.o
DFA: CMakeFiles/DFA.dir/src/DFA.cpp.o
DFA: CMakeFiles/DFA.dir/src/Node.cpp.o
DFA: CMakeFiles/DFA.dir/src/helpers.cpp.o
DFA: CMakeFiles/DFA.dir/build.make
DFA: CMakeFiles/DFA.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/teryjacky/FA/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable DFA"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DFA.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DFA.dir/build: DFA

.PHONY : CMakeFiles/DFA.dir/build

CMakeFiles/DFA.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DFA.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DFA.dir/clean

CMakeFiles/DFA.dir/depend:
	cd /home/teryjacky/FA/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/teryjacky/FA /home/teryjacky/FA /home/teryjacky/FA/cmake-build-debug /home/teryjacky/FA/cmake-build-debug /home/teryjacky/FA/cmake-build-debug/CMakeFiles/DFA.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DFA.dir/depend

