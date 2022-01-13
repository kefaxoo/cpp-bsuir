#include <iostream>

using namespace std;

struct price {
    int number;
    char name[10];
    float price;
};

int main() {
    struct price item;
    cout << "Введите номер товара: ";
    cin >> item.number;
    cout << endl << "Введите название товара (до 10 символов, без пробелов): ";
    scanf("%s", item.name);
    cout << endl << "Введите цену товара: ";
    cin >> item.price;

    cout << endl << "Информация о товаре: " << endl << "Номер товара: " << item.number << endl << "Название товара: ";
    printf("%s", item.name);
    cout << endl << "Цена товара: " << item.price << endl;
}