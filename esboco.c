#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

char NAME[20];
struct PC
{
  char name[20];
  int life; //pos[0]= Dice,1= times, 2=bonus
  int resistence;
  int damage[3]; //Dice, times, bonus
} goblin, player;

// goblin = {
//     "Goblin",
//     {6, 2, 0},
//     0,
//     15,
//     {6, 1, 2}};

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

int dice(int aux)
{
  return rand() % aux + 1;
}

// int lifeEnemy(struct PC aux)
// {
//   int life = 0;
//   for (int i = 0; i < aux.life[1]; i++)
//   {
//     life = life + dice(aux.life[0]);
//   }
//   return life;
// };

// int damageHero()
// {
//   int damage = 0;
//   for (int i = 0; i < player.damage[1]; i++)
//   {
//     damage = player.damage[0] + damage;
//   }
//   return damage + player.damage[2];
// }

// int hit()
// {
// }

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

void printColled (char *aux){
  int count = 0;
  while (*aux != 0)
  {
    if (count > 80 && *aux == ' ')
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

void main()
{

  //loginUser(); //começa com o login do usuario, deixar pra dps

  charSelection();
  //Textao
  clrscr();

  char *str = "Obstinado a conhecer a grande cidade de Whiterun e conhecer o mestre de sua arte"
              " você decide sair da fazenda que passou sua vida toda deixando para trás sua familia e amigos..."
              " Após 2 dias de viagem a sua primeira parada é na vila de Riverwood."
              " Uma vila pouco movimentada, com seu pricipal atrativo o madereira local.."
              " Você decide ir a taverna local para buscar direções que deve seguir para chegar a Whiterun\n";

  printColled(str);
}