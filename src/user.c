
#include "user.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tcreature.h"

struct Usuario hero, *p;

void criaUsuario() {
  FILE *ptr;
  int ret;
  char username[10];
  char pass[10];
  printf("Insira seu nome de usuário: ");
  scanf(" %[^\n]s", username);
  printf("Escolha uma senha: ");
  scanf(" %[^\n]s", pass);

  if ((ptr = fopen("user.txt", "ab")) == NULL) {
    printf("Erro na abertura de arquivo\n");
    exit(-1);
  }
  fprintf(ptr, "%s %s %d %d\n", username, pass, 0, 0);
  fclose(ptr);
}

int verificaLogin() {
  char username[10], senha[10], buffer[100 + 1];
  int ret = 0;
  p = &hero;
  FILE *ptr;

  printf("Informe o usuário: ");
  scanf(" %[^\n]s", username);
  printf("Informe a senha: ");
  scanf(" %[^\n]s", senha);

  if ((ptr = fopen("user.txt", "rb")) == NULL) {
    printf("Erro na abertura de arquivo\n");
    exit(-1);
  }
  while (ret != EOF) {
    ret = fscanf(ptr, "%s %s %d %d", p->username, p->pass, &p->save, &p->classe);
    //printf("%s %s %s %d %d\n", p->nome, p->username, p->pass, p->save, p->classe);
    if (strcmp(p->username, username) == 0 && strcmp(p->pass, senha) == 0) {
      fclose(ptr);
      return 1;
    }
  }
  fclose(ptr);
  return 0;
}

void Login() {
  int x = 1, logado;
  p = &hero;
  while (x) {
    int choice;
    printf("1 - Fazer login\n");
    printf("2 - Criar usuário\n");
    printf("3 - Entrar como anonimo\n");
    printf("-> ");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        logado = verificaLogin();
        if (logado) {
          printf("Login efetuado com sucesso!\n");
          x = 0;
        } else {
          printf("Usuário não existe!\n");
        }
        break;
      case 2:
        criaUsuario();
        break;
      case 3:
        strcpy(p->username, "Anon");
        strcpy(p->pass, "XD");
        p->classe = 0;
        p->save = 0;
        x = 0;
        break;
      default:
        printf("Opção não existe!\n");
        break;
    }
  }
}
