//
// Created by hiyok on 9/27/2018.
//
#include <iostream>
#include <string.h>
#include <stack>
#include "marcosHideki_0_profundidade.h"

#ifdef MOCK
static void print_matrix(uint8_t matrix[3][3])
{
    std::cout << (int) matrix[0][0] << " " << (int) matrix[0][1] << " " << (int) matrix[0][2] << std::endl;
    std::cout << (int) matrix[1][0] << " " << (int) matrix[1][1] << " " << (int) matrix[1][2] << std::endl;
    std::cout << (int) matrix[2][0] << " " << (int) matrix[2][1] << " " << (int) matrix[2][2] << std::endl;
}
#endif

void run_profundidade(puzzle_node_t *node)
{
    std::stack<puzzle_node_t> pilha;

#ifdef MOCK
    print_matrix(node->puzzle);
#endif
    std::cout << "Started Depth Search" << std::endl;
    uint32_t states = 0;

    /* Mocking a test */
//    swap_right(&node);
//    node = *node.right;
//    swap_down(&node);
//    node = *node.down;
//
//    swap_down(&node);
//    node = *node.down;

    pilha.push(*node);

    while (!pilha.empty() && states < MAX_STATES)
    {
        node = &pilha.top();

        states++;

        if (check_solved(node))
        {
            std::cout << "Puzzle Solved!! states: " << (int) states << std::endl;
            break;
        }

        swap_up(node);
        swap_down(node);
        swap_left(node);
        swap_right(node);

        if ((node->up != nullptr) && (node->up != node->father))
        {
            pilha.push(*node->up);
        }

        if ((node->down != nullptr) && (node->down != node->father))
        {
            pilha.push(*node->down);
        }

        if ((node->left != nullptr) && (node->left != node->father))
        {
            pilha.push(*node->left);
        }

        if ((node->right != nullptr) && (node->right != node->father))
        {
            pilha.push(*node->right);
        }

        pilha.pop();
    }

    std::cout << "states: " << (int) states << std::endl;
}