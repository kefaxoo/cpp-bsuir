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
    int i;

    for (i = 0; i < size; i++)
        if (array[i] == 0 && !firstZero) {
            firstZero = true;
            break;
        }

    if (i == size - 1 && !firstZero) {
        cout << endl << "there aren't any zero values" << endl;
        exit(0);
    }

    int multiplication = 1;
    int j;

    if (firstZero)
        for (j = i + 1; j < size; j++) {
            if (array[j] != 0) 
                multiplication *= array[j];
            else {
                if (array[j - 1] != 0) {
                    cout << endl << multiplication << endl;
                    exit(0);
                }
                else {
                    cout << endl << "there aren't any values between zeros" << endl;
                }
            }
        }

    if (j + i == size) {
        cout << endl << "there aren't second zero value" << endl;
    }
}