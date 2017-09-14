/*Aluna: Camila Barbosa Gomes de Araujo
  Matrícula: 2015016753*/

#include "Voo.h"

using namespace std;

int main(){
    Lista_Voos LV;
    Voo V;
    string codigo;
    int esc;

    cout << "PROGRAMA PARA IMPLEMENTAR UMA LISTA DE VOOS" << endl;
    do {
        do {
            cout << "1. Inserir um novo voo na lista" << endl;
            cout << "2. Imprimir todos os voos da lista" << endl;
            cout << "3. Procurar um voo a partir da origem" << endl;
            cout << "0. Sair" << endl;
            cin >> esc;
        } while (esc < 0 || esc > 3);

        switch (esc) {
            case 1:
            cout << "Voo a ser inserido: " << endl;
            cin >> V;
            
            LV.inserir(V);
            
            break;

            case 2:
            LV.imprimir();

            break;

            case 3:
            cout << "Aeroporto a pesquisar: ";
            cin >> codigo;
            LV.imprimir(codigo);
            break;

            default:
            break;
        }


    } while (esc != 0);

    return 0;
}