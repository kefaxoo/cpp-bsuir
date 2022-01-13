#include <iostream>

using namespace std;

int main() {
    int sum = 0;

    int i = 100;
    do {
        sum += i;
        i += 3;
    } while (i < 200);

    cout << sum << endl;
}