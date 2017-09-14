#include <cmath>
#include "vetor.h"

Vetor::Vetor(const Vetor &V)
{
    N = V.N;
    if (N>0)
    {
        x = new double[N];
        for (unsigned i=0; i<N; i++) x[i] = V.x[i];
    }
    else
    {
        x = NULL;
    }
}

Vetor::Vetor(int Num)
{
    if (Num<=0)
    {
        cerr << "Dimensao invalida\n";
        N = 0;
        x = NULL;
        return;
    }
    N = Num;
    x = new double[N];
}

Vetor::~Vetor()
{
    delete[] x;
    x = NULL;
    N = 0;
}

void Vetor::operator=(const Vetor &V)
{
    // Primeiro, testa se o usuario nao estah fazendo uma atribuicao redundante, tal como A=A
    if (this != &V)
    {
        // Em seguida, testa se a dimensao dos dois vetores eh a mesma
        // Se for, nao precisa desalocar e alocar de novo com outro tamnho.
        // Dah para aproveitar a mesma area, copiando soh os valores dos elementos
        if (this->N != V.N)
        {
            // Repito o codigo do destrutor
            delete[] this->x;

            // Repito o codigo do construtort por copia
            this->N = V.N;
            if (N>0)
            {
                x = new double[N];
            }
            else
            {
                x = NULL;
            }
        }
        for (unsigned i=0; i<N; i++) x[i] = V.x[i];
    }
}

double Vetor::operator[](int i) const
{
    if (i>=N || i<0)
    {
        cerr << "Indice invalido\n";
        return 0.0;
    }
    return x[i];
}

double &Vetor::operator[](int i)
{
    static double prov=0.0;
    if (i>=N || i<0)
    {
        cerr << "Indice invalido\n";
        return prov;
    }
    return x[i];
}

ostream &operator<<(ostream &X, const Vetor &V)
{
    X << '[';
    for (unsigned i=0; i<V.N; i++) X << V.x[i] << (i+1==V.N ? ']' : ';');
}

istream &operator>>(istream &X, Vetor &V)
{
    for (unsigned i=0; i<V.N; i++) X >> V.x[i];
}

Vetor Vetor::operator+(const Vetor &V) const
{
    if (N!=V.N)
    {
        cerr << "Dimensoes incompativeis\n";
        return Vetor();
    }
    if (N==0) return Vetor();
    Vetor prov(N);
    for (unsigned i=0; i<N; i++) prov.x[i] = x[i] + V.x[i];
    return prov;
}

Vetor Vetor::operator-(const Vetor &V) const
{
    if (N!=V.N)
    {
        cerr << "Dimensoes incompativeis\n";
        return Vetor();
    }
    if (N==0) return Vetor();
    Vetor prov(N);
    for (unsigned i=0; i<N; i++) prov.x[i] = x[i] - V.x[i];
    return prov;
}

double Vetor::norma() const
{
    double soma(0.0);
    for (unsigned i=0; i<N; i++) soma += x[i]*x[i];
    return sqrt(soma);
}

double Vetor::escalar(const Vetor &V) const
{
    if (N!=V.N)
    {
        cerr << "Dimensoes incompativeis\n";
        return 0.0;
    }
    if (N==0) return 0.0;
    double prov(0.0);
    for (unsigned i=0; i<N; i++) prov += x[i]*V.x[i];
    return prov;
}

Vetor Vetor::vetorial(const Vetor &V) const
{
    if (N!=3 || N!=V.N)
    {
        cerr << "Dimensoes incompativeis\n";
        return Vetor();
    }
    Vetor prov(3);
    prov.x[0] = x[1]*V.x[2] - x[2]*V.x[1];
    prov.x[1] = x[2]*V.x[0] - x[0]*V.x[2];
    prov.x[2] = x[0]*V.x[1] - x[1]*V.x[0];
    return prov;
}
