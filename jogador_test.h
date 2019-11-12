//
// Created by RHSKGAMES on 12/11/2019.
//

#ifndef MYGAME_JOGADOR_H
#define MYGAME_JOGADOR_H
#endif //MYGAME_JOGADOR_H

char c,sn; //esse conjunto está associado as variáveis inseridas no jogo
int dice; //Variáveis do mundo
float Edm,Ehp; //Variáveis do mundo
float hp,dm,mp; //Variáveis do jogador
int gold; //Variáveis do jogador

int character_creation ()
{
  printf("Escolha sua classe:\n"); //Aqui estará a escolha de Classe que irá variar entre Guerreiro e Mago

  while (1){
    while(1){

      printf("Digite g para guerreiro\nDigite m para mago\n");
      scanf(" %c",&c);

      switch (c) //comando para escolha de classe
      {
        case'g': //A classe de guerreiros estará focada em aguentar o dano recebido e ficar de pé o maximo de tempo
          hp=40;
          dm=10;
          mp=0;
          gold=30;
          printf("\nSeus status de guerreiro:\nVida:%.0f\nDano Fisico:%.0f\nPontos de Magia:%.0f\nOuro:%d\n",hp,dm,mp,gold);
          break;


        case 'm' : //A classe de mago estará foca em dar o maximo de dano em menor tempo
          hp=25;
          dm=0;
          mp=25;
          gold=30;
          printf("\nSeus status de Mago:\nVida:%.0f\nDano Fisico:%.0f\nPontos de Magia:%.0f\nOuro:%d\n",hp,dm,mp,gold);
          break;

        default:
          printf("Invalido\n");
          break;
      }
      if (c=='g'||c=='m'){
        break;
      }else{
        continue;
      }
    }
    while (1){ //caso o usuário desejar trocar de classe acontecera nesse grupo
      printf("\nVocê gostaria de trocar de classe digite s(sim) ou n(não): ");
      scanf(" %c",&sn);
      if (sn=='s'){
        break;
      }else if (sn=='n'){
        break;
      }else{
        printf("Invalido\n");
      }
    }
    if (sn=='n'){
      break;
    }

  }
}; //Função para a criação do personagem
