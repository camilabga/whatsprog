#include <iostream>
#include <cmath>

using namespace std;

class Ponto {
    private:
    float x;
    float y;

    public:
    Ponto();
    Ponto(float x, float y);
    void imprimir();
    float distancia(Ponto a);
    float getX();
    float getY();
    void setX(int x1);
    void setY(int y1);
};

class Retangulo {
    private:
    Ponto suD;
    Ponto inE;

    public:
    Retangulo();
    Retangulo(Ponto x1, Ponto x2, Ponto x3, Ponto x4);
    float area();
    bool pontoInterno(Ponto x);
};