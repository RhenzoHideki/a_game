#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "character.h"
#include "fight.h"

char choices; //esse conjunto está associado as variáveis inseridas no jogo
int dice; //Variáveis do mundo


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


char main()
{
    struct character player;
    character_creation(&player, choices);//finalização da escolha de personagem
    sleep(5);
    printf("\nSeus status:\nVida:%d\nDano Fisico:%d\nPontos de Magia:%d\nn",player.hp,player.dm,player.mp);


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

    escolha_Quest_1(&player);


    return printf("Fim");
} //Função main do jogo usado para progredir a história