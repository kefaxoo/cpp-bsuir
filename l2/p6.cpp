#include <iostream>

using namespace std;

void output(double x, int a, unsigned int b, char c) {
    a = x;
    b = x;
    c = x;
    cout << "x = " << x << endl << "a = " << a << endl << "b = " << b << endl << "c = " << c << endl;
}

int main() {
    double x = -78.345;
    int a;
    unsigned int b;
    char c;

    output(x, a, b, c);
    cout << "Введите x: ";
    cin >> x;
    cout << endl;
    output(x, a, b, c);
}