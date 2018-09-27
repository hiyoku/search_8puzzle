#include <iostream>
#include <cstring>
#include <time.h>
#include "8puzzle.h"
#include "largura/marcosHideki_0_largura.h"
#include "profundidade/marcosHideki_0_profundidade.h"

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

    puzzle_node_t node;
    init_first_node(&node);

    swap_right(&node);
    node = *node.right;
//    swap_down(&node);
//    node = *node.down;
//
//    swap_down(&node);
//    node = *node.down;

    run_largura(&node);
    run_profundidade(&node);

    return 0;
}