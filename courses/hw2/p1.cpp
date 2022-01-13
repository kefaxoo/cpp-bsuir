#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int alpha;
    cout << "Введите alpha в градусах: ";
    cin >> alpha;

    cout << endl << "formula: " << "z1 = 2sin^2(3pi - 2alpha)cos^2(5pi + 2alpha)" << endl;
    cout << "z1 = " << 2 * pow(sin(3 * M_PI - 2 * (alpha * M_PI / 180)), 2) * pow(cos(5 * M_PI + 2 * (alpha * M_PI / 180)), 2) << endl;
    cout << "formula: " << "z2 = 1/4 - 1/4*sin(5/2*pi - 8alpha)" << endl;
    cout << "z2 = " << 1/4 - (1/4) * sin((5/2)*M_PI - 8 * (alpha * M_PI / 180)) << endl;
}