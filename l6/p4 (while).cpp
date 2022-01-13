#include <iostream>

using namespace std;

int main() {
    int sum = 0;

    int i = 100;
    while (i < 200) {
        sum += i;
        i += 3;
    }

    cout << sum << endl;
}