#include <iostream>

using namespace std;

bool Check(double a, double b, double c) {
    if (a + b > c)
        if (a + c > b)
            if (b + c > a)
                return true;
    return false;
}

int Type(double a, double b, double c) {
    if (a <= 0 || b <= 0 || c <= 0)
        return 5;
    else if (Check(a, b, c)) {
            if (a == b && b == c)
                return 1;
            else if (a == b || a == c || b == c)
                return 2;
                else
                    return 3;
        }
        else
            return 4;
}

int main() {
    double a, b, c;
    cout << "Введите длину первой стороны: ";
    cin >> a;
    cout << endl << "Введите длину второй стороны: ";
    cin >> b;
    cout << endl << "Введите длину третьей стороны: ";
    cin >> c;

    switch (Type (a, b, c)) {
        case 1:
            cout << endl << "равносторонний треугольник" << endl;
            break;
        case 2:
            cout << endl << "равнобедренный треугольник" << endl;
            break;
        case 3:
            cout << endl << "разносторонний треугольник" << endl;
            break;
        case 4:
            cout << endl << "это не треугольник" << endl;
            break;
        default:
            cout << endl << "неверные данные" << endl;
    }
}