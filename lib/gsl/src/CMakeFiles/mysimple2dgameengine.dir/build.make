# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/francisco/Projects/gameEngines/sdl/2dgameEngine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/francisco/Projects/gameEngines/sdl/2dgameEngine/build

# Include any dependencies generated for this target.
include src/CMakeFiles/mysimple2dgameengine.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/mysimple2dgameengine.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/mysimple2dgameengine.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/mysimple2dgameengine.dir/flags.make

src/CMakeFiles/mysimple2dgameengine.dir/AssetMng.cpp.o: src/CMakeFiles/mysimple2dgameengine.dir/flags.make
src/CMakeFiles/mysimple2dgameengine.dir/AssetMng.cpp.o: /home/francisco/Projects/gameEngines/sdl/2dgameEngine/src/AssetMng.cpp
src/CMakeFiles/mysimple2dgameengine.dir/AssetMng.cpp.o: src/CMakeFiles/mysimple2dgameengine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/francisco/Projects/gameEngines/sdl/2dgameEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/mysimple2dgameengine.dir/AssetMng.cpp.o"
	cd /home/francisco/Projects/gameEngines/sdl/2dgameEngine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/mysimple2dgameengine.dir/AssetMng.cpp.o -MF CMakeFiles/mysimple2dgameengine.dir/AssetMng.cpp.o.d -o CMakeFiles/mysimple2dgameengine.dir/AssetMng.cpp.o -c /home/francisco/Projects/gameEngines/sdl/2dgameEngine/src/AssetMng.cpp

src/CMakeFiles/mysimple2dgameengine.dir/AssetMng.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mysimple2dgameengine.dir/AssetMng.cpp.i"
	cd /home/francisco/Projects/gameEngines/sdl/2dgameEngine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/francisco/Projects/gameEngines/sdl/2dgameEngine/src/AssetMng.cpp > CMakeFiles/mysimple2dgameengine.dir/AssetMng.cpp.i

src/CMakeFiles/mysimple2dgameengine.dir/AssetMng.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mysimple2dgameengine.dir/AssetMng.cpp.s"
	cd /home/francisco/Projects/gameEngines/sdl/2dgameEngine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/francisco/Projects/gameEngines/sdl/2dgameEngine/src/AssetMng.cpp -o CMakeFiles/mysimple2dgameengine.dir/AssetMng.cpp.s

src/CMakeFiles/mysimple2dgameengine.dir/Entity.cpp.o: src/CMakeFiles/mysimple2dgameengine.dir/flags.make
src/CMakeFiles/mysimple2dgameengine.dir/Entity.cpp.o: /home/francisco/Projects/gameEngines/sdl/2dgameEngine/src/Entity.cpp
src/CMakeFiles/mysimple2dgameengine.dir/Entity.cpp.o: src/CMakeFiles/mysimple2dgameengine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/francisco/Projects/gameEngines/sdl/2dgameEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/mysimple2dgameengine.dir/Entity.cpp.o"
	cd /home/francisco/Projects/gameEngines/sdl/2dgameEngine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/mysimple2dgameengine.dir/Entity.cpp.o -MF CMakeFiles/mysimple2dgameengine.dir/Entity.cpp.o.d -o CMakeFiles/mysimple2dgameengine.dir/Entity.cpp.o -c /home/francisco/Projects/gameEngines/sdl/2dgameEngine/src/Entity.cpp

src/CMakeFiles/mysimple2dgameengine.dir/Entity.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mysimple2dgameengine.dir/Entity.cpp.i"
	cd /home/francisco/Projects/gameEngines/sdl/2dgameEngine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/francisco/Projects/gameEngines/sdl/2dgameEngine/src/Entity.cpp > CMakeFiles/mysimple2dgameengine.dir/Entity.cpp.i

src/CMakeFiles/mysimple2dgameengine.dir/Entity.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mysimple2dgameengine.dir/Entity.cpp.s"
	cd /home/francisco/Projects/gameEngines/sdl/2dgameEngine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/francisco/Projects/gameEngines/sdl/2dgameEngine/src/Entity.cpp -o CMakeFiles/mysimple2dgameengine.dir/Entity.cpp.s

