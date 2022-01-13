#include <iostream>

using namespace std;

bool Check(int a, int b, int c) {
    if (a + b > c)
        if (a + c > b)
            if (b + c > a)
                return true;
    return false;
}

int main() {
    int a, b, c;
    cout << "Введите длину первой стороны: ";
    cin >> a;
    cout << endl << "Введите длину второй стороны: ";
    cin >> b;
    cout << endl << "Введите длину третьей стороны: ";
    cin >> c;

    if (Check(a, b, c))
        cout << endl << "Треугольник существует" << endl;
    else
        cout << endl << "Треугольник не существует" << endl;
}