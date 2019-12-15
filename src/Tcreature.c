#include "Tcreature.h"
#include <stdio.h>

struct Tcreature player;  //Instancia a struct player

struct Tcreature goblin = {  //Structre de inimigos
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
    {10, 1, 20},
    20};

struct Tcreature wolf = {
    "Lobo",
    0,
    26,
    13,
    {4, 2, 2},
    1};
