#include "poly.h"
#include <cmath>

using namespace std;

void Poly::copiar(const Poly &P){
    criar(P.grau);
    for (unsigned i = 0; i < grau; i++) {
        coef[i] = P.coef[i];
    }
}

void Poly::limpar(){
    grau = 0;
    if (coef != NULL) delete[] coef;
    coef = NULL;
}

void Poly::criar(unsigned grau){
    if (grau >= 0) {
        this->grau = grau;
        coef = new double[grau];
    } else {
        cout << "Grau invalido" << endl;
        grau = 0;
        coef = NULL;
    }
}

ostream &operator<<(ostream &X, const Poly &P){
    if (P.grau == 0){
        cerr << "Polinomio de dimensao nula\n";
        return X;
    }

    X << P.coef[0] << " + ";
    X << P.coef[1] << "x + ";
    for (unsigned i=2; i<P.grau-1; i++){
        X << P.coef[i] << "x^" << i << " + ";
    }
    X << P.coef[P.grau-1] << "x^" << P.grau-1 << endl; 
    
    return X;
}

istream &operator>>(istream &X, Poly &P){
    if (P.grau == 0){
        cerr << "Polinomio de dimensao nula\n";
        return X;
    }

    for (unsigned i=0; i<P.grau; i++){
        cout << "Coeficiente " << i << ": ";
        X >> P.coef[i];
     }

    return X;
}

Poly Poly::operator+(const Poly &P) const{
    unsigned maior = grau, g;
    if (P.grau > grau) maior = P.grau;
    for (int i = maior-1; i >= 0; i--) {
        if (coef[i]+P.coef[i]!=0) {
            g = i;
            continue;
        } else {
            g = i;
            break;
        }
    }

    Poly soma(g);

    for (int i = 0; i < grau; i++) {
        soma.coef[i] = coef[i]+P.coef[i];
    }

    return soma;
}

Poly Poly::operator*(const Poly &P) const{
    Poly mult(P.grau+grau);
    for (int i = 0; i < grau; i++) {
        for (int j= 0; j < P.grau; j++) {

        }
    }
    return mult;
}

double Poly::operator()(double n) const{
    double r=0;
    for(unsigned i = 0; i < grau; i++){
        r = r + coef[i] * pow(n, i);
    }
    return r;
}

double Poly::operator[](unsigned i) const{
    if (i >= 0 && i <= grau) {
        return coef[i];
    } else {
        cout << "Grau invalido" << endl;
    }
}