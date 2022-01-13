#include <iostream>

using namespace std;

int main() {
    int begin, end;

    cout << "Введите начальный год: ";
    cin >> begin;
    cout << endl << "Введите конченый год: ";
    cin >> end;

    while (++begin <= end) {
        if (begin % 4 == 0) {
            if (begin % 100 == 0) {
                if (begin % 400 == 0)
                    continue;
                else
                    cout << begin << endl;
            }
            else
                continue;
        }
        else
            cout << begin << endl;
    }
}