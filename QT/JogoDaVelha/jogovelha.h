#ifndef JOGOVELHA_H
#define JOGOVELHA_H


class JogoVelha
{
private:
    char x[3][3];
    char vez;
    char vencedor;
public:
    JogoVelha();
    void novo();
    inline char vezDeQuem(){return vez;}
};

extern JogoVelha JV;

#endif // JOGOVELHA_H
