#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
 char c,sn; //esse conjunto está associado as variáveis inseridas no jogo
 int dice,hp,dm,mp;

escolha_de_classe: //Aqui estará a escolha de Classe que irá variar entre Guerreiro e Mago
 printf("Escolha sua classe:\n");

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
     printf("\nSeus status de guerreiro:\nVida:%d\nDano Fisico:%d\nPontos de Magia:%d\n",hp,dm,mp);
    break;
 
    case 'm' : //A classe de mago estará foca em dar o maximo de dano em menor tempo
     hp=25;
     dm=0;
     mp=25;
     printf("Seus status de Mago:\nVida:%d\nDano Fisico:%d\nPontos de Magia:%d\n",hp,dm,mp);
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
   continue;
   }else if (sn=='n'){
   break;
   }else{
    printf("Invalido\n");
   }
  }
  if (sn=='n'){
   break;
  }
  continue;
  
 }//Finalização da escolha de personagem

 //inicio da Quest do aventureiro
 printf("\n*Você acorda dentro de uma estalagem* \n"); //adicionar detalhes a essa parte
 printf("Levanto,você olha o local em que está e não reconhece o local, se questionando o que está acontecendo e tenta lembrar o que faz naquele local,\nporém não consegue lembrar de nada e percebe que não consegue nem mesmo lembrar de seu nome ou passado\n");
 printf("\nNo meio da sua tentativa de compreender o que poderia estar acontecendo, uma pessoa bate na porta do quarto que você está.\n");
 printf("Você vai até a porta do quarto, abrindo, vê-se uma moça , ela entra no seu quarto e fala:\n");
 printf("Você deve pagar pelo estadia\n");
 printf("Questionar: s(sim) ou n(não)\n");
 scanf(" %c",&sn);
 while (1){
  if (sn=='s'){
   printf("ok\n");
   break;
  }else if(sn=='n'){
   break;
  } 
 }

 return 0;
}
