#include <iostream>

using namespace std;

void countOfBackSpace() {
    char a[256];
    cout << "Введите строку с клавиатуры (максимальный размер 256): ";
    cin.getline(a, 256);

    int count = 0;
    for (int i = 0; i < 256; i++) 
        if (a[i] == '\0')
                break;
            else if (a[i] == ' ')
                    count++;

    cout << endl << "Количество пробелов: " << count << endl;
}

int main() {
    countOfBackSpace();
}