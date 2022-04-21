#include <iostream>
#include <windows.h>
#include <conio.h>

#pragma warning (disable: 4703)

using namespace std;

int _count = 0;

struct Tree {
    int numberPassport;
    string name;
    Tree* left, * right;
} *root;

Tree *List(int number, string name) {
    Tree *t = new Tree;
    t -> numberPassport = number;
    t -> name = name;
    t -> left = t -> right = NULL;
    return t;
}

string enterString() {
    string str;
    int count = 0;

    while (true) {
        char temp = _getche();
        if (short(temp) == 13 || count == 255)
            break;

        str += temp;
        count++;
    }

    count = 0;
    for (int i = 1; i < str.length() - 1 || str[i] != '\0'; i++)
        if (str[i] == ' ' && (short(str[i - 1]) >= -64 && short(str[i - 1]) <= -1) && (short(str[i + 1]) >= -64 && short(str[i + 1]) <= -1))
            count++;

    if (count == 2)
        return str;
    else {
        cout << endl;
        return enterString();
    }
}

void createTree() {
    if (root != NULL) {
        cout << endl << "Освободите память" << endl;
        _count--;
        return;
    }

    int numberPassport;
    string name;

    cout << endl << _count << " человек:" << endl << "Введите номер паспорта: ";
    cin >> numberPassport;
    cout << endl << "Введите ФИО: ";
    name = enterString();

    root = List(numberPassport, name);
}

void viewTree(Tree *p, int level) {
    if (root == NULL || _count == 0) {
        cout << endl << "\"Дерево\" пустое" << endl;
        return;
    }

    if (p) {
        viewTree(p -> right, level + 1);
        cout << p -> numberPassport << " | " << p -> name << endl;
        viewTree(p -> left, level + 1);
    }
}

int _number;

void searchByNumber(Tree *p, int level, bool &find) {
    if (p) {
        searchByNumber(p -> right, level + 1, find);
        if (_number == p -> numberPassport) {
            cout << endl << "Найдено совпадение: " << p -> numberPassport << " | " << p -> name << endl;
            find = true;
        }
        searchByNumber(p -> left, level + 1, find);
    }
}

void findInfo(Tree *p, int level) {
    if (root == NULL || _count == 0) {
        cout << endl << "\"Дерево\" пустое" << endl;
        return;
    }

    bool find = false;

    cout << endl << "Введите номер паспорта: ";
    cin >> _number;
    searchByNumber(p, level, find);

    if (!find)
        cout << endl << "Совпадений не найдено" << endl;
}

void addElement(Tree *root) {
    if (root == NULL || _count < 2) {
        if (_count == 1)
            _count--;

        cout << endl << "\"Дерево\" пустое" << endl;
        return;
    }

    int numberPassport;
    string name;

    cout << endl << _count << " человек:" << endl << "Введите номер паспорта: ";
    cin >> numberPassport;
    cout << endl << "Введите ФИО: ";
    name = enterString();

    Tree *prev, *t;
    bool find = true;
    t = root;
    while (t && find) {
        prev = t;
        if ((numberPassport == t -> numberPassport) || (name == t -> name)) {
            find = false;
            cout << endl << "Элемент уже существует в дереве" << endl;
            _count--;
        }
        else if (numberPassport < t -> numberPassport)
            t = t -> left;
        else
            t = t -> right;
    }

    if (find) {
        t = List(numberPassport, name);
        if (numberPassport < prev -> numberPassport)
            prev -> left = t;
        else
            prev -> right = t;
    }
}

int _countOfSymbols = 0;

void coutCount(Tree *p, int level) {
    if (p) {
        coutCount(p -> right, level + 1);
        cout << p -> numberPassport << " | " << p -> name << " | ";
        int temp = 0;
        for (int i = 0; i < (p -> name).length(); i++)
            temp = (p -> name)[i] != ' ' && (p -> name)[i] != '\0' ? temp + 1 : temp;
        cout << temp << endl;
        _countOfSymbols += temp;
        coutCount(p -> left, level + 1);
    }
}

void coutCount() {
    if (root == NULL || _count == 0) {
        cout << endl << "\"Дерево\" пустое" << endl;
        return;
    }

    coutCount(root, 0);
    cout << "Общее количество строк в \"дереве\": " << _countOfSymbols << endl;
}

void deleteTree(Tree *t) {
    if (t != NULL) {
        deleteTree(t -> left);
        deleteTree(t -> right);
        delete t;
    }
}

void deleteTree() {
    if (_count > 0) {
        deleteTree(root);
        cout << endl << "Память освобождена" << endl;
        root = NULL;
        _count = 0;
    }
}

void exit() {
    if (root != NULL)
        deleteTree(root);

    exit(0);
}

void direct(Tree *p) {
    if (p) {
        cout << p -> numberPassport << " | " << p -> name << endl;
        direct(p -> left);
        direct(p -> right);
    }
}

void reverse(Tree *p) {
    if (p) {
        reverse(p -> left);
        reverse(p -> right);
        cout << p -> numberPassport << " | " << p -> name << endl;
    }
}

void getElements(Tree *p, int *numbers, string *names, int i, int j) {
    if (p) {
        numbers[j] = p -> numberPassport;
        names[j] = p -> name;
        getElements(p -> left, numbers, names, i + 1, j + 1);
        getElements(p -> right, numbers, names, i + 1, j + 1);
    }
}

