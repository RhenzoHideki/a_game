#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "jogador_test_2.h"


int func_atk_mob(){
  printf("Seu inimigo ataca\n");
  srand(time(NULL));
  dice=rand()%20+1;
  if (dice>=14){
    sleep(2);
    printf("Sua Vida:%0.f\n",hp);
  }else{
    hp=hp-Edm;
    printf("Seu inimigo te acertou\nSua vida:%0.f\n",hp);
  }
}//Função do Ataque do inimigo

int func_atk_player (){
  srand(time(NULL));
  dice=rand()%20+1;
  printf("Seu dado foi: %d\n",dice);
  if (dice>=12){
    sleep(2);
    printf("*Você acerta o inimigo*\n");
    Ehp=Ehp-dm-mp;
    printf("Vida do inimigo: %.0f\n",Ehp);
  }else{
    sleep(2);
    printf("Você errou o inimigo\n");
  }
}//Função do Ataque do Player

int func_combate(){
  //Inicio do Ataque do Player
  printf("digita 'a' para jogar um dado de ataque\n");
  scanf(" %c", &choices);
  while(choices!='a') {
    printf("digita 'a' para jogar um dado de ataque\n");
    scanf(" %c", &choices);
  }
  func_atk_player();
  //Final do Ataque do Player
  //Inicio do Ataque do inimigo
  sleep(3);
  func_atk_mob();
  //Final do ataque do inimigo

}//Função do Combate

int quest_1_lado_b(){

}

int batalha_a_d()
{
  sleep(3);
  printf("Sua viagem teve contratempos e problemas\n");
  sleep(2);
  printf("Após muitos problemas você vê um goblin,\nvocê tenta se preparar o mais rapido possivel\n");
  sleep(2);
  printf("*A batalha começou*\n");
  Ehp=30;
  Edm=8;
  do{
    Ehp=30;
    Edm=8;
   func_combate();
  } while (hp>0&&Ehp> 0);
}//Função da Batalha 'Caça dos Goblins' Dificil

int batalha_a_f()
{
  sleep(3);
  printf("\nVocê viajou uma manhão inteira sem ter nenhum problema\n");
  sleep(2);
  printf("Após um descanço você vê um goblin, você se prepara\n");
  sleep(2);
  printf("*A batalha começou\n*");


  do{
    while(choices!='a'){
      printf("digita 'a' para jogar um dado de ataque\n");
      scanf(" %c",&choices);
      dice=rand()%20+1;
      printf("Seu dado foi: %d\n",dice);
      if (dice>=12){
        printf("Você acertou!!\n");
        g->hp=g->hp-p->dm-mp;
        printf("Vida do Inimigo: %.0f\n",Ehp);
      }else {
        printf("Você errou\n");
      }
    }
    sleep(3);
    printf("Seu inimigo ataca\n");
    srand(time(NULL));
    dice=rand()%20+1;
    if (dice>=14){
      hp=hp-Edm;
      printf("Seu inimigo te acertou\nSua vida:%0.f\n",hp);
    }

  } while (Ehp>0&&hp>0);
} //Função da Batalha 'Caça dos Goblins' Fácil

int quest_1_lado_a ()
{
    struct character_creation goblin;
    struct character_creation *g;
    *g=goblin;

  sleep(2);
  printf("*Você escolhe a primeira missão* \n");
  sleep(3);
  printf("Essa missão irá tomar 3 jogadas para chegar nela\n");
  printf("Jogue o dado para decidir o caminho\n");
  sleep(3);
  do{
    printf("*digite 's' para jogar o dado*\n");
    scanf(" %c",&choices);
  }while (choices!='s');
  srand(time); //implementação do rolamento de dado
  dice=rand()%20+1;
  printf("seu dado rodou:%d\n",dice);

  if (dice>12){ //caminho mais facil caso dado maior que 8
    batalha_a_f();

  }else{ //caminho mais dificil caso erre o d20
    batalha_a_d();
  }
} //Função da Quest do Lado A 'Caça dos Goblins'

int escolha_Quest_1(){

  do{ //escolha da missão que será feito
    printf("(p)Primeira missão\n(s)Segunda missão\n");
    scanf(" %c",&choices);

    if (choices=='p'){ //primeira missão
      quest_1_lado_a();

    }else if (choices=='s'){ //segunda missão
      quest_1_lado_b();
    }else{
      printf("Invalido\n");
      continue;
    }
    break;
  }while (1);


} //Função das duas primeiras Quests

int dialogo_1()
{
  while (1){ //Pequeno desenvolvimento da razão por estar naquele local
    scanf(" %c",&choices);
    if (choices=='s'){//caso haja interrese do jogardor
      printf("*Você pergunta onde está e o que aconteceu*");
      sleep(3);
      printf("\n-Bem...Você tem que pagar a estadia ,mas se está se perguntando onde se encontra, estamos em um vilareijo a dois dias da capital do reino.\nJá você assim que entrou aqui acabou desmaiando\n");
      sleep(2);
      printf("Parece que você não lembra de muita coisa, vamos proseguir então ...\n");
      break;
    }else if(choices=='n'){//caso ele queira simplesmente prosseguir
      printf("-Bem parece que você não quer falar nada, vamos proseguir então...\n");
      break;
    }else{
      printf("Invalido\n");
      continue;
    }
  }
} //Função do primeiro dialogo

int main()
{


  character_creation();//finalização da escolha de personagem


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

  dialogo_1();

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

  escolha_Quest_1();


  return printf("Fim");
} //Função main do jogo usado para progredir a história