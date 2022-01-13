#include <iostream>

using namespace std;

void Sum() {
    int sum = 0;
    for (int i = 1; i <= 100; i++)
        sum += i;

    cout << "Сумма от 1 до 100 = " << sum << endl;
}

int main() {
    Sum();
}