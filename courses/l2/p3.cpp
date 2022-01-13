#include <iostream>

using namespace std;

int main() {
    char ch;
    bool b;
    int i;
    double d;

    cout << "Введите char: ";
    cin >> ch;
    cout << endl << "Введите bool: ";
    cin >> b;
    cout << endl << "Введите int: ";
    cin >> i;
    cout << endl << "Введите double: ";
    cin >> d;

    cout << endl << "Сумма всех значений: " << ch + b + i + d;
}