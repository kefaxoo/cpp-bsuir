#include <iostream>

using namespace std;

char *ToUpper(char a[]) {
    for (int i = 0; i < 256; i++)
        a[i] = toupper(a[i]);
    
    return a;
}

int main() {
    char a[256];
    cout << "Введите строку с клавиатуры (максимальный размер 256): ";
    cin.getline(a, 256);

    printf("%s", ToUpper(a));
}