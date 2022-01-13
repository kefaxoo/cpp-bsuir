#include <iostream>

using namespace std;

int main() {
    int n;

    cout << "Введите n: ";
    cin >> n;

    if (n < 2) {
        cout << endl << 0 << endl;
        exit(0);
    }

    int i = 2, sum = 0;

    for (int i = 2; i <= n; i += 2)
        sum += i;

    cout << endl << sum << endl;
}