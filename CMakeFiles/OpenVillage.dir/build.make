# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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
CMAKE_SOURCE_DIR = /home/mrremrem/CLionProjects/OpenVillage

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mrremrem/CLionProjects/OpenVillage

# Include any dependencies generated for this target.
include CMakeFiles/OpenVillage.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/OpenVillage.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/OpenVillage.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/OpenVillage.dir/flags.make

CMakeFiles/OpenVillage.dir/main.cpp.o: CMakeFiles/OpenVillage.dir/flags.make
CMakeFiles/OpenVillage.dir/main.cpp.o: main.cpp
CMakeFiles/OpenVillage.dir/main.cpp.o: CMakeFiles/OpenVillage.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mrremrem/CLionProjects/OpenVillage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/OpenVillage.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OpenVillage.dir/main.cpp.o -MF CMakeFiles/OpenVillage.dir/main.cpp.o.d -o CMakeFiles/OpenVillage.dir/main.cpp.o -c /home/mrremrem/CLionProjects/OpenVillage/main.cpp

CMakeFiles/OpenVillage.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenVillage.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mrremrem/CLionProjects/OpenVillage/main.cpp > CMakeFiles/OpenVillage.dir/main.cpp.i

CMakeFiles/OpenVillage.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenVillage.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mrremrem/CLionProjects/OpenVillage/main.cpp -o CMakeFiles/OpenVillage.dir/main.cpp.s

CMakeFiles/OpenVillage.dir/Player.cpp.o: CMakeFiles/OpenVillage.dir/flags.make
CMakeFiles/OpenVillage.dir/Player.cpp.o: Player.cpp
CMakeFiles/OpenVillage.dir/Player.cpp.o: CMakeFiles/OpenVillage.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mrremrem/CLionProjects/OpenVillage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/OpenVillage.dir/Player.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OpenVillage.dir/Player.cpp.o -MF CMakeFiles/OpenVillage.dir/Player.cpp.o.d -o CMakeFiles/OpenVillage.dir/Player.cpp.o -c /home/mrremrem/CLionProjects/OpenVillage/Player.cpp

CMakeFiles/OpenVillage.dir/Player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenVillage.dir/Player.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mrremrem/CLionProjects/OpenVillage/Player.cpp > CMakeFiles/OpenVillage.dir/Player.cpp.i

CMakeFiles/OpenVillage.dir/Player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenVillage.dir/Player.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mrremrem/CLionProjects/OpenVillage/Player.cpp -o CMakeFiles/OpenVillage.dir/Player.cpp.s

CMakeFiles/OpenVillage.dir/WindowManager.cpp.o: CMakeFiles/OpenVillage.dir/flags.make
CMakeFiles/OpenVillage.dir/WindowManager.cpp.o: WindowManager.cpp
CMakeFiles/OpenVillage.dir/WindowManager.cpp.o: CMakeFiles/OpenVillage.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mrremrem/CLionProjects/OpenVillage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/OpenVillage.dir/WindowManager.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OpenVillage.dir/WindowManager.cpp.o -MF CMakeFiles/OpenVillage.dir/WindowManager.cpp.o.d -o CMakeFiles/OpenVillage.dir/WindowManager.cpp.o -c /home/mrremrem/CLionProjects/OpenVillage/WindowManager.cpp

CMakeFiles/OpenVillage.dir/WindowManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenVillage.dir/WindowManager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mrremrem/CLionProjects/OpenVillage/WindowManager.cpp > CMakeFiles/OpenVillage.dir/WindowManager.cpp.i

CMakeFiles/OpenVillage.dir/WindowManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenVillage.dir/WindowManager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mrremrem/CLionProjects/OpenVillage/WindowManager.cpp -o CMakeFiles/OpenVillage.dir/WindowManager.cpp.s

