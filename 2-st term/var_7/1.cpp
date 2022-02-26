#include <iostream>

using namespace std;

double recursion(double x, int a, int n, int i = 0) {
    if (i != n)
        return recursion(0.5 * (x + a / x), a, n, i + 1);

    return x;
}

int main() {
    int a;
    cout << "Введите a: ";
    cin >> a;
    int n;
    cout << endl << "Введите n: ";
    cin >> n;
    double x = recursion(0.5 * (1 + a), a, n);
    cout << endl << "recursion: x = " << x << endl;
    x = 0.5 * (1 + a);
    for (int i = 1; i <= n; i++)
        x = 0.5 * (x + a / x);
    cout << endl << "loop: x = " << x << endl;
}