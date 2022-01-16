#include <iostream>

using namespace std;

int main() {
    int sizeOfLine, sizeOfColumn;
    cout << "enter size of line: ";
    cin >> sizeOfLine;

    cout << endl << "enter size of column: ";
    cin >> sizeOfColumn;

    int **matrix, i = 0;
    matrix = new int *[sizeOfColumn];
    while (i < sizeOfColumn)
        matrix[i++] = new int [sizeOfLine];

    for (int i = 0; i < sizeOfColumn; i++) {
        cout << endl << "enter " << sizeOfLine << " elements of " << i + 1 << " line with space separator: ";
        for (int j = 0; j < sizeOfLine; j++)
            cin >> matrix[i][j];
    }

    int count = 0;

    for (int i = 0; i < sizeOfColumn; i++)
        for (int j = 1; j < sizeOfLine - 1; j++)
            if (matrix[i][j] < matrix[i][j - 1] && matrix[i][j] > matrix[i][j + 1])
                count++;

    cout << endl << count << endl;

    for (i = 0; i < sizeOfLine; i++)
        delete [] matrix[i];
    delete [] matrix;
}