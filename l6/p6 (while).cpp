#include <iostream>

using namespace std;

int main() {
    int n, sum = 0;
    while (n != 0) {
        cout << endl << "Введите 0, чтобы выйти из цикла";
        cout << endl << "Введите n: ";
        cin >> n;
        if (n < 0)
            sum += n;
    }

    cout << endl << sum << endl;
}