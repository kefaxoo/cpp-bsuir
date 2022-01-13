#include <iostream>

using namespace std;

int main() {
    int i = 10, *ip = &i;
    float f = 10.1, *fp = &f;
    double d = 10.2, *dp = &d;
    char c = 'c', *cp = &c;
    bool b = true, *bp = &b;

    cout << "Адреса: " << endl << "1) int = " << ip << endl << "2) float = " << fp << endl << "3) double = " << dp << endl << "4) char = " << cp << endl << "5) bool = " << bp << endl;
}