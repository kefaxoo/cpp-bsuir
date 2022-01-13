#include <iostream>

using namespace std;

int main() {
    char a[256];
    cout << "Введите строку с клавиатуры (максимальный размер 256): ";
    cin.getline(a, 256);
    
    for (int i = 0; i < 256; i++)
        if (a[i] == '\0')
            break;
        else if (a[i] == ' ')
                cout << endl;
            else
                cout << a[i];
}