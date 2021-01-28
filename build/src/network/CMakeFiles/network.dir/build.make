# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_SOURCE_DIR = /root/dev/networkcmake

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/dev/networkcmake/build

# Include any dependencies generated for this target.
include src/network/CMakeFiles/network.dir/depend.make

# Include the progress variables for this target.
include src/network/CMakeFiles/network.dir/progress.make

# Include the compile flags for this target's objects.
include src/network/CMakeFiles/network.dir/flags.make

src/network/CMakeFiles/network.dir/Address.cpp.o: src/network/CMakeFiles/network.dir/flags.make
src/network/CMakeFiles/network.dir/Address.cpp.o: ../src/network/Address.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/dev/networkcmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/network/CMakeFiles/network.dir/Address.cpp.o"
	cd /root/dev/networkcmake/build/src/network && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/network.dir/Address.cpp.o -c /root/dev/networkcmake/src/network/Address.cpp

src/network/CMakeFiles/network.dir/Address.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/network.dir/Address.cpp.i"
	cd /root/dev/networkcmake/build/src/network && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/dev/networkcmake/src/network/Address.cpp > CMakeFiles/network.dir/Address.cpp.i

src/network/CMakeFiles/network.dir/Address.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/network.dir/Address.cpp.s"
	cd /root/dev/networkcmake/build/src/network && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/dev/networkcmake/src/network/Address.cpp -o CMakeFiles/network.dir/Address.cpp.s

src/network/CMakeFiles/network.dir/Client.cpp.o: src/network/CMakeFiles/network.dir/flags.make
src/network/CMakeFiles/network.dir/Client.cpp.o: ../src/network/Client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/dev/networkcmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/network/CMakeFiles/network.dir/Client.cpp.o"
	cd /root/dev/networkcmake/build/src/network && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/network.dir/Client.cpp.o -c /root/dev/networkcmake/src/network/Client.cpp

src/network/CMakeFiles/network.dir/Client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/network.dir/Client.cpp.i"
	cd /root/dev/networkcmake/build/src/network && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/dev/networkcmake/src/network/Client.cpp > CMakeFiles/network.dir/Client.cpp.i

src/network/CMakeFiles/network.dir/Client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/network.dir/Client.cpp.s"
	cd /root/dev/networkcmake/build/src/network && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/dev/networkcmake/src/network/Client.cpp -o CMakeFiles/network.dir/Client.cpp.s

src/network/CMakeFiles/network.dir/Network.cpp.o: src/network/CMakeFiles/network.dir/flags.make
src/network/CMakeFiles/network.dir/Network.cpp.o: ../src/network/Network.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/dev/networkcmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/network/CMakeFiles/network.dir/Network.cpp.o"
	cd /root/dev/networkcmake/build/src/network && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/network.dir/Network.cpp.o -c /root/dev/networkcmake/src/network/Network.cpp

src/network/CMakeFiles/network.dir/Network.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/network.dir/Network.cpp.i"
	cd /root/dev/networkcmake/build/src/network && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/dev/networkcmake/src/network/Network.cpp > CMakeFiles/network.dir/Network.cpp.i

src/network/CMakeFiles/network.dir/Network.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/network.dir/Network.cpp.s"
	cd /root/dev/networkcmake/build/src/network && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/dev/networkcmake/src/network/Network.cpp -o CMakeFiles/network.dir/Network.cpp.s

src/network/CMakeFiles/network.dir/NetworkHandler.cpp.o: src/network/CMakeFiles/network.dir/flags.make
src/network/CMakeFiles/network.dir/NetworkHandler.cpp.o: ../src/network/NetworkHandler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/dev/networkcmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/network/CMakeFiles/network.dir/NetworkHandler.cpp.o"
	cd /root/dev/networkcmake/build/src/network && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/network.dir/NetworkHandler.cpp.o -c /root/dev/networkcmake/src/network/NetworkHandler.cpp

src/network/CMakeFiles/network.dir/NetworkHandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/network.dir/NetworkHandler.cpp.i"
	cd /root/dev/networkcmake/build/src/network && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/dev/networkcmake/src/network/NetworkHandler.cpp > CMakeFiles/network.dir/NetworkHandler.cpp.i

src/network/CMakeFiles/network.dir/NetworkHandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/network.dir/NetworkHandler.cpp.s"
	cd /root/dev/networkcmake/build/src/network && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/dev/networkcmake/src/network/NetworkHandler.cpp -o CMakeFiles/network.dir/NetworkHandler.cpp.s

src/network/CMakeFiles/network.dir/Packet.cpp.o: src/network/CMakeFiles/network.dir/flags.make
src/network/CMakeFiles/network.dir/Packet.cpp.o: ../src/network/Packet.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/dev/networkcmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/network/CMakeFiles/network.dir/Packet.cpp.o"
	cd /root/dev/networkcmake/build/src/network && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/network.dir/Packet.cpp.o -c /root/dev/networkcmake/src/network/Packet.cpp

src/network/CMakeFiles/network.dir/Packet.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/network.dir/Packet.cpp.i"
	cd /root/dev/networkcmake/build/src/network && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/dev/networkcmake/src/network/Packet.cpp > CMakeFiles/network.dir/Packet.cpp.i

src/network/CMakeFiles/network.dir/Packet.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/network.dir/Packet.cpp.s"
	cd /root/dev/networkcmake/build/src/network && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/dev/networkcmake/src/network/Packet.cpp -o CMakeFiles/network.dir/Packet.cpp.s

