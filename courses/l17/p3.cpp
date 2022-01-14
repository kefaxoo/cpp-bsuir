#include <iostream>
#include <fstream>

using namespace std;

int main() {
    const string fileName = "2.txt"; // Название файла
    const int N = 256; // Константный размер строки
    ifstream openFile(fileName); // Открытие файла для чтения
    int sum = 0;

    if (openFile.is_open()) { // Проверка на существование файла
        char S[N]= ""; // В S будут считываться строки
        while (!openFile.eof()) { // Чтение файла до конца
            openFile.getline(S,N); // Построчное считывание информации в S 
            sum += atoi(S);
        }
    }
    else
        cout << "Файла не существует!" << endl;

    openFile.close();  // Закрыть файл для чтения

    cout << "Сумма: " << sum << endl;
}