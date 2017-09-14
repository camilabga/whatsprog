#include <iostream>
#include <cmath>

using namespace std;

class Poly
{
private:
  unsigned Dim;
  double *coef;

  void criar(unsigned Grau);
  void copiar(const Poly &P);
  void limpar();
public:
  inline Poly(): Dim(0), coef(NULL) {}
  inline Poly(const Poly &P) {copiar(P);}
  explicit inline Poly(unsigned Grau) {criar(Grau);}
  inline ~Poly() {limpar();}

  inline unsigned grau() const {return (Dim>0 ? Dim-1 : 0);}
  double operator[](unsigned i) const;

  friend ostream& operator<<(ostream &O, const Poly &P);
  friend istream& operator>>(istream &I, Poly &P);

  double operator()(double x) const;
  Poly operator+(const Poly &P) const;
  Poly operator*(const Poly &P) const;

  void operator=(const Poly &P) {if (this!=&P) {limpar(); copiar(P);}}
};

void Poly::criar(unsigned Grau)
{
  Dim = Grau+1;
  coef = new double[Dim];
  for (unsigned i=0; i<Dim; i++) coef[i] = 1.0;
}

void Poly::copiar(const Poly &P)
{
  criar(P.grau());
  for (unsigned i=0; i<Dim; i++) coef[i] = P.coef[i];
}

void Poly::limpar()
{
  if (coef != NULL) delete[] coef;
  Dim = 0;
  coef = NULL;
}

double Poly::operator[](unsigned i) const
{
  if (i>=Dim)
  {
    cerr << "Indice invalido\n";
    return 0.0;
  }
  return coef[Dim-1-i];
}

ostream& operator<<(ostream &O, const Poly &P)
{
  // Retorna se polinomio vazio
  if (P.Dim==0) return O;

  for (int i=P.grau(); i>=0; i--)
  {
    if (P.coef[i] == 0.0)
    {
      // Soh imprime um coeficiente nulo se for o ultimo coeficiente
      // de um polinomio de grau zero (ou seja, uma constante de valor 0.0)
      if (i==0 && P.grau()==0) O << P.coef[i];
    }
    else
    {
      // Imprime o sinal antes do coeficiente
      if (P.coef[i]<0.0) cout << '-';
      else
      {
        // Nao imprime o + no primeiro coeficiente
        if (i!=P.grau()) cout << '+';
      }

      // Testa se imprime o valor do coeficiente
      if (fabs(P.coef[i]) == 1.0)
      {
        if (i==0) cout << fabs(P.coef[i]);
      }
      else
      {
        cout << fabs(P.coef[i]);
        if (i>0) cout << '*';
      }

      // Imprime a variavel x
      if (i>0) cout << 'x';
      if (i>1) cout << '^' << i;
    }
  }
  return O;
}

istream& operator>>(istream &I, Poly &P)
{
  unsigned G;
  I >> G;
  if (G!=P.grau())
  {
    P.limpar();
    P.criar(G);
  }
  for (unsigned i=0; i<=G; i++) I >> P.coef[G-i];
  return I;
}

double Poly::operator()(double x) const
{
  double valor=0.0, potencia=1.0;
  for (unsigned i=0; i<Dim; i++)
  {
    valor += coef[i]*potencia;
    potencia *= x;
  }
  return valor;
}

Poly Poly::operator+(const Poly &P) const
{
  Poly prov(max(grau(),P.grau()));

  for (unsigned i=0; i<prov.Dim; i++)
  {
    prov.coef[i] = (i<Dim ? coef[i] : 0.0)+(i<P.Dim ? P.coef[i] : 0.0);
  }
  return prov;
}

Poly Poly::operator*(const Poly &P) const
{
  Poly prov(grau()+P.grau());

  for (unsigned i=0; i<prov.Dim; i++) prov.coef[i] = 0.0;

  for (unsigned i=0; i<Dim; i++)
  {
    for (unsigned j=0; j<P.Dim; j++)
    {
      prov.coef[i+j] += coef[i]*P.coef[j];
    }
  }
  return prov;
}

int main(void)
{
  Poly P1, P2, S, P;
  cout << "Primeiro polinomio: ";
  cin >> P1;
  cout << "Segundo polinomio: ";
  cin >> P2;

  S = P1+P2;
  P = P1*P2;

  cout << "P1 = " << P1 << "\tP1(0.0) = " << P1(0.0) << endl;
  cout << "P2 = " << P2 << "\tP2(1.0) = " << P2(1.0) << endl;
  cout << "Soma = " << S << endl;
  cout << "Produto = " << P << endl;
  return 0;
}
