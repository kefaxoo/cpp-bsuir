#include <iostream>

using namespace std;

int main() {
    double a, b, c;
    cout << "Введите первое число: ";
    cin >> a;
    cout << endl << "Введите второе число: ";
    cin >> b;
    cout << endl << "Введите третье число: ";
    cin >> c;

    cout << endl << "Сумма трёх чисел: " << a + b + c << endl << "Разность трёх чисел: " << a - b - c << endl << "Произведение трёх чисел: " << a * b * c << endl;
}