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
CMAKE_COMMAND = /snap/clion/250/bin/cmake/linux/x64/bin/cmake

# The command to remove a file.
RM = /snap/clion/250/bin/cmake/linux/x64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/angelo/Downloads/Universidade/Algoritmo e Estrutura de Dados/Projeto_AED"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/angelo/Downloads/Universidade/Algoritmo e Estrutura de Dados/Projeto_AED/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Projeto.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Projeto.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Projeto.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Projeto.dir/flags.make

CMakeFiles/Projeto.dir/main.cpp.o: CMakeFiles/Projeto.dir/flags.make
CMakeFiles/Projeto.dir/main.cpp.o: /home/angelo/Downloads/Universidade/Algoritmo\ e\ Estrutura\ de\ Dados/Projeto_AED/main.cpp
CMakeFiles/Projeto.dir/main.cpp.o: CMakeFiles/Projeto.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/angelo/Downloads/Universidade/Algoritmo e Estrutura de Dados/Projeto_AED/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Projeto.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Projeto.dir/main.cpp.o -MF CMakeFiles/Projeto.dir/main.cpp.o.d -o CMakeFiles/Projeto.dir/main.cpp.o -c "/home/angelo/Downloads/Universidade/Algoritmo e Estrutura de Dados/Projeto_AED/main.cpp"

CMakeFiles/Projeto.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Projeto.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/angelo/Downloads/Universidade/Algoritmo e Estrutura de Dados/Projeto_AED/main.cpp" > CMakeFiles/Projeto.dir/main.cpp.i

CMakeFiles/Projeto.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Projeto.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/angelo/Downloads/Universidade/Algoritmo e Estrutura de Dados/Projeto_AED/main.cpp" -o CMakeFiles/Projeto.dir/main.cpp.s

CMakeFiles/Projeto.dir/Student.cpp.o: CMakeFiles/Projeto.dir/flags.make
CMakeFiles/Projeto.dir/Student.cpp.o: /home/angelo/Downloads/Universidade/Algoritmo\ e\ Estrutura\ de\ Dados/Projeto_AED/Student.cpp
CMakeFiles/Projeto.dir/Student.cpp.o: CMakeFiles/Projeto.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/angelo/Downloads/Universidade/Algoritmo e Estrutura de Dados/Projeto_AED/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Projeto.dir/Student.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Projeto.dir/Student.cpp.o -MF CMakeFiles/Projeto.dir/Student.cpp.o.d -o CMakeFiles/Projeto.dir/Student.cpp.o -c "/home/angelo/Downloads/Universidade/Algoritmo e Estrutura de Dados/Projeto_AED/Student.cpp"

CMakeFiles/Projeto.dir/Student.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Projeto.dir/Student.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/angelo/Downloads/Universidade/Algoritmo e Estrutura de Dados/Projeto_AED/Student.cpp" > CMakeFiles/Projeto.dir/Student.cpp.i

CMakeFiles/Projeto.dir/Student.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Projeto.dir/Student.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/angelo/Downloads/Universidade/Algoritmo e Estrutura de Dados/Projeto_AED/Student.cpp" -o CMakeFiles/Projeto.dir/Student.cpp.s

CMakeFiles/Projeto.dir/Class.cpp.o: CMakeFiles/Projeto.dir/flags.make
CMakeFiles/Projeto.dir/Class.cpp.o: /home/angelo/Downloads/Universidade/Algoritmo\ e\ Estrutura\ de\ Dados/Projeto_AED/Class.cpp
CMakeFiles/Projeto.dir/Class.cpp.o: CMakeFiles/Projeto.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/angelo/Downloads/Universidade/Algoritmo e Estrutura de Dados/Projeto_AED/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Projeto.dir/Class.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Projeto.dir/Class.cpp.o -MF CMakeFiles/Projeto.dir/Class.cpp.o.d -o CMakeFiles/Projeto.dir/Class.cpp.o -c "/home/angelo/Downloads/Universidade/Algoritmo e Estrutura de Dados/Projeto_AED/Class.cpp"

CMakeFiles/Projeto.dir/Class.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Projeto.dir/Class.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/angelo/Downloads/Universidade/Algoritmo e Estrutura de Dados/Projeto_AED/Class.cpp" > CMakeFiles/Projeto.dir/Class.cpp.i