CMakeFiles/OpenVillage.dir/SpriteSheet.cpp.o: CMakeFiles/OpenVillage.dir/flags.make
CMakeFiles/OpenVillage.dir/SpriteSheet.cpp.o: SpriteSheet.cpp
CMakeFiles/OpenVillage.dir/SpriteSheet.cpp.o: CMakeFiles/OpenVillage.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mrremrem/CLionProjects/OpenVillage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/OpenVillage.dir/SpriteSheet.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OpenVillage.dir/SpriteSheet.cpp.o -MF CMakeFiles/OpenVillage.dir/SpriteSheet.cpp.o.d -o CMakeFiles/OpenVillage.dir/SpriteSheet.cpp.o -c /home/mrremrem/CLionProjects/OpenVillage/SpriteSheet.cpp

CMakeFiles/OpenVillage.dir/SpriteSheet.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenVillage.dir/SpriteSheet.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mrremrem/CLionProjects/OpenVillage/SpriteSheet.cpp > CMakeFiles/OpenVillage.dir/SpriteSheet.cpp.i

CMakeFiles/OpenVillage.dir/SpriteSheet.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenVillage.dir/SpriteSheet.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mrremrem/CLionProjects/OpenVillage/SpriteSheet.cpp -o CMakeFiles/OpenVillage.dir/SpriteSheet.cpp.s

CMakeFiles/OpenVillage.dir/Animation.cpp.o: CMakeFiles/OpenVillage.dir/flags.make
CMakeFiles/OpenVillage.dir/Animation.cpp.o: Animation.cpp
CMakeFiles/OpenVillage.dir/Animation.cpp.o: CMakeFiles/OpenVillage.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mrremrem/CLionProjects/OpenVillage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/OpenVillage.dir/Animation.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OpenVillage.dir/Animation.cpp.o -MF CMakeFiles/OpenVillage.dir/Animation.cpp.o.d -o CMakeFiles/OpenVillage.dir/Animation.cpp.o -c /home/mrremrem/CLionProjects/OpenVillage/Animation.cpp

CMakeFiles/OpenVillage.dir/Animation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenVillage.dir/Animation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mrremrem/CLionProjects/OpenVillage/Animation.cpp > CMakeFiles/OpenVillage.dir/Animation.cpp.i

CMakeFiles/OpenVillage.dir/Animation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenVillage.dir/Animation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mrremrem/CLionProjects/OpenVillage/Animation.cpp -o CMakeFiles/OpenVillage.dir/Animation.cpp.s

CMakeFiles/OpenVillage.dir/Map.cpp.o: CMakeFiles/OpenVillage.dir/flags.make
CMakeFiles/OpenVillage.dir/Map.cpp.o: Map.cpp
CMakeFiles/OpenVillage.dir/Map.cpp.o: CMakeFiles/OpenVillage.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mrremrem/CLionProjects/OpenVillage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/OpenVillage.dir/Map.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OpenVillage.dir/Map.cpp.o -MF CMakeFiles/OpenVillage.dir/Map.cpp.o.d -o CMakeFiles/OpenVillage.dir/Map.cpp.o -c /home/mrremrem/CLionProjects/OpenVillage/Map.cpp

CMakeFiles/OpenVillage.dir/Map.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenVillage.dir/Map.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mrremrem/CLionProjects/OpenVillage/Map.cpp > CMakeFiles/OpenVillage.dir/Map.cpp.i

CMakeFiles/OpenVillage.dir/Map.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenVillage.dir/Map.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mrremrem/CLionProjects/OpenVillage/Map.cpp -o CMakeFiles/OpenVillage.dir/Map.cpp.s

CMakeFiles/OpenVillage.dir/Tile.cpp.o: CMakeFiles/OpenVillage.dir/flags.make
CMakeFiles/OpenVillage.dir/Tile.cpp.o: Tile.cpp
CMakeFiles/OpenVillage.dir/Tile.cpp.o: CMakeFiles/OpenVillage.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mrremrem/CLionProjects/OpenVillage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/OpenVillage.dir/Tile.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OpenVillage.dir/Tile.cpp.o -MF CMakeFiles/OpenVillage.dir/Tile.cpp.o.d -o CMakeFiles/OpenVillage.dir/Tile.cpp.o -c /home/mrremrem/CLionProjects/OpenVillage/Tile.cpp

CMakeFiles/OpenVillage.dir/Tile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenVillage.dir/Tile.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mrremrem/CLionProjects/OpenVillage/Tile.cpp > CMakeFiles/OpenVillage.dir/Tile.cpp.i

