#include <iostream>

using namespace std;

int Max(int a, int b, int c) {
    int max = a;

    if (max < b)
        max = b;

    if (max < c)
        max = c;

    return max;
}

int main() {
    int a, b, c;
    cout << "Введите первое число: ";
    cin >> a;
    cout << endl << "Введите второе число: ";
    cin >> b;
    cout << endl << "Введите третье число: ";
    cin >> c;

    cout << endl << "Максимальное из трёх чисел: " << Max(a, b, c) << endl;
}