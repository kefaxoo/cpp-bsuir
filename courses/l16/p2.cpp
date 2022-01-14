#include <iostream>

using namespace std;

void Output (int array[], int size) {
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

int main() {
    int array[] = { 10, -4, 8, 99, -101, 0, 16, 0, 29, 56, 125, -34, 31, -4, 22, 16, 165 };

    cout << "Исходний массив: " << endl;
    int size = sizeof(array)/sizeof(array[0]);
    Output(array, size);

    for (int i = 0; i < size - 1; i++)
        for (int j = i; j < size; j++)
            if (array[i] < array[j])
                swap(array[i], array[j]);

    cout << "Отсортированный по возрастанию массив: " << endl;
    Output(array, size);
}