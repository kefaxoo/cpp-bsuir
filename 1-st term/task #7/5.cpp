#include <iostream>

using namespace std;

int main() {
    string temp;
    cout << endl << "enter a line: ";
    getline(cin, temp);

    cout << temp;

    int tempLength = 0, tempCount = 0, count = 0;
    for (int i = 0; i < temp.length(); i++) {
        if (temp[i] != ' ') {
            tempLength++;
            if (temp[i] == '1')
                tempCount++;
        }
        else {
            if (tempLength % 2 == 1)
                count += tempCount;
            tempLength = 0;
            tempCount = 0;
        }

        if (i == temp.length() - 1) {
            if (tempLength % 2 == 1)
                count += tempCount;
            tempLength = 0;
            tempCount = 0;
        }
    }

        cout << endl << "count = " << count;
}