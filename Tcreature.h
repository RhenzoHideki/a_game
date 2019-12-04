#ifndef TCREATURE_H
#define TCREATURE_H
struct Tcreature{
    char name[20];
    int classe;
    int life;
    int resistence;
    int damage[3];  //Dice, times, bonus
    int bonus;
} ;
#endif