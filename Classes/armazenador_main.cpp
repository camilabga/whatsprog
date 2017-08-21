#include <iostream>
#include "armazenador.h"

using namespace std;

int main(){
    valor V;
    Lista_valor L(1);
    int opcao;

    cout << "PROGRAMA PARA IMPLEMENTAR UMA LISTA DE VALORES\n";
    do{
        do{
            cout << "1 - Inserir um valor no fim da lista\n";
            cout << "2 - Imprimir o primeiro valor da lista\n";
            cout << "3 - Remover o primeiro valor da lista\n";
            cout << "4 - Imprimir o numero de elementos da lista\n";
            cout << "5 - Imprimir todos os valores da lista\n";
            cout << "0 - Terminar o programa\n";
            cin >> opcao;
        } while (opcao < 0 || opcao > 5);
        switch (opcao){
        case 1:
            cout << "Valor a ser inserido: ";
            cin >> V;
            L.insira_lista(V);
            break;
        case 2:
            V = L.primeiro_lista();
            cout << "Primeiro da lista = " << V << endl;
            break;
        case 3:
            L.remover_primeiro_lista();
            break;
        case 4:
            cout << "Numero de valores da lista = " << L.getN() << endl;
            break;
        case 5:
            L.imprimir_lista();
            break;
        default:
            break;
        }

    } while (opcao != 0);
    // Liberar a memoria alocada
    L.~Lista_valor();

    return 0;
}