CMakeFiles/Projeto.dir/Class.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Projeto.dir/Class.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/angelo/Downloads/Universidade/Algoritmo e Estrutura de Dados/Projeto_AED/Class.cpp" -o CMakeFiles/Projeto.dir/Class.cpp.s

CMakeFiles/Projeto.dir/LoadFIles.cpp.o: CMakeFiles/Projeto.dir/flags.make
CMakeFiles/Projeto.dir/LoadFIles.cpp.o: /home/angelo/Downloads/Universidade/Algoritmo\ e\ Estrutura\ de\ Dados/Projeto_AED/LoadFIles.cpp
CMakeFiles/Projeto.dir/LoadFIles.cpp.o: CMakeFiles/Projeto.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/angelo/Downloads/Universidade/Algoritmo e Estrutura de Dados/Projeto_AED/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Projeto.dir/LoadFIles.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Projeto.dir/LoadFIles.cpp.o -MF CMakeFiles/Projeto.dir/LoadFIles.cpp.o.d -o CMakeFiles/Projeto.dir/LoadFIles.cpp.o -c "/home/angelo/Downloads/Universidade/Algoritmo e Estrutura de Dados/Projeto_AED/LoadFIles.cpp"

CMakeFiles/Projeto.dir/LoadFIles.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Projeto.dir/LoadFIles.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/angelo/Downloads/Universidade/Algoritmo e Estrutura de Dados/Projeto_AED/LoadFIles.cpp" > CMakeFiles/Projeto.dir/LoadFIles.cpp.i

CMakeFiles/Projeto.dir/LoadFIles.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Projeto.dir/LoadFIles.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/angelo/Downloads/Universidade/Algoritmo e Estrutura de Dados/Projeto_AED/LoadFIles.cpp" -o CMakeFiles/Projeto.dir/LoadFIles.cpp.s

CMakeFiles/Projeto.dir/Schedule.cpp.o: CMakeFiles/Projeto.dir/flags.make
CMakeFiles/Projeto.dir/Schedule.cpp.o: /home/angelo/Downloads/Universidade/Algoritmo\ e\ Estrutura\ de\ Dados/Projeto_AED/Schedule.cpp
CMakeFiles/Projeto.dir/Schedule.cpp.o: CMakeFiles/Projeto.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/angelo/Downloads/Universidade/Algoritmo e Estrutura de Dados/Projeto_AED/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Projeto.dir/Schedule.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Projeto.dir/Schedule.cpp.o -MF CMakeFiles/Projeto.dir/Schedule.cpp.o.d -o CMakeFiles/Projeto.dir/Schedule.cpp.o -c "/home/angelo/Downloads/Universidade/Algoritmo e Estrutura de Dados/Projeto_AED/Schedule.cpp"

CMakeFiles/Projeto.dir/Schedule.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Projeto.dir/Schedule.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/angelo/Downloads/Universidade/Algoritmo e Estrutura de Dados/Projeto_AED/Schedule.cpp" > CMakeFiles/Projeto.dir/Schedule.cpp.i

CMakeFiles/Projeto.dir/Schedule.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Projeto.dir/Schedule.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/angelo/Downloads/Universidade/Algoritmo e Estrutura de Dados/Projeto_AED/Schedule.cpp" -o CMakeFiles/Projeto.dir/Schedule.cpp.s

CMakeFiles/Projeto.dir/UC.cpp.o: CMakeFiles/Projeto.dir/flags.make
CMakeFiles/Projeto.dir/UC.cpp.o: /home/angelo/Downloads/Universidade/Algoritmo\ e\ Estrutura\ de\ Dados/Projeto_AED/UC.cpp
CMakeFiles/Projeto.dir/UC.cpp.o: CMakeFiles/Projeto.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/angelo/Downloads/Universidade/Algoritmo e Estrutura de Dados/Projeto_AED/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Projeto.dir/UC.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Projeto.dir/UC.cpp.o -MF CMakeFiles/Projeto.dir/UC.cpp.o.d -o CMakeFiles/Projeto.dir/UC.cpp.o -c "/home/angelo/Downloads/Universidade/Algoritmo e Estrutura de Dados/Projeto_AED/UC.cpp"

