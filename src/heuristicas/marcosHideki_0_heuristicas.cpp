
#include <cstdlib>
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include "marcosHideki_0_heuristicas.h"

static bool finished = false;
static uint16_t position[2][9] = {
        {0, 0, 0, 1, 1, 1, 2, 2, 2},
        {0, 1, 2, 0, 1, 2, 0, 1, 2}
};

bool compareByH(const puzzle_node_t *a, const puzzle_node_t *b)
{
    return a->value_h < b->value_h;
}

uint8_t heuristica_01(puzzle_node_t *node)
{
    /* Funcao que retorna o valor da heuristica 1
     * Heuristica1: Quantidade de pecas em lugares errados
     * return: uint16_t */

    uint8_t counter = 0;
    int sum = 0;

    for (int y = 0; y < 3; ++y)
    {
        for (int x = 0; x < 3; ++x)
        {
            if(node->puzzle[y][x] != counter++)
            {
                sum++;
            }

        }
    }

    node->value_h = sum;

    return sum;
}

uint16_t heuristica_02(puzzle_node_t *node)
{
    /* Funcao que retorna o valor da heuristica 2
     * Heuristica2: Distancia Manhattan
     * return: uint16_t */

    uint8_t aux = 0;
    int sum = 0;

    for (int x = 0; x < 3; ++x)
    {
        for (int y = 0; y < 3; ++y)
        {
            aux = node->puzzle[x][y];
            if(aux)
            {
                sum = sum + abs(x - position[X][aux]) + abs(y - position[Y][aux]);
//                std::cout << " Num: " << (int) aux << std::endl;
//                std::cout << " Cur - X: " << (int) x << " - Y: " << (int) y << std::endl;
//                std::cout << " Nex - X: " << (int) position[X][aux] << " - Y: " << (int) position[Y][aux] << std::endl;
            }
        }
    }

    node->value_h = sum;

    return sum;
}

int heuristica_03(puzzle_node_t *node)
{
    /* Funcao que retorna o valor da heuristica 3
     * Heuristica2: Distancia Manhattan com pesos maiores em um lado do puzzle
     * return: uint16_t */

    uint8_t aux = 0;
    int value = 0;
    int sum = 0;

    for (int x = 0; x < 3; ++x)
    {
        for (int y = 0; y < 3; ++y)
        {
            aux = node->puzzle[x][y];
            if(aux)
            {
                if(x == 2)
                {
                    value = (abs(x - position[X][aux]) + abs(y - position[Y][aux]));
                    sum = sum + value * 3;
                }
                else
                {
                    value = abs(x - position[X][aux]) + abs(y - position[Y][aux]);
                    sum = sum + value;
                }
//                std::cout << " Num: " << (int) aux << std::endl;
//                std::cout << " Cur - X: " << (int) x << " - Y: " << (int) y << std::endl;
//                std::cout << " Nex - X: " << (int) position[X][aux] << " - Y: " << (int) position[Y][aux] << std::endl;
            }
        }
    }

//    std::cout << "SUM: " << sum << "  - WEIGHT: " << weight << std::endl;
    node->value_h = sum;
    return sum;
}

void set_heuristicas(puzzle_node_t *node, enum Heuristicas_t h_)
{
    switch (h_)
    {
        case H1:
        {
            heuristica_01(node);
            break;
        }

        case H2:
        {
            heuristica_02(node);
            break;
        }

        case H3:
        {
            heuristica_03(node);
            break;
        }

        default:
            break;
    }
}


void run_heuristicas(puzzle_node_t node_main, enum Heuristicas_t f_de_h)
{
    clock_t begin = clock();
    std::vector<puzzle_node_t *> all_states;

#ifdef MOCK
    //print_matrix(node->puzzle);
#endif
    std::cout << "Started Heuristics Search " << f_de_h + 1 << std::endl;
    uint32_t states = 0;

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

    all_states.push_back(node);

    set_heuristicas(node, f_de_h);
    double elapsed_secs;

    while (!all_states.empty() && states < MAX_STATES_H)
    {
        node = all_states.front();
        states++;

        if (check_solved(node))
        {
            std::cout << "Puzzle Solved!! states: " << (int) states << std::endl;
            clock_t end = clock();

            elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
            std::fstream file;
            file.open("Heuristica " + std::to_string(f_de_h), std::ios::in | std::ios::app);
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

        if ((node->up != nullptr) && (node->up != node->father))
        {
            set_heuristicas(node->up, f_de_h);
            all_states.push_back(node->up);
        }

        if ((node->down != nullptr) && (node->down != node->father))
        {
            set_heuristicas(node->down, f_de_h);
            all_states.push_back(node->down);
        }

        if ((node->left != nullptr) && (node->left != node->father))
        {
            set_heuristicas(node->left, f_de_h);
            all_states.push_back(node->left);
        }

        if ((node->right != nullptr) && (node->right != node->father))
        {
            set_heuristicas(node->right, f_de_h);
            all_states.push_back(node->right);
        }

        std::sort(all_states.begin(), all_states.end(), compareByH);

    }
    if (!finished)
    {
        clock_t end = clock();

        elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
        std::fstream file;
        file.open("Heuristica " + std::to_string(f_de_h), std::ios::in | std::ios::app);
        file << "Not Solved - " << elapsed_secs << " - " << states << std::endl;
        std::cout << "states: " << (int) states << std::endl;
        file.close();
    }

    std::cout << "Dealloc" << std::endl;
    for (int i = 0; i < all_states.size(); ++i) {
        free(all_states[i]);
    }

    std::cout << "Seconds used: " << elapsed_secs << std::endl;
}