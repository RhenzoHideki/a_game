#ifndef FIGHT_H
#define FIGHT_H

#include <stdio.h>
#include <stdlib.h>
#include "Tcreature.h"
#include "fight.h"
#include "mix.h"

//Header das funções de combate

void damageDone(struct Tcreature *damager, struct Tcreature *taker, int aux) { //Função que calcula o dano
    int damage = (dice(damager->damage[0]) * damager->damage[1] + damager->damage[2]) * aux;
    taker->life = taker->life - damage;
    if (taker->life > 0) {
        printf("%s causou %d de dano a %s\n", damager->name, damage, taker->name);
    } else {
        printf("%s deu uma chapoletada fatal de %d no %s\n", damager->name, damage, taker->name);
    }
};

void verifyHit(struct Tcreature *atk, struct Tcreature *def, int bonusPlus) { //Função que verifica se o atacante acertou
    int acerto = dice(20);
    int bonusMod = atk->bonus + bonusPlus;
    if (acerto == 20) {
        printf("%s rolou 20!! Acertos criticos dão o dobro de dano.\n", atk->name);
        damageDone(atk, def, 2);
    } else if (acerto + bonusMod < def->resistence) {
        printf("%s errou o golpe, rolou %d + %d e a resistencia do inimigo é %d\n", atk->name, acerto, bonusMod, def->resistence);
    } else {
        printf("%s rolou %d + %d e acertou o inimigo que tem resistencia %d\n", atk->name, acerto, bonusMod, def->resistence);
        damageDone(atk, def, 1);
    }
}

int isDead(struct Tcreature *aux) {//Função que verifica se o jogador continua vivo
    if (aux->life > 0) {
        return 0;
    } else {
        return 1;
    }
}

void fight(struct Tcreature *aux1, struct Tcreature aux2, int bonusPlus) {//Função que inicia a batalha
    while (1) {
        verifyHit(aux1, &aux2, bonusPlus);
        if (isDead(&aux2)) {
            printf("%s derrotou %s\n", aux1->name, aux2.name);
            break;
        }
        delay(5000000);
        verifyHit(&aux2, aux1, 0);
        if (isDead(aux1)) {
            printf("%s derrotou %s\n", aux2.name, aux1->name);
            break;
        }
        delay(5000000);
    }
}
#endif