#include <iostream>

using namespace std;

int Sum(int sum) {
    int a;
    cout << endl << "Введите число: ";
    cin >> a;
    if (a != 0)
        return Sum(sum + a);
    else
        return sum;
}

int main() {
    cout << "Сумма целых чисел: " << endl;
    cout << "Чтобы выйти введите 0" << endl;
    int sum = Sum(0);
    cout << "Cумма: " << sum << endl;
}