#pragma once
#include "raylib.h"
#include "Entities.h"

typedef enum stateSlingShot{SLOTHFUL, AIM, FIRED} stateSlingShot;

typedef struct Estilingue{
    Vector2 posicao;
    float altura;
    float largura;
    float raioMax;
    float energiaCinetica;
    stateSlingShot state;
    //Entities projectile;
}Estilingue;

void updateSlingShot(Estilingue *Estilingue, int *delta); 
void DrawSlingShot(Estilingue *Estilingue);