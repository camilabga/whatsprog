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
    Nin = P.getNumInputs();
    saida = P.getSaida();
    for (unsigned i = 0; i < Nin; i++) id_in[i] = P.getId_in(i);
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

void Porta::setSaida(bool_3S s){
    switch (s){
        case TRUE_3S:
            saida = TRUE_3S;
            break;
        case FALSE_3S:
            saida = FALSE_3S;
        default:
            saida = UNDEF_3S;
    }
}

void Porta::digitar(){
    cout << "Quantidade de entradas: ";
    cin >> Nin;
    if(Nin > 1 &&  Nin <= NUM_MAX_INPUTS_PORTA){
        for (unsigned i =0; i<Nin; i++){
            cout << "Id da entrada " << i << ": ";
            cin >> id_in[i];
        }
    } else {
        cerr << "Quantidade errada de entradas";
    }
    
    saida = UNDEF_3S;
}

bool Porta::ler(istream &I){
    I >> Nin;
    I.ignore(256,' ');

    if (Nin > NUM_MAX_INPUTS_PORTA || Nin < 1){
        cerr << "NUMERO DE INPUTS NA PORTA INVALIDO";
        return false;
    }

    for (unsigned i =0; i<Nin; i++){
        I >> this->id_in[i];
    }

    saida = UNDEF_3S;
    return true;
}

ostream &Porta::imprimir(ostream &O) const{
    if(Nin > 0 &&  Nin < 4){
        for (unsigned i =0; i<Nin; i++){
            O << id_in[i] << " ";
        }
    }
    return O;
}

/* FUNÇÕES DE PORTA NOT */

void Porta_NOT::digitar(){
    Nin = 1;
    cout<<"ID entrada: ";
    cin >> id_in[0];
    saida = UNDEF_3S;
}

bool Porta_NOT::ler(istream &I){
    I >> Nin;
    if(Nin!=1){
        cerr << "NUMERO DE INPUTS NA PORTA INVALIDO";
        return false;
    }
    I.ignore(255,' ');
    I >> this->id_in[0];
    saida = UNDEF_3S;
    return true;
}

ostream &Porta_NOT::imprimir(ostream &O) const{
    O << "NT " << Nin << ": ";
    O << id_in[0] << " ";
    return O;
}

bool_3S Porta_NOT::simular(const bool_3S in[]){
    if(in[0] == TRUE_3S){
        saida = FALSE_3S;
    } else if(in[0] == FALSE_3S){
        saida = TRUE_3S;
    }else{
        saida = UNDEF_3S;
    }

    return saida;
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