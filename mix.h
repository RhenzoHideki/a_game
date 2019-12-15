#ifndef MIX_H
#define MIX_H

extern void clrscr();                      //Função para limpar a tela
extern void randomize();                   //Começa a gerar numeros aleatórios conforme o tempo
extern int dice(int aux);                  //Retorna um numero aleatório
extern void delay(unsigned int mseconds);  //Função que dá delay conforme o clock
extern void colledPrint(char *aux);        //Função que printa uma string como se fosse digitado

#endif