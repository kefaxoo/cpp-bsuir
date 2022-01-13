#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Введите n: ";
    cin >> n;

    cout << endl;
    int i = 1;
    while (i++ <= n)
        cout << "*";
}