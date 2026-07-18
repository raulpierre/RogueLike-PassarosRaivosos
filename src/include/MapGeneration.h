#pragma once


//IMPORTS PADRAO LINGUAGEM C
#include <stdint.h>
#include <stdio.h>


//IMPPORTS DA BIBLIOTECA RAYLIB E DO PROJETO
#include "raylib/raylib.h"
#include "Construcoes.h"


//MACROS
#define LCG_A 1664525U
#define LCG_C 1013904223U



//ESTRUTURAS
typedef struct Tiles{
    bool possibilidades[3]; //tipo de construção
    bool colapsada; //verifica se ja foi decidida
    int entropia; //quantidade de possibilidades 
    int pecaFinal; //peça final
}Tiles;

typedef struct Floor{
    Vector2 origem;
    float altura;
    float largura;
}Floor;


//PROTOTIPOS DE FUNÇÔES
void definirSemente();   
uint32_t obterAleatorio();
int intervaloAleatorio(int min, int max);
void drawFloor(Floor floor);
bool acharMenorEntropia(int *outX, int *outY);
void inicializarMapa();
void desenharMapa();
void rodarWFC();
void propagarVizinho(int x, int y, int escolhida);