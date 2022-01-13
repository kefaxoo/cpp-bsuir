#include <iostream>

using namespace std;

int main() {
    double a, b;

    cout << "Введите первое число: ";
    cin >> a;
    cout << endl << "Введите второе число: ";
    cin >> b;

    cout << endl << "Сумма двух чисел: " << a + b << endl << "Произведение двух чисел: " << a * b << endl << "Среднее арифметическое чисел: " << (a + b) / 2 << endl;
}