#include <iostream>

using namespace std;

int main() {
    int a;
    while (!(a > 0 && a < 101)) {
        cout << "Введите номер билета: ";
        cin >> a;
    }

    switch (a) {
        case 12:
            cout << endl << "поездка на море" << endl;
            break;
        case 45:
            cout << endl << "главный приз" << endl;
            break;
        case 10:
        case 20:
        case 40:
            cout << endl << "ещё один лотерейный билет" << endl;
            break;
        case 34:
        case 47:
        case 59:
            cout << endl << "тысяча рублей" << endl;
            break;
        default:
            cout << endl << "попробуйте ещё раз" << endl;
    }
}