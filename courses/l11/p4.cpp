#include <iostream>>

using namespace std;

int main() {
    setlocale(LC_ALL, "RUSSIAN");
    string str = "Лермонтов Михаил Юрьевич", result = "";
    bool backspace = false, letter = true;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ' ') {
            backspace = true;
            result += str[i];
            letter = false;
        }
        if (str[i] != ' ' && !backspace)
            result += str[i];
        else if (str[i] != ' ' && backspace && !letter) {
            result += str[i];
            result += '.';
            letter = true;
        }
    }
    cout << endl << result << endl;
}