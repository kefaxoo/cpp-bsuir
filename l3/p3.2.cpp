#include <iostream>
#include <math.h>

using namespace std;

int main() {
    double b, z1, z2;
    cout << "Введите b: ";
    cin >> b;
    z1 = sqrt(2 * b + 2 * sqrt(pow(b, 2) - 4))/(sqrt(pow(b, 2) - 4) + b + 2);
    z2 = 1 / sqrt(b + 2);

    cout << "b = " << b << " | z1 = " << z1 << " | z2 = " << z2 << endl;
}