#include <iostream>
#include <cmath>

using namespace std;

double recursion(double x, int a) {
    if (x != sqrt(a))
        return recursion(0.5 * (x + a / x), a);

    return x;
}

double func (int a, int n) {
    double x = 0.5 * (1 + a);
    for (int i = 0; i <= n; i++)
        x = 0.5 * (x + a / x);

    return x;
}

int main() {
    int a;
    cout << "Введите a: ";
    cin >> a;
    int n;
    cout << endl << "Введите n: ";
    cin >> n;
    cout << endl << "recursion: x = " << recursion(0.5 * (1 + a), a) << endl;
    cout << endl << "loop: x = " << func(a, n) << endl;
}