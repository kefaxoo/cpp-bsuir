#include <iostream>

using namespace std;

int main () {
    float array[] = { 3.24, -7.16, 2.28, -0.16, -3.22, 7.14, 2.88, -3.20, 0.99, -4.15 }, sum = 0, sumOfMultiplications = 0, minOfPositive = INT_MAX, maxOfNegative = INT_MIN;
    int indexOfMin = 0, indexOfMax = 0;
    for (int i = 0; i < sizeof(array)/sizeof(array[0]); i++) {
        if (i % 2 != 0)
            sum += array[i];
        if (array[i] < 0 && array[i] > maxOfNegative)
            maxOfNegative = array[i];
        if (array[i] > 0 && array[i] < minOfPositive)
            minOfPositive = array[i];
        if (array[i] > array[indexOfMax])
            indexOfMax = i;
        if (array[i] < array[indexOfMin])
            indexOfMin = i;
        sumOfMultiplications += i * array[i];
    }

    float multiplication = 1;
    if (indexOfMin > indexOfMax)
        for (int i = indexOfMax + 1; i < indexOfMin; i++)
            multiplication *= array[i];
    else
        for (int i = indexOfMin + 1; i < indexOfMax; i++)
            multiplication *= array[i];

    float temp = array[indexOfMin];
    array[indexOfMin] = array[indexOfMax];
    array[indexOfMax] = temp;

    cout << endl << "Сумма элементов с нечётными индексами: " << sum << endl << "Наибольший элемент из отрицательных: " << array[indexOfMax] << endl << "Наименьший элемент из положительных: " << array[indexOfMin] << endl << "Произведение элементов массива между максимальным и минимальным элементами: " << multiplication << endl << "Сумма произведений: " << sumOfMultiplications << endl;
    for (int i = 0; i < sizeof(array)/sizeof(array[0]); i++) {
        cout << array[i] << endl;
    }
}