#include <iostream>

using namespace std;

class Ponto
{
private:
  double x,y;
public:
  inline Ponto(): x(0.0), y(0.0) {}
  friend ostream &operator<<(ostream &O, const Ponto &P);
  friend istream &operator>>(istream &I, Ponto &P);
};

ostream &operator<<(ostream &O, const Ponto &P)
{
  O << '[' << P.x << ';' << P.y << ']';
  return O;
}

istream &operator>>(istream &I, Ponto &P)
{
  I >> P.x >> P.y;
  return I;
}

class Linha
{
private:
  unsigned N;
  Ponto *x;
public:
  inline Linha(): N(0), x(NULL) {}
  Linha(const Linha &L);
  ~Linha(void);
  void operator=(const Linha &L);
  void adicionar(const Ponto &P);
  Linha operator+(const Linha &L) const;
  friend ostream &operator<<(ostream &O, const Linha &L);
};

Linha::Linha(const Linha &L)
{
  N = L.N;
  if (N>0) x = new Ponto[N];
  else x = NULL;
  // Copia os valores dos pontos
  for (unsigned i=0; i<N; i++) x[i]=L.x[i];
}

Linha::~Linha(void)
{
  if (N>0) delete[] x;
}

void Linha::operator=(const Linha &L)
{
  if (this != &L)
  {
    // Soh faz alguma coisa se as duas variaveis sendo atribuidas forem diferentes
    if (N != L.N)
    {
      // Soh desaloca a area antiga e aloca nova area se as dimensoes forem diferentes
      // Senao, reutiliza a mesma area e soh copia o valor dos elementos
      if (N>0) delete[] x;
      N = L.N;
      if (N>0) x = new Ponto[N];
      else x = NULL;
    }
    // Copia os valores dos pontos
    for (unsigned i=0; i<N; i++) x[i]=L.x[i];
  }
}

void Linha::adicionar(const Ponto &P)
{
  Ponto *prov = new Ponto[N+1];

  for (unsigned i=0; i<N; i++) prov[i]=x[i];
  prov[N] = P;
  if (N>0) delete[] x;
  N++;
  x = prov;
}

Linha Linha::operator+(const Linha &L) const
{
  Linha prov;
  prov.N = N+L.N;
  prov.x = new Ponto[N+L.N];
  for (unsigned i=0; i<N; i++) prov.x[i] = x[i];
  for (unsigned i=0; i<L.N; i++) prov.x[i+N] = L.x[i];
  return prov;
}

ostream &operator<<(ostream &O, const Linha &L)
{
  for (unsigned i=0; i<L.N; i++) O << L.x[i];
  return O;
}

int main(void)
{
  Linha L1,L2,L3;
  Ponto P;
  unsigned NPt, NPtAdic, i;

  do
  {
    cout << "Numero de pontos da 1a linha (>0): ";
    cin >> NPt;
  } while (NPt<=0);
  for (i=0; i<NPt; i++)
  {
    cout << "Digite o ponto indice " << i << ": ";
    cin >> P;
    L1.adicionar(P);
  }
  L2 = L1;
  do
  {
    cout << "Numero de pontos adicionais da 2a linha (>0): ";
    cin >> NPtAdic;
  } while (NPtAdic<=0);
  for (i=0; i<NPtAdic; i++)
  {
    cout << "Digite o ponto indice " << i+NPt << ": ";
    cin >> P;
    L2.adicionar(P);
  }
  L3 = L1+L2;
  cout << "1a linha: " << L1 << endl;
  cout << "2a linha: " << L2 << endl;
  cout << "3a linha: " << L3 << endl;

  return 0;
}
