#include "circuito_STL.h"

/* FUNÇÕES DE PORTA */

Porta::Porta(unsigned NI){
    if (NI > NUM_MAX_INPUTS_PORTA) {
        cerr << "NUMERO DE INPUTS NA PORTA INVALIDO";
    } else {
        Nin = NI;
    }
}

Porta::Porta(const Porta &P){

}

int Porta::getId_in(unsigned i) const{
    if (i < Nin) {
        return id_in[Nin];
    } else {
        cerr << "ID_IN INVALIDO";
    }
}

void Porta::setId_in(unsigned i, int N){
    if (i < Nin) {
        if (N != 0)
            cerr << "N INVALIDO";

        id_in[i] = N;
    } else {
        cerr << "ID_IN INVALIDO";
    }
}

void Porta::digitar(){
    cout << "Quantidade de entradas: ";
    cin >> Nin;
    if(Nin >= 2 &&  Nin <= 4){
        for (unsigned i =0; i<Nin; i++){
            cout << "Id da entrada " << i +1 << ": ";
            cin >> id_in[i];
        }
    }
    else{
        cerr << "quantidade errada de entradas";
    }
    saida = UNDEF_3S;
}

bool Porta::ler(istream &I){
    I >> Nin;
    I.ignore(255,' ');
    for (unsigned i =0; i<Nin; i++){
        I >> this->id_in[i];
    }
    saida = UNDEF_3S;
    return true;
}

/* FUNÇÕES DE PORTA NOT */

void Porta_NOT::digitar(){
    cout<<"ID entrada: ";
    cin >> id_in[0];
    saida = UNDEF_3S;
}

/* FUNÇÕES DE PORTA OR */

/* FUNÇÕES DE PORTA AND */

/* FUNÇÕES DE PORTA NOR */

/* FUNÇÕES DE PORTA XOR */

/* FUNÇÕES DE PORTA NXOR */

void Circuito::alocar(unsigned NI, unsigned NO, unsigned NP){
    inputs.resize(NI);
    id_out.resize(NO);
    portas.resize(NP);
}

void Circuito::limpar(){
    inputs.clear();
    id_out.clear();
    portas.clear();
}