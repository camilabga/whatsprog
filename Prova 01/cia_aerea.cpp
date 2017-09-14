#include "cia_aerea.h"

Voo::Voo(unsigned numV, unsigned hrCh, unsigned hrPt, string orig, string dest)
{
    if(numV >= 1000 && numV <=9999) numVoo = numV;
    else
    {
        cerr << "Numero do voo invalido, insira um valor entre 1000 e 9999!";
        return;
    }
    if(hrCh>=0000 && hrCh<=2359 && hrPt>=0000 && hrPt<=2359)
    {
        hrChegada = hrCh;
        hrPartida = hrPt;
    }
    else
    {
        cerr << "Formato de hora de chegada ou saida invalido, insira horas no formato (1230 = 12h30)!";
        return;
    }
    /*if(strlen(orig) == 3 && strlen(dest) == 3)
    {*/
        origem = orig;
        destino = dest;
    //}
    /*else
    {
        cerr << "Valor inserido para origem ou destino invalido!";
        return;
    }*/
}
void Voo::ler(istream &i)
{
    cout << "Numero do Voo, Hr de partida, Hr de chegada, Origem e Destino:" << endl;
    i >> numVoo;
    i >> hrPartida;
    i >> hrChegada;
    i >> origem;
    i >> destino;
}
void Voo::imprimir(ostream &o)
{
    o << "Numero do voo: " << numVoo << endl;
    o << "Hora de partida: " << hrPartida << endl;
    o << "Hora de chegada: " << hrChegada << endl;
    o << "Origem: " << origem << endl;
    o << "Destino " << destino << endl;
}
ostream &operator<<(ostream &o, Voo &A)
{
    A.imprimir(o);
    return o;
}
istream &operator>>(istream &i, Voo &A)
{
    A.ler(i);
    return i;
}

ListaVoos::ListaVoos(unsigned N)
{
    lista = new Voo[N];
}

ListaVoos::~ListaVoos()
{
    delete[] lista;
    N = 0;
}

void ListaVoos::copiar(const ListaVoos &L)
{
    for(unsigned i=0; i<L.N; i++)
        lista[i] = L.lista[i];
    N = L.N;
}

void ListaVoos::inserir(const Voo &V)
{

}
