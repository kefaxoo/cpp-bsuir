#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    cout << "Введите первое число: ";
    cin >> a;
    cout << endl << "Введите второе число: ";
    cin >> b;
    cout << endl << "Введите третье число: ";
    cin >> c;

    cout << a << " * " << b << " + " << c << " = " << a * b + c << endl;
    cout << b << " - " << c << " * " << a << " = " << b - c * a << endl;
    cout << a << " * (" << c << " - " << b << ") = " << a * (c - b) << endl;
}