#ifndef FIGHT_H
#define FIGHT_H

//Header das funções de combate

extern void damageDone();  //Função que calcula o dano
extern void verifyHit();   //Função que verifica se o atacante acertou
extern int isDead();       //Função que verifica se o jogador continua vivo
extern void fight();       //Função que inicia a batalha

#endif