#include <iostream>
#include <windows.h>
#include <conio.h>

#pragma warning (disable: 4703)

using namespace std;

int _count = 0;

struct Tree {
    int numberPassport;
    string name;
    Tree *left, *right;
} *root;

Tree *List (int number, string name) {
    Tree *t = new Tree;
    t -> numberPassport = number;
    t -> name = name;
    t -> left = t -> right = NULL;
    return t;
}

string enterString () {
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

void createTree () {
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

void viewTree (Tree *p, int level) {
    if (root == NULL) {
        cout << endl << "\"Дерево\" пустое" << endl;
        return;
    }

    if (p) {
        viewTree(p -> right, level + 1);
        cout << p -> numberPassport << " | " << p -> name << endl;
        viewTree(p -> left, level + 1);
    }
}

string _name;

void searchByName (Tree *p, int level) {
    if (p) {
        searchByName(p -> right, level + 1);
        if (_name == p -> name) {
            cout << endl << "Найдено совпадение: " << p -> numberPassport << " | " << p -> name << endl;
            return;
        }
        searchByName(p -> left, level + 1);
    }
}

int _number;

void searchByNumber (Tree *p, int level) {
    if (p) {
        searchByNumber(p -> right, level + 1);
        if (_number == p -> numberPassport)
            cout << endl << "Найдено совпадение: " << p -> numberPassport << " | " << p -> name << endl;
        searchByNumber(p -> left, level + 1);
    }
}

void findInfo (Tree *p, int level) {
    if (root == NULL) {
        cout << endl << "\"Дерево\" пустое" << endl;
        return;
    }

    int menu = 0;
    while (!(menu > 0 && menu < 3)) {
        cout << endl << "Выберите вид поиска: " << endl;
        cout << "1 - По номеру паспорта" << endl;
        cout << "2 - По ФИО" << endl;
        cout << "Ваш вариант: ";
        cin >> menu;
    }

    switch (menu) {
        case 1: {
            cout << endl << "Введите номер паспорта: ";
            cin >> _number;
            searchByNumber(p, level);
        }
            break;

        case 2: {
            cout << endl << "Введите ФИО: ";
            _name = enterString();
            searchByName(p, level);
        }

    }
}

void addElement (Tree *root) {
    if (root == NULL) {
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

Tree *deleteByNumber(Tree *root) {
    Tree *_delete, *prevDelete, *_right, *prevRight;
    _delete = root;
    prevDelete = NULL;
    while (_delete != NULL & _delete -> numberPassport != _number) {
        prevDelete = _delete;
        if (_delete -> numberPassport > _number)
            _delete = _delete -> left;
        else
            _delete = _delete -> right;

        if (_delete == NULL) {
            cout << endl << "Элемент не найден" << endl;
            return root;
        }

        if (_delete -> right == NULL)
            _right = _delete -> left;
        else if (_delete -> left == NULL)
            _right = 
    }
}

void deleteElement() {
    int menu = 0;
    while (!(menu > 0 && menu < 3)) {
        cout << endl << "Выберите вид удаления: " << endl;
        cout << "1 - По номеру паспорта" << endl;
        cout << "2 - По ФИО" << endl;
        cout << "Ваш вариант: ";
        cin >> menu;
    }

    switch (menu) {
    case 1: {
        cout << endl << "Введите номер паспорта: ";
        cin >> _number;
        deleteByNumber(root);
    }
          break;

    case 2: {
        cout << endl << "Введите ФИО: ";
        _name = enterString();
        deleteByName(root);
    }

    }
}

int main() {
    setlocale(LC_CTYPE, "RUSSIAN");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    while (true) {
        int menu;
        cout << endl << "Меню работы с \"деревом\":" << endl;
        cout << "1 - Создать \"дерево\"" << endl;
        cout << "2 - Добавить элемент в \"дерево\"" << endl;
        cout << "3 - Просмотр элементов \"дерева\"" << endl;
        cout << "4 - Найти человека\\номер паспорта по его номеру паспорта\\имени" << endl;
        cout << "5 - Удаление элемента из \"дерева\"" << endl;
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
        }
    }
}