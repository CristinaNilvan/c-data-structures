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
CMAKE_SOURCE_DIR = C:\Users\crist\OneDrive\Desktop\Exercitii\merge-binary-search-trees

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\crist\OneDrive\Desktop\Exercitii\merge-binary-search-trees\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/merge_binary_search_trees.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/merge_binary_search_trees.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/merge_binary_search_trees.dir/flags.make

CMakeFiles/merge_binary_search_trees.dir/main.c.obj: CMakeFiles/merge_binary_search_trees.dir/flags.make
CMakeFiles/merge_binary_search_trees.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\crist\OneDrive\Desktop\Exercitii\merge-binary-search-trees\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/merge_binary_search_trees.dir/main.c.obj"
	C:\PROGRA~1\CODEBL~1\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\merge_binary_search_trees.dir\main.c.obj   -c C:\Users\crist\OneDrive\Desktop\Exercitii\merge-binary-search-trees\main.c

CMakeFiles/merge_binary_search_trees.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/merge_binary_search_trees.dir/main.c.i"
	C:\PROGRA~1\CODEBL~1\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\crist\OneDrive\Desktop\Exercitii\merge-binary-search-trees\main.c > CMakeFiles\merge_binary_search_trees.dir\main.c.i

CMakeFiles/merge_binary_search_trees.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/merge_binary_search_trees.dir/main.c.s"
	C:\PROGRA~1\CODEBL~1\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\crist\OneDrive\Desktop\Exercitii\merge-binary-search-trees\main.c -o CMakeFiles\merge_binary_search_trees.dir\main.c.s

# Object files for target merge_binary_search_trees
merge_binary_search_trees_OBJECTS = \
"CMakeFiles/merge_binary_search_trees.dir/main.c.obj"

# External object files for target merge_binary_search_trees
merge_binary_search_trees_EXTERNAL_OBJECTS =

merge_binary_search_trees.exe: CMakeFiles/merge_binary_search_trees.dir/main.c.obj
merge_binary_search_trees.exe: CMakeFiles/merge_binary_search_trees.dir/build.make
merge_binary_search_trees.exe: CMakeFiles/merge_binary_search_trees.dir/linklibs.rsp
merge_binary_search_trees.exe: CMakeFiles/merge_binary_search_trees.dir/objects1.rsp
merge_binary_search_trees.exe: CMakeFiles/merge_binary_search_trees.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\crist\OneDrive\Desktop\Exercitii\merge-binary-search-trees\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable merge_binary_search_trees.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\merge_binary_search_trees.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/merge_binary_search_trees.dir/build: merge_binary_search_trees.exe

.PHONY : CMakeFiles/merge_binary_search_trees.dir/build

CMakeFiles/merge_binary_search_trees.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\merge_binary_search_trees.dir\cmake_clean.cmake
.PHONY : CMakeFiles/merge_binary_search_trees.dir/clean

CMakeFiles/merge_binary_search_trees.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\crist\OneDrive\Desktop\Exercitii\merge-binary-search-trees C:\Users\crist\OneDrive\Desktop\Exercitii\merge-binary-search-trees C:\Users\crist\OneDrive\Desktop\Exercitii\merge-binary-search-trees\cmake-build-debug C:\Users\crist\OneDrive\Desktop\Exercitii\merge-binary-search-trees\cmake-build-debug C:\Users\crist\OneDrive\Desktop\Exercitii\merge-binary-search-trees\cmake-build-debug\CMakeFiles\merge_binary_search_trees.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/merge_binary_search_trees.dir/depend

