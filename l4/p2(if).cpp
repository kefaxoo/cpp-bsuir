#include <iostream>

using namespace std;

int main() {
    int a;
    while (!(a > 0 && a < 101)) {
        cout << "Введите номер билета: ";
        cin >> a;
    }

    if (a == 12)
        cout << endl << "поездка на море" << endl;
    else if (a == 45)
        cout << endl << "главный приз" << endl;
        else if (a == 10 || a == 20 || a == 40)
            cout << endl << "ещё один лотерейный билет" << endl;
            else if (a == 34 || a == 47 || a == 59)
                cout << endl << "тысяча рублей" << endl;
                else
                    cout << endl << "попробуйте ещё раз" << endl;
}