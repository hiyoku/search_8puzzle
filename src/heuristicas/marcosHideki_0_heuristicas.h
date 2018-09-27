#ifndef BUSCAS8PUZZLE_MARCOSHIDEKI_0_HEURISTICAS_H
#define BUSCAS8PUZZLE_MARCOSHIDEKI_0_HEURISTICAS_H
#include "../8puzzle.h"

enum Heuristicas_t {
    H1 = 0,
    H2 = 1;
    H3 = 2;
} Heuristicas_t;

void run_heuristicas(puzzle_node_t *node, enum Heuristicas_t f_de_h);
#endif //BUSCAS8PUZZLE_MARCOSHIDEKI_0_HEURISTICAS_H
