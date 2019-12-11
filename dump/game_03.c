#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main()
{
  char c,sn; //esse conjunto está associado as variáveis inseridas no jogo
  int dice,i; //Variáveis do mundo
  float Edm,Ehp; //Variáveis do mundo
  float hp,dm,mp; //Variáveis do jogador
  int gold; //Variáveis do jogador

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

  }//Finalização da escolha de personagem

  //inicio da Quest do aventureiro
  sleep(1);
  printf("\n*Você acorda dentro de uma estalagem* \n");
  sleep(2);
  printf("Levantando,você olha o local em que está e não reconhece o local, se questionando o que está acontecendo e tenta lembrar o que faz naquele local,\nporém não consegue lembrar de nada e percebe que não consegue nem mesmo lembrar de seu nome ou passado.\n");
  sleep(5);
  printf("No meio da sua tentativa de compreender o que poderia estar acontecendo, uma pessoa bate na porta do quarto que você está.\n");
  sleep(3);
  printf("Você vai até a porta do quarto, abrindo, vê-se uma moça , ela entra no seu quarto e fala:\n");
  sleep(2);
  printf("-Você deve pagar pela estadia\n");
  printf("Questionar o que está acontecendo: s(sim) ou n(não)\n");
  sleep(1);

  while (1){ //Pequeno desenvolvimento da razão por estar naquele local
    scanf(" %c",&sn);
    if (sn=='s'){//caso haja interrese do jogardor
      printf("*Você pergunta onde está e o que aconteceu*");
      sleep(3);
      printf("\n-Bem...Você tem que pagar a estadia ,mas se está se perguntando onde se encontra, estamos em um vilareijo a dois dias da capital do reino.\nJá você assim que entrou aqui acabou desmaiando\n");
      sleep(2);
      printf("Parece que você não lembra de muita coisa, vamos proseguir então ...\n");
      break;
    }else if(sn=='n'){//caso ele queira simplesmente prosseguir
      printf("-Bem parece que você não quer falar nada, vamos proseguir então...\n");
      break;
    }else{
      printf("Invalido\n");
      continue;
    }
  }

  sleep(3);//desenvolvimento de quais são as Quests possiveis
  printf("-A estadia seria 50 moedas, porém você provavelmente não terá esse dinheiro\n");
  sleep(3);
  printf("-Então como forma de pagamento você poderia resolver um dos problemas que estamos tendo\n");
  sleep(3);
  printf("-Ah você pode decidir qual problema deseja resolver e ainda te daremos algo\n");
  sleep(6);
  printf("\n-O primeiro é matar alguns goblins que tem atacado as nossas colheitar em volta da vila,\nlá provavelmente você poderá encontrar equipamentos como escudo ou espadas \n");
  sleep(6);
  printf("\n-A outra opção é ir no pantano que fica proximo daqui e coletar alguns ingredientes,\nmas você deve tomar cuidado ,pois lá é um lugar misterioso com rumores de atividades magicas\nCom muita sorte você porderia fortalecer sua magia\n");
  sleep(4);
  printf("-Então qual a sua escolha?\n");

  do{ //escolha da missão que será feito
    printf("(p)Primeira missão\n(s)Segunda missão\n");
    scanf(" %c",&sn);

    if (sn=='p'){ //primeira missão
      sleep(2);
      printf("*Você escolhe a primeira missão* \n");
      sleep(3);
      printf("Essa missão irá tomar 3 jogadas para chegar nela\n");
      printf("Jogue o dado para decidir o caminho\n");
      sleep(3);
      do{
        printf("*digite 's' para jogar o dado*\n");
        scanf(" %c",&sn);
      }while (sn!='s');
      srand(time(NULL)); //implementação do rolamento de dado
      dice=rand()%20+1;
      printf("seu dado rodou:%d\n",dice);

      if (dice>12){ //caminho mais facil caso dado maior que 8
        sleep(3);
        printf("\nVocê viajou uma manhão inteira sem ter nenhum problema\n");
        sleep(2);
        printf("Após um descanço você vê um goblin, você se prepara\n");
        sleep(2);
        printf("*A batalha começou\n*");
        Ehp=30;
        Edm=8;
        do{
          while(sn!='a'){
            printf("digita 'a' para jogar um dado de ataque\n");
            scanf(" %c",&sn);
            dice=rand()%20+1;
            printf("Seu dado foi: %d\n",dice);
            if (dice>=12){
             printf("Você teve acerto crítico!!\n");
             Ehp=Ehp-2*dm-2*mp;
             printf("Vida do Inimigo: %.0f\n",Ehp);
            }else{
             printf("Você errou\n");
             if ((dice=1)){
              hp=hp-0.1*dm-0.1*mp;
              printf("Você teve errou crítico,sua vida:%.0f",hp);
             }
            }
          }

        } while (Ehp>=0 || hp>=0);
        break;

      }else{ //caminho mais dificil caso erre o d20
        sleep(3);
        printf("Sua viagem teve contratempos e problemas\n");
        sleep(2);
        printf("Após muitos problemas você vê um goblin,\nvocê tenta se preparar o mais rapido possivel\n");
        sleep(2);
        printf("*A batalha começou*\n");
        Ehp=30;
        Edm=8;
        do{
          while(sn!='a') {
            printf("digita 'a' para jogar um dado de ataque\n");
            scanf(" %c", &sn);
          
            srand(time(NULL));
            dice=rand()%20+1;
            printf("Seu dado foi: %d\n",dice);
            if (dice>=12){
            printf("*Você acerta o inimigo*\n");
             if ((dice=20)) {
               printf("Você teve acerto crítico!!\n");
               Ehp=Ehp-2*0.5*dm-2*0.5*mp;
               printf("Vida do Inimigo: %.0f",Ehp);
             }else{
               Ehp=Ehp-0.5*dm-2*0.5*mp;
               printf("Vida do inimigo: %.0f\n",Ehp);
             }
            }else{
             printf("Você errou\n");
             if ((dice=1)){
              hp=hp-0.2*dm-0.2*mp;
              printf("Você teve errou crítico,sua vida:%.0f\n",hp);
             }
            }
          }
        } while (Ehp>=0 || hp>=0);
        break;
      }

      break;

    }else if (sn=='s'){ //segunda missão
      sleep(2);
      printf("*Você escolhe a segunda missão* \n");
      sleep(3);
      printf("Essa missão irá tomar 3 jogadas para chegar nela\n");
      printf("Jogue o dado para decidir o caminho\n");
      sleep(3);
      do{
        printf("*digite 's' para jogar o dado*\n");
        scanf(" %c",&sn);
      }while (sn!='s');
      srand(time(NULL)); //implementação do rolamento de dado
      dice=rand()%20+1;
      printf("seu dado rodou:%d\n",dice);
      if (dice>12){ //caminho mais facil caso dado maior que 8
        printf("\nVocê viajou uma manhão inteira sem ter nenhum problema\n");

      }else{ //caminho mais dificil caso erre o d20
        printf("Sua viagem teve contratempos e problemas\n");

      }

      break;

    }else{
      printf("Invalido\n");
      continue;
    }
  }while (1);

  return 0;
}