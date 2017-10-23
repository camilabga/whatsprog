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
        if (N == 0)
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
    if(Nin > 1 &&  Nin < NUM_MAX_INPUTS_PORTA){
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

ostream &Porta_OR::imprimir(ostream &O) const{
    O << "OR " << Nin << ": ";
    Porta::imprimir(O);
    return O;
}

bool_3S Porta_OR::simular(const bool_3S in[]){
    switch (Nin){
        case 2:
            if(in[0] == TRUE_3S || in[1] == TRUE_3S){
                saida = TRUE_3S;
            } else if(in[0] == UNDEF_3S || in[1] == UNDEF_3S){
                saida = UNDEF_3S;
            } else {
                saida = FALSE_3S;
            }
            break;
        case 3:
            if(in[0] == TRUE_3S || in[1] == TRUE_3S || in[2] == TRUE_3S){
                saida = TRUE_3S;
                return saida;
            }else if(in[0] == UNDEF_3S || in[1] == UNDEF_3S || in[2] == UNDEF_3S){
                saida = UNDEF_3S;
            }else{
                saida = FALSE_3S;
            }
            break;
        case 4:
            if(in[0] == TRUE_3S || in[1] == TRUE_3S || in[2] == TRUE_3S || in[3] == TRUE_3S){
                saida = TRUE_3S;
            }else if(in[0] == UNDEF_3S || in[1] == UNDEF_3S || in[2] == UNDEF_3S || in[3] == UNDEF_3S){
                saida = UNDEF_3S;
            }else{
                saida = FALSE_3S;
            }
            break;
        default:
            cerr << "Numero de entradas invalido.";
            return UNDEF_3S;
    }

    return saida;
}

/* FUNÇÕES DE PORTA AND */

ostream &Porta_AND::imprimir(ostream &O) const{
    O << "AN " << Nin << ": ";
    Porta::imprimir(O);
    return O;
}

bool_3S Porta_AND::simular(const bool_3S in[]){
    switch (Nin){
        case 2:
            if (in[0] == TRUE_3S && in[1] == TRUE_3S) {
                saida = TRUE_3S;
            } else if (in[0] == FALSE_3S || in[1] == FALSE_3S) {
                saida = FALSE_3S;
            } else {
                saida = UNDEF_3S;
            }
        break;

        case 3:
            if (in[0] == TRUE_3S && in[1] == TRUE_3S
                && in[2] == TRUE_3S) {
                saida = TRUE_3S;
            } else if (in[0] == FALSE_3S || in[1] == FALSE_3S
                || in[2] == FALSE_3S) {
                saida = FALSE_3S;
            } else {
                saida = UNDEF_3S;
            }
        break;

        case 4:
            if (in[0] == TRUE_3S && in[1] == TRUE_3S
                && in[2] == TRUE_3S && in[3] == TRUE_3S) {
                saida = TRUE_3S;
            } else if (in[0] == FALSE_3S || in[1] == FALSE_3S
                || in[2] == FALSE_3S || in[3] == FALSE_3S) {
                saida = FALSE_3S;
            } else {
                saida = UNDEF_3S;
            }
        break;

        default:
            cerr << "Numero de entradas invalido.";
            return UNDEF_3S;

    }

    return saida;
}

/* FUNÇÕES DE PORTA NAND */

ostream &Porta_NAND::imprimir(ostream &O) const{
    O << "NA " << Nin << ": ";
    Porta::imprimir(O);
    return O;
}

bool_3S Porta_NAND::simular(const bool_3S in[]){
    switch (Nin){
        case 2:
            if (in[0] == TRUE_3S && in[1] == TRUE_3S) {
                saida = FALSE_3S;
            } else if (in[0] == FALSE_3S || in[1] == FALSE_3S) {
                saida = TRUE_3S;
            } else {
                saida = UNDEF_3S;
            }
        break;

        case 3:
            if (in[0] == TRUE_3S && in[1] == TRUE_3S
                && in[2] == TRUE_3S) {
                saida = FALSE_3S;
            } else if (in[0] == FALSE_3S || in[1] == FALSE_3S
                || in[2] == FALSE_3S) {
                saida = TRUE_3S;
            } else {
                saida = UNDEF_3S;
            }
        break;

        case 4:
            if (in[0] == TRUE_3S && in[1] == TRUE_3S
                && in[2] == TRUE_3S && in[3] == TRUE_3S) {
                saida = FALSE_3S;
            } else if (in[0] == FALSE_3S || in[1] == FALSE_3S
                || in[2] == FALSE_3S || in[3] == FALSE_3S) {
                saida = TRUE_3S;
            } else {
                saida = UNDEF_3S;
            }
        break;

        default:
            cerr << "Numero de entradas invalido.";
            return UNDEF_3S;

    }

    return saida;
}


/* FUNÇÕES DE PORTA NOR */

ostream &Porta_NOR::imprimir(ostream &O) const{
    O << "NO " << Nin << ": ";
    Porta::imprimir(O);
    return O;
}

bool_3S Porta_NOR::simular(const bool_3S in[]){
    switch (Nin){
        case 2:
            if(in[0] == TRUE_3S || in[1] == TRUE_3S){
                saida = FALSE_3S;
            } else if(in[0] == UNDEF_3S || in[1] == UNDEF_3S){
                saida = UNDEF_3S;
            } else {
                saida = TRUE_3S;
            }

            break;
        case 3:
            if(in[0] == TRUE_3S || in[1] == TRUE_3S || in[2] == TRUE_3S){
                saida = FALSE_3S;
                return saida;
            }else if(in[0] == UNDEF_3S || in[1] == UNDEF_3S || in[2] == UNDEF_3S){
                saida = UNDEF_3S;
            }else{
                saida = TRUE_3S;
            }
            break;
        case 4:
            if(in[0] == TRUE_3S || in[1] == TRUE_3S || in[2] == TRUE_3S || in[3] == TRUE_3S){
                saida = FALSE_3S;
            }else if(in[0] == UNDEF_3S || in[1] == UNDEF_3S || in[2] == UNDEF_3S || in[3] == UNDEF_3S){
                saida = UNDEF_3S;
            }else{
                saida = TRUE_3S;
            }
            break;
        default:
            cerr << "Numero de entradas invalido.";
            return UNDEF_3S;
    }

    return saida;
}

/* FUNÇÕES DE PORTA XOR */

ostream &Porta_XOR::imprimir(ostream &O) const{
    O << "XO " << Nin << ": ";
    Porta::imprimir(O);
    return O;
}

bool_3S Porta_XOR::simular(const bool_3S in[]){
    switch (Nin){
        case 2:
            if(in[0] == UNDEF_3S || in[1] == UNDEF_3S){
                saida = UNDEF_3S;
            } else if(in[0] == in[1]){
                saida = FALSE_3S;
            } else{
                saida = TRUE_3S;
            }

            break;

        case 3:
            if(in[0] == UNDEF_3S || in[1] == UNDEF_3S || in[2] == UNDEF_3S){
                saida = UNDEF_3S;
            }else if(in[0] == in[1] && in[0] == in[2]){
                saida = FALSE_3S;
            }else{
                saida = TRUE_3S;
            }
            break;

        case 4:
            if(in[0] == UNDEF_3S || in[1] == UNDEF_3S || in[2] == UNDEF_3S 
                || in[3] == UNDEF_3S){
                saida = UNDEF_3S;
            }else if(in[0] == in[1] && in[0] == in[2] && in[0] == in[3]){
                saida = FALSE_3S;
            }else{
                saida = TRUE_3S;
            }
            break;

        default:
            cerr << "Numero de entradas invalido.";
            return UNDEF_3S;
    }

    return saida;
}

/* FUNÇÕES DE PORTA NXOR */

ostream &Porta_NXOR::imprimir(ostream &O) const{
    O << "NX " << Nin << ": ";
    Porta::imprimir(O);
    return O;
}

bool_3S Porta_NXOR::simular(const bool_3S in[]){
    switch (Nin){
        case 2:
            if(in[0] == UNDEF_3S || in[1] == UNDEF_3S){
                saida = UNDEF_3S;
            } else if(in[0] == in[1]){
                saida = TRUE_3S;
            } else{
                saida = FALSE_3S;
            }

            break;

        case 3:
            if(in[0] == UNDEF_3S || in[1] == UNDEF_3S || in[2] == UNDEF_3S){
                saida = UNDEF_3S;
            }else if(in[0] == in[1] && in[0] == in[2]){
                saida = TRUE_3S;
            }else{
                saida = FALSE_3S;
            }
            break;

        case 4:
            if(in[0] == UNDEF_3S || in[1] == UNDEF_3S || in[2] == UNDEF_3S 
                || in[3] == UNDEF_3S){
                saida = UNDEF_3S;
            }else if(in[0] == in[1] && in[0] == in[2] && in[0] == in[3]){
                saida = TRUE_3S;
            }else{
                saida = FALSE_3S;
            }
            break;

        default:
            cerr << "Numero de entradas invalido.";
            return UNDEF_3S;
    }

    return saida;
}

/* FUNÇÕES DE CIRCUITO */

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

void Circuito::simular(){
    for (unsigned i = 0; i < Nportas; i++) {
        portas[i]->setSaida(UNDEF_3S);
    }

    bool tudo_def, alguma_def;
    bool_3S in_porta[NUM_MAX_INPUTS_PORTA];

    do {
        tudo_def = true;
        alguma_def = false;

        for (unsigned i = 0; i < Nportas; i++) {
            if (portas[i]->getSaida() == UNDEF_3S) {

                for (unsigned j = 0; j < portas[i]->getNumInputs(); i++) {
                    if (portas[i]->getId_in(j) < 0)
                        in_porta[j] = inputs[-1*(portas[i]->getId_in(j))-1];

                    if (portas[i]->getId_in(j) > 0)
                        in_porta[j] = portas[portas[i]->getId_in(j)-1]->getSaida();
                }

                portas[i]->simular(in_porta);

                if (portas[i]->getSaida() == UNDEF_3S) {
                    tudo_def = false;
                } else {
                    alguma_def = true;
                }
            }
        }

    } while(!tudo_def && alguma_def);
}