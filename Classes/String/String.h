#include <iostream>

using namespace std;

class String {
private:
    char *str;
    unsigned N;
    void criar(unsigned tam);
    void copiar(const String &S);
    void limpar();
public:
    String(); // default
    inline String(const String &S){copiar(S);} // por cópia
    inline String(unsigned tam) {criar(tam);}
    String(char *C);
    inline ~String() {limpar();} // destrutor

    inline unsigned size() const {return N;}
    char getChar(unsigned i) const;

    inline void operator=(const String &S){if(this != &S){limpar(); copiar(S);}}
    inline char operator[](unsigned i) const {return getChar(i);}

    friend istream &operator>>(istream &X, String &S); 
    friend ostream &operator<<(ostream &X, const String &S);
    String operator+(const String &S) const;

    String toupper() const;
    inline friend String toupper(const String &S) {return S.toupper();}
};