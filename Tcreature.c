#include <stdio.h>
#include "Tcreature.h"

struct Tcreature {
    char name[20];
    int classe;
    int life;
    int resistence;
    int damage[3];  //Dice, times, bonus
    int bonus;
};