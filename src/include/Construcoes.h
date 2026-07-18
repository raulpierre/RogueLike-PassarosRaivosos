#pragma once
#include <stdbool.h>
#include "raylib/raylib.h"


typedef enum Construções{
    BASE, // pode ter uma construção em cima 
    TOPO, // nao pode ter nada em cima 
    AEREO, // preso a objetos voadores
    //SUSPENSO // preso em terreno nao destrutivel
}Construções;

