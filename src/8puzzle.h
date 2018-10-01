#ifndef BUSCAS8PUZZLE_8PUZZLE_H
#define BUSCAS8PUZZLE_8PUZZLE_H

#include <stdint.h>
#include <ctime>
#include <fstream>

#define     X               0
#define     Y               1
#define     MAX_STATES      500000
#define     MAX_STATES_H    10000

//#define     MOCK

/* DataStructure Used to create a graph*/
typedef struct puzzle_node_t
{
    puzzle_node_t *father;
    puzzle_node_t *left;
    puzzle_node_t *right;
    puzzle_node_t *up;
    puzzle_node_t *down;
    uint8_t puzzle[3][3];
    uint8_t zero_position[2];
    int value_h;
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
bool check_solved(puzzle_node_t *node);
void init_first_node(puzzle_node_t *node);
void swap_up(puzzle_node_t *node);
void swap_down(puzzle_node_t *node);
void swap_left(puzzle_node_t *node);
void swap_right(puzzle_node_t *node);
uint8_t find_masterpiece(puzzle_node_t *node);

#endif //BUSCAS8PUZZLE_8PUZZLE_H
