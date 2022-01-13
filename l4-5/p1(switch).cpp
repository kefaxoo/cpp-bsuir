#include <iostream>

using namespace std;

int main() {
    int a;
    cout << "Введите оценку: ";
    cin >> a;

    switch (a) {
        case 0:
        case 1:
        case 2:
            cout << endl << "неудовлетворительно" << endl;
            break;
        case 3:
        case 4:
            cout << endl << "посредственно" << endl;
            break;
        case 5:
        case 6:
            cout << endl << "удовлетворительно" << endl;
            break;
        case 7:
        case 8:
            cout << endl << "хорошо" << endl;
            break;
        case 9:
        case 10:
            cout << endl << "отлично" << endl;
            break;
        default:
            cout << endl << "некорректная оценка" << endl;
    }
}