CMakeFiles/OpenVillage.dir/Tile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenVillage.dir/Tile.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mrremrem/CLionProjects/OpenVillage/Tile.cpp -o CMakeFiles/OpenVillage.dir/Tile.cpp.s

CMakeFiles/OpenVillage.dir/TileManager.cpp.o: CMakeFiles/OpenVillage.dir/flags.make
CMakeFiles/OpenVillage.dir/TileManager.cpp.o: TileManager.cpp
CMakeFiles/OpenVillage.dir/TileManager.cpp.o: CMakeFiles/OpenVillage.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mrremrem/CLionProjects/OpenVillage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/OpenVillage.dir/TileManager.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OpenVillage.dir/TileManager.cpp.o -MF CMakeFiles/OpenVillage.dir/TileManager.cpp.o.d -o CMakeFiles/OpenVillage.dir/TileManager.cpp.o -c /home/mrremrem/CLionProjects/OpenVillage/TileManager.cpp

CMakeFiles/OpenVillage.dir/TileManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenVillage.dir/TileManager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mrremrem/CLionProjects/OpenVillage/TileManager.cpp > CMakeFiles/OpenVillage.dir/TileManager.cpp.i

CMakeFiles/OpenVillage.dir/TileManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenVillage.dir/TileManager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mrremrem/CLionProjects/OpenVillage/TileManager.cpp -o CMakeFiles/OpenVillage.dir/TileManager.cpp.s

CMakeFiles/OpenVillage.dir/GameManager.cpp.o: CMakeFiles/OpenVillage.dir/flags.make
CMakeFiles/OpenVillage.dir/GameManager.cpp.o: GameManager.cpp
CMakeFiles/OpenVillage.dir/GameManager.cpp.o: CMakeFiles/OpenVillage.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mrremrem/CLionProjects/OpenVillage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/OpenVillage.dir/GameManager.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OpenVillage.dir/GameManager.cpp.o -MF CMakeFiles/OpenVillage.dir/GameManager.cpp.o.d -o CMakeFiles/OpenVillage.dir/GameManager.cpp.o -c /home/mrremrem/CLionProjects/OpenVillage/GameManager.cpp

CMakeFiles/OpenVillage.dir/GameManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenVillage.dir/GameManager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mrremrem/CLionProjects/OpenVillage/GameManager.cpp > CMakeFiles/OpenVillage.dir/GameManager.cpp.i

CMakeFiles/OpenVillage.dir/GameManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenVillage.dir/GameManager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mrremrem/CLionProjects/OpenVillage/GameManager.cpp -o CMakeFiles/OpenVillage.dir/GameManager.cpp.s

CMakeFiles/OpenVillage.dir/HomeVillage.cpp.o: CMakeFiles/OpenVillage.dir/flags.make
CMakeFiles/OpenVillage.dir/HomeVillage.cpp.o: HomeVillage.cpp
CMakeFiles/OpenVillage.dir/HomeVillage.cpp.o: CMakeFiles/OpenVillage.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mrremrem/CLionProjects/OpenVillage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/OpenVillage.dir/HomeVillage.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OpenVillage.dir/HomeVillage.cpp.o -MF CMakeFiles/OpenVillage.dir/HomeVillage.cpp.o.d -o CMakeFiles/OpenVillage.dir/HomeVillage.cpp.o -c /home/mrremrem/CLionProjects/OpenVillage/HomeVillage.cpp

CMakeFiles/OpenVillage.dir/HomeVillage.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenVillage.dir/HomeVillage.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mrremrem/CLionProjects/OpenVillage/HomeVillage.cpp > CMakeFiles/OpenVillage.dir/HomeVillage.cpp.i

CMakeFiles/OpenVillage.dir/HomeVillage.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenVillage.dir/HomeVillage.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mrremrem/CLionProjects/OpenVillage/HomeVillage.cpp -o CMakeFiles/OpenVillage.dir/HomeVillage.cpp.s

