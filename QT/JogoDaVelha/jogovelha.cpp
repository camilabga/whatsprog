#include "jogovelha.h"

JogoVelha::JogoVelha(){

}

void JogoVelha::novo(){
    for(unsigned i = 0; i < 3; i++) for (unsigned j = 0; j < 3; j++) x[i][j] = ' ';
    vez = 'x';
    vencedor = ' ';
}
