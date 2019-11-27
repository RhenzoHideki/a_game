//
// Created by aluno on 27/11/2019.
//

#ifndef GAME_FIGHT_H
#define GAME_FIGHT_H

#endif //GAME_FIGHT_H

#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

int func_atk_player (){
    srand(time(NULL));
    dice=rand()%20+1;
    printf("Seu dado foi: %d\n",dice);
    if (dice>=12){              //Aqui tbm seria fixo, cada monstro com o suas resistencias, ai calcula com a situações...
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
    printf("digita 'a' para jogar um dado de ataque\n");                //Aqui podemos tentar integrar com alguma coisa, se for possivel o firebase, pode ser até em app...
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