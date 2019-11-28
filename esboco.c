#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

char NAME[20] = "Teste";
struct Tcreature
{
  char name[20];
  int life; //pos[0]= Dice,1= times, 2=bonus
  int resistence;
  int damage[3]; //Dice, times, bonus
} player;

struct Tcreature goblin = {
    "Goblin",
    20,
    15,
    {6, 1, 2}};

struct Tcreature galinha = {
    "Galinha",
    30,
    16,
    {10, 1, 5}};

void delay(unsigned int mseconds)
{
  clock_t goal = mseconds + clock();
  while (goal > clock())
    ;
}

void clrscr()
{
  system("@cls||clear");
}

void randomize()
{
  srand(time(NULL));
}

int dice(int aux)
{
  return (rand() % aux) + 1;
}

int damageDone(struct Tcreature *damager, struct Tcreature *taker, int aux)
{
  int damage = (dice(damager->damage[0]) * damager->damage[1] + damager->damage[2]) * aux;
  taker->life = taker->life - damage;
  if (taker->life > 0)
  {
    printf("%s causou %d de dano a %s", damager->name, damage, taker->name);
    return 0;
  }
  else
  {
    printf("%s deu uma chapoletada fatal no %s", damager->name, taker->name);
    return 1;
  }
};

void defineClassPlayer(int aux)
{
  strcpy(player.name, NAME);
  if (aux == 1)
  {
    player.life = 50;
    player.damage[0] = 6;
    player.damage[1] = 1;
    player.damage[2] = 3;
    player.resistence = 16;
  }
  else if (aux == 2)
  {
    player.life = 30;
    player.damage[0] = 4;
    player.damage[1] = 2;
    player.damage[2] = 4;
    player.resistence = 14;
  }
  else if (aux == 2)
  {
    player.life = 40;
    player.damage[0] = 4;
    player.damage[1] = 2;
    player.damage[2] = 2;
    player.resistence = 16;
  }
}

void colledPrint(char *aux)
{
  int count = 0;
  while (*aux != 0)
  {
    if (*aux == '\n')
    {
      count = 0;
    }
    if (count > 100 && *aux == ' ')
    {
      printf("\n");
      count = 0;
      *aux++;
    }
    printf("%c", *aux++);
    fflush(stdout);
    delay(50000);
    count++;
  }
}

void charSelection()
{
  int escolha = 0, continuar;
  while (1)
  {
    while (escolha < 1 || escolha > 3)
    {
      clrscr();
      printf("==========================\n");
      printf("Escolha uma das classes:\n");
      printf("1 - Guerreiro\n");
      printf("2 - Mago\n");
      printf("3 - Arqueiro\n");
      printf("-> ");
      scanf("%d", &escolha);
      switch (escolha)
      {
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
        printf("Resistencia - 16\n");
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
    scanf("%d", &continuar);
    if (continuar == 1)
    {
      break;
    }
    else
    {
      escolha = 0;
    }
  }
}

void verifyHit(struct Tcreature *atk, struct Tcreature *def)
{
  int acerto = dice(20);
  if (acerto = 20)
  {
    printf("Você rolou 20!! Acertos criticos dão o dobro de dano.\n");
    damageDone(atk, def, 2);
  }
  else if (acerto < def->resistence)
  {
    printf("%s errou o golpe, rolou %d e a resistencia do inimigo é %d\n",atk->name, acerto, def->resistence);
  }
  else
  {
    printf("Você rolou %d e acertou o inimigo que tem resistencia %d\n", acerto, def->resistence);
    damageDone(atk, def, 1);
  }
}

void fight(struct Tcreature *aux1, struct Tcreature aux2)
{
  int acerto, damage;
  while (aux1.life > 1 && aux2.life > 1)
  {
    printf("%s se prepara pra atacar...e..\n", aux1.name);

    aux2.life = aux2.life - damage;
    if (aux2.life < 1)
      break;

    printf("%s se prepara pra atacar...e..\n", aux2.name);
    acerto = dice(20);
    if (acerto = 20)
    {
      printf("Você rolou 20!! Acertos criticos dão o dobro de dano.\n");
      damage = (2 * damageDone(aux2.damage));
    }
    else if (acerto < aux1.resistence)
    {
      printf("Errou o golpe, você rolou %d e a resistencia do inimigo é %d\n", acerto, aux1.resistence);
    }
    else
    {
      printf("Você rolou %d e acertou o inimigo que tem resistencia %d\n", acerto, aux1.resistence);
      damage = damageDone(aux2.damage);
    }
    aux1.life = aux1.life - damage;
  }
}

void easterEgg()
{
  int escolha;
  char *str1 = "Você deseja fazer alguma coisa a respeito??\n1 - Fugir da galinha??\n2 - Pedir ajuda??\n3 - Chorar pela sua mamãe??\n->";
  char *str2 = "Sua escolha pouco importa, a galinha quer sanguee!!\n";
  colledPrint(str1);
  scanf("%d", &escolha);
  colledPrint(str2);
  fight(player, galinha);
}

void main()
{

  //loginUser(); //começa com o login do usuario, deixar pra dps
  randomize();
  charSelection();
  //Textao
  clrscr();

  char *str1 = "Obstinado a conhecer a grande cidade de Whiterun e conhecer o mestre de sua arte"
               " você decide sair da fazenda que passou sua vida toda deixando para trás sua familia e amigos..."
               " Após 2 dias de viagem a sua primeira parada é na vila de Riverwood."
               " Uma vila pouco movimentada, com seu pricipal atrativo o madereira local.."
               " Você decide ir a taverna local para buscar direções que deve seguir para chegar a Whiterun\n\n"
               "Em frente a taverna você já consegue ouvir musica, você vê algumas galinhas e uma carroça."
               " Uma das galinhas para bem em sua frente bloqueando sua passagem (Obiviamente de proposito.....).\n";

  colledPrint(str1);
  easterEgg();
}