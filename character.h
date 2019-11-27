//
// Created by aluno on 27/11/2019.
//

#ifndef GAME_CHARACTER_H
#define GAME_CHARACTER_H

#endif //GAME_CHARACTER_H
#include <stdio.h>
#include <string.h>

struct character {
    int hp;
    int dm;
    int mp;
};

void character_creation (struct character *aux1,char aux2)
{

    printf("Escolha sua classe:\n"); //Aqui estará a escolha de Classe que irá variar entre Guerreiro e Mago

    while (1){
        while(1){

            printf("Digite g para guerreiro\nDigite m para mago\n");
            scanf(" %c",&aux2);

            switch (aux2) //comando para escolha de classe
            {
                case'g': //A classe de guerreiros estará focada em aguentar o dano recebido e ficar de pé o maximo de tempo
                    aux1->hp=40;
                    aux1->dm=10;
                    aux1->mp=0;
                    printf("\nSeus status de guerreiro:\nVida:%d\nDano Fisico:%d\nPontos de Magia:%d\n",aux1->hp,aux1->dm,aux1->mp);
                    break;


                case 'm' : //A classe de mago estará foca em dar o maximo de dano em menor tempo
                    aux1->hp=25;
                    aux1->dm=0;
                    aux1->mp=25;
                    printf("\nSeus status de Mago:\nVida:%d\nDano Fisico:%d\nPontos de Magia:%d\n",aux1->hp,aux1->dm,aux1->mp);
                    break;

                default:
                    printf("Invalido\n");
                    break;
            }
            if (aux2=='g'||aux2=='m'){
                break;
            }else{
                continue;
            }
        }
        while (1){ //caso o usuário desejar trocar de classe acontecera nesse grupo
            printf("\nVocê gostaria de trocar de classe digite s(sim) ou n(não): ");
            scanf(" %c",&aux2);
            if (aux2=='s'){
                break;
            }else if (aux2=='n'){
                break;
            }else{
                printf("Invalido\n");
            }
        }
        if (aux2=='n'){
            break;
        }

    }
}; //Função para a criação do personagem