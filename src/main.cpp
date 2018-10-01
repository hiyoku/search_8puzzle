#include <iostream>
#include <cstring>
#include <time.h>
#include "8puzzle.h"
#include "largura/marcosHideki_0_largura.h"
#include "profundidade/marcosHideki_0_profundidade.h"
#include "heuristicas/marcosHideki_0_heuristicas.h"

using namespace std;

static void print_matrix(uint8_t matrix[3][3])
{
    cout << (int) matrix[0][0] << " " << (int) matrix[0][1] << " " << (int) matrix[0][2] << endl;
    cout << (int) matrix[1][0] << " " << (int) matrix[1][1] << " " << (int) matrix[1][2] << endl;
    cout << (int) matrix[2][0] << " " << (int) matrix[2][1] << " " << (int) matrix[2][2] << endl;
}

int main()
{
    cout << "Testing..." << endl;
    srand(unsigned (time(0)));

//    swap_right(&node);
//    node = *node.right;
//    swap_down(&node);
//    node = *node.down;
//
//    swap_down(&node);
//    node = *node.down;

//    cout << "Heuristica 1: " << (int) heuristica_01(&node) << endl;
//    cout << "Heuristica 2: " << (int) heuristica_02(&node) << endl;
//    cout << "Heuristica 3: " << heuristica_03(&node) << endl;

    uint16_t counter = 1;
    while (counter <= 200)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout << "Running solver n: " << counter << "..." << endl;
        puzzle_node_t node;
        init_first_node(&node);

        run_largura(&node);
        run_profundidade(&node);
        run_heuristicas(&node, H1);
        run_heuristicas(&node, H2);
        run_heuristicas(&node, H3);

        counter++;
    }
    return 0;
}