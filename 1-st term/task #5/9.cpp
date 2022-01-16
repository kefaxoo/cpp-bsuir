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

    bool firstZero = false;
    int index = -1;

    for (int i = 0; i < size; i++)
        if (array[i] == 0)
            index = i;

    if (index == -1) {
        cout << endl << "there aren't any zero in array" << endl;
        exit(0);
    }

    if (index == size - 1) {
        cout << endl << "last zero is the last element of array" << endl;
        exit(0);
    }
    
    int sum = 0;
    for (int i = index; i < size; i++)
        sum += array[i];

    cout << endl << "sum of element in array after last zero: " << sum << endl;
}