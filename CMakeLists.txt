cmake_minimum_required(VERSION 3.25)
project(RubiksCubeSolver)

set(CMAKE_CXX_STANDARD 17)

add_executable(RubiksCubeSolver main.cpp GenCube.cpp GenCube.h Cube3d.cpp Cube3d.h DFS.h BFS.h IDDFS.h PatternDatabases/NibbleArray.h PatternDatabases/NibbleArray.cpp PatternDatabases/PatternDatabase.cpp PatternDatabases/PatternDatabase.h)
