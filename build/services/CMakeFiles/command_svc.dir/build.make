# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = /home/chris/Workspaces/quadcopter_ws/src/services

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/chris/Workspaces/quadcopter_ws/build/services

# Include any dependencies generated for this target.
include CMakeFiles/command_svc.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/command_svc.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/command_svc.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/command_svc.dir/flags.make

CMakeFiles/command_svc.dir/src/command_svc.cpp.o: CMakeFiles/command_svc.dir/flags.make
CMakeFiles/command_svc.dir/src/command_svc.cpp.o: /home/chris/Workspaces/quadcopter_ws/src/services/src/command_svc.cpp
CMakeFiles/command_svc.dir/src/command_svc.cpp.o: CMakeFiles/command_svc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/chris/Workspaces/quadcopter_ws/build/services/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/command_svc.dir/src/command_svc.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/command_svc.dir/src/command_svc.cpp.o -MF CMakeFiles/command_svc.dir/src/command_svc.cpp.o.d -o CMakeFiles/command_svc.dir/src/command_svc.cpp.o -c /home/chris/Workspaces/quadcopter_ws/src/services/src/command_svc.cpp

CMakeFiles/command_svc.dir/src/command_svc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/command_svc.dir/src/command_svc.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/chris/Workspaces/quadcopter_ws/src/services/src/command_svc.cpp > CMakeFiles/command_svc.dir/src/command_svc.cpp.i

CMakeFiles/command_svc.dir/src/command_svc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/command_svc.dir/src/command_svc.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/chris/Workspaces/quadcopter_ws/src/services/src/command_svc.cpp -o CMakeFiles/command_svc.dir/src/command_svc.cpp.s

# Object files for target command_svc
command_svc_OBJECTS = \
"CMakeFiles/command_svc.dir/src/command_svc.cpp.o"

# External object files for target command_svc
command_svc_EXTERNAL_OBJECTS =

command_svc: CMakeFiles/command_svc.dir/src/command_svc.cpp.o
command_svc: CMakeFiles/command_svc.dir/build.make
command_svc: CMakeFiles/command_svc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/chris/Workspaces/quadcopter_ws/build/services/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable command_svc"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/command_svc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/command_svc.dir/build: command_svc
.PHONY : CMakeFiles/command_svc.dir/build

CMakeFiles/command_svc.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/command_svc.dir/cmake_clean.cmake
.PHONY : CMakeFiles/command_svc.dir/clean

CMakeFiles/command_svc.dir/depend:
	cd /home/chris/Workspaces/quadcopter_ws/build/services && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/chris/Workspaces/quadcopter_ws/src/services /home/chris/Workspaces/quadcopter_ws/src/services /home/chris/Workspaces/quadcopter_ws/build/services /home/chris/Workspaces/quadcopter_ws/build/services /home/chris/Workspaces/quadcopter_ws/build/services/CMakeFiles/command_svc.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/command_svc.dir/depend