void sort(int *numbers, string *names) {
    for (int i = 0; i < _count - 1; i++)
        for (int j = i; j < _count; j++)
            if (*(numbers + i) > *(numbers + j)) {
                swap(*(numbers + i), *(numbers + j));
                string temp = *(names + i);
                *(names + i) = *(names + j);
                *(names + j) = temp;
            }
}

void addElementsForArrays(Tree *root, int numberPassport, string name) {
    Tree *prev, *t;
    bool find = true;
    t = root;
    while (t && find) {
        prev = t;
        if ((numberPassport == t -> numberPassport) || (name == t -> name)) {
            find = false;
            cout << endl << "Элемент уже существует в дереве" << endl;
            _count--;
        }
        else if (numberPassport < t -> numberPassport)
            t = t -> left;
        else
            t = t -> right;
    }

    if (find) {
        t = List(numberPassport, name);
        if (numberPassport < prev -> numberPassport)
            prev -> left = t;
        else
            prev -> right = t;
    }
}

void view() {
    if (root == NULL || _count == 0) {
        cout << endl << "\"Дерево\" пустое" << endl;
        return;
    }
    
    int menu = 0;
    while (!(menu > 0 && menu < 4)) {
        cout << endl << "Меню выбора обхода дерева: " << endl;
        cout << "1 - Прямой обход" << endl;
        cout << "2 - Обратный обход" << endl;
        cout << "3 - В порядке возрастания ключа" << endl;
        cout << "Ваш выбор: ";
        cin >> menu;
    }

    cout << endl << "#Паспорта | ФИО" << endl;
    switch (menu) {
        case 1:
            direct(root);
            break;
        case 2:
            reverse(root);
            break;
        case 3: {
            int *arrayOfNumbers = new int[_count];
            string *arrayOfNames = new string[_count];
            getElements(root, arrayOfNumbers, arrayOfNames, 0, 0);
            sort(arrayOfNumbers, arrayOfNames);
            deleteTree(root);
            root = List(arrayOfNumbers[0], arrayOfNames[0]);
            for (int i = 1; i < _count; i++)
                addElementsForArrays(root, arrayOfNumbers[i], arrayOfNames[i]);
            direct(root);

            delete[] arrayOfNumbers;
            delete[] arrayOfNames;
        }
    }
}

void deleteElement() {
    if (root == NULL || _count == 0) {
        cout << endl << "\"Дерево\" пустое" << endl;
        return;
    }
    
    int menu = 0;
    while (!(menu > 0 && menu < 3)) {
        cout << endl << "Выберите вид удаления: " << endl;
        cout << "1 - По номеру паспорта" << endl;
        cout << "2 - По ФИО" << endl;
        cout << "Ваш вариант: ";
        cin >> menu;
    }

    int *arrayOfNumbers = new int[_count];
    string *arrayOfNames = new string[_count];
    getElements(root, arrayOfNumbers, arrayOfNames, 0, 0);
    sort(arrayOfNumbers, arrayOfNames);
    deleteTree(root);
    bool find = false;

    cout << endl << "Введите номер паспорта: ";
    cin >> _number;
    if (_count > 1)
        for (int i = 0; i < _count - 1; i++) {
            if (arrayOfNumbers[i] == _number) {
                find = true;
                for (int j = i; j < _count - 1; j++) {
                    arrayOfNames[j] = arrayOfNames[j + 1];
                    arrayOfNumbers[j] = arrayOfNumbers[j + 1];
                }

                break;
            }
        }
    else if (arrayOfNumbers[0] == _number)
        find = true;

    if (find)
        _count--;

    if (_count == 0 && find) {
        return;
    }

    root = List(arrayOfNumbers[0], arrayOfNames[0]);
    for (int i = 1; i < _count; i++)
        addElementsForArrays(root, arrayOfNumbers[i], arrayOfNames[i]);

    delete[] arrayOfNumbers;
    delete[] arrayOfNames;
}


int main() {
    setlocale(LC_CTYPE, "RUSSIAN");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "RUSSIAN");
    while (true) {
        int menu;
        cout << endl << "Меню работы с \"деревом\":" << endl;
        cout << "1 - Создать \"дерево\"" << endl;
        cout << "2 - Добавить элемент в \"дерево\"" << endl;
        cout << "3 - Просмотр элементов \"дерева\"" << endl;
        cout << "4 - Найти человека\\номер паспорта по его номеру паспорта\\имени" << endl;
        cout << "5 - Удаление элемента из \"дерева\"" << endl;
        cout << "6 - Вывести количество символов во всех строках \"дерева\"" << endl;
        cout << "7 - Освобождение памяти" << endl;
        cout << "8 - Просмотр элементов различными способами" << endl;
        cout << "0 - Завершение работы" << endl;
        cout << "Ваш выбор: ";
        cin >> menu;

        switch (menu) {
        case 1: {
            _count++;
            createTree();
        }
              break;

        case 2: {
            _count++;
            addElement(root);
        }
              break;

        case 3: {
            cout << endl << "Просмотр \"дерева\":" << endl << "#Паспорта | ФИО" << endl;
            viewTree(root, 0);
        }
              break;

        case 4:
            findInfo(root, 0);
            break;

        case 5:
            deleteElement();
            break;

        case 6:
            coutCount();
            break;

        case 7:
            deleteTree();
            break;

        case 8:
            view();
            break;

        case 0:
            if (_count == 0)
                exit(0);
            else
                exit();
        }
    }
}