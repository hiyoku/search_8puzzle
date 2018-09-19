#ifndef BUSCAS8PUZZLE_8PUZZLE_H
#define BUSCAS8PUZZLE_8PUZZLE_H

#include <stdint.h>

/* DataStructure Used to create a graph*/
typedef struct puzzle_node_t
{
    puzzle_node_t *father;
    puzzle_node_t *left;
    puzzle_node_t *right;
    puzzle_node_t *up;
    puzzle_node_t *down;
    uint8_t puzzle[3][3];
} puzzle_node_t;

/* ENUM for movement options */
typedef enum puzzle_movements_t
{
    NO_MOVEMENT = 0,
    MOVEMENT_UP = 1,
    MOVEMENT_RIGHT = 2,
    MOVEMENT_DOWN = 3,
    MOVEMENT_LEFT = 4,
} puzzle_movements_t;

/* Movement Functions */
void swap_up(puzzle_node_t node);
void swap_down(puzzle_node_t node);
void swap_left(puzzle_node_t node);
void swap_right(puzzle_node_t node);

#endif //BUSCAS8PUZZLE_8PUZZLE_H
