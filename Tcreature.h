#ifndef TCREATURE_H
#define TCREATURE_H

extern struct Tcreature {  //Estrutura das creaturas do jogo.. incluindo player.
  char name[20];
  int classe;
  int life;
  int resistence;
  int damage[3];  //Dice, times, bonus
  int bonus;
};

#endif