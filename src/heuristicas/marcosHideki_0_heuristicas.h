#ifndef BUSCAS8PUZZLE_MARCOSHIDEKI_0_HEURISTICAS_H
#define BUSCAS8PUZZLE_MARCOSHIDEKI_0_HEURISTICAS_H
#include "../8puzzle.h"

enum Heuristicas_t {
    H1 = 0,
    H2 = 1,
    H3 = 2,
};

uint8_t heuristica_01(puzzle_node_t *node);
uint16_t heuristica_02(puzzle_node_t *node);
int heuristica_03(puzzle_node_t *node);
void run_heuristicas(puzzle_node_t node, enum Heuristicas_t f_de_h);
#endif //BUSCAS8PUZZLE_MARCOSHIDEKI_0_HEURISTICAS_H
