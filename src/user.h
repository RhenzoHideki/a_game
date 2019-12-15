
#ifndef A_GAME_USER_H
#define A_GAME_USER_H

extern struct Usuario {
  char nome[20];
  char username[10];
  char pass[10];
  int save;
  int classe;
};

extern void criaUsuario();
extern void verificaLogin();
extern void Login();

#endif  //A_GAME_USER_H