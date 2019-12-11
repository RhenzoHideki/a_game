#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

struct Usuario {
  char nome[20];
  char username[10];
  char pass[10];
  int save;
  int classe;
} aux, *p;

void criaUsuario() {
  FILE *ptr;
  int ret;
  p = &aux;
  char nome[20];
  char username[10];
  char pass[10];
  printf("Insira seu nome: ");
  scanf(" %[^\n]s", p->nome);
  printf("Insira seu nome de usuário: ");
  scanf(" %[^\n]s", p->username);
  printf("Escolha uma senha: ");
  scanf(" %[^\n]", p->pass);

  if ((ptr = fopen("user.txt", "ab")) == NULL) {
    printf("Erro na abertura de arquivo\n");
    exit(-1);
  }
  fprintf(ptr, "%s %s %s %d %d\n", p->nome, p->username, p->pass, p->save, p->classe);
  fclose(ptr);
}

void verificaLogin() {
  p = &aux;
  char username[10], senha[10], buffer[100 + 1];
  FILE *ptr;
  int ret = 0, i = 0;

  printf("Informe o usuário: ");
  scanf(" %[^\n]s", username);
  printf("Informe a senha: ");
  scanf(" %[^\n]s", senha);

  if ((ptr = fopen("user.txt", "rb")) == NULL) {
    printf("Erro na abertura de arquivo\n");
    exit(-1);
  }
  while (ret != EOF) {
    ret = fscanf(ptr, "%s %s %s %d %d", p->nome, p->username, p->pass, &p->save, &p->classe);
    //printf("%s %s %s %d %d\n", p->nome, p->username, p->pass, p->save, p->classe);
    if (strcmp(p->username, username) == 0 && strcmp(p->pass, senha) == 0) {
      printf("Login efetuado com sucesso!\n");
      break;
    } else {
      printf("Usuário invalido");
      break;
    }
  }
  fclose(ptr);
}

void Login() {
  int x = 1;
  while (x) {
    int choice;
    printf("1 - Fazer login\n");
    printf("2 - Criar usuário\n");
    printf("3 - Entrar como anonimo\n");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        verificaLogin();
        x = 0;
        break;
      case 2:
        criaUsuario();
        break;
      case 3:
        x = 0;
        break;
      default:
        printf("Opção não existe!");
        break;
    }
  }
}

void main() {
  Login();
}