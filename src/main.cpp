#include <iostream>
#include <cstring>
#include <time.h>
#include "8puzzle.h"
#include "largura/marcosHideki_0_largura.h"

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

    run();

    return 0;
}