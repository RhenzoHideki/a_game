//
// Created by RHSKGAMES on 12/11/2019.
//


char choices; //esse conjunto está associado as variáveis inseridas no jogo
int dice; //Variáveis do mundo

struct character
{

    char name[20];
    int hp;
    int mp;
    int dm;
    int res;
    int gold;

}player;  /*Variáveis do jogador/NPC */


void creation (struct character aux1)
{
    struct character *p;
    *p=aux1;

  printf("Digite seu nome:");
  scanf(" %s",p->name);
  printf("Escolha sua classe:\n"); //Aqui estará a escolha de Classe que irá variar entre Guerreiro e Mago

  while (1){
    while(1){

      printf("Digite g para guerreiro\nDigite m para mago\nDigete r para range\n");
      scanf(" %c",&choices);

      switch (choices) //comando para escolha de classe
      {
        case'g': //A classe de guerreiros estará focada em aguentar o dano recebido e ficar de pé o maximo de tempo
          p->hp=40;
          p->dm=10;
          p->mp=0;
          p->res;
          p->gold=30;
          printf("\nSeus status de guerreiro:\nVida:%.0f\nDano Fisico:%.0f\nPontos de Magia:%.0f\nResistencia:%d\nOuro:%d\n",p->hp,p->dm,p->mp,p->res,p->gold);
          break;


        case 'm' : //A classe de mago estará foca em dar o maximo de dano em menor tempo
          p->hp=25;
          p->dm=0;
          p->mp=25;
          p->res;
          p->gold=30;
          printf("\nSeus status de Mago:\nVida:%.0f\nDano Fisico:%.0f\nPontos de Magia:%.0f\nResistencia:\nOuro:%d\n",p->hp,p->dm,p->mp,p->res,p->gold);
          break;

          case 'r':
            p->hp=0;
            p->dm=0;
            p->mp=0;
            p->res=0;
            p->gold=0;
            printf("\nSeus status de ranger:\nVida:%.0f\nDano Fisico:%.0f\nPontos de Magia:%.0f\nResistencia:\nOuro:%d\n",p->hp,p->dm,p->mp,p->res,p->gold);
            break;

        default:
          printf("Invalido\n");
          break;
      }
      if (choices=='g'||choices=='m'){
        break;
      }else{
        continue;
      }
    }
    while (1){ //caso o usuário desejar trocar de classe acontecera nesse grupo
      printf("\nVocê gostaria de trocar de classe digite s(sim) ou n(não): ");
      scanf(" %c",&choices);
      if (choices=='s'){
        break;
      }else if (choices=='n'){
        break;
      }else{
        printf("Invalido\n");
      }
    }
    if (choices=='n'){
      break;
    }
  }
}; //Função para a criação do personagem
