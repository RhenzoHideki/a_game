#ifndef MIX_H
#define MIX_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

void clrscr() { //Função para limpar a tela
    system("@cls||clear");
} 

void randomize() { //Começa a gerar numeros aleatórios conforme o tempo
    srand(time(NULL));
}

int dice(int aux) { //Retorna um numero aleatório
    return (rand() % aux) + 1;
}


void delay(unsigned int mseconds) { //Função que dá delay conforme o clock
    clock_t goal = mseconds + clock();
    while (goal > clock())
        ;
}

void colledPrint(char *aux) { //Função que printa uma string como se fosse digitado
    int count = 0;
    while (*aux != 0) {
        if (*aux == '\n') {
            count = 0;
        }
        if (count > 100 && *aux == ' ') {
            printf("\n");
            count = 0;
            *aux++;
        }
        printf("%c", *aux++);
        fflush(stdout);
        delay(50000);
        count++;
    }
}

#endif