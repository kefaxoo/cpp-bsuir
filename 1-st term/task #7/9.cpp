#include <iostream>

using namespace std;

int main() {
    string str;

    cout << "enter a line: ";
    getline(cin, str);

    int count = 1;
    for (int i = 0; i < str.length(); i++)
        if (str[i] == ' ')
            count++;

    string *sortNumbers = new string[count];
    count = 0;
    for (int i = 0; i < str.length(); i++)
        if (str[i] == ' ')
            count++;
        else
            sortNumbers[count] += str[i];

    for (int i = 0; i < count; i++)
        for (int j = i; j < count + 1; j++)
            if (sortNumbers[i][0] > sortNumbers[j][0]) {
                string temp = sortNumbers[i];
                sortNumbers[i] = sortNumbers[j];
                sortNumbers[j] = temp;
            }

    cout << endl << "sort: " << endl;
    for (int i = 0; i < count + 1; i++)
        cout << sortNumbers[i] << endl;
}