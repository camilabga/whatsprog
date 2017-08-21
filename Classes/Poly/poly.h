#ifndef _POLY_H_
#define _POLY_H_

#include <iostream>
using namespace std;

class Poly{
private:
    unsigned grau;
    double *coef;

    void copiar(const Poly &P);
    void limpar();
    void criar(unsigned grau);

public:
    inline Poly(){grau = 0; coef = NULL;}
    inline Poly(Poly &P){copiar(P);}
    explicit inline Poly(unsigned grau) {criar(grau);}
    inline ~Poly(){limpar();}

    friend ostream &operator<<(ostream &X, const Poly &P);
    friend istream &operator>>(istream &X, Poly &P);

    inline void operator=(const Poly &P) {if (this!=&P) {limpar(); copiar(P);}}
    Poly operator+(const Poly &P) const;
    Poly operator*(const Poly &P) const;
    double operator()(double n) const;
    double operator[](unsigned i) const;
};

#endif // _POLY_H_