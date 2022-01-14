#include <iostream>
#include <fstream>

using namespace std;

int main() {
    const string fileName = "1.txt";
    ofstream openFile(fileName);
    cout << "Ввод символов в файл (для завершения программы, введите z): ";
    while (true) {
        string a;
        getline(cin, a);
        for (int i = 0; i < a.length(); i++) {
            if (a[i] == 'z') {
                openFile.close();
                exit(0);
            }
            openFile << a[i];
        }
    }
}