CMakeFiles/OpenVillage.dir/DebugLog.cpp.o: CMakeFiles/OpenVillage.dir/flags.make
CMakeFiles/OpenVillage.dir/DebugLog.cpp.o: DebugLog.cpp
CMakeFiles/OpenVillage.dir/DebugLog.cpp.o: CMakeFiles/OpenVillage.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mrremrem/CLionProjects/OpenVillage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/OpenVillage.dir/DebugLog.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OpenVillage.dir/DebugLog.cpp.o -MF CMakeFiles/OpenVillage.dir/DebugLog.cpp.o.d -o CMakeFiles/OpenVillage.dir/DebugLog.cpp.o -c /home/mrremrem/CLionProjects/OpenVillage/DebugLog.cpp

CMakeFiles/OpenVillage.dir/DebugLog.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenVillage.dir/DebugLog.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mrremrem/CLionProjects/OpenVillage/DebugLog.cpp > CMakeFiles/OpenVillage.dir/DebugLog.cpp.i

CMakeFiles/OpenVillage.dir/DebugLog.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenVillage.dir/DebugLog.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mrremrem/CLionProjects/OpenVillage/DebugLog.cpp -o CMakeFiles/OpenVillage.dir/DebugLog.cpp.s

CMakeFiles/OpenVillage.dir/TextBox.cpp.o: CMakeFiles/OpenVillage.dir/flags.make
CMakeFiles/OpenVillage.dir/TextBox.cpp.o: TextBox.cpp
CMakeFiles/OpenVillage.dir/TextBox.cpp.o: CMakeFiles/OpenVillage.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mrremrem/CLionProjects/OpenVillage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/OpenVillage.dir/TextBox.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OpenVillage.dir/TextBox.cpp.o -MF CMakeFiles/OpenVillage.dir/TextBox.cpp.o.d -o CMakeFiles/OpenVillage.dir/TextBox.cpp.o -c /home/mrremrem/CLionProjects/OpenVillage/TextBox.cpp

CMakeFiles/OpenVillage.dir/TextBox.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenVillage.dir/TextBox.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mrremrem/CLionProjects/OpenVillage/TextBox.cpp > CMakeFiles/OpenVillage.dir/TextBox.cpp.i

CMakeFiles/OpenVillage.dir/TextBox.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenVillage.dir/TextBox.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mrremrem/CLionProjects/OpenVillage/TextBox.cpp -o CMakeFiles/OpenVillage.dir/TextBox.cpp.s

CMakeFiles/OpenVillage.dir/FontContainer.cpp.o: CMakeFiles/OpenVillage.dir/flags.make
CMakeFiles/OpenVillage.dir/FontContainer.cpp.o: FontContainer.cpp
CMakeFiles/OpenVillage.dir/FontContainer.cpp.o: CMakeFiles/OpenVillage.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mrremrem/CLionProjects/OpenVillage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/OpenVillage.dir/FontContainer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OpenVillage.dir/FontContainer.cpp.o -MF CMakeFiles/OpenVillage.dir/FontContainer.cpp.o.d -o CMakeFiles/OpenVillage.dir/FontContainer.cpp.o -c /home/mrremrem/CLionProjects/OpenVillage/FontContainer.cpp

CMakeFiles/OpenVillage.dir/FontContainer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenVillage.dir/FontContainer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mrremrem/CLionProjects/OpenVillage/FontContainer.cpp > CMakeFiles/OpenVillage.dir/FontContainer.cpp.i

CMakeFiles/OpenVillage.dir/FontContainer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenVillage.dir/FontContainer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mrremrem/CLionProjects/OpenVillage/FontContainer.cpp -o CMakeFiles/OpenVillage.dir/FontContainer.cpp.s

CMakeFiles/OpenVillage.dir/CollisionBox.cpp.o: CMakeFiles/OpenVillage.dir/flags.make
CMakeFiles/OpenVillage.dir/CollisionBox.cpp.o: CollisionBox.cpp
CMakeFiles/OpenVillage.dir/CollisionBox.cpp.o: CMakeFiles/OpenVillage.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mrremrem/CLionProjects/OpenVillage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/OpenVillage.dir/CollisionBox.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OpenVillage.dir/CollisionBox.cpp.o -MF CMakeFiles/OpenVillage.dir/CollisionBox.cpp.o.d -o CMakeFiles/OpenVillage.dir/CollisionBox.cpp.o -c /home/mrremrem/CLionProjects/OpenVillage/CollisionBox.cpp

