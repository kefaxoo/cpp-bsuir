#include <iostream>

using namespace std;

int main() {
    char a;
    cout << "Введите символ: ";
    cin >> a;

    switch (a) {
        case 'y':
        case 'Y':
        case 'd':
        case 'D':
            cout << endl << "да" << endl;
            break;
        case 'n':
        case 'N':
            cout << endl << "нет" << endl;
            break;
        case '?':
            cout << endl << "не знаю" << endl;
            break;
        default:
            cout << endl << "некорректный символ" << endl;
    }
}