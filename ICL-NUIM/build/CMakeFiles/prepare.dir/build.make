# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/changfei/whelan_ws/src/EVO_ORB_SLAM3/ICL-NUIM

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/changfei/whelan_ws/src/EVO_ORB_SLAM3/ICL-NUIM/build

# Include any dependencies generated for this target.
include CMakeFiles/prepare.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/prepare.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/prepare.dir/flags.make

CMakeFiles/prepare.dir/src/prepare.cc.o: CMakeFiles/prepare.dir/flags.make
CMakeFiles/prepare.dir/src/prepare.cc.o: ../src/prepare.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/changfei/whelan_ws/src/EVO_ORB_SLAM3/ICL-NUIM/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/prepare.dir/src/prepare.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/prepare.dir/src/prepare.cc.o -c /home/changfei/whelan_ws/src/EVO_ORB_SLAM3/ICL-NUIM/src/prepare.cc

CMakeFiles/prepare.dir/src/prepare.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/prepare.dir/src/prepare.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/changfei/whelan_ws/src/EVO_ORB_SLAM3/ICL-NUIM/src/prepare.cc > CMakeFiles/prepare.dir/src/prepare.cc.i

CMakeFiles/prepare.dir/src/prepare.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/prepare.dir/src/prepare.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/changfei/whelan_ws/src/EVO_ORB_SLAM3/ICL-NUIM/src/prepare.cc -o CMakeFiles/prepare.dir/src/prepare.cc.s

CMakeFiles/prepare.dir/src/prepare.cc.o.requires:

.PHONY : CMakeFiles/prepare.dir/src/prepare.cc.o.requires

CMakeFiles/prepare.dir/src/prepare.cc.o.provides: CMakeFiles/prepare.dir/src/prepare.cc.o.requires
	$(MAKE) -f CMakeFiles/prepare.dir/build.make CMakeFiles/prepare.dir/src/prepare.cc.o.provides.build
.PHONY : CMakeFiles/prepare.dir/src/prepare.cc.o.provides

CMakeFiles/prepare.dir/src/prepare.cc.o.provides.build: CMakeFiles/prepare.dir/src/prepare.cc.o


# Object files for target prepare
prepare_OBJECTS = \
"CMakeFiles/prepare.dir/src/prepare.cc.o"

# External object files for target prepare
prepare_EXTERNAL_OBJECTS =

../prepare: CMakeFiles/prepare.dir/src/prepare.cc.o
../prepare: CMakeFiles/prepare.dir/build.make
../prepare: CMakeFiles/prepare.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/changfei/whelan_ws/src/EVO_ORB_SLAM3/ICL-NUIM/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../prepare"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/prepare.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/prepare.dir/build: ../prepare

.PHONY : CMakeFiles/prepare.dir/build

CMakeFiles/prepare.dir/requires: CMakeFiles/prepare.dir/src/prepare.cc.o.requires

.PHONY : CMakeFiles/prepare.dir/requires

CMakeFiles/prepare.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/prepare.dir/cmake_clean.cmake
.PHONY : CMakeFiles/prepare.dir/clean

CMakeFiles/prepare.dir/depend:
	cd /home/changfei/whelan_ws/src/EVO_ORB_SLAM3/ICL-NUIM/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/changfei/whelan_ws/src/EVO_ORB_SLAM3/ICL-NUIM /home/changfei/whelan_ws/src/EVO_ORB_SLAM3/ICL-NUIM /home/changfei/whelan_ws/src/EVO_ORB_SLAM3/ICL-NUIM/build /home/changfei/whelan_ws/src/EVO_ORB_SLAM3/ICL-NUIM/build /home/changfei/whelan_ws/src/EVO_ORB_SLAM3/ICL-NUIM/build/CMakeFiles/prepare.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/prepare.dir/depend