src/CMakeFiles/mysimple2dgameengine.dir/EntityMng.cpp.o: src/CMakeFiles/mysimple2dgameengine.dir/flags.make
src/CMakeFiles/mysimple2dgameengine.dir/EntityMng.cpp.o: /home/francisco/Projects/gameEngines/sdl/2dgameEngine/src/EntityMng.cpp
src/CMakeFiles/mysimple2dgameengine.dir/EntityMng.cpp.o: src/CMakeFiles/mysimple2dgameengine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/francisco/Projects/gameEngines/sdl/2dgameEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/mysimple2dgameengine.dir/EntityMng.cpp.o"
	cd /home/francisco/Projects/gameEngines/sdl/2dgameEngine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/mysimple2dgameengine.dir/EntityMng.cpp.o -MF CMakeFiles/mysimple2dgameengine.dir/EntityMng.cpp.o.d -o CMakeFiles/mysimple2dgameengine.dir/EntityMng.cpp.o -c /home/francisco/Projects/gameEngines/sdl/2dgameEngine/src/EntityMng.cpp

src/CMakeFiles/mysimple2dgameengine.dir/EntityMng.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mysimple2dgameengine.dir/EntityMng.cpp.i"
	cd /home/francisco/Projects/gameEngines/sdl/2dgameEngine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/francisco/Projects/gameEngines/sdl/2dgameEngine/src/EntityMng.cpp > CMakeFiles/mysimple2dgameengine.dir/EntityMng.cpp.i

src/CMakeFiles/mysimple2dgameengine.dir/EntityMng.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mysimple2dgameengine.dir/EntityMng.cpp.s"
	cd /home/francisco/Projects/gameEngines/sdl/2dgameEngine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/francisco/Projects/gameEngines/sdl/2dgameEngine/src/EntityMng.cpp -o CMakeFiles/mysimple2dgameengine.dir/EntityMng.cpp.s

src/CMakeFiles/mysimple2dgameengine.dir/Game.cpp.o: src/CMakeFiles/mysimple2dgameengine.dir/flags.make
src/CMakeFiles/mysimple2dgameengine.dir/Game.cpp.o: /home/francisco/Projects/gameEngines/sdl/2dgameEngine/src/Game.cpp
src/CMakeFiles/mysimple2dgameengine.dir/Game.cpp.o: src/CMakeFiles/mysimple2dgameengine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/francisco/Projects/gameEngines/sdl/2dgameEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/mysimple2dgameengine.dir/Game.cpp.o"
	cd /home/francisco/Projects/gameEngines/sdl/2dgameEngine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/mysimple2dgameengine.dir/Game.cpp.o -MF CMakeFiles/mysimple2dgameengine.dir/Game.cpp.o.d -o CMakeFiles/mysimple2dgameengine.dir/Game.cpp.o -c /home/francisco/Projects/gameEngines/sdl/2dgameEngine/src/Game.cpp

src/CMakeFiles/mysimple2dgameengine.dir/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mysimple2dgameengine.dir/Game.cpp.i"
	cd /home/francisco/Projects/gameEngines/sdl/2dgameEngine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/francisco/Projects/gameEngines/sdl/2dgameEngine/src/Game.cpp > CMakeFiles/mysimple2dgameengine.dir/Game.cpp.i

src/CMakeFiles/mysimple2dgameengine.dir/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mysimple2dgameengine.dir/Game.cpp.s"
	cd /home/francisco/Projects/gameEngines/sdl/2dgameEngine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/francisco/Projects/gameEngines/sdl/2dgameEngine/src/Game.cpp -o CMakeFiles/mysimple2dgameengine.dir/Game.cpp.s

src/CMakeFiles/mysimple2dgameengine.dir/TextureMng.cpp.o: src/CMakeFiles/mysimple2dgameengine.dir/flags.make
src/CMakeFiles/mysimple2dgameengine.dir/TextureMng.cpp.o: /home/francisco/Projects/gameEngines/sdl/2dgameEngine/src/TextureMng.cpp
src/CMakeFiles/mysimple2dgameengine.dir/TextureMng.cpp.o: src/CMakeFiles/mysimple2dgameengine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/francisco/Projects/gameEngines/sdl/2dgameEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CMakeFiles/mysimple2dgameengine.dir/TextureMng.cpp.o"
	cd /home/francisco/Projects/gameEngines/sdl/2dgameEngine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/mysimple2dgameengine.dir/TextureMng.cpp.o -MF CMakeFiles/mysimple2dgameengine.dir/TextureMng.cpp.o.d -o CMakeFiles/mysimple2dgameengine.dir/TextureMng.cpp.o -c /home/francisco/Projects/gameEngines/sdl/2dgameEngine/src/TextureMng.cpp

