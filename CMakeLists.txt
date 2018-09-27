cmake_minimum_required(VERSION 3.10.2)
project(Buscas8Puzzle)

set(CMAKE_CXX_STANDARD 17)

add_executable(Buscas8Puzzle src/main.cpp src/8puzzle.h src/largura/marcosHideki_0_largura.h src/largura/marcosHideki_0_largura.cpp src/8puzzle.cpp src/profundidade/marcosHideki_0_profundidade.cpp src/profundidade/marcosHideki_0_profundidade.h src/heuristicas/marcosHideki_0_heuristicas.cpp src/heuristicas/marcosHideki_0_heuristicas.h)