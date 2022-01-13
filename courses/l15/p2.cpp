#include <iostream>
#include <ctime>

using namespace std;

struct date {
    int day;
    int month;
    int year;
};

int main() {
    struct date date;
    cout << "Введите день рождения: ";
    cin >> date.day;
    cout << endl << "Введите месяц рождения: ";
    cin >> date.month;
    cout << endl << "Введите год рождения: ";
    cin >> date.year;

    switch (date.month) {
        case 1:
        case 2:
        case 12:
            cout << endl << "Человек родился зимой" << endl;
            break;
        case 3:
        case 4:
        case 5:
            cout << endl << "Человек родился весной" << endl;
            break;
        case 6:
        case 7:
        case 8:
            cout << endl << "Человек родился летом" << endl;
            break;
        case 9:
        case 10:
        case 11:
            cout << endl << "Человек родился осенью" << endl;
            break;
    }

    time_t now = time(0);
    tm *timeInUnix = localtime(&now);

    cout << "Человеку в этом году исполнится/исполнилось: " << 1900 + timeInUnix->tm_year - date.year;
}