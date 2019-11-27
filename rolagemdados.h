//
// Created by aluno on 20/11/2019.
//

#ifndef JOGO_ROLAGEMDADOS_H
#define JOGO_ROLAGEMDADOS_H

#endif //JOGO_ROLAGEMDADOS_H

#include <stdio.h>
#include <stdlib.h>
#include "jogador_test_2.h"
#include <time.h>

int rolagem_dados() {

    srand(time(NULL));
    dice = rand() % 20 + 1;
    printf("Seu dado foi: %d\n", dice);

    return dice;
}