#include <iostream>

using namespace std;

int main() {
    int a;
    cout << "Введите оценку: ";
    cin >> a;

    if (a > -1 && a < 3)
        cout << endl << "неудовлетворительно" << endl;
    else if (a > 2 && a < 5)
        cout << endl << "посредственно" << endl;
        else if (a > 4 && a < 7)
            cout << endl << "удовлетворительно" << endl;
            else if (a > 6 && a < 9)
                cout << endl << "хорошо" << endl;
                else if (a > 8 && a < 11)
                    cout << endl << "отлично" << endl;
                    else
                        cout << endl << "некорректная оценка" << endl;
}