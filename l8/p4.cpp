#include <iostream>

using namespace std;

int main() {
    int matrix[5][5] = { -12, 34, 95, 11, -6,
                         0, 67, 44, -25, 31,
                         -63, 55, -2, 0, 72,
                         95, 27, 79, 5, 16,
                         48, 44, 18, 37, -99 };

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            if (matrix[i][j] == 0)
                cout << "[" << i << "; " << j << "]" << endl;
}