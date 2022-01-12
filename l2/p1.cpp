#include <iostream>

using namespace std;

int main() {
    cout << "Изучение типов данных и операторов ввода-вывода" << endl;
    int x, y;
    cout << "Введите переменную x: ";
    cin >> x;
    cout << endl << "Введите переменную y: ";
    cin >> y;
    int sum = x + y;
    cout << endl << "Сумма переменных x и y равна " << sum << endl << x << " * " << y << " = " << x * y << endl;
}