#include <iostream>

using namespace std;

int main () {
    int array[6], sum = 0;
    for (int i = 0; i < 6; i++) {
        array[i] = i * i;
        cout << i << " " << array[i] << endl;
        sum += array[i];
    }

    cout << endl << "Сумма элементов массива: " << sum << endl;
}