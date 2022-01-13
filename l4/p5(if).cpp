#include <iostream>

using namespace std;

int main() {
    char a;
    cout << "Введите символ: ";
    cin >> a;

    if (a == 'y' || a == 'Y' || a == 'd' || a == 'D')
        cout << endl << "да" << endl;
    else if (a == 'n' || a == 'N')
            cout << endl << "нет" << endl;
        else if (a == '?')
            cout << endl << "не знаю" << endl;
            else
                cout << endl << "некорректный символ" << endl;
}