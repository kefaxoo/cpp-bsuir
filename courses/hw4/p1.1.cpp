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

    if (height >= 170)
        if (time <= 10)
            if (jumpHeight >= 1.4) {
                cout << endl << "Кандидат прошёл кастинг";
                exit(0);
            }

    cout << endl << "Кандидат не прошёл кастинг";
}