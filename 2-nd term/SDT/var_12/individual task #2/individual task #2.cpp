/* Задание (вариант 12):
Динамически создать массив размера n (n вводится с клавиатуры) и заполнить его случайными числами из диапазона [a, b] (a, b вводятся с клавиатуры). Заполнение массива, вывод
элементов массива на экран реализовать с помощью функций.Вычислить произведение элементов массива, расположенных между максимальным и минимальным элементами, с помощью функций.
*/

#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

int input_int() { // функция корректного ввода значений типа int
    while (true) { // бесконечный цикл
        int temp; // временная переменная
        cin >> temp;
        if (cin.good()) // если введённые значения правильны
            return temp; // возвращаем их
        else {
            cin.clear(); // иначе сбрасываем флаги ошибок
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // очистка потока
            cout << endl << "Переменная введена неправильно, попробуйте ещё раз: ";
        }
    }
}

int get_size() { // функция ввода размера массива
    while (true) { // бесконечный цикл
        int size;
        cout << "Введите размер: ";
        size = input_int();
        if (size > 0) // проверка, чтобы размерность была допустимой
            return size;
        else
            cout << endl << "Введён недопустимый размер, попробуйте ещё раз" << endl;
    }
}

void get_interval(int& left, int& right) { // функция ввода промежутка рандома
    cout << endl << "Введите начало промежутка рандома: ";
    left = input_int();
    cout << endl << "Введите конец промежутка рандома: ";
    right = input_int();
    if (left > right) // проверка, если пользователь ввёл неправильные границы (левая больше правой)
        swap(left, right);
}

int random(const int left, const int right) { // функция получения рандомного значения в промежутке [left; right]
    return rand() % (right - left + 1) + left;
}

void fill_array(int* array, const int size) { // функция заполнения массива
    int left;
    int right;
    get_interval(left, right);
    for (int i = 0; i < size; i++) {
        // так как C++ предоставляет рандом от 0 до максимального значения типа переменной, то нам надо рассмотреть случай с отрицательными границами
        if (left >= 0) // если начало больше нуля => весь промежуток больше нуля
            *(array + i) = random(left, right);
        else if (right < 0) // если конец меньше нуля => весь промежуток меньше нуля
            *(array + i) = -random(abs(right), abs(left)); // чтобы получить значение из этого промежутка, мы отправляем границы наоборот и полученное значение делаем со знаком минус
        else { // если промежуток от - до +
            if (rand() % 2) // получаем рандомное значение 1 или 0
                *(array + i) = random(0, right); // если 1, то мы получаем рандомное значение в + части промежутка
            else
                *(array + i) = -random(0, abs(left)); // если 0, то мы получаем рандомное значение в - части промежутка
        }
    }
}

int find_multiplication(int *array, const int size) {
    int minIndex = 0; // переменная индекса минимального элемента
    int maxIndex = 0; // переменная индекса максимального элемента
    for (int i = 0; i < size; i++) { // поиск индексов
        minIndex = *(array + minIndex) > *(array + i) ? i : minIndex; // тернарная операция
        maxIndex = *(array + maxIndex) < *(array + i) ? i : maxIndex;
    }

    int multiplication = 1; // переменная произведения
    for (int i = minIndex; i <= maxIndex; i++)
        multiplication *= *(array + i);

    return multiplication; // возвращаем произведение
}

void output(int* array, const int size) { // функция вывода
    for (int i = 0; i < size; i++)
        cout << *(array + i) << " ";
}

void clean_memory(const int* array) { // функция очистки памяти
    delete[] array;
}

int main() {
    srand(time(0)); // сбрасываем рандом
    setlocale(LC_ALL, "RUSSIAN"); // подключаем поддержку русского языка
    int size = get_size();
    int* array = new int[size];
    fill_array(array, size);
    cout << endl << "Полученный массив" << endl;
    output(array, size);
    cout << endl << "Произведение элементов массива между минимальным и максимальным элементами: " << find_multiplication(array, size);
    clean_memory(array);
}
