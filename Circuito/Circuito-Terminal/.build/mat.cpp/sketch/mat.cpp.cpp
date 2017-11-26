#include <Arduino.h>
#line 1 "/home/barbosa/Documentos/CeT/2017.2/Programação Avançada/Circuito/Circuito-Terminal/mat.cpp"
#line 1 "/home/barbosa/Documentos/CeT/2017.2/Programação Avançada/Circuito/Circuito-Terminal/mat.cpp"
#include <iostream>

using namespace std;

int main () {
    unsigned long long int matricula;

    cout << "MATRICULA = ";
    cin >> matricula;
    cout << hex << matricula;

    return 0;
}
