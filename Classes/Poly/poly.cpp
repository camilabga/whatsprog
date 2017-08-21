#include "poly.h"

using namespace std;

void Poly::copiar(const Poly &P);
void Poly::limpar(){
    grau = 0;
    if (coef =! NULL) delete[] coef;
    coef = NULL;
}

void Poly::criar(unsigned grau);

friend ostream &operator<<(ostream &X, const Poly &P);
friend istream &operator>>(istream &X, Poly &P);

Poly Poly::operator+(const Poly &P) const;
Poly Poly::operator*(const Poly &P) const;
double Poly::operator()(double n) const;
double Poly::operator[](unsigned i) const;