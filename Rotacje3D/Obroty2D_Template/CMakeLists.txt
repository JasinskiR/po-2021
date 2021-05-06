cmake_minimum_required(VERSION 3.12)

project(Obroty_3D VERSION 0.1 LANGUAGES CXX)
find_package (Threads)

add_library(WEKTOR ./inc/Wektor.hh ./src/empty.cpp)
target_include_directories(WEKTOR PUBLIC ./inc ./src)

add_library(MACIERZ ./inc/MacierzRot.hh ./src/empty.cpp)
target_link_libraries(MACIERZ WEKTOR)
target_include_directories(MACIERZ PUBLIC ./inc ./src)

add_library(FIGURE ./inc/Figure.hh ./src/empty.cpp)
target_link_libraries(FIGURE MACIERZ)
target_include_directories(FIGURE PUBLIC ./inc ./src)

add_library(GNU ./src/Dr2D_gnuplot_api.cpp)
target_include_directories(GNU PUBLIC ./inc)

set(LIBS WEKTOR MACIERZ FIGURE)

add_executable(Obroty_3D ./src/main.cpp)
target_link_libraries(Obroty_3D MACIERZ GNU FIGURE ${CMAKE_THREAD_LIBS_INIT})

target_compile_options(-Wall -Wextra -pedantic -Werror)
