# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\08809\Desktop\RP2040\sdk\pico-sdk\tools\elf2uf2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\08809\Desktop\RP2040\src\ov2640_pio\build\elf2uf2

# Include any dependencies generated for this target.
include CMakeFiles/elf2uf2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/elf2uf2.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/elf2uf2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/elf2uf2.dir/flags.make

CMakeFiles/elf2uf2.dir/main.cpp.obj: CMakeFiles/elf2uf2.dir/flags.make
CMakeFiles/elf2uf2.dir/main.cpp.obj: CMakeFiles/elf2uf2.dir/includes_CXX.rsp
CMakeFiles/elf2uf2.dir/main.cpp.obj: C:/Users/08809/Desktop/RP2040/sdk/pico-sdk/tools/elf2uf2/main.cpp
CMakeFiles/elf2uf2.dir/main.cpp.obj: CMakeFiles/elf2uf2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\08809\Desktop\RP2040\src\ov2640_pio\build\elf2uf2\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/elf2uf2.dir/main.cpp.obj"
	C:\Users\08809\Desktop\RP2040\sdk\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/elf2uf2.dir/main.cpp.obj -MF CMakeFiles\elf2uf2.dir\main.cpp.obj.d -o CMakeFiles\elf2uf2.dir\main.cpp.obj -c C:\Users\08809\Desktop\RP2040\sdk\pico-sdk\tools\elf2uf2\main.cpp

CMakeFiles/elf2uf2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/elf2uf2.dir/main.cpp.i"
	C:\Users\08809\Desktop\RP2040\sdk\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\08809\Desktop\RP2040\sdk\pico-sdk\tools\elf2uf2\main.cpp > CMakeFiles\elf2uf2.dir\main.cpp.i

CMakeFiles/elf2uf2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/elf2uf2.dir/main.cpp.s"
	C:\Users\08809\Desktop\RP2040\sdk\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\08809\Desktop\RP2040\sdk\pico-sdk\tools\elf2uf2\main.cpp -o CMakeFiles\elf2uf2.dir\main.cpp.s

# Object files for target elf2uf2
elf2uf2_OBJECTS = \
"CMakeFiles/elf2uf2.dir/main.cpp.obj"

# External object files for target elf2uf2
elf2uf2_EXTERNAL_OBJECTS =

elf2uf2.exe: CMakeFiles/elf2uf2.dir/main.cpp.obj
elf2uf2.exe: CMakeFiles/elf2uf2.dir/build.make
elf2uf2.exe: CMakeFiles/elf2uf2.dir/linkLibs.rsp
elf2uf2.exe: CMakeFiles/elf2uf2.dir/objects1.rsp
elf2uf2.exe: CMakeFiles/elf2uf2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\08809\Desktop\RP2040\src\ov2640_pio\build\elf2uf2\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable elf2uf2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\elf2uf2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/elf2uf2.dir/build: elf2uf2.exe
.PHONY : CMakeFiles/elf2uf2.dir/build

CMakeFiles/elf2uf2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\elf2uf2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/elf2uf2.dir/clean

CMakeFiles/elf2uf2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\08809\Desktop\RP2040\sdk\pico-sdk\tools\elf2uf2 C:\Users\08809\Desktop\RP2040\sdk\pico-sdk\tools\elf2uf2 C:\Users\08809\Desktop\RP2040\src\ov2640_pio\build\elf2uf2 C:\Users\08809\Desktop\RP2040\src\ov2640_pio\build\elf2uf2 C:\Users\08809\Desktop\RP2040\src\ov2640_pio\build\elf2uf2\CMakeFiles\elf2uf2.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/elf2uf2.dir/depend

