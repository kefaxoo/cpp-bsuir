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

    cout << "b = " << pow(y, pow(abs(x), (1./3.))) + pow(cos(y), 3)*((abs(x - y) * (1 + (pow(sin(z), 2) / sqrt(x + y))))/(pow(exp(1), abs(x - y)) + (x / 2)));
}