#include <iostream>

using namespace std;

int main() {
    int matrix[5][5] = { -12, 34, 95, 11, -6,
                         0, 67, 44, -25, 31,
                         -63, 55, -2, 0, 72,
                         95, 27, 79, 5, 16,
                         48, 44, 18, 37, -99 };
    int sum = 0, max = INT_MIN, sumOfMainDiagnoal = 0;

    cout << "Размер матрицы: " << sizeof(matrix) << endl;
    for (int i = 0; i < 5; i++) {
        int temp = 0;
        for (int j = 0; j < 5; j++) {
            cout << matrix[i][j] << " ";
            temp += matrix[i][j];
            max = matrix[i][j] > max ? matrix[i][j] : max;
            sum += matrix[i][j];
        }
        cout << temp << endl;
        sumOfMainDiagnoal += matrix[i][i];
    }
    cout << "Сумма всех элементов матрицы: " << sum << endl << "Максимальный элемент матрицы: " << max << endl << "Cумма элементов главной диагонали: " << sumOfMainDiagnoal << endl;
}