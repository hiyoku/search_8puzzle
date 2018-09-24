#include <iostream>
#include "marcosHideki_0_largura.h"
#include "../8puzzle.h"
#include <queue>

void run(void)
{
    std::queue<puzzle_node_t> fila;

    puzzle_node_t node;
    init_first_node(&node);
    fila.push(node);

    while (!fila.empty())
    {
        node = fila.front();

        swap_up(&node);
        swap_down(&node);
        swap_left(&node);
        swap_right(&node);

        if ((node.up != nullptr) && (node.up != node.father))
        {
            fila.push(*node.up);
        }
    }
}