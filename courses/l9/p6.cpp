#include <iostream>
#include <time.h>

using namespace std;

void Output (int array[], int size) { 
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
        cout << endl;
}

int Max (int array[], int size) {
    int max = INT_MIN;
    for (int i = 0; i < size; i++)
        max = max < array[i] ? array[i] : max;
    
    return max;
}

int *Replace (int array[], int size, int replace) {
    for (int i = 0; i < size; i++)
        array[i] = array[i] == replace ? 0 : array[i];

    return array;
}

void Output2 (int array[], int size) {
    int indexMax = 0, indexMin = 0;

    for (int i = 0; i < size; i++) {
        indexMax = array[i] > array[indexMax] ? i : indexMax;
        indexMin = array[i] < array[indexMin] ? i : indexMin;
    }

    if (indexMin > indexMax) {
        cout << "Элементы, расположенные между максимальным и минимальным элементами: ";
        for (int i = indexMax + 1; i < indexMin; i++)
            cout << array[i] << " ";
    }
    else {
        cout << "Элементы, расположенные между минимальным и максимальным элементами: ";
        for (int i = indexMin + 1; i < indexMax; i++)
            cout << array[i] << " ";
    }
}

bool Similars (int array[], int size) {
    for (int i = 0; i < size - 1; i++)
        for (int j = i + 1; j < size; j++)
            if (array[i] == array[j])
                return true;

    return false;
}

void Sort (int array[], int size, bool way) {
    if (way) {
        for (int i = 0; i < size - 1; i++)
            for (int j = i; j < size; j++)
                if (array[i] > array[j])
                    swap(array[i], array[j]);
    }
    else {
        for (int i = 0; i < size - 1; i++)
            for (int j = i; j < size; j++)
                if (array[i] < array[j])
                    swap(array[i], array[j]);
    }

    Output(array, size);
}

int main() {
    srand(time(0));
    int size;

    cout << "Введите размер массива: ";
    cin >> size;

    int *array = new int[size], begin, end;

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

    for (int i = 0; i < size; i++)
        array[i] = rand() % (end - begin + 1) + begin;

    cout << endl << "Полученный массив: " << endl;
    Output(array, size);

    int menu;
    while (true) {
        cout << endl << "Выберите функцию: " << endl;
        cout << "1) Максимальный элемент в массиве" << endl;
        cout << "2) Замена чисел на 0" << endl;
        cout << "3) Вывод элементов, расположенных между максимальным и минимальным элементами" << endl;
        cout << "4) Нахождение повторяющихся значений" << endl;
        cout << "5) Сортировка массива" << endl;
        cout << "Ваш выбор: ";
        cin >> menu;

        if (menu > 0 && menu < 6)
            break;
    }

    switch (menu) {
        case 1: 
            cout << endl << "Максимальный элемент в массиве: " << Max(array, size) << endl;
            break;
        case 2: {
            int a;
            cout << endl << "Введите число: ";
            cin >> a;
            
            array = Replace(array, size, a);
            cout << endl << "Массив с заменой: ";
            for (int i = 0; i < size; i++)
                cout << array[i] << " ";
            cout << endl;
        }
            break;
        case 3:
            Output2(array, size);
            break;
        case 4:
            if (Similars(array, size))
                cout << endl << "В массиве есть повторяющиеся значения" << endl;
            else
                cout << endl << "В массиве нет повторяющиеся значения" << endl;
            break;
        case 5: {
            bool way;
            
            while (true) {
                cout << endl << "1 - сортировка по возрастанию" << endl;
                cout << "0 - сортировка по убыванию" << endl;
                cin >> way;
                if (way || !way)
                    break;
            }

            Sort(array, size, way);
        }
            break;
    }

    delete []array;
}