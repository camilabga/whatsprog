//André Fonseca Cavalcanti
//2012980974
#include <iostream>
#include <string>

using namespace std;

class Voo{
private:
    unsigned int NumeroDoVoo,HoraDePartida,HoraDeChegada;
    string AeroportoDeOrigem,AeroportoDeDestino;
public:
    friend ostream& operator<<(ostream &O, const Voo &V);
    friend istream& operator>>(istream &I, Voo &V);
};

istream& operator>>(istream &I, Voo &V)
{
    Voo aux;
    unsigned tam,hora;

    aux = V;
    tam = aux.AeroportoDeOrigem.size;
    hora = aux.HoraDePartida;

    if(aux.NumeroDoVoo<1000 || aux.NumeroDoVoo>9999){
        cout<<"Valor incompativel"<<endl;
    }
    if(tam !=3){
        cout<<"Valor incompativel"<<endl;
    }
    if(hora>2359){
        cout<<"Valor incompativel"<<endl;
    }
}

ostream& operator<<(ostream &O, const Voo &V)
{
    cout<<V.NumeroDoVoo<<endl;
    cout<<V.AeroportoDeOrigem<<endl;
    cout<<V.HoraDePartida<<endl;
    cout<<V.AeroportoDeDestino<<endl;
    cout<<V.HoraDeChegada<<endl;
}

class ListaVoos{
private:
    unsigned N;
    double *x;
public:
  ListaVoos();
  ListaVoos(unsigned int Num);
  ~ListaVoos();

  void imprimir() const;
  void inserir(Voo V);
};

void ListaVoos::inserir(Voo V)
{
  double *prov = new double[N+1];
  for (unsigned i=0; i<N; i++) prov[i] = x[i];
  prov[N] = V;
  delete[] x;
  x = prov;
  N++;
}
void ListaVoos::imprimir(void) const
{
  for (unsigned i=0; i<N; i++) cout << x[i] << ' ';
  cout << endl;
}

int main()
{
    ListaVoos LV;
    Voo V;
    string codigo;
    int opcao;
    cout << "PROGRAMA PARA IMPLEMENTAR UMA LISTA DE VOOS\n";
    do
    {
        do
        {
            cout << "1 - Inserir um novo voo na lista\n";
            cout << "2 - Imprimir todos os voos da lista\n";
            cout << "3 - Procurar um voo a partir da origem\n";
            cout << "0 - Terminar o programa\n";
            cin >> opcao;
        } while (opcao<0 || opcao>3);
        switch (opcao)
        {
        case 1:
            cout << "Voo a ser inserido:\n";
            cin >> V;
            LV.inserir(V);
            break;
        case 2:
            LV.imprimir();
            break;
        case 3:
            cout << "Aeroporto de origem a pesquisar:\n";
            cin >> codigo;
            LV.imprimir(codigo);
            break;
        default:
            break;
        }
    } while (opcao!=0);
    return 0;
}
