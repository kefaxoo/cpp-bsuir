#include <iostream>

using namespace std;

int main() {
    string str = "The quick brown fox jumps over the lazy dog.";
    char n;
    
    while (true) {
        cout << "Введите букву: ";
        cin >> n;

        if (n == '0')
            break;

        for (int i = 0; i < str.length(); i++)
            str[i] = str[i] == n ? '*' : str[i];

        cout << endl << str << endl;
    }
}