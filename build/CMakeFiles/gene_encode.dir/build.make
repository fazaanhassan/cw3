# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/user/Documents/cw3/cw3-cs0019-bit-lzw-fazaanhassan

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/user/Documents/cw3/cw3-cs0019-bit-lzw-fazaanhassan/build

# Include any dependencies generated for this target.
include CMakeFiles/gene_encode.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/gene_encode.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/gene_encode.dir/flags.make

CMakeFiles/gene_encode.dir/src/comp0019lib.c.o: CMakeFiles/gene_encode.dir/flags.make
CMakeFiles/gene_encode.dir/src/comp0019lib.c.o: ../src/comp0019lib.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/Documents/cw3/cw3-cs0019-bit-lzw-fazaanhassan/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/gene_encode.dir/src/comp0019lib.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/gene_encode.dir/src/comp0019lib.c.o   -c /home/user/Documents/cw3/cw3-cs0019-bit-lzw-fazaanhassan/src/comp0019lib.c

CMakeFiles/gene_encode.dir/src/comp0019lib.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gene_encode.dir/src/comp0019lib.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/user/Documents/cw3/cw3-cs0019-bit-lzw-fazaanhassan/src/comp0019lib.c > CMakeFiles/gene_encode.dir/src/comp0019lib.c.i

CMakeFiles/gene_encode.dir/src/comp0019lib.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gene_encode.dir/src/comp0019lib.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/user/Documents/cw3/cw3-cs0019-bit-lzw-fazaanhassan/src/comp0019lib.c -o CMakeFiles/gene_encode.dir/src/comp0019lib.c.s

CMakeFiles/gene_encode.dir/src/comp0019lib.c.o.requires:

.PHONY : CMakeFiles/gene_encode.dir/src/comp0019lib.c.o.requires

CMakeFiles/gene_encode.dir/src/comp0019lib.c.o.provides: CMakeFiles/gene_encode.dir/src/comp0019lib.c.o.requires
	$(MAKE) -f CMakeFiles/gene_encode.dir/build.make CMakeFiles/gene_encode.dir/src/comp0019lib.c.o.provides.build
.PHONY : CMakeFiles/gene_encode.dir/src/comp0019lib.c.o.provides

CMakeFiles/gene_encode.dir/src/comp0019lib.c.o.provides.build: CMakeFiles/gene_encode.dir/src/comp0019lib.c.o


CMakeFiles/gene_encode.dir/src/comp0019.c.o: CMakeFiles/gene_encode.dir/flags.make
CMakeFiles/gene_encode.dir/src/comp0019.c.o: ../src/comp0019.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/Documents/cw3/cw3-cs0019-bit-lzw-fazaanhassan/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/gene_encode.dir/src/comp0019.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/gene_encode.dir/src/comp0019.c.o   -c /home/user/Documents/cw3/cw3-cs0019-bit-lzw-fazaanhassan/src/comp0019.c

CMakeFiles/gene_encode.dir/src/comp0019.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gene_encode.dir/src/comp0019.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/user/Documents/cw3/cw3-cs0019-bit-lzw-fazaanhassan/src/comp0019.c > CMakeFiles/gene_encode.dir/src/comp0019.c.i

CMakeFiles/gene_encode.dir/src/comp0019.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gene_encode.dir/src/comp0019.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/user/Documents/cw3/cw3-cs0019-bit-lzw-fazaanhassan/src/comp0019.c -o CMakeFiles/gene_encode.dir/src/comp0019.c.s

CMakeFiles/gene_encode.dir/src/comp0019.c.o.requires:

.PHONY : CMakeFiles/gene_encode.dir/src/comp0019.c.o.requires

CMakeFiles/gene_encode.dir/src/comp0019.c.o.provides: CMakeFiles/gene_encode.dir/src/comp0019.c.o.requires
	$(MAKE) -f CMakeFiles/gene_encode.dir/build.make CMakeFiles/gene_encode.dir/src/comp0019.c.o.provides.build
.PHONY : CMakeFiles/gene_encode.dir/src/comp0019.c.o.provides

CMakeFiles/gene_encode.dir/src/comp0019.c.o.provides.build: CMakeFiles/gene_encode.dir/src/comp0019.c.o


