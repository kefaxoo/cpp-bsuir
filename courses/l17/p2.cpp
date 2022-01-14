#include <iostream>
#include <fstream>

using namespace std;

int main() {
    const string fileName = "2.txt";
    ofstream openFile(fileName);
    for (int i = 10; i <= 100; i += 10) {
        openFile << i;
        if (i != 100)
            openFile << "\n";
    }

    openFile.close();
}