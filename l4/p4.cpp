#include <iostream>

using namespace std;

int main() {
    double x, y;
    cout << "Введите координату по x: ";
    cin >> x;
    cout << endl << "Введите координату по y: ";
    cin >> y;

    if (x <= -2 && y >= 1)
        cout << endl << "true 1";
    if (y >= -2 && y <= 1.5)
        cout << endl << "true 2";
    if ((x >= 2 && y >= 0) || (x >= 1 && y <= -1))
        cout << endl << "true 3";
    if (x >= 1 && y >= 2 && y <= 4)
        cout << endl << "true 4";
    if (x >= 2 && (y >= 1 || y <= -1.5))
        cout << endl << "true 5";
    if (x >= 1 && x <= 3 && y >= -2 && y <= -1)
        cout << endl << "true 6";
    if (x <= 2 && y >= 0.5 && y <= 1.5 || x >= 2)
        cout << endl << "true 7";
}