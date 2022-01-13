#include <iostream>

using namespace std;

int main () {
    const int SIZE = 5;
    float array[SIZE], sum = 0;
    for (int i = 0; i < SIZE; i++) {
        cout << endl << "Введите " << i + 1 << " элемент массива: ";
        cin >> array[i];
        sum += array[i];
    }

    cout << endl << "Сумма элементов массива: " << sum << endl << "Размер массива в байтах: " << sizeof(array) << endl << "Индекс последнего элемента: " << SIZE - 1 << endl;
}