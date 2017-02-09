cmake_minimum_required(VERSION 3.6)
project(cgraph)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        graph.c
        graph.h
        kruskal.c random.c random.h qsort.h qsort.c)

add_executable(cgraph ${SOURCE_FILES})
target_link_libraries(cgraph m)