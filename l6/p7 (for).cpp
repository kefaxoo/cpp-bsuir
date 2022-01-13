#include <iostream>

using namespace std;

int main() {
    int begin, end;

    cout << "Введите начальный год: ";
    cin >> begin;
    cout << endl << "Введите конченый год: ";
    cin >> end;

    for (int i = begin; i <= end; i++) {
        if (i % 4 == 0) {
            if (i % 100 == 0) {
                if (i % 400 == 0)
                    continue;
                else
                    cout << i << endl;
            }
            else
                continue;
        }
        else
            cout << i << endl;
    }
}