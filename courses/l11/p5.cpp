#include <iostream>

using namespace std;

int main() {
    int array[10];
    for (int i = 0; i < sizeof(array)/sizeof(array[0]); i++) {
        cout << "&array[" << i << "] = " << array + i << endl;
    }
}