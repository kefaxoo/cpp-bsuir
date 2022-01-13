#include <iostream>

using namespace std;

int main() {
    string str = "The quick brown fox jumps over the lazy dog.";
    int n;
    
    cout << "Введите n: ";
    cin >> n;

    str[n] = '*';

    cout << endl << str << endl;
}