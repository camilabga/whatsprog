#include <iostream>
#include "questao01.h"

using namespace std;

int main () {
    Ponto x1(1,0);
    Ponto x2(0,1);
    Ponto x3(0,0);
    Ponto x4(1,1);

    Retangulo r(x1, x2, x3, x4);

    return 0;
}