CMakeFiles/Projeto.dir/UC.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Projeto.dir/UC.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/angelo/Downloads/Universidade/Algoritmo e Estrutura de Dados/Projeto_AED/UC.cpp" > CMakeFiles/Projeto.dir/UC.cpp.i

CMakeFiles/Projeto.dir/UC.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Projeto.dir/UC.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/angelo/Downloads/Universidade/Algoritmo e Estrutura de Dados/Projeto_AED/UC.cpp" -o CMakeFiles/Projeto.dir/UC.cpp.s

CMakeFiles/Projeto.dir/UI.cpp.o: CMakeFiles/Projeto.dir/flags.make
CMakeFiles/Projeto.dir/UI.cpp.o: /home/angelo/Downloads/Universidade/Algoritmo\ e\ Estrutura\ de\ Dados/Projeto_AED/UI.cpp
CMakeFiles/Projeto.dir/UI.cpp.o: CMakeFiles/Projeto.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/angelo/Downloads/Universidade/Algoritmo e Estrutura de Dados/Projeto_AED/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Projeto.dir/UI.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Projeto.dir/UI.cpp.o -MF CMakeFiles/Projeto.dir/UI.cpp.o.d -o CMakeFiles/Projeto.dir/UI.cpp.o -c "/home/angelo/Downloads/Universidade/Algoritmo e Estrutura de Dados/Projeto_AED/UI.cpp"

CMakeFiles/Projeto.dir/UI.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Projeto.dir/UI.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/angelo/Downloads/Universidade/Algoritmo e Estrutura de Dados/Projeto_AED/UI.cpp" > CMakeFiles/Projeto.dir/UI.cpp.i

CMakeFiles/Projeto.dir/UI.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Projeto.dir/UI.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/angelo/Downloads/Universidade/Algoritmo e Estrutura de Dados/Projeto_AED/UI.cpp" -o CMakeFiles/Projeto.dir/UI.cpp.s

# Object files for target Projeto
Projeto_OBJECTS = \
"CMakeFiles/Projeto.dir/main.cpp.o" \
"CMakeFiles/Projeto.dir/Student.cpp.o" \
"CMakeFiles/Projeto.dir/Class.cpp.o" \
"CMakeFiles/Projeto.dir/LoadFIles.cpp.o" \
"CMakeFiles/Projeto.dir/Schedule.cpp.o" \
"CMakeFiles/Projeto.dir/UC.cpp.o" \
"CMakeFiles/Projeto.dir/UI.cpp.o"

# External object files for target Projeto
Projeto_EXTERNAL_OBJECTS =

Projeto: CMakeFiles/Projeto.dir/main.cpp.o
Projeto: CMakeFiles/Projeto.dir/Student.cpp.o
Projeto: CMakeFiles/Projeto.dir/Class.cpp.o
Projeto: CMakeFiles/Projeto.dir/LoadFIles.cpp.o
Projeto: CMakeFiles/Projeto.dir/Schedule.cpp.o
Projeto: CMakeFiles/Projeto.dir/UC.cpp.o
Projeto: CMakeFiles/Projeto.dir/UI.cpp.o
Projeto: CMakeFiles/Projeto.dir/build.make
Projeto: CMakeFiles/Projeto.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/angelo/Downloads/Universidade/Algoritmo e Estrutura de Dados/Projeto_AED/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable Projeto"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Projeto.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Projeto.dir/build: Projeto
.PHONY : CMakeFiles/Projeto.dir/build

CMakeFiles/Projeto.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Projeto.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Projeto.dir/clean

CMakeFiles/Projeto.dir/depend:
	cd "/home/angelo/Downloads/Universidade/Algoritmo e Estrutura de Dados/Projeto_AED/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/angelo/Downloads/Universidade/Algoritmo e Estrutura de Dados/Projeto_AED" "/home/angelo/Downloads/Universidade/Algoritmo e Estrutura de Dados/Projeto_AED" "/home/angelo/Downloads/Universidade/Algoritmo e Estrutura de Dados/Projeto_AED/cmake-build-debug" "/home/angelo/Downloads/Universidade/Algoritmo e Estrutura de Dados/Projeto_AED/cmake-build-debug" "/home/angelo/Downloads/Universidade/Algoritmo e Estrutura de Dados/Projeto_AED/cmake-build-debug/CMakeFiles/Projeto.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Projeto.dir/depend

