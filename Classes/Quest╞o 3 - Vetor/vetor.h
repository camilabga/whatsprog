#ifndef _VETOR_H_
#define _VETOR_H_

#include <iostream>

using namespace std;

class Vetor
{
private:
    unsigned N;
    double *x;
public:
    inline Vetor(): N(0), x(NULL) {}
    Vetor(const Vetor &V);
    explicit Vetor(int Num);
    ~Vetor();
    void operator=(const Vetor &V);

    inline unsigned dimensao() const {return N;}
    double operator[](int i) const;
    double &operator[](int i);

    friend ostream &operator<<(ostream &X, const Vetor &V);
    friend istream &operator>>(istream &X, Vetor &V);

    Vetor operator+(const Vetor &V) const;
    Vetor operator-(const Vetor &V) const;

    double norma() const;
    double escalar(const Vetor &V) const;
    Vetor vetorial(const Vetor &V) const;
};

#endif
