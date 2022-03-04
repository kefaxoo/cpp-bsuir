#include <iostream>
#include <time.h>

using namespace std;

struct list {
    int element;
    list *prev, *next;
} *_begin, *_end, *t;

int _count = 0;

void createList (list **begin, list **end, int element) {
    t = new list;
    t -> element = element;
    t -> next = t -> prev = NULL;
    *begin = *end = t;
}

void getInterval (int &begin, int &end) {
    cout << endl << "Введите начало промежутка рандома: ";
    cin >> begin;

    cout << endl << "Введите конец промежутка рандома: ";
    cin >> end;

    if (begin > end)
        swap(begin, end);
}

int random (int begin, int end) {
    return rand() % (end - begin + 1) + begin;
}

int menuInput () {
    int menu;
    while (!(menu > 0 && menu < 3)) {
        cout << endl << "Меню ввода элемента в список: " << endl;
        cout << "1 - ручное заполнение" << endl;
        cout << "2 - рандомное заполнение" << endl;
        cout << "Ваш выбор: ";
        cin >> menu;
    }

    int element;
    switch (menu) {
        case 1: {
            cout << endl << "Введите " << _count << " элемент списка: ";
            cin >> element;
            return element;
        }
        case 2: {
            int begin, end;
            getInterval(begin, end);

            if (begin >= 0)
                return random(begin, end);
            else if (end < 0)
                return -random(end, begin);
            else {
                int temp = rand() % 2;
                if (temp == 1)
                    return random(0, end);
                else
                    return -random(0, begin);
            }
        }
    }

    return 0;
}

void createList () {
    if (_begin != NULL) {
        cout << endl << "Освободите память" << endl;
        return;
    }

    createList(&_begin, &_end, menuInput());
}

void addElement (int destination, list **begin, list **end, int element) {
    t = new list;
    t -> element = element;
    if (destination == 1) {
        t -> prev = NULL;
        t -> next = *begin;
        (*begin) -> prev = t;
        *begin = t;
    } else {
        t -> next = NULL;
        t -> prev = *end;
        (*end) -> next = t;
        *end = t;
    }
}

void addElement () {
    if (_begin == NULL) {
        cout << endl << "Список пустой" << endl;
        return;
    }

    int destination;
    while (true) {
        cout << endl << "Выберите с какой стороны списка добавить элемент: " << endl;
        cout << "1 - В начало" << endl;
        cout << "2 - В конец" << endl;
        cout << "Ваш выбор: ";
        cin >> destination;

        if (destination == 1 || destination == 2)
            break;
    }

    addElement(destination, &_begin, &_end, menuInput());

    if (destination == 1)
        t = _begin;
    else
        t = _end;
}

void viewList (int destination, list *t) {
    while (t != NULL) {
        cout << t -> element << endl;
        if (destination == 1)
            t = t -> next;
        else
            t = t -> prev;

    }
}

void viewList () {
    if (!_begin) {
        cout << endl << "Список пустой" << endl;
        return;
    }

    int destination;
    while (true) {
        cout << endl << "Выберите с какой стороны вывести список: " << endl;
        cout << "1 - C начала" << endl;
        cout << "2 - С конца" << endl;
        cout << "Ваш выбор: ";
        cin >> destination;

        if (destination == 1 || destination == 2)
            break;
    }

    if (destination == 1) {
        t = _begin;
        cout << endl << "Вывод списка с начала" << endl;
    } else {
        t = _end;
        cout << endl << "Вывод списка с конца" << endl;
    }

    viewList(destination, t);
}

void deleteList (list **p) {
    while (*p != NULL) {
        t = *p;
        *p = (*p) -> next;
        delete t;
    }
}

void deleteElement () {
    int element;
    cout << endl << "Введите элемент для удаления: ";
    cin >> element;

    list *indexAddress = NULL;
    t = _begin;
    while (t != NULL) {
        if (t -> element == element) {
            indexAddress = t;
            t = t -> next;
            break;
        }
        t = t -> next;
    }

    if (indexAddress == NULL) {
        cout << endl << "Совпадений не найдено" << endl;
        return;
    }

    if (indexAddress -> element == _begin -> element) {
        if (_begin -> next == NULL) {
            deleteList(&_begin);
            return;
        }

        _begin = _begin -> next;
        _begin -> prev = NULL;
    } else if (indexAddress -> element = _end -> element) {
        _end = _end -> prev;
        _end -> next = NULL;
    } else {
        (indexAddress -> prev) -> next = indexAddress -> next;
        (indexAddress -> next) -> prev = indexAddress -> prev;
        indexAddress = NULL;
    }
}

void cleanMemory () {
    if (_begin != NULL)
        deleteList(&_begin);
    cout << endl << "Память освобождена" << endl;
}

void exit () {
    if (_begin != NULL)
        deleteList(&_begin);
    exit(0);
}

int main() {
    srand(time(0));

    while (true) {
        int menu;
        cout << endl << "Меню работы со списком" << endl;
        cout << "1 - Создать список" << endl;
        cout << "2 - Добавить элемент в список" << endl;
        cout << "3 - Просмотр элементов списка" << endl;
        cout << "4 - Удаление элемента в списке" << endl;
        cout << "5 - Освобождение памяти" << endl; // аналог lab_2
        cout << "6 - Перенести из созданного списка в новый список все элементы расположенные между началом и максимальным значением" << endl;
        cout << "0 - Завершение работы" << endl;
        cout << "Ваш выбор: ";
        cin >> menu;

        switch (menu) {
            case 1:
                _count++;
                createList();
                break;
            case 2:
                _count++;
                addElement();
                break;
            case 3:
                viewList();
                break;
            case 4:
                deleteElement();
                break;
            case 5:
                cleanMemory();
                break;
            case 6:
                break;
            case 0:
                exit();
        }
    }
}