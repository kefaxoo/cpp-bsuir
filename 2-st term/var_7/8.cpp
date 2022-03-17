#include <iostream>
#include <math.h>

using namespace std;

double f (double x) {
    return x - 5 * pow(sin(x), 2);
}

double formulaOfAverages (double a, double b, double n) {
    double h = (b - a) / n;

    double *X = new double[(int)n + 1];
    double x = a;
    for (int i = 0; i <= n; i++) {
        X[i] = x;
        x += h;
    }
    
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += f((X[i] + X[i + 1]) / 2);
    }

    delete [] X;

    return sum * h;
}

double getInterval_EPS (double a, double b, double n, double eps) {
    double i1, i2 = formulaOfAverages(a, b, n);
    do {
        i1 = i2;
        n *= 2;
        i2 = formulaOfAverages(a, b, n);
    } while (abs(i1 - i2) >= eps);
    
    return i2;
}

int main() {
    double a, b, eps, n;
    cout << "Введите начало предела интегрирования: ";
    cin >> a;
    cout << endl << "Введите конец предела интегрирования: ";
    cin >> b;
    cout << endl << "Введите eps: ";
    cin >> eps;
    cout << endl << "Введите n: ";
    cin >> n;
    
    cout << endl << "Значение интеграла по разбиению на " << n << ": " << formulaOfAverages(a, b, n) << endl;
    cout << "Значение интеграла по точности eps: " << getInterval_EPS(a, b, n, eps);
}