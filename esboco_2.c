#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "mix.h"
#include "Tcreature.h"
#include "fight.h"

char NAME[20] = "Arthur";

struct Tcreature player;

struct Tcreature goblin = {
    "Goblin",
    0,
    20,
    15,
    {6, 1, 2},
    1};

struct Tcreature galinha = {
    "Galinha",
    666,
    30,
    16,
    {10, 1, 5},
    4};

struct Tcreature wolf = {
    "Lobo",
    0,
    26,
    13,
    {4, 2, 2},
    1};


void easterEgg() {
    int escolha, x = 1;
    char *str1 = "Você deseja fazer alguma coisa a respeito??\n1 - Deixar a galinha em paz\n2 - Chutar a galinha\n-> ";
    colledPrint(str1);

    while (x) {
        scanf("%d", &escolha);
        switch (escolha) {
            case 1:
                printf("Você desvia da galinha vai em direção da taverna.\n");
                x = 0;
                break;
            case 2:
                printf("Você decide lutar com a galinha!\n");
                fight(&player, galinha, 0);
                x = 0;
                break;
            default:
                printf("Escolha não existe!\n");
                break;
        }
    }
}

void quest_1a() {
    char *str1 =
        "Após uma hora você sai da taverna e encontra Abdam com sua carroça te esperando para sair."
        " Vocês saem rumo a oeste pela estrada do rei, um pouco antes de escurecer vocês decidem parar para montar acampamento."
        " Você diz a Abdam que ira pegar lenha para fazer uma fogueira.\n";
    colledPrint(str1);
    colledPrint("Abdam -> Eu preferia que não chamassemos muita atenção, pois pode haver saqueadores na floresta.\n");
    colledPrint("Oque você deseja fazer?\n");
    colledPrint("1 - Não acender a fogueira\n");
    colledPrint("2 - Insistir em acender a fogueira\n");
    int x = 1, escolha;
    while (x) {
        scanf("%d", &escolha);
        switch (escolha) {
            case 1:
                clrscr();
                colledPrint("No calar da noite, uivos os acordam e os dois levantam apavorados, você ve um vuto na escuridão e avista oque parece ser um lobo solitário.\n");
                colledPrint("Você pregueja por não ter acendido a fogueira....Por ter baixa visibilidade você recebera um debuff de -2 de acerto.\n");
                fight(&player, wolf, -2);
                x = 0;
                break;
            case 2:
                clrscr();
                colledPrint("No calar da noite, uivos os acordam e os dois levantam apavorados, você avista um lobo solitário.\n");
                fight(&player, wolf, 0);
                x = 0;
                break;
            default:
                printf("Escolha não existe!\n");
                break;
        }
    }
}

void quest_1b() {
  char *str1="Na manhã você s";

}

void quest_1() {
    int x = 1, escolha;
    char *str1 = "1 - Você aceita a proposta e pergunta se daqui uma hora está bom?\n2 - Você rejeita a proposta mas diz que pode sair pela manhã do dia seguinte se ele estiver disposto.\n->";
    colledPrint(str1);
    while (x) {
        scanf("%d", &escolha);
        switch (escolha) {
            case 1:
                colledPrint("Abdam -> Perfeito, estou com pressa então quanto antes sairmos melhor, assim que chegarmos lhe pagarei 100 moedas.\n");
                colledPrint("Loading..........................................................................................................................................");
                x = 0;
                clrscr();
                quest_1a();
                break;
            case 2:
                colledPrint("Abdam -> Ok..., vou perder um pouco dinheiro com atraso , mas assim que chegarmos lhe pagarei 50 moedas.\n");
                x = 0;
                colledPrint("Loading..........................................................................................................................................");
                clrscr();
                quest_1b();
                break;
            default:
                printf("Escolha não existe!\n");
                break;
        }
    }
}


void defineClassPlayer(int aux) {
    strcpy(player.name, NAME);
    if (aux == 1) {
        player.classe = 1;
        player.life = 50;
        player.damage[0] = 6;
        player.damage[1] = 1;
        player.damage[2] = 3;
        player.resistence = 16;
        player.bonus = 3;
    } else if (aux == 2) {
        player.classe = 2;
        player.life = 30;
        player.damage[0] = 4;
        player.damage[1] = 2;
        player.damage[2] = 4;
        player.resistence = 14;
        player.bonus = 3;
    } else if (aux == 3) {
        player.classe = 3;
        player.life = 40;
        player.damage[0] = 4;
        player.damage[1] = 2;
        player.damage[2] = 2;
        player.resistence = 15;
        player.bonus = 3;
    }
}

