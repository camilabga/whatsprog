#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream exemplo("teste.txt");

    for (unsigned i = 0; i < 10000000; i++) {
        exemplo << i << endl;
    }

    exemplo.close();

    return 0;
}