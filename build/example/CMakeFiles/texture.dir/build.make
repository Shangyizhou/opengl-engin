# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.30

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
CMAKE_SOURCE_DIR = D:\shangyizhou\code\opengl\opengl-engine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\shangyizhou\code\opengl\opengl-engine\build

# Include any dependencies generated for this target.
include example/CMakeFiles/texture.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include example/CMakeFiles/texture.dir/compiler_depend.make

# Include the progress variables for this target.
include example/CMakeFiles/texture.dir/progress.make

# Include the compile flags for this target's objects.
include example/CMakeFiles/texture.dir/flags.make

example/CMakeFiles/texture.dir/texture.cc.obj: example/CMakeFiles/texture.dir/flags.make
example/CMakeFiles/texture.dir/texture.cc.obj: example/CMakeFiles/texture.dir/includes_CXX.rsp
example/CMakeFiles/texture.dir/texture.cc.obj: D:/shangyizhou/code/opengl/opengl-engine/example/texture.cc
example/CMakeFiles/texture.dir/texture.cc.obj: example/CMakeFiles/texture.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\shangyizhou\code\opengl\opengl-engine\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object example/CMakeFiles/texture.dir/texture.cc.obj"
	cd /d D:\shangyizhou\code\opengl\opengl-engine\build\example && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT example/CMakeFiles/texture.dir/texture.cc.obj -MF CMakeFiles\texture.dir\texture.cc.obj.d -o CMakeFiles\texture.dir\texture.cc.obj -c D:\shangyizhou\code\opengl\opengl-engine\example\texture.cc

example/CMakeFiles/texture.dir/texture.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/texture.dir/texture.cc.i"
	cd /d D:\shangyizhou\code\opengl\opengl-engine\build\example && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\shangyizhou\code\opengl\opengl-engine\example\texture.cc > CMakeFiles\texture.dir\texture.cc.i

example/CMakeFiles/texture.dir/texture.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/texture.dir/texture.cc.s"
	cd /d D:\shangyizhou\code\opengl\opengl-engine\build\example && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\shangyizhou\code\opengl\opengl-engine\example\texture.cc -o CMakeFiles\texture.dir\texture.cc.s

# Object files for target texture
texture_OBJECTS = \
"CMakeFiles/texture.dir/texture.cc.obj"

# External object files for target texture
texture_EXTERNAL_OBJECTS =

D:/shangyizhou/code/opengl/opengl-engine/bin/texture.exe: example/CMakeFiles/texture.dir/texture.cc.obj
D:/shangyizhou/code/opengl/opengl-engine/bin/texture.exe: example/CMakeFiles/texture.dir/build.make
D:/shangyizhou/code/opengl/opengl-engine/bin/texture.exe: D:/shangyizhou/code/opengl/opengl-engine/lib/libglfw3.a
D:/shangyizhou/code/opengl/opengl-engine/bin/texture.exe: D:/shangyizhou/code/opengl/opengl-engine/lib/libglad.a
D:/shangyizhou/code/opengl/opengl-engine/bin/texture.exe: example/CMakeFiles/texture.dir/linkLibs.rsp
D:/shangyizhou/code/opengl/opengl-engine/bin/texture.exe: example/CMakeFiles/texture.dir/objects1.rsp
D:/shangyizhou/code/opengl/opengl-engine/bin/texture.exe: example/CMakeFiles/texture.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=D:\shangyizhou\code\opengl\opengl-engine\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable D:\shangyizhou\code\opengl\opengl-engine\bin\texture.exe"
	cd /d D:\shangyizhou\code\opengl\opengl-engine\build\example && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\texture.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
example/CMakeFiles/texture.dir/build: D:/shangyizhou/code/opengl/opengl-engine/bin/texture.exe
.PHONY : example/CMakeFiles/texture.dir/build

example/CMakeFiles/texture.dir/clean:
	cd /d D:\shangyizhou\code\opengl\opengl-engine\build\example && $(CMAKE_COMMAND) -P CMakeFiles\texture.dir\cmake_clean.cmake
.PHONY : example/CMakeFiles/texture.dir/clean

example/CMakeFiles/texture.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\shangyizhou\code\opengl\opengl-engine D:\shangyizhou\code\opengl\opengl-engine\example D:\shangyizhou\code\opengl\opengl-engine\build D:\shangyizhou\code\opengl\opengl-engine\build\example D:\shangyizhou\code\opengl\opengl-engine\build\example\CMakeFiles\texture.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : example/CMakeFiles/texture.dir/depend

