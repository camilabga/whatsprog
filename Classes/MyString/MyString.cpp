#include <iostream>
#include <cstring>
#include "MyString.h"

using namespace std;

void MyString::criar(unsigned numC)
{
  // Essa funcao soh deve ser chamada sozinha se vc tiver certeza que o objeto estah vazio
  // Por exemplo, em um construtor.
  // Caso nao tenha certeza, deve ser chamada primeiro a funcao limpar
  N = numC;
  c = (N==0 ? NULL : new char[N]);
}

void MyString::limpar()
{
  if (c!=NULL) delete[] c;
  N = 0;
  c = NULL;
}

void MyString::copiar(const MyString &S)
{
  // Essa funcao soh deve ser chamada sozinha se vc tiver certeza que o objeto estah vazio
  // Por exemplo, em um construtor.
  // Caso nao tenha certeza, deve ser chamada primeiro a funcao limpar
  criar(S.N);
  for (unsigned i=0; i<N; i++) c[i] = S.c[i];
}

MyString::MyString(const char *S)
{
  criar(strlen(S));
  for (unsigned i=0; i<N; i++) c[i] = S[i];
}

char MyString::getChar(unsigned i) const
{
  if (i>=N)
  {
    cerr << "Indice incompativel\n";
    return '\0';
  }
  return c[i];
}

void MyString::setChar(unsigned i, char C)
{
  if (i>=N)
  {
    cerr << "Indice incompativel\n";
    return;
  }
  c[i] = C;
}

ostream &operator<<(ostream &X, const MyString &S)
{
  if (S.N==0)
  {
    cerr << "MyString de dimensao nula\n";
    return X;
  }
  for (unsigned i=0; i<S.N; i++)
  {
    X << S.c[i];
  }
  return X;
}

istream &operator>>(istream &X, MyString &S)
{
  // Leitura de string com no máximo 255 caracteres
  static char buffer[256];  // Buffer provisorio
  X >> ws; // Le e descarta da stream todos os delimitadores (newline, espaco, etc).
  X.getline(buffer,256);
  S.limpar();
  S.criar(strlen(buffer));
  for (unsigned i=0; i<S.N; i++) S.c[i] = buffer[i];
  return X;
}

bool MyString::operator==(const MyString &S) const
{
  if (N != S.N) return false;
  for (unsigned i=0; i<N; i++)
  {
    if (c[i] != S.c[i]) return false;
  }
  return true;
}

bool MyString::operator<(const MyString &S) const
{
  unsigned num = min(N,S.N);
  for (unsigned i=0; i<N; i++)
  {
    if (c[i] < S.c[i]) return true;
    if (c[i] > S.c[i]) return false;
  }
  // se chegou aqui, os num primeiros caracteres sao identicos
  // Testa o comprimento da segunda string
  if (S.N > num) return true;
  // Nesse caso, ou as duas strings sao identicas
  // ou a primeira string eh mais longa que a segunda
  return false;
}

bool MyString::operator>(const MyString &S) const
{
  unsigned num = min(N,S.N);
  for (unsigned i=0; i<N; i++)
  {
    if (c[i] > S.c[i]) return true;
    if (c[i] < S.c[i]) return false;
  }
  // se chegou aqui, os num primeiros caracteres sao identicos
  // Testa o comprimento da primeira string
  if (N > num) return true;
  // Nesse caso, ou as duas strings sao identicas
  // ou a segunda string eh mais longa que a segunda
  return false;
}

MyString MyString::operator+(const MyString &S) const
{
  MyString prov(N+S.N);
  for (unsigned i=0; i<N; i++) prov.c[i] = c[i];
  for (unsigned i=0; i<S.N; i++) prov.c[i+N] = S.c[i];
  return prov;
}

MyString MyString::toupper() const
{
  MyString prov(N);
  for (unsigned i=0; i<N; i++) prov.c[i] = std::toupper(c[i]);
  return prov;
}

MyString MyString::tolower() const
{
  MyString prov(N);
  for (unsigned i=0; i<N; i++) prov.c[i] = std::tolower(c[i]);
  return prov;
}
