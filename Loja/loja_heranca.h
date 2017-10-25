#ifndef _LOJA_H_
#define _LOJA_H_

#include <iostream>
#include <string>
#include <limits>
#include <fstream>
#include <exception>
#include <typeinfo>

using namespace std;

class Produto{
private:
    string nome;
    unsigned preco;
public:
    inline Produto(const char *N="", unsigned P=0): nome(N), preco(P) {}
    istream &digitar(istream &I);
    ostream &imprimir(ostream &O) const;
    istream &ler(istream &I);
    inline ostream &salvar(ostream &O) const {return imprimir(O);}

    inline unsigned getPreco()const{return preco;}

};

inline istream &operator>>(istream &I, Produto &X) {return X.digitar(I);}
inline ostream &operator<<(ostream &O, Produto &X) {return X.imprimir(O);}


class Livro:public Produto{
private:
    string autor;
public:
    inline Livro(const char *nome="", unsigned P=0, const char *A=""): Produto(nome, P), autor(A){}
    ostream &imprimir(ostream &O)const;
    istream &digitar(istream &I);
    inline void setAutor(const char *A){autor=A;}
    inline string getAutor(){return autor;}
    istream &ler(istream &I);
    inline ostream &salvar(ostream &O) const {return imprimir(O);}
};

class CD:public Produto{
private:
    unsigned numFaixas;
public:
    inline CD(const char *nome="", unsigned P=0, unsigned NF=0): Produto(nome, P), numFaixas(NF){};
    ostream &imprimir(ostream &O)const;
    istream &digitar(istream &I);
    inline void setNF(unsigned NF){numFaixas=NF;}
    inline unsigned getNF(){return numFaixas;}
    istream &ler(istream &I);
    inline ostream &salvar(ostream &O) const {return imprimir(O);}

    inline unsigned getNumFaixas()const{return numFaixas;}
};

class DVD:public Produto{
private:
    unsigned duracao;
public:
    inline DVD(const char *nome="", unsigned P=0, unsigned D=0): Produto(nome, P), duracao(D){}
    ostream &imprimir(ostream &O)const;
    istream &digitar(istream &I);
    inline void setDuracao(unsigned D){duracao=D;}
    inline unsigned getDuracao()const{return duracao;}
    istream &ler(istream &I);
    inline ostream &salvar(ostream &O) const {return imprimir(O);}
};

inline ostream &operator<<(ostream &O, Livro &X) {return X.imprimir(O);}
inline ostream &operator<<(ostream &O, CD &X) {return X.imprimir(O);}
inline ostream &operator<<(ostream &O, DVD &X) {return X.imprimir(O);}

inline istream &operator>>(istream &I, Livro &X) {return X.digitar(I);}
inline istream &operator>>(istream &I, CD &X) {return X.digitar(I);}
inline istream &operator>>(istream &I, DVD &X) {return X.digitar(I);}

class ListaLivro{
private:
    Livro *x;
    unsigned N;
public:
    inline ListaLivro():x(NULL),N(0){}
    inline ~ListaLivro(){delete[] x; N=0;}
    void incluir(const Livro &L);
    void excluir(unsigned id);
    void imprimir() const;
    void ler(istream &I);
    void salvar(ostream &O) const;
};

class ListaCD{
private:
    CD *x;
    unsigned N;
public:
    inline ListaCD():x(NULL),N(0){}
    inline ~ListaCD(){delete[] x; N=0;}
    void incluir(const CD &L);
    void excluir(unsigned id);
    void imprimir() const;
    void ler(istream &I);
    void salvar(ostream &O) const;
};

class ListaDVD{
private:
    DVD *x;
    unsigned N;
public:
    inline ListaDVD():x(NULL),N(0){}
    inline ~ListaDVD(){delete[] x; N=0;}
    void incluir(const DVD &L);
    void excluir(unsigned id);
    void imprimir() const;
    void ler(istream &I);
    void salvar(ostream &O) const;
};

class Loja{
private:
    ListaLivro LL;
    ListaCD LC;
    ListaDVD LD;
public:
    inline Loja(): LL(), LC(), LD() {}
    inline void incluirLivro(const Livro &X) {LL.incluir(X);}
    inline void excluirLivro(unsigned id) {LL.excluir(id);}
    inline void incluirDVD(const DVD &X) {LD.incluir(X);}
    inline void excluirDVD(unsigned id) {LD.excluir(id);}
    inline void incluirCD(const CD &X) {LC.incluir(X);}
    inline void excluirCD(unsigned id) {LC.excluir(id);}
    void imprimir() const;
    void ler(const char* arq);
    void salvar(const char* arq) const;
};

#endif // _LOJA_H_
