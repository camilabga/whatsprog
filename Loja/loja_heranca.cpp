#include "loja_heranca.h"

// sair dados

ostream &Produto::imprimir(ostream &O)const {
    O<<"\""<<nome<<"\";$"; // barra invertida p entrar a aspa
    O<<preco/100<<".";
    O<<(preco%100)/10<<preco%10;
    return O;
}

ostream &Livro::imprimir(ostream &O)const{
    Produto::imprimir(O);
    O<<";\""<<autor<<"\""<<endl;
}

ostream &CD::imprimir(ostream &O)const{
    Produto::imprimir(O);
    O<<";"<<numFaixas<<endl;
    return O;
}

ostream &DVD::imprimir(ostream &O)const{
    Produto::imprimir(O);
    O<<";"<<duracao<<endl;
    return O;
}

void ListaLivro::imprimir()const{
    cout<<"LISTALIVRO "<<N<<endl;
    for(unsigned i=0;i<N;i++)
        cout<<i+1<<") L: "<<x[i];
}

void ListaCD::imprimir()const{
    cout<<"LISTACD "<<N<<endl;
    for(unsigned i=0;i<N;i++)
        cout<<i+1<<") C: "<<x[i];
}

void ListaDVD::imprimir()const{
    cout<<"LISTADVD "<<N<<endl;
    for(unsigned i=0;i<N;i++)
        cout<<i+1<<") D: "<<x[i];
}

void Loja::imprimir() const{
    LL.imprimir();
    LC.imprimir();
    LD.imprimir();   
}

// entrar dados

istream &Produto::digitar(istream &I){
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout<<"Nome: ";
    getline(I,nome,'\n');
    float preco1;
    cout<<"Preco: ";
    I>>preco1;
    while (cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Entrada incorreta, tente novamente" << endl;
        cout<<"Preco: ";
        I>>preco1;
    }
    
    preco = (unsigned)(preco1*100);
    
}

istream &Livro::digitar(istream &I){
    Produto::digitar(I);
    cout<<"Autor: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(I,autor,'\n');
    return I;
}

istream &CD::digitar(istream &I){
    Produto::digitar(I);
    cout<<"Nº Faixas: ";
    I>>numFaixas;

    while (cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Entrada incorreta, tente novamente" << endl;
        cout<<"Nº Faixas: ";
        I>>numFaixas;
    }

    return I;
}

istream &DVD::digitar(istream &I){
    Produto::digitar(I);
    cout<<"Duracao: ";
    I>>duracao;

    while (cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Entrada incorreta, tente novamente" << endl;
        cout<<"Duracao: ";
        I>>duracao;
    }

    return I;
}

// ler

istream &Produto::ler(istream &I){
    I.ignore(numeric_limits<streamsize>::max(), '"');
    getline(I,nome,'"');
    I.ignore(numeric_limits<streamsize>::max(), '$');
    unsigned unid,cent;
    I>>unid;
    I.ignore(numeric_limits<streamsize>::max(), '.');
    I>>cent;
    preco=unid*100+cent;    
    I.ignore(numeric_limits<streamsize>::max(), ';');
}

istream &Livro::ler(istream &I){
    Produto::ler(I);
    I.ignore(numeric_limits<streamsize>::max(), '"');
    getline(I,autor,'"');
}

istream &CD::ler(istream &I){
    Produto::ler(I);
    I>>numFaixas;
}

istream &DVD::ler(istream &I){
    Produto::ler(I);
    I>>duracao;
}

// FUNCOES LISTAS

// incluir

void ListaLivro::incluir(const Livro &L){
    Livro *prov = new Livro[N+1];
    for(unsigned i=0;i<N;i++)
        prov[i]=x[i];
    prov[N]=L;
    N++;    
    delete[] x;
    x=prov;
}

void ListaCD::incluir(const CD &C){
    CD *prov = new CD[N+1];
    for (unsigned i = 0; i < N; i++)
        prov[i] = x[i];
    prov[N] = C;
    N++;
    delete[] x;
    x = prov;
}

void ListaDVD::incluir(const DVD &D){
    DVD *prov = new DVD[N+1];
    for (unsigned i = 0; i < N; i++)
        prov[i] = x[i];
    prov[N] = D;
    N++;
    delete[] x;
    x = prov;
}

// excluir

void ListaCD::excluir(unsigned id){
    id--;
    CD *prov = new CD[N-1];
    for(unsigned i=0;i<id;i++)
        prov[i]=x[i];
    for(unsigned i=id;i<N-1;i++)
        prov[i]=x[i+1];
    delete[] x;
    x=prov;
    N--;
}

void ListaLivro::excluir(unsigned id){
    id--;
    Livro *prov = new Livro[N-1];
    for(unsigned i=0;i<id;i++)
        prov[i]=x[i];
    for(unsigned i=id;i<N-1;i++)
        prov[i]=x[i+1];
    delete[] x;
    x=prov;
    N--;
}

void ListaDVD::excluir(unsigned id){
    id--;
    DVD *prov = new DVD[N-1];
    for(unsigned i=0;i<id;i++)
        prov[i]=x[i];
    for(unsigned i=id;i<N-1;i++)
        prov[i]=x[i+1];
    delete[] x;
    x=prov;
    N--;
}

// salvar

void ListaLivro::salvar(ostream &O) const{
    O<<"LISTALIVRO "<<N<<endl;
    for(unsigned i=0;i<N;i++){    
        O<<"L: ";
        O<<x[i];
    }
}

void ListaCD::salvar(ostream &O) const{
    O<<"LISTACD "<<N<<endl;
    for(unsigned i=0;i<N;i++){    
        O<<"C: ";
        O<<x[i];
    }
}

void ListaDVD::salvar(ostream &O) const{
    O<<"LISTADVD "<<N<<endl;
    for(unsigned i=0;i<N;i++){    
        O<<"D: ";
        O<<x[i];
    }
}

void Loja::salvar(const char* arq) const{
    ofstream arquivo(arq);
    LL.salvar(arquivo);
    LC.salvar(arquivo);
    LD.salvar(arquivo);
    arquivo.close();
}

// ler

void ListaLivro::ler(istream &I){
    Livro L;
    L.ler(I);
    incluir(L);
}

void ListaCD::ler(istream &I){
    CD C;
    C.ler(I);
    incluir(C);
}

void ListaDVD::ler(istream &I){
    DVD D;
    D.ler(I);
    incluir(D);
}

void Loja::ler(const char* arq){
    ifstream arquivo(arq); 
    string prov;
    unsigned tam;
    arquivo>>prov>>tam;
    if(prov=="LISTALIVRO")    
        for(unsigned i=0;i<tam;i++)
            LL.ler(arquivo);
    arquivo>>prov>>tam;
    if(prov=="LISTACD")
        for(unsigned i=0;i<tam;i++)
            LC.ler(arquivo);
    
    arquivo>>prov>>tam;
    if(prov=="LISTADVD")     
        for(unsigned i=0;i<tam;i++)
            LD.ler(arquivo);
}