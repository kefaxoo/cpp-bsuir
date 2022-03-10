#include <iostream>

using namespace std;

struct Tree {
    int value;
    Tree *left, *right;
} *root; // указатель корня

int _count = 0;

Tree *List (int value) {
    Tree *t = new Tree;
    t -> value = value;
    t -> left = t -> right = NULL;
    return t;
}

void viewTree (Tree *p, int level) {
    if (root == NULL) {
        cout << endl << "\"Дерево\" пустое" << endl;
        return;
    }

    if (p) {
        viewTree(p -> right, level + 1);
        cout << p -> value << " ";
        
        viewTree(p -> left, level + 1);
    }
}

Tree *deleteElement (Tree *root, int valueToDelete) {
    Tree *_delete, *prevDelete, *_right, *prevRight;
    _delete = root;
    prevDelete = NULL;
    while (_delete != NULL && _delete -> value != valueToDelete) {
        prevDelete = _delete;
        if (_delete -> value > valueToDelete)
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
            _right = _delete -> right;
        else {
            prevRight = _delete;
            _right = _delete -> left;
            while (_right -> right != NULL) {
                prevRight = _right;
                _right = _right -> right;
            }

            if (prevRight == _delete)
                _right -> right = _delete -> right;
            else {
                _right -> right = _delete -> right;
                prevRight -> right = _right -> left;
                _right -> left = prevRight;
            }
        }

        if (_delete == root)
            root = _right;
        else if (_delete -> value < prevDelete -> value)
            prevDelete -> left = _right;
        else
            prevDelete -> right = _right;
        
        delete _delete;
        _count--;
        return root;
    }
}

void deleteElement () {
    int valueToDelete;
    cout << endl << "Введите значение, которое хотите удалить: ";
    cin >> valueToDelete;

    root = deleteElement(root, valueToDelete);
}

void deleteTree (Tree *t) {
    if (t != NULL) {
        deleteTree(t -> left);
        deleteTree(t -> right);
        delete t;
    }
}

void deleteTree () {
    deleteTree(root);
    cout << endl << "Память освобождена" << endl;
    root = NULL;
}

int manualInput () {
    int value;
    cout << endl << "Введите " << _count << " элемент \"дерева\": ";
    cin >> value;
    return value;
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

int randomInput () {
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

int menuInput () {
    int menu;
    while (!(menu > 0 && menu < 9)) {
        cout << endl << "Меню ввода элементов в \"дерево\"" << endl;
        cout << "1 - ручной ввод" << endl;
        cout << "2 - рандом" << endl;
        cout << "Ваш выбор: ";
        cin >> menu;
    }

    _count++;

    switch (menu) {
        case 1:
            return manualInput();
            break;
        case 2:
            return randomInput();
    }
}

void addElement (Tree *root, int value) {
    if (root == NULL) {
        cout << endl << "\"Дерево\" пустое" << endl;
        return;
    }

    Tree *prev, *t;
    bool find = true;
    t = root;
    while (t && find) {
        prev = t;
        if (value == t -> value) {
            find = false;
            cout << endl << "Элемент уже существует в дереве" << endl;
            _count--;
        }
        else if (value < t -> value)
            t = t -> left;
        else
            t = t -> right;
    }

    if (find) {
        t = List(value);
        if (value < prev -> value)
            prev -> left = t;
        else
            prev -> right = t;
    }
}

void createTree () {
    if (root != NULL) {
        cout << endl << "Освободите память" << endl;
        return;
    }

    root = List(menuInput());
}

void exit() {
    if (root != NULL)
        deleteTree(root);
    exit(0);
}

int main() {
    while (true) {
        int menu;
        cout << endl << "Меню работы с \"деревом\"" << endl;
        cout << "1 - Создать \"дерево\"" << endl;
        cout << "2 - Добавить элемент в \"дерево\"" << endl;
        cout << "3 - Просмотр элементов в \"дереве\"" << endl;
        cout << "4 - Удаление элемента из \"дерева\"" << endl;
        cout << "5 - Освобождение памяти" << endl;
        cout << "0 - Завершение работы" << endl;
        cout << "Ваш выбор: ";
        cin >> menu;

        switch (menu) {
            case 1:
                createTree();
                break;
            case 2:
                addElement(root, menuInput());
                break;
            case 3: {
                cout << endl << "Элементы \"дерева\": ";
                viewTree(root, 0);
                cout << endl;
            }
                break;
            case 4:
                deleteElement();
                break;
            case 5:
                deleteTree();
                break;
            case 0:
                exit();
        }
    }
}