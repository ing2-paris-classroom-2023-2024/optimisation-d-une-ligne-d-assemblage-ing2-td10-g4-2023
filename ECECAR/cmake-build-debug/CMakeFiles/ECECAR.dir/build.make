# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.23

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2022.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2022.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\ncadi\CLionProjects\untitled58\optimisation-d-une-ligne-d-assemblage-ing2-td10-g4-2023\ECECAR

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\ncadi\CLionProjects\untitled58\optimisation-d-une-ligne-d-assemblage-ing2-td10-g4-2023\ECECAR\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ECECAR.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ECECAR.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ECECAR.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ECECAR.dir/flags.make

CMakeFiles/ECECAR.dir/main.c.obj: CMakeFiles/ECECAR.dir/flags.make
CMakeFiles/ECECAR.dir/main.c.obj: ../main.c
CMakeFiles/ECECAR.dir/main.c.obj: CMakeFiles/ECECAR.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\ncadi\CLionProjects\untitled58\optimisation-d-une-ligne-d-assemblage-ing2-td10-g4-2023\ECECAR\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ECECAR.dir/main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/ECECAR.dir/main.c.obj -MF CMakeFiles\ECECAR.dir\main.c.obj.d -o CMakeFiles\ECECAR.dir\main.c.obj -c C:\Users\ncadi\CLionProjects\untitled58\optimisation-d-une-ligne-d-assemblage-ing2-td10-g4-2023\ECECAR\main.c

CMakeFiles/ECECAR.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ECECAR.dir/main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\ncadi\CLionProjects\untitled58\optimisation-d-une-ligne-d-assemblage-ing2-td10-g4-2023\ECECAR\main.c > CMakeFiles\ECECAR.dir\main.c.i

CMakeFiles/ECECAR.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ECECAR.dir/main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\ncadi\CLionProjects\untitled58\optimisation-d-une-ligne-d-assemblage-ing2-td10-g4-2023\ECECAR\main.c -o CMakeFiles\ECECAR.dir\main.c.s

# Object files for target ECECAR
ECECAR_OBJECTS = \
"CMakeFiles/ECECAR.dir/main.c.obj"

# External object files for target ECECAR
ECECAR_EXTERNAL_OBJECTS =

ECECAR.exe: CMakeFiles/ECECAR.dir/main.c.obj
ECECAR.exe: CMakeFiles/ECECAR.dir/build.make
ECECAR.exe: CMakeFiles/ECECAR.dir/linklibs.rsp
ECECAR.exe: CMakeFiles/ECECAR.dir/objects1.rsp
ECECAR.exe: CMakeFiles/ECECAR.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\ncadi\CLionProjects\untitled58\optimisation-d-une-ligne-d-assemblage-ing2-td10-g4-2023\ECECAR\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ECECAR.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ECECAR.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ECECAR.dir/build: ECECAR.exe
.PHONY : CMakeFiles/ECECAR.dir/build

CMakeFiles/ECECAR.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ECECAR.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ECECAR.dir/clean

CMakeFiles/ECECAR.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\ncadi\CLionProjects\untitled58\optimisation-d-une-ligne-d-assemblage-ing2-td10-g4-2023\ECECAR C:\Users\ncadi\CLionProjects\untitled58\optimisation-d-une-ligne-d-assemblage-ing2-td10-g4-2023\ECECAR C:\Users\ncadi\CLionProjects\untitled58\optimisation-d-une-ligne-d-assemblage-ing2-td10-g4-2023\ECECAR\cmake-build-debug C:\Users\ncadi\CLionProjects\untitled58\optimisation-d-une-ligne-d-assemblage-ing2-td10-g4-2023\ECECAR\cmake-build-debug C:\Users\ncadi\CLionProjects\untitled58\optimisation-d-une-ligne-d-assemblage-ing2-td10-g4-2023\ECECAR\cmake-build-debug\CMakeFiles\ECECAR.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ECECAR.dir/depend

