#include <iostream>

using namespace std;

struct stack {
    char sign;
    stack *next;
} *_begin;

int getPriority (char sign) {
    switch (sign) {
        case '/':
        case '*':
            return 3;
        case '+':
        case '-':
            return 2;
        case '(':
            return 1;
    }

    return 0;
}

stack *inStack (stack *p, char in) {
    stack *t = new stack;
    t -> sign = in;
    t -> next = p;
    return t;
}

stack *outStack (stack *p, char &out) {
    stack *t = p;
    out = p -> sign;
    p = p -> next;
    delete t;
    return p;
}

double result (char *str) {
    cout << "Ввод данных: " << endl;
    char symbol, ic = 'z' + 1, symbol2, symbol1;
    double array[200], value2, value1, result;
    for (int i = 0; str[i] != '\0'; i++) {
        symbol = str[i];
        if (symbol >= 'a' && symbol <= 'z') {
            cout << symbol << " = ";
            cin >> array[short(symbol)];
        }
    }

    for (int i = 0; str[i] != '\0'; i++) {
        symbol = str[i];
        if (!(symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/'))
            _begin = inStack(_begin, symbol);
        else  {
            _begin = outStack(_begin, symbol2);
            _begin = outStack(_begin, symbol1);
            value2 = array[short(symbol2)];
            value1 = array[short(symbol1)];
            switch (symbol) {
                case '+':
                    result = value1 + value2;
                    break;
                case '-':
                    result = value1 - value2;
                    break;
                case '*':
                    result = value1 * value2;
                    break;
                case '/':
                    result = value1 / value2;
                    break;
            }

            array[short(ic)] = result;
            _begin = inStack(_begin, ic);
            ic++;
        }
    }

    return result;
}

int main() {
    stack *t, *p = NULL;
    char temp;
    string in, out;
    int l;
    cout << "Введите формулу: ";
    cin >> in;
    for (int i = 0; in[i] != '\0'; i++) {
        if (tolower(in[i]) >= 'a' && tolower(in[i]) <= 'z')
            out += tolower(in[i]);

        if (in[i] == '(')
            p = inStack(p, in[i]);

        if (in[i] == ')') {
            while ((p -> sign) != '(') {
                p = outStack(p, temp);
                if (!p)
                    temp = '\0';

                out += temp;
            }

            t = p;
            p = p -> next;
            delete t;
        }

        if (in[i] == '+' || in[i] == '-' || in[i] == '*' || in[i] == '/') {
            while (p != NULL && getPriority(p -> sign) >= getPriority(in[i])) {
                p = outStack(p, temp);
                out += temp;
            }

            p = inStack(p, in[i]);
        }
    }

    while (p != NULL) {
        p = outStack(p, temp);
        out += temp;
    }

    cout << endl << "Полученное выражение в обратной польской записи: " << out << endl;
    char *array = new char[out.length()];
    for (int i = 0; i < out.length(); i++)
        array[i] = out[i];

    cout << result(array) << endl;

    delete [] array;
}