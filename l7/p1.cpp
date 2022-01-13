#include <iostream>

using namespace std;

int main () {
    int array[5] = { 12, -5, 78, 10, 4 };
    for (int i = 0; i < 5; i++) {
        cout << i << " " << array[i] << endl;
    }

    cout << endl << "Размер массива в байтах: " << sizeof(array) << endl;
}