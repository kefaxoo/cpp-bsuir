// я понял, что третья функция через этот рандом не имеет смысла :)
#include <iostream>
#include <time.h>

using namespace std;

void Output(int **matrix, int sizeOfLine, int sizeOfColumn) {
    for (int i = 0; i < sizeOfColumn; i++) {
        for (int j = 0; j < sizeOfLine; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}

int Sum(int array[], int sizeOfLine) {
    int sum = 0;
    for (int i = 0; i < sizeOfLine; i++)
        sum += array[i];

    return sum;
}

int SumOfMainDiagonal(int **matrix, int sizeOfColumn) {
    int sum = 0;
    for (int i = 0; i < sizeOfColumn; i++)
        sum += matrix[i][i];

    return sum;
}

bool Check(int number) { 
    return number >= 0 ? true : false;
}

int main() {
    srand(time(0));
    int sizeOfLine, sizeOfColumn;

    cout << "Введите размер строки: ";
    cin >> sizeOfLine;

    cout << endl << "Введите размер столбца: ";
    cin >> sizeOfColumn;

    int **matrix = new int *[sizeOfColumn];
    for (int i = 0; i < sizeOfColumn; i++)
        matrix[i] = new int [sizeOfLine];

    int begin, end;

    while (true) {
        cout << endl << "Введите начало промежутка: ";
        cin >> begin;
        if (begin >= 0)
            break;
    }

    while (true) {
        cout << endl << "Введите конец промежутка: ";
        cin >> end;
        if (end >= 0)
            break;
    }

    // проверка, если границы промежутка введены неверно
    if (begin > end) {
        int temp = begin;
        begin  = end;
        end = temp;
    }

    for (int i = 0; i < sizeOfColumn; i++)
        for (int j = 0; j < sizeOfLine; j++)
            matrix[i][j] = rand() % (end - begin + 1) + begin;

    cout << endl << "Полученная матрица: " << endl;
    Output(matrix, sizeOfLine, sizeOfColumn);
    
    int menu;
    while (true) {
        cout << endl << "Выберите функцию: " << endl;
        cout << "1) Сумма i строки" << endl;
        cout << "2) Сумма главной диагонали" << endl;
        cout << "3) Проверка на положительность элемента матрицы" << endl;
        cout << "Ваш выбор: ";
        cin >> menu;

        if (menu > 0 && menu < 4)
            break;
    }

    switch (menu) {
        case 1:  {
            int i;
            cout << endl << "Введите номер строки: ";
            cin >> i;
            cout << endl << "Сумма " << i << " строки: " << Sum(matrix[i], sizeOfLine) << endl;
        }
            break;
        case 2:
            if (sizeOfLine == sizeOfColumn)
                cout << endl << "Сумма главной диагонали: " << SumOfMainDiagonal(matrix, sizeOfColumn) << endl;
            else
                cout << "Данная функция не может быть выполнена, так как матрица не квадртаная" << endl;
            break;
        case 3: {
            int i, j;
            cout << endl << "Введите i: ";
            cin >> i;
            cout << endl << "Введите j: ";
            cin >> j;

            if(Check(matrix[i][j]))
                cout << endl << matrix[i][j] << " не отрицательное" << endl;
            else
                cout << endl << matrix[i][j] << " отрицательное" << endl;
        }
            break;
    }
}