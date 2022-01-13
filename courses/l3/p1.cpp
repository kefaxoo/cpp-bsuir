#include <iostream>

using namespace std;

int main() {
    int menu;
    while (!(menu > 0 && menu < 3)) {
        cout << "Программа-конвертация" << endl;
        cout << "1) Перевод скорости из км/ч в м/с" << endl;
        cout << "2) Перевод температуру из Цельсия в Фаренгейта" << endl;
        cout << "Выбранный пункт: ";
        cin >> menu;
    }

    switch (menu) {
        case 1: {
            const float mPerS = 5./18.;
            double kmPerH;
            cout << endl << "Перевод скорости из км/ч в м/с" << endl;
            cout << "Введите скорость в км/ч: ";
            cin >> kmPerH;
            cout << endl << "Скорость в м/с: " << kmPerH * mPerS << endl;
        }
            break;
        case 2: {
            const double fahrenheitFirstPart = 9./5.;
            const int fahrenheitSecondPart = 32;
            double celsius;
            cout << endl << "Перевод температуру из Цельсия в Фаренгейта" << endl;
            cout << "Введите температуру в Цельсия: ";
            cin >> celsius;
            cout << endl << "Скорость в Фаренгейта: " << celsius * fahrenheitFirstPart + fahrenheitSecondPart << endl;
        }
    }
}