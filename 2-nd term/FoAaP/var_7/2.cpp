#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

struct stack {
    int element;
    stack *next;
} *begin1, *begin2;

stack *inStack (stack *p, int element) {
    stack *t = new stack;
    t -> element = element;
    t -> next = p;
    return t;
}

void manualInput (int count) {
    for (int i = 0; i < count; i++) {
        int element;
        cout << endl << "Введите " << i + 1 << " элемент стека: ";
        cin >> element;
        begin1 = inStack(begin1, element);
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
    int beginInterval, endInterval;
    getInterval(beginInterval, endInterval);
    for (int i = 0; i < count; i++) {
        if (beginInterval >= 0)
            begin1 = inStack(begin1, random(beginInterval, endInterval));
        else if (endInterval < 0)
            begin1 = inStack(begin1, -random(abs(endInterval), abs(beginInterval)));
        else
            begin1 = inStack(begin1, rand() % 2 ? random(0, endInterval) : -random(0, abs(beginInterval)));
    }
}

void menuInput (int count) {
    int menu = -1;
    while (!(menu > 0 && menu < 3)) {
        cout << endl << "Меню ввода элементов в стек:" << endl;
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
    if (begin1 != NULL) {
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

void output(stack *p) {
    stack *t = p;
    while (t != p) {
        cout << t -> element << endl;
        t = t -> next;
    }
}

void view(stack *begin) {
    if (!begin) {
        cout << endl << "Стек пустой" << endl;
        return;
    }

    stack *t = begin;
    int menu = -1;
    while (!(menu > 0 && menu < 4)) {
        cout << endl << "Выберите способ сортировки:" << endl;
        cout << "1 - Обмен адресов" << endl;
        cout << "2 - Обмен информацией" << endl;
        cout << "3 - Без сортировки" << endl;
        cout << "Ваш выбор: ";
        cin >> menu;
    }

    switch (menu) {
        case 1:
            firstMethodOfSort(&begin);
            break;
        case 2:
            secondMethodOfSort(begin);
            break;
        case 3:
            output(begin);
    }

    while (t != NULL) {
        cout << endl << t -> element;
        t = t -> next;
    }
    
    cout << endl;
}

void deleteStack (stack **p) {
    stack *t;
    while (*p != NULL) {
        t = *p;
        *p = (*p) -> next;
        delete t;
    }
}

void cleanMemory() {
    if (begin1 != NULL)
        deleteStack(&begin1);

    if (begin2 != NULL)
        deleteStack(&begin2);

    cout << endl << "Память освобождена" << endl;
}

void exit() {
    if (begin1 != NULL)
        deleteStack(&begin1);

    if (begin2 != NULL)
        deleteStack(&begin2);

    exit(0);
}

void moveFromFirstStacKToAnother() {
    if (begin1 == NULL) {
        cout << endl << "Первый стек пустой" << endl;
        return;
    }

    int count;
    for (stack *t = begin1; t != NULL; t = t -> next)
        count++;

    int *array = new int[count];
    count = 0;
    for (stack *t = begin1; t != NULL; t = t -> next)
        *(array + count++) = t -> element;

    int iMax = 0;
    for (int i = 0; i < count; i++)
        iMax = *(array + iMax) < *(array + i) ? i : iMax;

    deleteStack(&begin2);
    for (int i = 0; i <= iMax; i++)
        begin2 = inStack(begin2, *(array + i));

    view(begin2);
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
            case 3:
                view(begin1);
                break;
            case 4:
                cleanMemory();
                break;
            case 5:
                moveFromFirstStacKToAnother();
                break;
            case 0:
                exit();
        }
    }
}
