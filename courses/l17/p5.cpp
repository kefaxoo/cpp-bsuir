#include <iostream>
#include <fstream>

using namespace std;

int main() {
    const string fileName = "sklad.txt"; // Название файла
    const int N = 256; // Константный размер строки
    ifstream openFile(fileName); // Открытие файла для чтения
    string temp;

    if (openFile.is_open()) { // Проверка на существование файла
        char S[N]= ""; // В S будут считываться строки
        while (!openFile.eof()) { // Чтение файла до конца
            openFile.getline(S,N); // Построчное считывание информации в S 
            temp += S;
            temp += ' ';
        }
    }
    else
        cout << "Файла не существует!" << endl;

    openFile.close();  // Закрыть файл для чтения

    int count = 0;
    for (int i = 0; i < temp.length(); i++)
        if (temp[i] == ' ')
            count++;

    string *lines = new string[count];
    int *prices = new int[count];
    for (int i = 0; i < count; i++)
        prices[i] = 0;

    count = 0;
    cout << temp << endl;
    for (int i = 0; i < temp.length(); i++)
        if (temp[i] != ' ') {
            lines[count] += temp[i];
            switch (temp[i]) {
                case 'g':
                    prices[count] += 1;
                    break;
                case 'G':
                    prices[count] += 5;
                    break;
                case 'p':
                    prices[count] += 5;
                    break;
                case 'P':
                    prices[count] += 10;
                    break;
                case 'r':
                    prices[count] += 20;
                    break;
                case 'R':
                    prices[count] += 50;
                    break;
                case 'e':
                    prices[count] += 40;
                    break;
                case 'E':
                    prices[count] += 80;
                    break;
                case 'd':
                    prices[count] += 100;
                    break;
                case 'D':
                    prices[count] += 500;
                    break;
            }
        }
        else
            count++;

    for (int i = 0; i < count - 1; i++)
        for (int j = i; j < count; j++)
            if (prices[i] < prices[j]) {
                swap(prices[i], prices[j]);
                swap(lines[i], lines[j]);
            }

    for (int i = 0; i < count; i++)
        cout << i + 1 << " " << lines[i] << " - " << prices[i] << endl;
}