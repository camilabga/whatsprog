#include <iostream>
#include <cstring>

using namespace std;

class Voo
{
private:
    unsigned numVoo, hrChegada, hrPartida;
    string origem, destino;

public:
    Voo(): numVoo(0), hrChegada(0), hrPartida(0), origem(NULL), destino(NULL) {}
    Voo(unsigned numV, unsigned hrCh, unsigned hrPt, string orig, string dest);
    inline ~Voo() {};

    void ler(istream &i);
    void imprimir(ostream &o);

    friend ostream &operator<<(ostream &o, Voo &A);
    friend istream &operator>>(istream &i, Voo &A);

    friend class Lista_Voos;
};

class ListaVoos
{
private:
    Voo *lista;
    unsigned N;

public:
    ListaVoos(): lista(NULL), N(0) {}
    inline ListaVoos(const ListaVoos &L) {copiar(L);}
    ListaVoos(unsigned N);
    ~ListaVoos();

    void copiar(const ListaVoos &L);
    void inserir(const Voo &V);
};