src/network/CMakeFiles/network.dir/Peer.cpp.o: src/network/CMakeFiles/network.dir/flags.make
src/network/CMakeFiles/network.dir/Peer.cpp.o: ../src/network/Peer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/dev/networkcmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/network/CMakeFiles/network.dir/Peer.cpp.o"
	cd /root/dev/networkcmake/build/src/network && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/network.dir/Peer.cpp.o -c /root/dev/networkcmake/src/network/Peer.cpp

src/network/CMakeFiles/network.dir/Peer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/network.dir/Peer.cpp.i"
	cd /root/dev/networkcmake/build/src/network && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/dev/networkcmake/src/network/Peer.cpp > CMakeFiles/network.dir/Peer.cpp.i

src/network/CMakeFiles/network.dir/Peer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/network.dir/Peer.cpp.s"
	cd /root/dev/networkcmake/build/src/network && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/dev/networkcmake/src/network/Peer.cpp -o CMakeFiles/network.dir/Peer.cpp.s

src/network/CMakeFiles/network.dir/PeerManager.cpp.o: src/network/CMakeFiles/network.dir/flags.make
src/network/CMakeFiles/network.dir/PeerManager.cpp.o: ../src/network/PeerManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/dev/networkcmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object src/network/CMakeFiles/network.dir/PeerManager.cpp.o"
	cd /root/dev/networkcmake/build/src/network && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/network.dir/PeerManager.cpp.o -c /root/dev/networkcmake/src/network/PeerManager.cpp

src/network/CMakeFiles/network.dir/PeerManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/network.dir/PeerManager.cpp.i"
	cd /root/dev/networkcmake/build/src/network && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/dev/networkcmake/src/network/PeerManager.cpp > CMakeFiles/network.dir/PeerManager.cpp.i

src/network/CMakeFiles/network.dir/PeerManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/network.dir/PeerManager.cpp.s"
	cd /root/dev/networkcmake/build/src/network && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/dev/networkcmake/src/network/PeerManager.cpp -o CMakeFiles/network.dir/PeerManager.cpp.s

src/network/CMakeFiles/network.dir/Server.cpp.o: src/network/CMakeFiles/network.dir/flags.make
src/network/CMakeFiles/network.dir/Server.cpp.o: ../src/network/Server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/dev/networkcmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object src/network/CMakeFiles/network.dir/Server.cpp.o"
	cd /root/dev/networkcmake/build/src/network && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/network.dir/Server.cpp.o -c /root/dev/networkcmake/src/network/Server.cpp

src/network/CMakeFiles/network.dir/Server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/network.dir/Server.cpp.i"
	cd /root/dev/networkcmake/build/src/network && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/dev/networkcmake/src/network/Server.cpp > CMakeFiles/network.dir/Server.cpp.i

src/network/CMakeFiles/network.dir/Server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/network.dir/Server.cpp.s"
	cd /root/dev/networkcmake/build/src/network && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/dev/networkcmake/src/network/Server.cpp -o CMakeFiles/network.dir/Server.cpp.s

# Object files for target network
network_OBJECTS = \
"CMakeFiles/network.dir/Address.cpp.o" \
"CMakeFiles/network.dir/Client.cpp.o" \
"CMakeFiles/network.dir/Network.cpp.o" \
"CMakeFiles/network.dir/NetworkHandler.cpp.o" \
"CMakeFiles/network.dir/Packet.cpp.o" \
"CMakeFiles/network.dir/Peer.cpp.o" \
"CMakeFiles/network.dir/PeerManager.cpp.o" \
"CMakeFiles/network.dir/Server.cpp.o"

# External object files for target network
network_EXTERNAL_OBJECTS =

src/network/libnetwork.a: src/network/CMakeFiles/network.dir/Address.cpp.o
src/network/libnetwork.a: src/network/CMakeFiles/network.dir/Client.cpp.o
src/network/libnetwork.a: src/network/CMakeFiles/network.dir/Network.cpp.o
src/network/libnetwork.a: src/network/CMakeFiles/network.dir/NetworkHandler.cpp.o
src/network/libnetwork.a: src/network/CMakeFiles/network.dir/Packet.cpp.o
src/network/libnetwork.a: src/network/CMakeFiles/network.dir/Peer.cpp.o
src/network/libnetwork.a: src/network/CMakeFiles/network.dir/PeerManager.cpp.o
src/network/libnetwork.a: src/network/CMakeFiles/network.dir/Server.cpp.o
src/network/libnetwork.a: src/network/CMakeFiles/network.dir/build.make
src/network/libnetwork.a: src/network/CMakeFiles/network.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/dev/networkcmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX static library libnetwork.a"
	cd /root/dev/networkcmake/build/src/network && $(CMAKE_COMMAND) -P CMakeFiles/network.dir/cmake_clean_target.cmake
	cd /root/dev/networkcmake/build/src/network && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/network.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/network/CMakeFiles/network.dir/build: src/network/libnetwork.a

.PHONY : src/network/CMakeFiles/network.dir/build

src/network/CMakeFiles/network.dir/clean:
	cd /root/dev/networkcmake/build/src/network && $(CMAKE_COMMAND) -P CMakeFiles/network.dir/cmake_clean.cmake
.PHONY : src/network/CMakeFiles/network.dir/clean

src/network/CMakeFiles/network.dir/depend:
	cd /root/dev/networkcmake/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/dev/networkcmake /root/dev/networkcmake/src/network /root/dev/networkcmake/build /root/dev/networkcmake/build/src/network /root/dev/networkcmake/build/src/network/CMakeFiles/network.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/network/CMakeFiles/network.dir/depend
