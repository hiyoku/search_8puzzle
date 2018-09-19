cmake_minimum_required(VERSION 3.12)
project(Buscas8Puzzle)

set(CMAKE_CXX_STANDARD 17)

add_executable(Buscas8Puzzle src/main.cpp src/8puzzle.h src/largura/marcosHideki_0_largura.h src/largura/marcosHideki_0_largura.cpp src/8puzzle.cpp)