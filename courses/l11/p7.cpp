#include <iostream>

using namespace std;

int main() {
    int array[] = { 16, 78, 99, 6, -29, 19, -52, 65, -88, 51, -79, -22, 32, -25, -62, -69, -2, -59, -75, 89, -87, 95, -22, 85, -49, -75, 76, 73, -59, -52, 30, 49, -28, -48, 0, 57, -6, -85, 0, -18, -97, -21, -95, 64, 22, -2, 69, -84, -1, -71, -25, 47, 72, 43, 15, -44, 44, 61, 4, 74, 88, -61, 0, -64, -83, 97, 0, 90, 15, 8, -54, 19, 73, 35, -67, -87, 85, -99, -70, 10, 98, 58, -10, -29, 95, 62, 77, 89, 36, -32, 78, 60, -79, -18, 30, -13, -34, -92, 1, -38 };

    int **matrix = new int *[10];
    for (int i = 0; i < 10; i++)
        matrix[i] = new int[10];

    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++) {
            matrix[i][j] = array[i + j];
            if (j == 0 || j == 9)
            cout << "[" << i << "," << j << "] | adress = " << &matrix[i][j] << " | value = " << matrix[i][j] << endl;
        } 

    
}