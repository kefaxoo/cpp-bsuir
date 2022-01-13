#include <iostream>

using namespace std;

int main() {
    int height, time;
    double jumpHeight;
    cout << "Введите рост кандидата (в см): ";
    cin >> height;
    cout << endl << "Введите время пробега (в с): ";
    cin >> time;
    cout << endl << "Введите высоту прыжка (в м): ";
    cin >> jumpHeight;

    if (height >= 170 && time <= 10 && jumpHeight >= 1.4)
        cout << endl << "Кандидат прошёл кастинг";
    else
        cout << endl << "Кандидат не прошёл кастинг";
}