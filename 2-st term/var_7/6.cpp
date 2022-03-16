#include <iostream>
#include <math.h>

using namespace std;

double f (double x) {
    return x - 5 * pow(sin(x), 2) - 5;
}

double secantMethod (double a, double b, double eps) {
    double x1 = a, x2 = b, y, res;
    int i = 0;
    do {
        y = res;
        res = x2 - ((x2 - x1) / (f(x2) - f(x1))) * f(x2);
        x1 = x2;
        x2 = res;
        i++;
    } while (abs(y - res) >= eps);
    cout << "Количество итерации в функции: " << i;
    return res;
}

int main() {
    double a, b, h, eps;
    cout << "Введите начало промежутка: ";
    cin >> a;
    cout << endl << "Введите конец промежутка: ";
    cin >> b;
    cout << endl << "Введите шаг h: ";
    cin >> h;
    cout << endl << "Введите eps: ";
    cin >> eps;

    int i = 0, num = 0;
    double root, x;
    for (x = a - h; x <= b + h; x += h) {
        i++;
        if (f(x) * f(x + h) < 0) {
            num++;
            root = secantMethod(x, x + h, eps);
            cout << endl << "Количество итерации в главной функции: " << i << endl;
            cout << num << "-й корень числа уравнения: " << root << endl;
            cout << endl;
            i = 0;
        }
    }

    if (num == 0)
        cout << endl << "Нет корней" << endl;
}