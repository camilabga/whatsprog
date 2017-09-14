#include "Matriz.h"

void Matriz::criar(unsigned numL, unsigned numC)
{
    cout << "criou" << endl;
    // Essa funcao soh deve ser chamada sozinha se vc tiver certeza que o objeto estah vazio
    // Por exemplo, em um construtor.
    // Caso nao tenha certeza, deve ser chamada primeiro a funcao limpar
    if (numL==0 || numC==0)
    {
        cerr << "Matriz de dimensao nula\n";
        NL = NC = 0;
        x = NULL;
        return;
    }
    NL = numL;
    NC = numC;
    x = new double*[NL];
    for (unsigned i=0; i<NL; i++) x[i] = new double[NC];
}

void Matriz::copiar(const Matriz &N)
{
    cout << "copiou" << endl;
    // Essa funcao soh deve ser chamada sozinha se vc tiver certeza que o objeto estah vazio
    // Por exemplo, em um construtor.
    // Caso nao tenha certeza, deve ser chamada primeiro a funcao limpar
    criar(N.NL, N.NC);
    for (unsigned i=0; i<NL; i++)
    {
        for (unsigned j=0; j<NC; j++) x[i][j] = N.x[i][j];
    }
}

void Matriz::limpar()
{
    cout << "limpou" << endl;
    if (x!=NULL)
    {
        for (unsigned i=0; i<NL; i++) delete[] x[i];
        delete[] x;
    }
    NL = NC = 0;
    x = NULL;
}

Matriz::Matriz()
{
    //cout << "Entrei no construtor default!\n";
    NL = NC = 0;
    x = NULL;
}

double Matriz::getElem(unsigned i, unsigned j) const
{
    if (i>=NL || j>=NC)
    {
        cerr << "Indices incompativeis\n";
        return 0.0;
    }
    return x[i][j];
}

void Matriz::setElem(unsigned i, unsigned j, double Valor)
{
    if (i>=NL || j>=NC)
    {
        cerr << "Indices incompativeis\n";
        return;
    }
    x[i][j] = Valor;
}

ostream &operator<<(ostream &X, const Matriz &N)
{
    if (N.NL==0 || N.NC==0)
    {
        cerr << "Matriz de dimensao nula\n";
        return X;
    }
    for (unsigned i=0; i<N.NL; i++)
    {
        for (unsigned j=0; j<N.NC; j++)
        {
            X << N.x[i][j] << ' ';
        }
        X << endl;
    }
    return X;
}

istream &operator>>(istream &X, const Matriz &N){
    if (N.NL==0 || N.NC==0)
    {
        cerr << "Matriz de dimensao nula\n";
        return X;
    }
    for (unsigned i=0; i<N.NL; i++)
    {
        for (unsigned j=0; j<N.NC; j++)
        {
            X >> N.x[i][j];
        }
    }
    return X;
}

Matriz Matriz::operator+(const Matriz &N) const
{
    if (NL != N.NL || NC != N.NC || NL==0 || NC==0)
    {
        cerr << "Matrizes de dimensao incompativeis ou nulas\n";
        return Matriz();
    }
    Matriz prov(NL,NC);
    for (unsigned i=0; i<NL; i++) for (unsigned j=0; j<NC; j++)
        prov.x[i][j] = this->x[i][j] + N.x[i][j];
    return prov;
}

Matriz Matriz::operator-(const Matriz &N) const
{
    if (NL != N.NL || NC != N.NC || NL==0 || NC==0)
    {
        cerr << "Matrizes de dimensao incompativeis ou nulas\n";
        return Matriz();
    }
    Matriz prov(NL,NC);
    for (unsigned i=0; i<NL; i++) for (unsigned j=0; j<NC; j++)
        prov.x[i][j] = this->x[i][j] - N.x[i][j];
    return prov;
}

Matriz Matriz::operator-() const
{
    if (NL==0 || NC==0)
    {
        cerr << "Matriz de dimensao nula\n";
        return Matriz();
    }
    Matriz prov(NL,NC);
    for (unsigned i=0; i<NL; i++) for (unsigned j=0; j<NC; j++)
        prov.x[i][j] = - x[i][j];
    return prov;
}

Matriz Matriz::operator*(const Matriz &N) const
{
    if (NC != N.NL || NL==0 || NC==0 || N.NC==0)
    {
        cerr << "Matrizes de dimensao incompativeis ou nulas\n";
        return Matriz();
    }
    Matriz prov(NL,N.NC);
    for (unsigned i=0; i<prov.NL; i++) for (unsigned j=0; j<prov.NC; j++)
    {
        prov.x[i][j] = 0.0;
        for (unsigned k=0; k<NC; k++) prov.x[i][j] += x[i][k]*N.x[k][j];
    }
    return prov;
}

// Transposta
Matriz Matriz::operator!(void) const
{
    if (NL==0 || NC==0)
    {
        cerr << "Matriz de dimensao nula\n";
        return Matriz();
    }
    Matriz prov(NC,NL);
    for (unsigned i=0; i<NL; i++) for (unsigned j=0; j<NC; j++)
        prov.x[j][i] = x[i][j];
    return prov;

}
