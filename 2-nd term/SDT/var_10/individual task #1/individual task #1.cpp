/* Задание (вариант 10):
Динамически создать массив размера n (n вводится с клавиатуры) и
заполнить его случайными числами из диапазона [a, b] (a, b вводятся
с клавиатуры). Заполнение массива, вывод элементов массива на экран
реализовать с помощью функций. Удалить из массива все четные элементы
с помощью функции. Дополнительных массивов не использовать. */
#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

int getSize() {
    while (true) {
        int size;
        cout << "Введите размер: ";
        cin >> size;
        if (size > 0)
            return size;
        else
            cout << endl << "Введён недопустимый размер, попробуйте ещё раз" << endl;
    }
}

void getInterval (int &left, int &right) {
    cout << endl << "Введите начало промежутка рандома: ";
    cin >> left;
    cout << endl << "Введите конец промежутка рандома: ";
    cin >> right;
    if (left > right)
        swap(left, right);
}

int random (int left, int right) {
    return rand() % (right - left + 1) + left;
}

void fillArray (int *array, int size) {
    int left;
    int right;
    getInterval(left, right);
    for (int i = 0; i < size; i++) {
        if (left >= 0)
            *(array + i) = random(left, right);
        else if (right < 0)
            *(array + i) = -random(abs(right), abs(left));
        else {
            if (rand() % 2)
                *(array + i) = random(0, right);
            else
                *(array + i) = -random(0, abs(left));
        }
    }
}

int *resize (int *array, int &size) {
    int count = 0;
    for (int i = 0; i < size; i++)
        count = *(array + i) % 2 == 0 ? count + 1 : count;

    size -= count;
    int *temp = new int[size];
    int j = 0;
    for (int i = 0; i < size + count; i++)
        if (*(array + i) % 2 != 0)
            *(temp + j++) = *(array + i);

    swap(temp, array);
    delete [] temp;
    return array;
}

void output(int *array, int size) {
    for (int i = 0; i < size; i++)
        cout << *(array + i) << " ";
}

void cleanMemory(int *array) {
    delete [] array;
}

int main() {
    srand(time(0));
    setlocale(LC_ALL, "RUSSIAN");
    int size = getSize();
    int *array = new int[size];
    fillArray(array, size);
    cout << endl << "Полученный массив" << endl;
    output(array, size);
    array = resize(array, size);
    cout << endl << "Массив без чётных элементов" << endl;
    output(array, size);
    cleanMemory(array);
}