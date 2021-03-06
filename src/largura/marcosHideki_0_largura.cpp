#include <iostream>
#include <cstring>
#include "marcosHideki_0_largura.h"
#include "../8puzzle.h"
#include <queue>

static bool finished = false;


#ifdef MOCK
static void print_matrix(uint8_t matrix[3][3])
{
    std::cout << (int) matrix[0][0] << " " << (int) matrix[0][1] << " " << (int) matrix[0][2] << std::endl;
    std::cout << (int) matrix[1][0] << " " << (int) matrix[1][1] << " " << (int) matrix[1][2] << std::endl;
    std::cout << (int) matrix[2][0] << " " << (int) matrix[2][1] << " " << (int) matrix[2][2] << std::endl;
}
#endif

void run_largura(puzzle_node_t node_main)
{
    std::queue<puzzle_node_t> fila;

#ifdef MOCK
    print_matrix(node->puzzle);
#endif
    std::cout << "Started Breadth Search" << std::endl;
    uint32_t states = 0;

    /* Mocking a test */
//    swap_right(&node);
//    node = *node.right;
//    swap_down(&node);
//    node = *node.down;
//
//    swap_down(&node);
//    node = *node.down;

    std::vector<puzzle_node_t *> all_states;
    double elapsed_secs;
    auto *node = new puzzle_node_t;
    memcpy(node, &node_main, sizeof(puzzle_node_t));

    all_states.push_back(node);

    fila.push(*node);
    clock_t begin = clock();


    while (!fila.empty() && states < MAX_STATES)
    {
        node = &fila.front();
        states++;


        if (check_solved(node))
        {
            std::cout << "Puzzle Solved!! states: " << (int) states << std::endl;
            clock_t end = clock();

            elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
            std::fstream file;
            file.open("largura", std::ios::in | std::ios::app);
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
            fila.push(*node->up);
            all_states.push_back(node->up);
        }

        if ((node->down != nullptr) && !check_states_visited(&all_states, node->down))
        {
            fila.push(*node->down);
            all_states.push_back(node->down);
        }

        if ((node->left != nullptr) && !check_states_visited(&all_states, node->left))
        {
            fila.push(*node->left);
            all_states.push_back(node->left);
        }

        if ((node->right != nullptr) && !check_states_visited(&all_states, node->right))
        {
            fila.push(*node->right);
            all_states.push_back(node->right);
        }

        fila.pop();
    }

    if (!finished)
    {
        clock_t end = clock();

        elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
        std::fstream file;
        file.open("largura", std::ios::in | std::ios::app);
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