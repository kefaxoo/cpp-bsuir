#include <iostream>

using namespace std;

int main() {
    int x, y;
    cout << "Введите первое число: ";
    cin >> x;
    cout << endl << "Введите второе число: ";
    cin >> y;

    if (x > 2 && y > 3)
        cout << endl << "Бинго 1";
    if (x >= 5 && y == 10)
        cout << endl << "Бинго 2";
    if (x > 3 && y < -3)
        cout << endl << "Бинго 3";
    if (x > 0 && y > 0)
        cout << endl << "Бинго 4";
    if (x == 1 || y == 1)
        cout << endl << "Бинго 5";
    if (x != 0 || y != 0)
        cout << endl << "Бинго 6";
}