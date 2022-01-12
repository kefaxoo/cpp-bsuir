#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int alpha;
    cout << "Введите угол в градусах: ";
    cin >> alpha;
    cout << endl << "Угол в радианах: " << (alpha * M_PI) / 180 << endl;
}