void charSelection() {
    int escolha = 0, continuar;
    while (1) {
        while (escolha < 1 || escolha > 3) {
            clrscr();
            printf("==========================\n");
            printf("Escolha uma das classes:\n");
            printf("1 - Guerreiro\n");
            printf("2 - Mago\n");
            printf("3 - Arqueiro\n");
            printf("-> ");
            scanf("%d", &escolha);
            switch (escolha) {
                case 1:
                    clrscr();
                    printf("==========================\n");
                    printf("A classe Guerreiro possui os\nseguintes atributos:\n");
                    printf("Vida - 50\n");
                    printf("Resistencia - 16\n");
                    printf("Dano - 1 dado D6 + 3\n");
                    printf("==========================\n");
                    break;
                case 2:
                    clrscr();
                    printf("==========================\n");
                    printf("A classe Mago possui os\nseguintes atributos:\n");
                    printf("Vida - 30\n");
                    printf("Resistencia - 13\n");
                    printf("Dano - 2 dados D4 + 3\n");
                    printf("==========================\n");
                    break;
                case 3:
                    clrscr();
                    printf("==========================\n");
                    printf("A classe Arquiro possui os\nseguintes atributos:\n");
                    printf("Vida - 40\n");
                    printf("Resistencia - 15\n");
                    printf("Dano - 2 dados D4 + 2\n");
                    printf("==========================\n");
                    break;
                default:
                    printf("Escollha não existe!");
                    break;
            }
        }
        defineClassPlayer(escolha);
        printf("Deseja continuar para aventura?\nOu deseja escolhar uma nova classe?\n");
        printf("1 - Continuar\n");
        printf("2 - Escolher nova classe\n");
        printf("-> ");
        scanf("%d", &continuar);
        if (continuar == 1) {
            break;
        } else {
            escolha = 0;
        }
    }
}

void main() {
    //loginUser(); //começa com o login do usuario, deixar pra dps
    randomize();
    charSelection();
    clrscr();
    char *str1 =
        "Obstinado a conhecer a grande cidade de Solitude e conhecer o mestre de sua arte"
        " você decide sair da fazenda que passou sua vida toda deixando para trás sua familia e amigos..."
        " Após 2 dias de viagem a sua primeira parada é na vila de Riverwood."
        " Uma vila pouco movimentada, com seu pricipal atrativo a madereira local.."
        " Você decide ir a taverna local para buscar direções que deve seguir para chegar a Solitude\n\n"
        "Em frente a taverna você já consegue ouvir musica, você vê algumas galinhas e uma carroça."
        " Uma das galinhas para bem em sua frente bloqueando sua passagem (Obiviamente de proposito.....).\n";

    //colledPrint(str1);
    easterEgg();
   // colledPrint("Loading ..................................................................");
    clrscr();

    char *str2 =
        "Você abre a porta da taverna e vê o bardo tocando uma musica animadora alguns clientes ao redor bebendo de cantando"
        " ao se aproximar do balcão o taverneiro o comprimenta:\n"
        "Taverneiro ->  Olá aventureiro você deseja algo para comer ou beber?\n"
        "Você -> Gostaria de uma cerveja e saber que direção fica Solitude.\n"
        "O taverneiro te entrega a cerveja e diz:\n"
        "Taverneiro -> Aqui está a cerveja e fica 5 moedas tudo.. e Solitude fica a um dia de viagem a oeste pela estrada do rei.\n"
        "Você agradece e paga o taberneiro e volta sua atenção para a musica. Após algum tempo um homem se aproxima de você e lhe pergunta:\n"
        "Abdam -> Olá aventureiro, meu nome é Abdam, e fiquei sabendo que você está a caminho de Solitude, tenho algumas"
        " mercadorias para negociar lá, estou um pouco atrasado e gostaria de sair ainda hoje e teriamos que pernoitar na estrada então seria bom viajar em maior número, oque você acha?\n";
    //colledPrint(str2);

    quest_1();
}