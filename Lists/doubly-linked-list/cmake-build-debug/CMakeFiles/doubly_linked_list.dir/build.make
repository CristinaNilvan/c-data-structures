# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2.4\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\crist\OneDrive\Desktop\Github\doubly-linked-list

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\crist\OneDrive\Desktop\Github\doubly-linked-list\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/doubly_linked_list.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/doubly_linked_list.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/doubly_linked_list.dir/flags.make

CMakeFiles/doubly_linked_list.dir/main.c.obj: CMakeFiles/doubly_linked_list.dir/flags.make
CMakeFiles/doubly_linked_list.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\crist\OneDrive\Desktop\Github\doubly-linked-list\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/doubly_linked_list.dir/main.c.obj"
	C:\PROGRA~1\CODEBL~1\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\doubly_linked_list.dir\main.c.obj   -c C:\Users\crist\OneDrive\Desktop\Github\doubly-linked-list\main.c

CMakeFiles/doubly_linked_list.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/doubly_linked_list.dir/main.c.i"
	C:\PROGRA~1\CODEBL~1\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\crist\OneDrive\Desktop\Github\doubly-linked-list\main.c > CMakeFiles\doubly_linked_list.dir\main.c.i

CMakeFiles/doubly_linked_list.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/doubly_linked_list.dir/main.c.s"
	C:\PROGRA~1\CODEBL~1\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\crist\OneDrive\Desktop\Github\doubly-linked-list\main.c -o CMakeFiles\doubly_linked_list.dir\main.c.s

# Object files for target doubly_linked_list
doubly_linked_list_OBJECTS = \
"CMakeFiles/doubly_linked_list.dir/main.c.obj"

# External object files for target doubly_linked_list
doubly_linked_list_EXTERNAL_OBJECTS =

doubly_linked_list.exe: CMakeFiles/doubly_linked_list.dir/main.c.obj
doubly_linked_list.exe: CMakeFiles/doubly_linked_list.dir/build.make
doubly_linked_list.exe: CMakeFiles/doubly_linked_list.dir/linklibs.rsp
doubly_linked_list.exe: CMakeFiles/doubly_linked_list.dir/objects1.rsp
doubly_linked_list.exe: CMakeFiles/doubly_linked_list.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\crist\OneDrive\Desktop\Github\doubly-linked-list\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable doubly_linked_list.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\doubly_linked_list.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/doubly_linked_list.dir/build: doubly_linked_list.exe

.PHONY : CMakeFiles/doubly_linked_list.dir/build

CMakeFiles/doubly_linked_list.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\doubly_linked_list.dir\cmake_clean.cmake
.PHONY : CMakeFiles/doubly_linked_list.dir/clean

CMakeFiles/doubly_linked_list.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\crist\OneDrive\Desktop\Github\doubly-linked-list C:\Users\crist\OneDrive\Desktop\Github\doubly-linked-list C:\Users\crist\OneDrive\Desktop\Github\doubly-linked-list\cmake-build-debug C:\Users\crist\OneDrive\Desktop\Github\doubly-linked-list\cmake-build-debug C:\Users\crist\OneDrive\Desktop\Github\doubly-linked-list\cmake-build-debug\CMakeFiles\doubly_linked_list.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/doubly_linked_list.dir/depend

