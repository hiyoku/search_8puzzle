#ifndef BUSCAS8PUZZLE_8PUZZLE_H
#define BUSCAS8PUZZLE_8PUZZLE_H

#include <cstdint>
#include <ctime>
#include <fstream>
#include <vector>

#define     X               0
#define     Y               1
#define     MAX_STATES      300000
#define     MAX_STATES_H    100000

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
bool puzzle_is_same(puzzle_node_t *n1, puzzle_node_t *n2);
bool check_states_visited(std::vector<puzzle_node_t*> *arr, puzzle_node_t *node);
void init_first_node(puzzle_node_t *node);
void swap_up(puzzle_node_t *node);
void swap_down(puzzle_node_t *node);
void swap_left(puzzle_node_t *node);
void swap_right(puzzle_node_t *node);
uint8_t find_masterpiece(puzzle_node_t *node);

#endif //BUSCAS8PUZZLE_8PUZZLE_H
