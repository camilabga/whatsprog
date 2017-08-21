#include "String.h"
#include <cstring>

void String::criar(unsigned tam){
    N = tam;
    str = (N== 0 ? NULL : new char[N]);
}

void String::copiar(const String &S){
    criar(S.N);
    for (unsigned i = 0; i < this->N; i++) {
        this->str[i] = S.str[i];
    }
}

void String::limpar(){
    if (str != NULL) delete[] str;
    N=0;
    str = NULL;
}

String::String(){
    N = 0;
    str = NULL;
}

String::String(char *C){
    unsigned tam = strlen(C);
    criar(tam);

    for (unsigned i = 0; i < N; i++) this->str[i] = C[i];

}

ostream &operator<<(ostream &X, const String &S){
    for (unsigned i = 0; i < S.N; i++) {
        X << S.str[i];
    }
    return X;
}

String String::operator+(const String &S) const{
    String soma(this->N + S.N);
    for (unsigned i = 0; i < N; i++) soma.str[i] = str[i];
    for (unsigned i = 0; i < S.N; i++) soma.str[i+N] = S.str[i];

    return soma;
}