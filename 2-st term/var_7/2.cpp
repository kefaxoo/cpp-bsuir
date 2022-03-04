#include <iostream>
#include <time.h>

using namespace std;

struct stack {
    int element;
    stack *next;
} *_begin, *t;

struct _stack {
    int element;
    _stack *_next;
} *_begin1, *_t;

stack *inStack (stack *p, int element) {
    stack *t = new stack;
    t -> element = element;
    t -> next = p;
    return t;
}

_stack *_inStack (_stack *p, int element) {
    _stack *_t = new _stack;
    _t -> element = element;
    _t -> _next = p;
    return _t;
}

void manualInput (int count) {
    for (int i = 0; i < count; i++) {
        int element;
        cout << endl << "Введите " << i + 1 << " элемент стека: ";
        cin >> element;
        _begin = inStack(_begin, element);
    }
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

void randomInput (int count) {
    int begin, end;
    getInterval(begin, end);

    for (int i = 0; i < count; i++) {
        if (begin >= 0)
            _begin = inStack(_begin, random(begin, end));
        else if (end < 0)
            _begin = inStack(_begin, -random(abs(end), abs(begin)));
        else {
            int temp = rand() % 2;
            if (temp == 1)
                _begin = inStack(_begin, random(0, end));
            else
                _begin = inStack(_begin, -random(0, abs(begin)));
        }
    }
}

void menuInput (int count) {
    int menu;
    while (!(menu > 0 && menu < 3)) {
        cout << endl << "Меню ввода элементов в стек: " << endl;
        cout << "1 - ручной ввод" << endl;
        cout << "2 - рандомное заполнение" << endl;
        cout << "Ваш выбор: ";
        cin >> menu;
    }

    switch (menu) {
        case 1:
            manualInput(count);
            break;
        case 2:
            randomInput(count);
    }
}

void createStack (int &count) {
    if (_begin != NULL) {
        cout << endl << "Освободите память" << endl;
        return;
    }

    cout << endl << "Введите количество элементов в стеке: ";
    cin >> count;

    menuInput(count);
}

int add() {
    int count;
    cout << endl << "Введите количество элементов: ";
    cin >> count;

    menuInput(count);

    return count;
}

void firstMethodOfSort(stack **p) {
    stack *t = NULL, *t1, *r;
    if ((*p) -> next -> next == NULL)
        return;

    do {
        for (t1 = *p; t1 -> next -> next != t; t1 = t1 -> next)
            if (t1 -> next -> element > t1 -> next -> next -> element) {
                r = t1 -> next -> next;
                t1 -> next -> next = r -> next;
                r -> next = t1 -> next;
                t1 -> next = r;
            }
        t = t1 -> next;
    } while ((*p) -> next -> next != t);
}

void secondMethodOfSort(stack *p) {
    stack *t = NULL, *t1;
    int r;
    do {
        for (t1 = p; t1 -> next != t; t1 = t1 -> next)
            if (t1 -> element > t1 -> next -> element) {
                r = t1 -> element;
                t1 -> element = t1 -> next -> element;
                t1 -> next -> element = r;
            }
        t = t1;
    } while (p -> next != t);
}

void thirdMethodOfSort(stack *p) {
    stack *t = p;
    while (t != p) {
        cout << t -> element << endl;
        t = t -> next;
    }
}

void view(stack *p) {
    if (!_begin) {
        cout << endl << "Стек пустой" << endl;
        return;
    }

    stack *t = p;

    int menu = -1;
    while (!(menu > 0 && menu < 4)) {
        cout << endl << "Выберите способ сортировки: " << endl;
        cout << "1 - Обмен адресов" << endl;
        cout << "2 - Обмен информацией" << endl;
        cout << "3 - Без сортировки" << endl;
        cout << "Ваш выбор: ";
        cin >> menu;
    }

    switch (menu) {
        case 1:
            firstMethodOfSort(&_begin);
            break;
        case 2:
            secondMethodOfSort(_begin);
            break;
        case 3:
            thirdMethodOfSort(_begin);
    }

    while (t != NULL) {
        cout << endl << t -> element;
        t = t -> next;
    }

    cout << endl;
}

void firstMethodOfSort(_stack **p) {
    _stack *t = NULL, *t1, *r;
    if ((*p) -> _next -> _next == NULL)
        return;

    do {
        for (t1 = *p; t1 -> _next -> _next != t; t1 = t1 -> _next)
            if (t1 -> _next -> element > t1 -> _next -> _next -> element) {
                r = t1 -> _next -> _next;
                t1 -> _next -> _next = r -> _next;
                r -> _next = t1 -> _next;
                t1 -> _next = r;
            }
        t = t1 -> _next;
    } while ((*p) -> _next -> _next != t);
}

void secondMethodOfSort(_stack *p) {
    _stack *t = NULL, *t1;
    int r;
    do {
        for (t1 = p; t1 -> _next != t; t1 = t1 -> _next)
            if (t1 -> element > t1 -> _next -> element) {
                r = t1 -> element;
                t1 -> element = t1 -> _next -> element;
                t1 -> _next -> element = r;
            }
        t = t1;
    } while (p -> _next != t);
}

void thirdMethodOfSort(_stack *p) {
    _stack *t = p;
    while (t != p) {
        cout << t -> element << endl;
        t = t -> _next;
    }
}

void view(_stack *p) {
    if (!_begin) {
        cout << endl << "Стек пустой" << endl;
        return;
    }

    _stack *t = p;

    int menu = -1;
    while (!(menu > 0 && menu < 4)) {
        cout << endl << "Выберите способ сортировки: " << endl;
        cout << "1 - Обмен адресов" << endl;
        cout << "2 - Обмен информацией" << endl;
        cout << "3 - Без сортировки" << endl;
        cout << "Ваш выбор: ";
        cin >> menu;
    }

    switch (menu) {
        case 1:
            firstMethodOfSort(&_begin1);
            break;
        case 2:
            secondMethodOfSort(_begin1);
            break;
        case 3:
            thirdMethodOfSort(_begin1);
    }

    while (t != NULL) {
        cout << endl << t -> element;
        t = t -> _next;
    }

    cout << endl;
}

void deleteStack (stack **p) {
    while (*p != NULL) {
        t = *p;
        *p = (*p) -> next;
        delete t;
    }
}

void deleteStack (_stack **p) {
    while (*p != NULL) {
        _t = *p;
        *p = (*p) -> _next;
        delete _t;
    }
}

void cleanMemory() {
    if (_begin != NULL)
        deleteStack(&_begin);
    if (_begin1 != NULL)
        deleteStack(&_begin1);
    cout << endl << "Память освобождена" << endl;
}

void exit() {
    if (_begin != NULL)
        deleteStack(&_begin);
    if (_begin1 != NULL)
        deleteStack(&_begin1);
    exit(0);
}

void moveFromFirstStackToAnother() {
    if (_begin == NULL) {
        cout << endl << "Первый стек пустой" << endl;
        return;
    }

    stack *t = _begin;
    int count;
    while (t != NULL) {
        count++;
        t = t -> next;
    }

    int *array = new int[count];
    count = 0;
    t = _begin;
    while (t != NULL) {
        array[count++] = t -> element;
        t = t -> next;
    }

    int iMax = 0;
    for (int i = 0; i < count; i++)
        iMax = array[iMax] < array[i] ? i : iMax;

    deleteStack(&_begin1);

    for (int i = 0; i <= iMax; i++)
        _begin1 = _inStack(_begin1, array[i]);

    view(_begin1);
}

int main() {
    srand(time(0));
    int count;

    while (true) {
        int menu;
        cout << endl << "Меню работы со стеком: " << endl;
        cout << "1 - Создать стек" << endl;
        cout << "2 - Добавить элементы в стек" << endl;
        cout << "3 - Просмотр элементов стека" << endl;
        cout << "4 - Освобождение памяти" << endl;
        cout << "5 - Перенести из созданного стека в новый стек все элементы между началом и максимальным значением" << endl;
        cout << "0 - Завершение работы" << endl;
        cout << "Ваш выбор: ";
        cin >> menu;

        switch (menu) {
            case 1:
                createStack(count);
                break;
            case 2:
                count += add();
                break;
            case 3:
                view(_begin);
                break;
            case 4:
                cleanMemory();
                break;
            case 5:
                moveFromFirstStackToAnother();
                break;
            case 0:
                exit();
        }
    }
}