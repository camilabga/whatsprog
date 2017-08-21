#include "questao01.h"

Ponto::Ponto(){
    x = 0;
    y = 0;
}

Ponto::Ponto(float x1, float y1){
    x = x1;
    y = y1;
}

float Ponto::getX(){
    return x;
}

float Ponto::getY(){
    return y;
}

void Ponto::setX(int x1){
    x = x1;
}

void Ponto::setY(int y1){
    y = y1;
}

void Ponto::imprimir(){
    cout << "x = " << x << endl << "y = " << y << endl;
}

float Ponto::distancia(Ponto a){
    float x1 = a.getX();
    float y1 = a.getY();

    return (sqrt((x-x1)*(x-x1) + (y-y1)*(y-y1) ));
}

Retangulo::Retangulo(){
    b1.setX(0);
    b1.setY(0);
    b1.setX(1);
    b1.setY(0);
    c1.setX(0);
    c1.setY(1);
    c2.setX(1);
    c2.setY(1);
}

Retangulo::Retangulo(Ponto x1, Ponto x2, Ponto x3, Ponto x4){
    if ((((x1.getX() == x2.getX()) && (x1.getY() != x2.getY())) || ((x1.getX() == x3.getX()) && 
    (x1.getY() != x3.getY())) || ((x1.getX() == x4.getX()) && (x1.getY() != x4.getY()))) &&
     ){

    } else {

    }
    
    
    b1 = x1;
    b2 = x2;
    c1 = x3;
    c2 = x4;



}

float Retangulo::area(){
    if ((b2.getX()-b1.getX())*(c1.getY()-b1.getY()) < 0) {
        return -(b2.getX()-b1.getX())*(c1.getY()-b1.getY());
    }

    return (b2.getX()-b1.getX())*(c1.getY()-b1.getY());
    
}

bool Retangulo::pontoInterno(Ponto x){
    return true;
}