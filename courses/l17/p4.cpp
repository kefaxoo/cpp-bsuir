#include <iostream>
#include <fstream>

using namespace std;

int main() {
    const string fileName = "jewels.txt"; // Название файла
    const int N = 256; // Константный размер строки
    ifstream openFile(fileName); // Открытие файла для чтения
    int jewel[5] = { 0, 0, 0, 0, 0 };

    if (openFile.is_open()) { // Проверка на существование файла
        char S[N]= ""; // В S будут считываться строки
        while (!openFile.eof()) { // Чтение файла до конца
            openFile.getline(S,N); // Построчное считывание информации в S 
            for (int i = 0; i < N; i++) {
                switch (S[i]) {
                    case 'g':
                        jewel[0]++;
                        break;
                    case 'r':
                        jewel[1]++;
                        break;
                    case 'e':
                        jewel[2]++;
                        break;
                    case 'p':
                        jewel[3]++;
                        break;
                    case 'd':
                        jewel[4]++;
                        break;
                }
            }
        }
    }
    else
        cout << "Файла не существует!" << endl;

    openFile.close();  // Закрыть файл для чтения

    cout << "Гномы собрали драгоценности: " << endl;
    cout << "Золото: " << jewel[0] << endl;
    cout << "Рубины: " << jewel[1] << endl;
    cout << "Изумруды: " << jewel[2] << endl;
    cout << "Жемчуг: " << jewel[3] << endl;
    cout << "Алмазы: " << jewel[4] << endl;
}