CMakeFiles/gene_encode.dir/src/decomp0019.c.o: CMakeFiles/gene_encode.dir/flags.make
CMakeFiles/gene_encode.dir/src/decomp0019.c.o: ../src/decomp0019.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/Documents/cw3/cw3-cs0019-bit-lzw-fazaanhassan/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/gene_encode.dir/src/decomp0019.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/gene_encode.dir/src/decomp0019.c.o   -c /home/user/Documents/cw3/cw3-cs0019-bit-lzw-fazaanhassan/src/decomp0019.c

CMakeFiles/gene_encode.dir/src/decomp0019.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gene_encode.dir/src/decomp0019.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/user/Documents/cw3/cw3-cs0019-bit-lzw-fazaanhassan/src/decomp0019.c > CMakeFiles/gene_encode.dir/src/decomp0019.c.i

CMakeFiles/gene_encode.dir/src/decomp0019.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gene_encode.dir/src/decomp0019.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/user/Documents/cw3/cw3-cs0019-bit-lzw-fazaanhassan/src/decomp0019.c -o CMakeFiles/gene_encode.dir/src/decomp0019.c.s

CMakeFiles/gene_encode.dir/src/decomp0019.c.o.requires:

.PHONY : CMakeFiles/gene_encode.dir/src/decomp0019.c.o.requires

CMakeFiles/gene_encode.dir/src/decomp0019.c.o.provides: CMakeFiles/gene_encode.dir/src/decomp0019.c.o.requires
	$(MAKE) -f CMakeFiles/gene_encode.dir/build.make CMakeFiles/gene_encode.dir/src/decomp0019.c.o.provides.build
.PHONY : CMakeFiles/gene_encode.dir/src/decomp0019.c.o.provides

CMakeFiles/gene_encode.dir/src/decomp0019.c.o.provides.build: CMakeFiles/gene_encode.dir/src/decomp0019.c.o


# Object files for target gene_encode
gene_encode_OBJECTS = \
"CMakeFiles/gene_encode.dir/src/comp0019lib.c.o" \
"CMakeFiles/gene_encode.dir/src/comp0019.c.o" \
"CMakeFiles/gene_encode.dir/src/decomp0019.c.o"

# External object files for target gene_encode
gene_encode_EXTERNAL_OBJECTS =

libgene_encode.a: CMakeFiles/gene_encode.dir/src/comp0019lib.c.o
libgene_encode.a: CMakeFiles/gene_encode.dir/src/comp0019.c.o
libgene_encode.a: CMakeFiles/gene_encode.dir/src/decomp0019.c.o
libgene_encode.a: CMakeFiles/gene_encode.dir/build.make
libgene_encode.a: CMakeFiles/gene_encode.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/user/Documents/cw3/cw3-cs0019-bit-lzw-fazaanhassan/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C static library libgene_encode.a"
	$(CMAKE_COMMAND) -P CMakeFiles/gene_encode.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gene_encode.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/gene_encode.dir/build: libgene_encode.a

.PHONY : CMakeFiles/gene_encode.dir/build

CMakeFiles/gene_encode.dir/requires: CMakeFiles/gene_encode.dir/src/comp0019lib.c.o.requires
CMakeFiles/gene_encode.dir/requires: CMakeFiles/gene_encode.dir/src/comp0019.c.o.requires
CMakeFiles/gene_encode.dir/requires: CMakeFiles/gene_encode.dir/src/decomp0019.c.o.requires

.PHONY : CMakeFiles/gene_encode.dir/requires

CMakeFiles/gene_encode.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/gene_encode.dir/cmake_clean.cmake
.PHONY : CMakeFiles/gene_encode.dir/clean

CMakeFiles/gene_encode.dir/depend:
	cd /home/user/Documents/cw3/cw3-cs0019-bit-lzw-fazaanhassan/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/user/Documents/cw3/cw3-cs0019-bit-lzw-fazaanhassan /home/user/Documents/cw3/cw3-cs0019-bit-lzw-fazaanhassan /home/user/Documents/cw3/cw3-cs0019-bit-lzw-fazaanhassan/build /home/user/Documents/cw3/cw3-cs0019-bit-lzw-fazaanhassan/build /home/user/Documents/cw3/cw3-cs0019-bit-lzw-fazaanhassan/build/CMakeFiles/gene_encode.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/gene_encode.dir/depend

