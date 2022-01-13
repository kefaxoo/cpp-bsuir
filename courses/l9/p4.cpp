#include <iostream>

using namespace std;

int Sum() {
    int sum = 0;
    for (int i = 1; i <= 100; i++)
        sum += i;

    return sum;
}

int main() {
    cout << "Сумма чисел от 1 до 100: " << Sum() << endl;
}