#include <iostream>
#include <math.h>

using namespace std;

int main() {
    double y, x, z;

    cout << "x: ";
    cin >> x;
    cout << endl << "y: ";
    cin >> y;
    cout << endl << "z: ";
    cin >> z;

    cout << "formula: " << endl << "alpha = ln(y^-sqrt(abs(x))) * (x - y/2) + sin^2(arctg(z))" << endl;
    cout << "alpha = " << log(pow(y, -sqrt(abs(x)))) * (x - y / 2) + pow(sin(atan(z)), 2);
}