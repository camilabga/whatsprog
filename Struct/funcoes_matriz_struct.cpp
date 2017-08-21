#include <iostream>

using namespace std;

/*
Exerc�cio de utiliza��o de fun��es em conjunto com arrays alocados dinamicamente (ponteiros)

Nesse exercicio, voce deve definir o novo tipo Matriz utilizando uma struct, que armazena
tanto o numero de linhas e de colunas de cada matriz quanto o ponteiro

A partir desse tipo Matriz, voce deve programar as funcoes necessarias para executar o programa
principal a seguir. A ideia eh permitir fazer as operacoes indicadas com matrizes de quaisquer
dimensoes, fornecidas pelo usuario no momento da execucao (e nao na compilacao).

*/

// FACA SEUS ACRESCIMOS NO CODIGO AQUI



struct Matriz {
    unsigned nColunas;
    unsigned nLinhas;
    int **mat;
};

Matriz novaMatriz(unsigned NL, unsigned NC){
    Matriz nova;
    nova.nColunas = NC;
    nova.nLinhas = NL;
    
    nova.mat = new int*[NL];
    for (int i = 0; i < NL; i++) {
        nova.mat[i] = new int[NC];
    }

    for (int i = 0; i < NL; i++) {
        for(int j = 0; j < NC; j++){
            nova.mat[i][j] = 0;
        }
    }

    return nova;

}

void leMatriz (Matriz &M){
    for (int i = 0; i < M.nLinhas; i++) {
        for(int j = 0; j < M.nColunas; j++){
            cout << "[" << i << "][" << j << "]: ";
            cin >> M.mat[i][j];
        }
    }
}

Matriz produtoMatrizes (Matriz &A, Matriz &B) {
    Matriz produto = novaMatriz(A.nLinhas, B.nColunas);

    for (int i = 0; i < A.nLinhas; i++) {
        for (int j = 0; j < B.nColunas; j++) {
            for (int k = 0; k < A.nColunas; k++) {
                produto.mat[i][j] = produto.mat[i][j] + A.mat[i][k]*B.mat[k][j];
            }
        }
    }

    return produto;
}

void imprimeMatriz(Matriz &M){
    for (int i = 0; i < M.nLinhas; i++) {
        for(int j = 0; j < M.nColunas; j++){
            cout << M.mat[i][j] << endl;
        }
    }
}

void liberaMatriz(Matriz &M){
    delete[] M.mat;
}

int main(void)
{
    // Declaracao das matrizes
    Matriz A, B, C;

    unsigned NLa, NCa, NLb, NCb;
    do {
        cout << "Linhas de A: ";
        cin >> NLa;
    } while (NLa <= 0);
    do {
        cout << "Colunas de A: ";
        cin >> NCa;
    } while (NCa <= 0);
    // Obs: NLb = NCa
    NLb = NCa;
    do {
        cout << "Colunas de B: ";
        cin >> NCb;
    } while (NCb <= 0);

    // Alocacao das matrizes
    A = novaMatriz(NLa,NCa);
    B = novaMatriz(NLb,NCb);

    // Leitura das matrizes A e B
    leMatriz(A);
    leMatriz(B);

    // produto das matrizes
    C = produtoMatrizes(A,B);

    // Impressao das matrizes
    imprimeMatriz(C);

    // Liberacao das memorias
    liberaMatriz(A);
    liberaMatriz(B);
    liberaMatriz(C);

    return  0;
}
