#include <iostream>
#include <string.h>
#include "marcosHideki_0_largura.h"
#include "../8puzzle.h"
#include <queue>

static void print_matrix(uint8_t matrix[3][3])
{
    std::cout << (int) matrix[0][0] << " " << (int) matrix[0][1] << " " << (int) matrix[0][2] << std::endl;
    std::cout << (int) matrix[1][0] << " " << (int) matrix[1][1] << " " << (int) matrix[1][2] << std::endl;
    std::cout << (int) matrix[2][0] << " " << (int) matrix[2][1] << " " << (int) matrix[2][2] << std::endl;
}

void run(void)
{
    std::queue<puzzle_node_t> fila;

    puzzle_node_t node;
    puzzle_node_t *aux;
    init_first_node(&node);
    print_matrix(node.puzzle);
    swap_down(&node);

    if (node.down == nullptr)
    {
        std::cout << "NULL??" << std::endl;
    }
    aux = node.down;
    node = *node.down;
    std::cout << "o" << std::endl;
    print_matrix(node.puzzle);

    fila.push(node);

    uint32_t states = 0;

    while (!fila.empty() && states < MAX_STATES)
    {
        node = fila.front();
        fila.pop();
        states++;

        if (check_solved(&node))
        {
            std::cout << "Puzzle Solved!! states: " << (int) states << std::endl;
            break;
        }

        swap_up(&node);
        swap_down(&node);
        swap_left(&node);
        swap_right(&node);

        if ((node.up != nullptr) && (node.up != node.father))
        {
            fila.push(*node.up);
        }

        if ((node.down != nullptr) && (node.down != node.father))
        {
            fila.push(*node.down);
        }

        if ((node.left != nullptr) && (node.left != node.father))
        {
            fila.push(*node.left);
        }

        if ((node.right != nullptr) && (node.right != node.father))
        {
            fila.push(*node.right);
        }


    }
}