#include <iostream>

using namespace std;

int main() {
    int a, b, x;

    cout << "Введите a: ";
    cin >> a;
    cout << endl << "Введите b: ";
    cin >> b;
    cout << endl << "Введите x: ";
    cin >> x;

    cout << endl;
    x == 0 ? cout << "ноль" : cout << "не ноль";
    cout << endl;
    a > b ? x = b : x = a;

    if (x > 10 && x < 10)
        x *= 2;
    else
        x *= 8;

    cout << "x = " << x;
}