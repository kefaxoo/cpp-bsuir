#include <iostream>

using namespace std;

int main () {
    const int SIZE = 5;
    float array[SIZE], sum = 0;
    for (int i = 0; i < SIZE; i++) {
        cout << endl << "Введите " << i + 1 << " элемент массива: ";
        cin >> array[i];
        sum += array[i];
        if (array[i] == 0) {
            for (int j = i; j < SIZE; j++)
                array[j] = 0;
            break;
        }
    }

    sum /= SIZE;

    cout << endl << "Среднее арифметическое: " << sum << endl;
}