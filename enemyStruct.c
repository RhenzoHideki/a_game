#include <stdio.h>

int rdice(int aux)
{
  switch (aux)
  {
  case 4:
    rand() % 4 + 1;
    break;
  case 6:
    rand() % 6 + 1;
    break;
  case 8:
    rand() % 8 + 1;
    break;
  default:
    break;
  }
}

struct Enemy
{
  char name[20];
  int life[3]; // pos[0] = Base life, pos[1] = dice, pos[2] = times
  int mana;
  int resistence;
  int damage[3]; // pos[0]= dice, pos[1] = times, pos[2] = bonus
};

struct Enemy goblin = {
    "Goblin",
    {7, 2, 12},
    1,
    15,
    {6, 1, 2}};

void main (){
  printf("Nome %s\nVida Base %d\nDado de vida %d\nQntd Dados %d\n",goblin.name,goblin.damage[0],goblin.damage[1],goblin.damage[2]);
}