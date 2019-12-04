#ifndef MIX_H
#define MIX_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

void clrscr() {
    system("@cls||clear");
}

void randomize() {
    srand(time(NULL));
}

int dice(int aux) {
    return (rand() % aux) + 1;
}


void delay(unsigned int mseconds) {
    clock_t goal = mseconds + clock();
    while (goal > clock())
        ;
}

void colledPrint(char *aux) {
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