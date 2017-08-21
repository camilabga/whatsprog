#include <iostream>
using namespace std;
#include "armazenador.h"

Lista_valor::Lista_valor(unsigned dim){
    N = dim;
    x = (N > 0 ? new valor[N] : NULL);
}

unsigned Lista_valor::getN(){
    return N;
}

Lista_valor::Lista_valor(const Lista_valor &L){
    N = L.N;
    x = new valor[N];
    for(int i = 0; i < N; i++) x[i] = L.x[i];
}

Lista_valor::~Lista_valor(void){
    if (x != NULL) delete[] x;
}

void Lista_valor::insira_lista(valor V){
    valor *nova = new valor[N + 1];
    for (int i = 0; i < N; i++){
        nova[i] = x[i];
    }
    nova[N] = V;
    delete[] x;
    x = nova;
    N++;
}

valor Lista_valor::primeiro_lista(){
    return x[0];
}

void Lista_valor::remover_primeiro_lista(){
    valor *nova = new valor[N-1];
    for (int i = 1; i < N; i++)
    {
        nova[i-1] = x[i];
    }
    delete[] x;
    x = nova;
    N--;
}

void Lista_valor::imprimir_lista(){
    for (int i = 0; i < N; i++){
        cout << "Valor " << i + 1 << " = " << x[i] << endl;
    }
}