src/CMakeFiles/mysimple2dgameengine.dir/TextureMng.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mysimple2dgameengine.dir/TextureMng.cpp.i"
	cd /home/francisco/Projects/gameEngines/sdl/2dgameEngine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/francisco/Projects/gameEngines/sdl/2dgameEngine/src/TextureMng.cpp > CMakeFiles/mysimple2dgameengine.dir/TextureMng.cpp.i

src/CMakeFiles/mysimple2dgameengine.dir/TextureMng.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mysimple2dgameengine.dir/TextureMng.cpp.s"
	cd /home/francisco/Projects/gameEngines/sdl/2dgameEngine/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/francisco/Projects/gameEngines/sdl/2dgameEngine/src/TextureMng.cpp -o CMakeFiles/mysimple2dgameengine.dir/TextureMng.cpp.s

# Object files for target mysimple2dgameengine
mysimple2dgameengine_OBJECTS = \
"CMakeFiles/mysimple2dgameengine.dir/AssetMng.cpp.o" \
"CMakeFiles/mysimple2dgameengine.dir/Entity.cpp.o" \
"CMakeFiles/mysimple2dgameengine.dir/EntityMng.cpp.o" \
"CMakeFiles/mysimple2dgameengine.dir/Game.cpp.o" \
"CMakeFiles/mysimple2dgameengine.dir/TextureMng.cpp.o"

# External object files for target mysimple2dgameengine
mysimple2dgameengine_EXTERNAL_OBJECTS =

src/libmysimple2dgameengine.a: src/CMakeFiles/mysimple2dgameengine.dir/AssetMng.cpp.o
src/libmysimple2dgameengine.a: src/CMakeFiles/mysimple2dgameengine.dir/Entity.cpp.o
src/libmysimple2dgameengine.a: src/CMakeFiles/mysimple2dgameengine.dir/EntityMng.cpp.o
src/libmysimple2dgameengine.a: src/CMakeFiles/mysimple2dgameengine.dir/Game.cpp.o
src/libmysimple2dgameengine.a: src/CMakeFiles/mysimple2dgameengine.dir/TextureMng.cpp.o
src/libmysimple2dgameengine.a: src/CMakeFiles/mysimple2dgameengine.dir/build.make
src/libmysimple2dgameengine.a: src/CMakeFiles/mysimple2dgameengine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/francisco/Projects/gameEngines/sdl/2dgameEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX static library libmysimple2dgameengine.a"
	cd /home/francisco/Projects/gameEngines/sdl/2dgameEngine/build/src && $(CMAKE_COMMAND) -P CMakeFiles/mysimple2dgameengine.dir/cmake_clean_target.cmake
	cd /home/francisco/Projects/gameEngines/sdl/2dgameEngine/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mysimple2dgameengine.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/mysimple2dgameengine.dir/build: src/libmysimple2dgameengine.a
.PHONY : src/CMakeFiles/mysimple2dgameengine.dir/build

src/CMakeFiles/mysimple2dgameengine.dir/clean:
	cd /home/francisco/Projects/gameEngines/sdl/2dgameEngine/build/src && $(CMAKE_COMMAND) -P CMakeFiles/mysimple2dgameengine.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/mysimple2dgameengine.dir/clean

src/CMakeFiles/mysimple2dgameengine.dir/depend:
	cd /home/francisco/Projects/gameEngines/sdl/2dgameEngine/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/francisco/Projects/gameEngines/sdl/2dgameEngine /home/francisco/Projects/gameEngines/sdl/2dgameEngine/src /home/francisco/Projects/gameEngines/sdl/2dgameEngine/build /home/francisco/Projects/gameEngines/sdl/2dgameEngine/build/src /home/francisco/Projects/gameEngines/sdl/2dgameEngine/build/src/CMakeFiles/mysimple2dgameengine.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/mysimple2dgameengine.dir/depend

