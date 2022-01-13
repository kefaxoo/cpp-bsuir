#include <iostream>

using namespace std;

int main() {
    char line[100];
    cout << "Введите строку (размер до 100 символов): ";
    cin.getline(line, 100);

    for (int i = 0; i < 100; i++)
        if (line[i] == ' ')
            cout << (void *)&line[i] << endl;
}