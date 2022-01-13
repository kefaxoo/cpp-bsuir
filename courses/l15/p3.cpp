#include <iostream>

using namespace std;

struct pupil {
    string name;
    double average;
};

int main() {
    pupil Class [5];
    double sum = 0;
    int maxIndex = 0;
    for (int i = 0; i < 5; i++) {
        cout << endl << "Введите имя " << i + 1 << " ученика: ";
        cin >> Class[i].name;
        cout << endl << "Введите его/её средний балл: ";
        cin >> Class[i].average;
        sum += Class[i].average;
        maxIndex = Class[i].average > Class[maxIndex].average ? i : maxIndex;
    }

    sum /= 5;

    cout << endl << "Средний балл класса: " << sum << endl;
    cout << "Ученик | Средний балл" << endl;
    for (int i = 0; i < 5; i++) {
        cout << Class[i].name << " | " <<  Class[i].average;
        if (Class[i].average == Class[maxIndex].average)
            cout << " Наивысший средний балл";
        cout << endl;
    }
}