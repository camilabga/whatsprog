#include "Voo.h"

using namespace std;

Voo::Voo() {
    num = 1000;
    origem = "AAA";
    destino = "AAA";
    partida = 0000;
    chegada = 0000;
}

Voo::Voo(Voo &voo){
    setNum(voo.num);
    setOrigem(voo.origem);
    setChegada(voo.chegada);
    setPartida(voo.partida);
    setChegada(voo.chegada);
}

Voo::Voo(int n, string o, string d, unsigned int p, unsigned int c){
    setNum(n);
    setOrigem(o);
    setDestino(d);
    setPartida(p);
    setChegada(c);
}

ostream &operator<<(ostream &X, const Voo &V){
    X << "VOO " << V.num << ": " << endl 
      << "Aero de Origem = " << V.origem << endl
      << "Aero de Destino = " << V.destino << endl
      << "Hora de Partida = " << V.partida << endl
      << "Hora de Chegada = " << V.chegada << endl << endl;
}

istream &operator>>(istream &X, Voo &V){
    cout << "Voo ";
    X >> V.num;
    cout << "Aero de Origem = ";
    X >> V.origem;
    cout << "Aero de Chegada = ";
    X >> V.destino;
    cout << "Hora de Chegada = ";
    X >> V.chegada;
    cout << "Hora de PArtida = ";
    X >> V.partida;

    return X;
}

void Voo::setNum(int num){
    if (num >= 1000 && num <= 9999) {
        this->num = num;
    } else {
        cout << "Numero de voo invalido";
        this->num = 1000;
    }
}
void Voo::setOrigem(string origem){
    if (sizeof(origem) == 3) {
        this->origem = origem;
    } else {
        cout << "Aero de origem invalido";
        this->origem = "AAA";
    }
}

void Voo::setDestino(string destino){
    if (sizeof(destino) == 3) {
        this->destino = origem;
    } else {
        cout << "Aero de destino invalido";
        this->destino = "AAA";
    }
}

void Voo::setPartida(unsigned int num){
    if (num >= 0 && num <= 2359) {
        partida = num;
    } else {
        cout << "Hora de partida invalido";
        partida = 0000;
    }
}

void Voo::setChegada(unsigned int chegada){
    if (num >= 0 && num <= 2359) {
        partida = num;
    } else {
        cout << "Hora de partida invalido";
        partida = 0000;
    }
}

void Lista_Voos::criar(unsigned num){
    if (num >= 0){
        n = num;
        lista = new Voo[n];
    } else {
        n = 0;
        lista = NULL;
    }
}

void Lista_Voos::limpar(){
    if (lista!=NULL) delete[] lista;
    n = 0;
    lista = NULL;
}

void Lista_Voos::copiar(const Lista_Voos &L){
    criar(L.n);
    for (unsigned i = 0; i < n; i++) {
        lista[i] = L.lista[i];
    }
}

void Lista_Voos::inserir(Voo &V){
    Lista_Voos prov(n + 1);
    for (unsigned i = 0; i < n; i++) {
        prov.lista[i] = lista[i];
    }
    prov.lista[n] = V;

    limpar();
    copiar(prov);    
}

void Lista_Voos::imprimir(){
    for (unsigned i = 0; i < n; i++) {
        cout << lista[i] << endl;
    }
}

void Lista_Voos::imprimir(string aero){
    for (unsigned i = 0; i < n; i++) {
        if (aero == lista[i].getOrigem()) {
            cout << lista[i] << endl;
        }
    }
}