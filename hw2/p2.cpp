#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int m, n;
    cout << "Введите m: ";
    cin >> m;
    cout << endl << "Введите n: ";
    cin >> n;

    cout << endl << "formula: " << "z1 = ((m-1)sqrt(m)-(n-1)sqrt(n))/(sqrt(m^3)+nm+m^2-m)" << endl;
    cout << "z1 = " << ((m - 1) * sqrt(m) - (n - 1) * sqrt(n))/(sqrt(pow(m, 3)) + n * m + pow(m, 2) - m) << endl;
    cout << "formula: " << "z2 = (sqrt(m) - sqrt(n))/m" << endl;
    cout << "z2 = " << (sqrt(m) - sqrt(n))/m << endl;
}