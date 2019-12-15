#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Tcreature.h"
#include "fight.h"
#include "mix.h"
#include "user.h"

char NAME[20] = "Default";

struct Tcreature player, galinha, wolf, goblin;

void easterEgg() {  // Primeira missão, optativa..
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

void quest_1a() {  // Missão bifurcada, esse é o lado A
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

void quest_1b() {  //Missão bifurcada, Lado B
  char *str1 =
      "Você paga por um quarto na taverna e na manha seguinte acorda e encontra Abdam com sua carroça te esperando para sair."
      " Vocês saem rumo a oeste pela estrada do rei... Após algumas horas de viagem vocês fazem uma parada para pegar agua em um riacho quando são atacados por um Goblin!!\n";
  colledPrint(str1);
  fight(&player, goblin, 0);
}

void quest_1() {  // 1° Missão
  int x = 1, escolha;
  char *str1 =
      "1 - Você aceita a proposta e pergunta se daqui uma hora está bom?\n"
      "2 - Você rejeita a proposta mas diz que pode sair pela manhã do dia seguinte se ele estiver disposto.\n-> ";
  colledPrint(str1);
  while (x) {
    scanf("%d", &escolha);
    switch (escolha) {
      case 1:
        colledPrint("Abdam -> Perfeito, estou com pressa então quanto antes sairmos melhor, assim que chegarmos lhe pagarei 100 moedas.\n");
        colledPrint("Loading................................................................................");
        x = 0;
        clrscr();
        quest_1a();
        break;
      case 2:
        colledPrint("Abdam -> Ok..., vou perder um pouco dinheiro com atraso , mas assim que chegarmos lhe pagarei 50 moedas.\n");
        x = 0;
        colledPrint("Loading................................................................................");
        clrscr();
        quest_1b();
        break;
      default:
        printf("Escolha não existe!\n");
        break;
    }
  }
}

void goodEnding() {  //Final do jogo
  char *str1 =
      "Apesar dos problemas encontrados no caminho o grupo chega em Solitude.. Abdam olha para o aventureiro e o vê de boca aberta admirando a cidade, e dá um tapa em suas costas.\n"
      "Continua.................\n\n\n"
      "Desenvolvedores:\n"
      "Rhenzo Hideki\n"
      "Mike Domingues\n";
  colledPrint(str1);
}

void defineClassPlayer(int aux) {  //Define os atributos da classe selecionada...
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

void saveContent(struct Tcreature *aux1, int *aux2) {  // Estrutura que verifica e salva o conteudo do jogador
  int escolha, x = 1;
  if (isDead(aux1)) {
    colledPrint("Você morreu...\n");
    colledPrint("1 - Continuar do ultimo save\n");
    colledPrint("2 - Recomeçar o jogo\n");
    colledPrint("3 - Sair do jogo\n");
    while (x) {
      printf("-> ");
      scanf("%d", &escolha);
      switch (escolha) {
        case 1:
          x = 0;
          break;
        case 2:
          *aux2 = 0;
          x = 0;
          break;
        case 3:
          *aux2 = 4;
          x = 0;
          break;
        default:
          colledPrint("Opção invalida...");
          break;
      }
    }
  } else {
    *aux2 = *aux2 + 1;
  }
  defineClassPlayer(aux1->classe);
}

void charSelection() {  //Opções para seleção de classe
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
void main() {  //Main...
  int save = 0, x = 1;
  char *str1 =
      "Obstinado a conhecer a grande cidade de Solitude e conhecer o mestre de sua arte"
      " você decide sair da fazenda que passou sua vida toda deixando para trás sua familia e amigos..."
      " Após 2 dias de viagem a sua primeira parada é na vila de Riverwood."
      " Uma vila pouco movimentada, com seu pricipal atrativo a madereira local.."
      " Você decide ir a taverna local para buscar direções que deve seguir para chegar a Solitude\n\n"
      "Em frente a taverna você já consegue ouvir musica, você vê algumas galinhas e uma carroça."
      " Uma das galinhas para bem em sua frente bloqueando sua passagem (Obviamente de proposito.....)\n";

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

  randomize();
  while (x) {  //While/Switch que faz a função de checkpoint do jogo..
    switch (save) {
      case 0:
        Login();
        charSelection();
        colledPrint("Saving ..................................................................");
        clrscr();
        save++;
        break;
      case 1:
        colledPrint(str1);
        easterEgg();
        colledPrint("Saving ..................................................................");
        clrscr();
        saveContent(&player, &save);
        break;

      case 2:
        colledPrint(str2);
        quest_1();
        colledPrint("Saving ..................................................................");
        clrscr();
        saveContent(&player, &save);
        break;

      case 3:
        goodEnding();
        x = 0;
        break;

      case 4:
        x = 0;
        break;

      default:
        printf("Are you god?");
        break;
    }
  }
}