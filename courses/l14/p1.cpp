#include <iostream>
#include <time.h>

using namespace std;

void Output(int *array, int size) {
    cout << endl;
    for (int i = 0; i < size; i++)
        cout << i + 1 << " | " << array[i] << endl;
}

int Max(int *array, int size) {
    int max = INT_MIN;
    for (int i = 0; i < size; i++)
        max = array[i] > max ? array[i] : max;

    return max;
}

int Sum(int *array, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += array[i];

    return sum;
}

int *Replace (int *array, int size) {
    int n, i;
    cout << "Введите n: ";
    cin >> n;
    cout << endl << "Выберите элемент из списка: " << endl;;
    Output(array, size);
    while (true) {
        cout << "Ваш выбор: ";
        cin >> i;
        if (i >= 0 && i < size)
            break;
    }
    array[i] = n;
    return array;
}

int *Fill (int *array, int size) {
    int menuFunction;
    while (true) {
        cout << endl << "Выберите способ заполнения массива: " << endl;
        cout << "1) Ручной ввод" << endl;
        cout << "2) Случайное заполнение" << endl;
        cout << "Ваш выбор: ";
        cin >> menuFunction;

        if (menuFunction > 0 && menuFunction < 3)
            break;
    }

    switch (menuFunction) {
        case 1:
            for (int i = 0; i < size; i++) {
                cout << endl << "Введите " << i + 1 << " элемент массива: ";
                cin >> array[i];
            }
            break;
        case 2: {
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

            for (int i = 0; i < size; i++)
                array[i] = rand() % (end - begin + 1) + begin;
        }
    }

    return array;
}

int *Sort (int *array, int size) {
    int menu;
    while (true) {
        cout << endl << "Выберите сортировку: " << endl;
        cout << "1) По возрастанию" << endl;
        cout << "2) По убыванию" << endl;
        cout << "Ваш выбор: ";
        cin >> menu;

        if (menu > 0 && menu < 3)
            break;
    }

    switch (menu) {
        case 1:
            for (int i = 0; i < size - 1; i++)
                for (int j = i; j < size; j++)
                    if (array[i] > array[j])
                        swap(array[i], array[j]);
            break;
        case 2:
            for (int i = 0; i < size - 1; i++)
                for (int j = i; j < size; j++)
                    if (array[i] < array[j])
                        swap(array[i], array[j]);
    }

    return array;
}

int main() {
    srand(time(0));
    int size, *array;
    while (true) {
        int menu;
        cout << "Главное меню: " << endl;
        cout << "1) Создать массив" << endl;
        cout << "2) Заполнить массив" << endl;
        cout << "3) Вывести массив" << endl;
        cout << "4) Найти максимум" << endl;
        cout << "5) Найти сумму" << endl;
        cout << "6) Заменить элемент" << endl;
        cout << "7) Сортировать" << endl << endl;
        cout << "0) Выход" << endl;
        cout << "Ваш выбор: ";
        cin >> menu;

        bool breakvar = false;
        switch (menu) {
            case 0:
                breakvar = true;
                break;
            case 1: {
                cout << endl << "Введите размер массива: ";
                cin >> size;

                array = new int[size];
            }
                break;
            case 2:
                array = Fill(array, size);
                break;
            case 3:
                Output(array, size);
                break;
            case 4:
                cout << endl << "Максимальный элемент массива: " << Max(array, size) << endl;
                break;
            case 5:
                cout << endl << "Сумма всех элементов массива: " << Sum(array, size) << endl;
                break;
            case 6:
                array = Replace(array, size);
                break;
            case 7:
                array = Sort(array, size);
                break;
            default:
                cout << endl << "Введён неправильный номер пункта. Попробуйте ещё раз!" << endl;
        }

        if (breakvar)
            break;
    }
}