#include <cstring>
#include <malloc.h>
#include <algorithm>
#include <vector>
#include "8puzzle.h"


static uint8_t random_uint8 (uint8_t i)
{
    return rand() % i;
}

static bool check_bounds(int8_t x, int8_t y)
{
    /* This function check bounds of coordinates
     * Input: future X and Y
     * Output: True if overflow the limits, false if not */
    if ((x < 0) || x > 2)
    {
        return true;
    }

    if ((y < 0) || y > 2)
    {
        return true;
    }

    return false;
}

uint8_t find_masterpiece(puzzle_node_t *node)
{
    for (int y = 0; y < 3; y++)
    {
        for (int x = 0; x < 3; x++)
        {
            if (node->puzzle[y][x] == 0)
            {
                node->zero_position[X] = x;
                node->zero_position[Y] = y;

                return 0;
            }
        }
    }

    return 1;
}

bool check_solved(puzzle_node_t *node)
{
    uint8_t values = 0;

    for (uint8_t y = 0; y < 3; y++)
    {
        for (uint8_t x = 0; x < 3; x++)
        {
            if (node->puzzle[y][x] != values++)
            {
                return false;
            }
        }
    }

    return true;
}

void init_first_node(puzzle_node_t *node)
{
    /* Function to start a 8 pieces puzzle */
    node->up = nullptr;
    node->down = nullptr;
    node->left = nullptr;
    node->right = nullptr;
    node->father = nullptr;
    std::vector<uint8_t> values;
    for (uint8_t i = 0; i < 9; ++i)
    {
        values.push_back(i);
    }

    //std::random_shuffle(values.begin(), values.end(), random_uint8);

    uint8_t index = 0;

    for (uint8_t y = 0; y < 3; y++)
    {
        for (int x = 0; x < 3; x++)
        {
            node->puzzle[y][x] = values[index++];
        }
    }

    find_masterpiece(node);
}

void swap_up(puzzle_node_t *node) {
    /* Function to swap zero to the up field
    *  This function don't have any restrictions */
    int8_t x = node->zero_position[X];
    int8_t y = node->zero_position[Y];

    if(check_bounds(x, y - 1))
    {
        node->up = nullptr;
    }
    else
    {
        puzzle_node_t temp;
        memcpy(&temp, node, sizeof(puzzle_node_t));

        temp.puzzle[y][x] = temp.puzzle[y - 1][x];
        temp.puzzle[y - 1][x] = 0;
        temp.zero_position[X] = x;
        temp.zero_position[Y] = y - 1;

        memcpy(&temp.father, node, sizeof(puzzle_node_t));

        node->up = (puzzle_node_t *) malloc(sizeof(puzzle_node_t));
        memcpy(node->up, &temp, sizeof(puzzle_node_t));
    }
}

void swap_down(puzzle_node_t *node)
{
    /* Function to swap zero to the down field
    *  This function don't have any restrictions */
    int8_t x = node->zero_position[X];
    int8_t y = node->zero_position[Y];

    if(check_bounds(x, y + 1))
    {
        node->down = nullptr;
    }
    else
    {
        puzzle_node_t temp;
        memcpy(&temp, node, sizeof(puzzle_node_t));
        memcpy(&temp.father, node, sizeof(puzzle_node_t));

        temp.puzzle[y][x] = temp.puzzle[y + 1][x];
        temp.puzzle[y + 1][x] = 0;
        temp.zero_position[X] = x;
        temp.zero_position[Y] = y + 1;

        node->down = (puzzle_node_t *) malloc(sizeof(puzzle_node_t));
        memcpy(node->down, &temp, sizeof(puzzle_node_t));
    }
}

void swap_left(puzzle_node_t *node)
{
    /* Function to swap zero to the left field
     * This function don't have any restrictions */
    int8_t x = node->zero_position[X];
    int8_t y = node->zero_position[Y];

    if(check_bounds(x - 1, y))
    {
        node->left = nullptr;
    }
    else
    {
        puzzle_node_t temp;
        memcpy(&temp, node, sizeof(puzzle_node_t));

        temp.puzzle[y][x] = temp.puzzle[y][x - 1];
        temp.puzzle[y][x - 1] = 0;
        temp.zero_position[X] = x - 1;
        temp.zero_position[Y] = y;

        memcpy(&temp.father, node, sizeof(puzzle_node_t));

        node->left = (puzzle_node_t *) malloc(sizeof(puzzle_node_t));
        memcpy(node->left, &temp, sizeof(puzzle_node_t));
    }
}

void swap_right(puzzle_node_t *node)
{
    /* Function to swap zero to the right field
     * This function don't have any restrictions */
    int8_t x = node->zero_position[X];
    int8_t y = node->zero_position[Y];

    if(check_bounds(x + 1, y))
    {
        node->right = nullptr;
    }
    else
    {
        puzzle_node_t temp;
        memcpy(&temp, node, sizeof(puzzle_node_t));

        temp.puzzle[y][x] = temp.puzzle[y][x + 1];
        temp.puzzle[y][x + 1] = 0;
        temp.zero_position[X] = x + 1;
        temp.zero_position[Y] = y;

        memcpy(&temp.father, node, sizeof(puzzle_node_t));

        node->right = (puzzle_node_t *) malloc(sizeof(puzzle_node_t));
        memcpy(node->right, &temp, sizeof(puzzle_node_t));
    }
}