CMakeFiles/OpenVillage.dir/CollisionBox.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenVillage.dir/CollisionBox.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mrremrem/CLionProjects/OpenVillage/CollisionBox.cpp > CMakeFiles/OpenVillage.dir/CollisionBox.cpp.i

CMakeFiles/OpenVillage.dir/CollisionBox.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenVillage.dir/CollisionBox.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mrremrem/CLionProjects/OpenVillage/CollisionBox.cpp -o CMakeFiles/OpenVillage.dir/CollisionBox.cpp.s

CMakeFiles/OpenVillage.dir/EntityManager.cpp.o: CMakeFiles/OpenVillage.dir/flags.make
CMakeFiles/OpenVillage.dir/EntityManager.cpp.o: EntityManager.cpp
CMakeFiles/OpenVillage.dir/EntityManager.cpp.o: CMakeFiles/OpenVillage.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mrremrem/CLionProjects/OpenVillage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/OpenVillage.dir/EntityManager.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OpenVillage.dir/EntityManager.cpp.o -MF CMakeFiles/OpenVillage.dir/EntityManager.cpp.o.d -o CMakeFiles/OpenVillage.dir/EntityManager.cpp.o -c /home/mrremrem/CLionProjects/OpenVillage/EntityManager.cpp

CMakeFiles/OpenVillage.dir/EntityManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenVillage.dir/EntityManager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mrremrem/CLionProjects/OpenVillage/EntityManager.cpp > CMakeFiles/OpenVillage.dir/EntityManager.cpp.i

CMakeFiles/OpenVillage.dir/EntityManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenVillage.dir/EntityManager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mrremrem/CLionProjects/OpenVillage/EntityManager.cpp -o CMakeFiles/OpenVillage.dir/EntityManager.cpp.s

CMakeFiles/OpenVillage.dir/Sign.cpp.o: CMakeFiles/OpenVillage.dir/flags.make
CMakeFiles/OpenVillage.dir/Sign.cpp.o: Sign.cpp
CMakeFiles/OpenVillage.dir/Sign.cpp.o: CMakeFiles/OpenVillage.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mrremrem/CLionProjects/OpenVillage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/OpenVillage.dir/Sign.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OpenVillage.dir/Sign.cpp.o -MF CMakeFiles/OpenVillage.dir/Sign.cpp.o.d -o CMakeFiles/OpenVillage.dir/Sign.cpp.o -c /home/mrremrem/CLionProjects/OpenVillage/Sign.cpp

CMakeFiles/OpenVillage.dir/Sign.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenVillage.dir/Sign.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mrremrem/CLionProjects/OpenVillage/Sign.cpp > CMakeFiles/OpenVillage.dir/Sign.cpp.i

CMakeFiles/OpenVillage.dir/Sign.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenVillage.dir/Sign.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mrremrem/CLionProjects/OpenVillage/Sign.cpp -o CMakeFiles/OpenVillage.dir/Sign.cpp.s

CMakeFiles/OpenVillage.dir/Entity.cpp.o: CMakeFiles/OpenVillage.dir/flags.make
CMakeFiles/OpenVillage.dir/Entity.cpp.o: Entity.cpp
CMakeFiles/OpenVillage.dir/Entity.cpp.o: CMakeFiles/OpenVillage.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mrremrem/CLionProjects/OpenVillage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building CXX object CMakeFiles/OpenVillage.dir/Entity.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OpenVillage.dir/Entity.cpp.o -MF CMakeFiles/OpenVillage.dir/Entity.cpp.o.d -o CMakeFiles/OpenVillage.dir/Entity.cpp.o -c /home/mrremrem/CLionProjects/OpenVillage/Entity.cpp

CMakeFiles/OpenVillage.dir/Entity.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenVillage.dir/Entity.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mrremrem/CLionProjects/OpenVillage/Entity.cpp > CMakeFiles/OpenVillage.dir/Entity.cpp.i

CMakeFiles/OpenVillage.dir/Entity.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenVillage.dir/Entity.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mrremrem/CLionProjects/OpenVillage/Entity.cpp -o CMakeFiles/OpenVillage.dir/Entity.cpp.s

