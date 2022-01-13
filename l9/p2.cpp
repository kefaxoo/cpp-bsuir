#include <iostream>

using namespace std;

int Sum(int a, int b) {
    return a + b;
}

int main() {
    int a, b;
    cout << "Введите первое число: ";
    cin >> a;
    cout << endl << "Введите второе число: ";
    cin >> b;

    cout << endl << "Сумма " << a << " и " << b << " = " << Sum(a, b) << endl;
}