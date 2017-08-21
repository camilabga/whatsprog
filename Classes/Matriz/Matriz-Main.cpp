#include <iostream>
#include "Matriz.h"

using namespace std;

int main()
{
    Matriz A(3,3), B(3,3), C;

    cout << "Primeira matriz:\n";
    cin >> A;
    cout << "Segunda matriz:\n";
    cin >> B;

    C = !B;  // Transposta
    C.setElem(0,0, -1000.0);

    cout << "Soma:\n";
    cout << A+B;
    cout << "Transposta alterada:\n";
    cout << C;
}
