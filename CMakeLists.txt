cmake_minimum_required(VERSION 3.12)
project(Igraph)

set(CMAKE_CXX_STANDARD 14)

add_executable(Igraph main.cpp igraph.h ListGraph.h MatrixGraph.h SetGraph.h ArcGraph.h ListGraph.cpp MatrixGraph.cpp ArcGraph.cpp SetGraph.cpp searches.cpp Searches.h testfunc.h testfunc.cpp)