#include <iostream>

using namespace std;

int main() {
    int size;

    cout << "enter size: ";
    cin >> size;

    int *array = new int[size];

    for (int i = 0; i < size; i++) {
        cout << endl << "enter " << i + 1 << " element of array: ";
        cin >> array[i];
    }

    int min = 0;
    for (int i = 0; i < size; i++)
        if (array[i] < array[min])
            min = i;

    if (min == size - 1) {
        cout << "there aren't any values after min element" << endl;
        exit(0);
    }

    int sum = 0;
    for (int i = min + 1; i < size; i++)
        sum += array[i];

    
    cout << "sum of elements after minimal element: " << sum << endl;
}