# Object files for target OpenVillage
OpenVillage_OBJECTS = \
"CMakeFiles/OpenVillage.dir/main.cpp.o" \
"CMakeFiles/OpenVillage.dir/Player.cpp.o" \
"CMakeFiles/OpenVillage.dir/WindowManager.cpp.o" \
"CMakeFiles/OpenVillage.dir/SpriteSheet.cpp.o" \
"CMakeFiles/OpenVillage.dir/Animation.cpp.o" \
"CMakeFiles/OpenVillage.dir/Map.cpp.o" \
"CMakeFiles/OpenVillage.dir/Tile.cpp.o" \
"CMakeFiles/OpenVillage.dir/TileManager.cpp.o" \
"CMakeFiles/OpenVillage.dir/GameManager.cpp.o" \
"CMakeFiles/OpenVillage.dir/HomeVillage.cpp.o" \
"CMakeFiles/OpenVillage.dir/DebugLog.cpp.o" \
"CMakeFiles/OpenVillage.dir/TextBox.cpp.o" \
"CMakeFiles/OpenVillage.dir/FontContainer.cpp.o" \
"CMakeFiles/OpenVillage.dir/CollisionBox.cpp.o" \
"CMakeFiles/OpenVillage.dir/EntityManager.cpp.o" \
"CMakeFiles/OpenVillage.dir/Sign.cpp.o" \
"CMakeFiles/OpenVillage.dir/Entity.cpp.o"

# External object files for target OpenVillage
OpenVillage_EXTERNAL_OBJECTS =

OpenVillage: CMakeFiles/OpenVillage.dir/main.cpp.o
OpenVillage: CMakeFiles/OpenVillage.dir/Player.cpp.o
OpenVillage: CMakeFiles/OpenVillage.dir/WindowManager.cpp.o
OpenVillage: CMakeFiles/OpenVillage.dir/SpriteSheet.cpp.o
OpenVillage: CMakeFiles/OpenVillage.dir/Animation.cpp.o
OpenVillage: CMakeFiles/OpenVillage.dir/Map.cpp.o
OpenVillage: CMakeFiles/OpenVillage.dir/Tile.cpp.o
OpenVillage: CMakeFiles/OpenVillage.dir/TileManager.cpp.o
OpenVillage: CMakeFiles/OpenVillage.dir/GameManager.cpp.o
OpenVillage: CMakeFiles/OpenVillage.dir/HomeVillage.cpp.o
OpenVillage: CMakeFiles/OpenVillage.dir/DebugLog.cpp.o
OpenVillage: CMakeFiles/OpenVillage.dir/TextBox.cpp.o
OpenVillage: CMakeFiles/OpenVillage.dir/FontContainer.cpp.o
OpenVillage: CMakeFiles/OpenVillage.dir/CollisionBox.cpp.o
OpenVillage: CMakeFiles/OpenVillage.dir/EntityManager.cpp.o
OpenVillage: CMakeFiles/OpenVillage.dir/Sign.cpp.o
OpenVillage: CMakeFiles/OpenVillage.dir/Entity.cpp.o
OpenVillage: CMakeFiles/OpenVillage.dir/build.make
OpenVillage: CMakeFiles/OpenVillage.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mrremrem/CLionProjects/OpenVillage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Linking CXX executable OpenVillage"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/OpenVillage.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/OpenVillage.dir/build: OpenVillage
.PHONY : CMakeFiles/OpenVillage.dir/build

CMakeFiles/OpenVillage.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/OpenVillage.dir/cmake_clean.cmake
.PHONY : CMakeFiles/OpenVillage.dir/clean

CMakeFiles/OpenVillage.dir/depend:
	cd /home/mrremrem/CLionProjects/OpenVillage && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mrremrem/CLionProjects/OpenVillage /home/mrremrem/CLionProjects/OpenVillage /home/mrremrem/CLionProjects/OpenVillage /home/mrremrem/CLionProjects/OpenVillage /home/mrremrem/CLionProjects/OpenVillage/CMakeFiles/OpenVillage.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/OpenVillage.dir/depend

