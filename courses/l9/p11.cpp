#include <iostream>
#include <time.h>

using namespace std;

void Output (int array[], int size) { 
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
        cout << endl;
}

int Check(int array1[], int array2[], int size) {
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < size; i++) {
        sum1 += array1[i];
        sum2 += array2[i];
    }
    
    if (sum1 > sum2)
        return 1;
    else if (sum1 < sum2)
        return -1;
        else
            return 0;
}

int main() {
    srand(time(0));
    int size;

    cout << "Введите размер массива: ";
    cin >> size;

    int *array1 = new int[size], *array2 = new int[size], begin, end;

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

    for (int i = 0; i < size; i++) {
        array1[i] = rand() % (end - begin + 1) + begin;
        array2[i] = rand() % (end - begin + 1) + begin;
    }

    cout << endl << "Полученные массивы: " << endl;
    Output(array1, size);
    cout << endl;
    Output(array2, size);

    switch (Check(array1, array2, size)) {
        case -1:
            cout << endl << "Первый массив меньше второго" << endl;
            break;
        case 1:
            cout << endl << "Первый массив больше второго" << endl;
            break;        
        case 0:
            cout << endl << "Первый массив равен второму" << endl;
            break;
    }
}