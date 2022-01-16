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

    string *sortWords = new string[count];
    count = 0;
    for (int i = 0; i < str.length(); i++)
        if (str[i] == ' ')
            count++;
        else
            sortWords[count] += str[i];

    for (int i = 0; i < count; i++)
        for (int j = i; j < count + 1; j++)
            if (sortWords[i][0] > sortWords[j][0]) {
                string temp = sortWords[i];
                sortWords[i] = sortWords[j];
                sortWords[j] = temp;
            }

    cout << endl << "sort: " << endl;
    for (int i = 0; i < count + 1; i++)
        cout << sortWords[i] << endl;
}