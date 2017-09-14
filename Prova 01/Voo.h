#include <iostream>
#include <string>

using namespace std;

class Voo {
private:
    int num;
    string origem;
    string destino;
    unsigned int partida;
    unsigned int chegada;

public:
    Voo();
    Voo(Voo &voo);
    Voo(int num, string origem, string destino, unsigned int partida, unsigned int chegada);

    inline int getNum(){return num;}
    inline string getOrigem(){return origem;}
    inline string getDestino(){return destino;}
    inline unsigned int getPartida(){return partida;}
    inline unsigned int getChegada(){return chegada;}

    friend ostream &operator<<(ostream &X, const Voo &V);
    friend istream &operator>>(istream &X, Voo &V);

    void setNum(int num);
    void setOrigem(string origem);
    void setDestino(string destino);
    void setPartida(unsigned int partida);
    void setChegada(unsigned int chegada);

};


class Lista_Voos{
private:
    Voo *lista;
    unsigned n;

    void criar(unsigned num);
    void limpar();
    void copiar(const Lista_Voos &L);

public:
    inline Lista_Voos(){n = 0; lista = NULL;}
    inline Lista_Voos(unsigned num){criar(num);}

    void inserir(Voo &V);
    void imprimir();
    void imprimir(string aero);

};
