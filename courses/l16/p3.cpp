#include <iostream>

using namespace std;

void Output (int matrix[][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}

int main() {
    int matrix[10][10] ={ -12, 34, 95, 11, -6, 4, -6, 22, 0, 10,
                          0, 67, 44, -25, 31, 2, 17, 99, 1, 7,
                          -63, 55, -2, 0, 72, 99, -15, 33, 1, 2,
                          95, 27, 79, 5, 16, 55, 47, 12, -2, 35,
                          48, 44, 18, 37, -99, 54, -47, 7, 32, 1,
                          0, 67, 44, -25, 31, 2, 17, 99, 1, 7,
                          -63, 55, -2, 0, 72, 99, -15, 33, 1, 2,
                          95, 27, 79, 5, 16, 55, 47, 12, -2, 35,
                          48, 44, 18, 37, -99, 54, -47, 7, 32, 1,
                          0, 67, 44, -25, 31, 2, 17, 99, 1, 7 };

    cout << "Исходняя матрица: " << endl;
    Output(matrix);

    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 9; j++)
            for (int k = j; k < 10; k++)
                if (matrix[i][j] > matrix[i][k])
                    swap(matrix[i][j], matrix[i][k]);

    cout << "Отсортированная по возрастанию матрица: " << endl;
    Output(matrix);
}