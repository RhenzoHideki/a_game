#include <stdio.h>

struct Enemy
{
  char name[20];
  int life[3]; //pos[0]= Dice,1= times, 2=bonus
  int mana;
  int resistence;
  int damage[3];
} goblin;

struct Hero
{
  char name[20];
  int life[3]; //pos[0]= Dice,1= times, 2=bonus
  int mana;
  int resistence;
  int damage[3];
  int gold;
} player1;

goblin = {
    "Goblin",
    {6, 2, 0},
    0,
    15,
    {6, 1, 2}};

dice(int aux)
{
  return rand() % aux + 1;
}

int lifeEnemy(struct Enemy aux)
{
  int life = 0;
  for (int i = 0; i < aux.life[1]; i++)
  {
    life = life + dice(aux.life[0]);
  }
  return life;
};

int damageHero(){
  int damage=0;
  for (int i = 0; i < player1.damage[1]; i++)
  {
    damage = player1.damage[0] + damage;
  }
  return damage+player1.damage[2];  
}

int hit(){
    
}

void main()
{
  printf("%d\n", goblin.damage[2]);
}
