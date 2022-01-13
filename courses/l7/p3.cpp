#include <iostream>

using namespace std;

int main () {
    int array[4], max = INT_MIN;
    for (int i = 0; i < 4; i++) {
        cout << endl << "Введите " << i + 1 << " элемент массива: ";
        cin >> array[i];
        if (array[i] > max)
            max = array[i];
    }

    cout << endl << "Максимальный элемент массива: " << max << endl;
}