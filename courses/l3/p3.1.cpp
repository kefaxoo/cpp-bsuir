#include <iostream>
#include <math.h>

using namespace std;

int main() {
    double alpha, z1, z2;
    cout << "Введите alpha: ";
    cin >> alpha;
    z1 = cos(alpha) + sin(alpha) + cos(3 * alpha) + sin(3 * alpha);
    z2 = 2 * sqrt(2) * cos(alpha) * sin(M_PI / 4 + 2 * alpha);

    cout << "alpha = " << alpha << " | z1 = " << z1 << " | z2 = " << z2 << endl;
}