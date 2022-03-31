#include <iostream>
#include <math.h>

using namespace std;

double f (double x) {
    return x - 5 * pow(sin(x), 2);
}

double linearInterpolation (double X[], double x, int i) {
    return f(X[i]) + ((x - X[i]) / (X[i + 1] - X[i])) * (f(X[i + 1]) - f(X[i]));
}

int main() {
    double x, h, a, b, *X, *Yt;
    int i, m, n = 2;
    cout << "Введите начало промежутка: ";
    cin >> a;
    cout << endl << "Введите конец промежутка: ";
    cin >> b;
    cout << endl << "Введите количество точек: ";
    cin >> m;
    h = (b - a) / (m - 1);
    X = new double [m];
    Yt = new double [m];
    x = a;
    for (int i = 0; i < m; i++) {
        X[i] = x;
        x += h;
    }

    cout << endl << "Линейная интерполяция:" << endl;
    cout << "x | ~f(x)" << endl;
    for (x = a, i = 0; i < m; i++, x += h) {
        Yt[i] = linearInterpolation(X, x, i);
        cout << X[i] << " | " << Yt[i] << endl;
    }
}