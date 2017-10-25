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
        return id_in[i];
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
    Nin = NI;
    Nout = NO;
    Nportas = NP;
}

void Circuito::limpar(){
    inputs.clear();
    id_out.clear();
    portas.clear();
    Nin = 0;
    Nout = 0;
    Nportas = 0;
}

void Circuito::digitar(){
    int NI, NO, NP;
    do{
        cout<<"Quantidade de entradas: ";
        cin>>NI;
    } while(NI>4);
    do{
        cout<<"Quantidade de saidas: ";
        cin>>NO;
    } while(NO<=0);
    cout<<"Quantidade de portas: ";
    cin>>NP;
    limpar();
    alocar(NI,NO,NP);

    unsigned cont=0;
    Porta_NOT NT;
    Porta_AND AN;
    Porta_NAND NA;
    Porta_OR OR;
    Porta_NOR NOR;
    Porta_XOR XO;
    Porta_NXOR NX;
    string tipo;
    do{
        cout << "digite o tipo da porta " << cont+1 << ": ";
        cin >> tipo;
        if(tipo == "NT") portas[cont] = (&NT) -> clone();
        else if(tipo == "AN") portas[cont] = (&AN) -> clone();
        else if(tipo == "NA") portas[cont] = (&NA) -> clone();
        else if(tipo == "OR") portas[cont] = (&OR) -> clone();
        else if(tipo == "NO") portas[cont] = (&NOR) -> clone();
        else if(tipo == "XO") portas[cont] = (&XO) -> clone();
        else if(tipo == "NX") portas[cont] = (&NX) -> clone();
        else{
            cerr << "Tipo de porta inesistente.";
            limpar();
            return;
        }
        portas[cont] -> digitar();
        cont++;
    } while(cont < Nportas);
    int ID;
    for(unsigned i=0; i < Nout; i++) {
        cout << "ID do sinal que vai para a saida " << i+1 << endl;
        cin >> ID;
        if(ID <= Nportas){
            id_out[i] = ID;
        } else {
            cerr << "id invalido.";
            return;
        }
    }
}

void Circuito::ler(const char *arq){
    ifstream arquivo(arq);
    string prov, tipo;
    int NI, NO, NP, Nin;
    if (arquivo.is_open()){
        arquivo>>prov>>NI>>NO>>NP;
        if(prov!="CIRCUITO:"||NI<=0||NO<=0||NP<=0){
            cerr<<"Erro: Cabecalho 'CIRCUITO:'";
            return;
        }
        limpar();
        alocar(NI,NO,NP);
        arquivo.ignore(255,'\n');

        arquivo>>prov;

        if(prov!="PORTAS"){
            cerr<<"Erro: Palavra chave 'PORTAS:'";
            return;
        }
        arquivo.ignore(255,'\n');

        Porta_NOT NT;
        Porta_AND AN;
        Porta_NAND NA;
        Porta_OR OR;
        Porta_NOR NOR;
        Porta_XOR XO;
        Porta_NXOR NX;
        int i=0, int_prov;
        do{
            arquivo >> int_prov;
            if(int_prov != i+1){
                cerr<<"Portas fora de ordem, ou faltando\n";
                return;
            }
            arquivo.ignore(255, ' ');
            arquivo >> tipo;
            if(tipo == "NT") portas[i] = (&NT) -> clone();
            else if(tipo == "AN") portas[i] = (&AN) -> clone();
            else if(tipo == "NA") portas[i] = (&NA) -> clone();
            else if(tipo == "OR") portas[i] = (&OR) -> clone();
            else if(tipo == "NO") portas[i] = (&NOR) -> clone();
            else if(tipo == "XO") portas[i] = (&XO) -> clone();
            else if(tipo == "NX") portas[i] = (&NX) -> clone();  
            else cerr<<"Tipo de porta inexistentes";
            portas[i]->ler(arquivo);
        } while(i < NP);
        arquivo>>prov;
        if(prov!="SAIDAS:"){
            cerr<<"Erro: Palavra chave 'SAIDAS:'";
            return;
        }
        arquivo.ignore(255, '\n');
        i=0;
        do{
            arquivo >> int_prov;
            if(int_prov != i+1){
                cerr<<"Saidas fora de ordem, ou fantando\n";
                return;
            }
            arquivo.ignore(255, ' ');
            arquivo >> int_prov;
            if(int_prov>NP||int_prov==0){
                cerr<<"Id out > Nportas";
                return;
            }
            id_out[i]=int_prov;
            i++;
        }  while(i<NO);
    }
    
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

                for (unsigned j = 0; j < portas[i]->getNumInputs(); j++) {
                    
                    if (portas[i]->getId_in(j) < 0){
                        in_porta[j] = inputs[-1*(portas[i]->getId_in(j))-1];
                    }

                    if (portas[i]->getId_in(j) > 0){
                        in_porta[j] = portas[portas[i]->getId_in(j)-1]->getSaida();
                    }
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

    for (unsigned i = 0; i < Nportas; i++) {
        cout << endl << "saida = " << portas[i]->getSaida() << endl;
    }

}