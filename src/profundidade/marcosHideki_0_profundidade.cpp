//
// Created by hiyok on 9/27/2018.
//
#include <iostream>
#include <cstring>
#include <stack>
#include "marcosHideki_0_profundidade.h"

static bool finished = false;

#ifdef MOCK
static void print_matrix(uint8_t matrix[3][3])
{
    std::cout << (int) matrix[0][0] << " " << (int) matrix[0][1] << " " << (int) matrix[0][2] << std::endl;
    std::cout << (int) matrix[1][0] << " " << (int) matrix[1][1] << " " << (int) matrix[1][2] << std::endl;
    std::cout << (int) matrix[2][0] << " " << (int) matrix[2][1] << " " << (int) matrix[2][2] << std::endl;
}
#endif

void run_profundidade(puzzle_node_t node_main)
{
    clock_t begin = clock();
    std::stack<puzzle_node_t> pilha;
    std::vector<puzzle_node_t *> all_states;


#ifdef MOCK
    print_matrix(node->puzzle);
#endif
    std::cout << "Started Depth Search" << std::endl;
    uint32_t states = 0;
    double elapsed_secs;

    /* Mocking a test */
//    swap_right(&node);
//    node = *node.right;
//    swap_down(&node);
//    node = *node.down;
//
//    swap_down(&node);
//    node = *node.down;

    auto *node = new puzzle_node_t;
    memcpy(node, &node_main, sizeof(puzzle_node_t));

    pilha.push(*node);
    all_states.push_back(node);

    while (!pilha.empty() && states < MAX_STATES)
    {
        node = &pilha.top();

        states++;

        if (check_solved(node))
        {
            std::cout << "Puzzle Solved!! states: " << (int) states << std::endl;
            clock_t end = clock();

            elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
            std::fstream file;
            file.open("profundidade", std::ios::in | std::ios::app);
            file << "Solved! - " << elapsed_secs << " - " << states << std::endl;
            std::cout << "states: " << (int) states << std::endl;
            file.close();
            finished = true;
            break;
        }

        swap_up(node);
        swap_down(node);
        swap_left(node);
        swap_right(node);

        if ((node->up != nullptr) && !check_states_visited(&all_states, node->up))
        {
            pilha.push(*node->up);
            all_states.push_back(node->up);
        }

        if ((node->down != nullptr) && !check_states_visited(&all_states, node->down))
        {
            pilha.push(*node->down);
            all_states.push_back(node->down);
        }

        if ((node->left != nullptr) && !check_states_visited(&all_states, node->left))
        {
            pilha.push(*node->left);
            all_states.push_back(node->left);
        }

        if ((node->right != nullptr) && !check_states_visited(&all_states, node->right))
        {
            pilha.push(*node->right);
            all_states.push_back(node->right);
        }

        pilha.pop();
    }

    if (!finished)
    {
        clock_t end = clock();

        elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
        std::ofstream file;
        file.open("profundidade", std::ios::in | std::ios::app);
        file << "Not Solved! - " << elapsed_secs << " - " << states << std::endl;
        std::cout << "states: " << (int) states << std::endl;
        file.close();
    }

    std::cout << "Dealloc" << std::endl;
    for (int i = 0; i < all_states.size(); ++i) {
        free(all_states[i]);
    }

    std::cout << "[Finished Width] - Seconds used: " << elapsed_secs << std::endl;
}