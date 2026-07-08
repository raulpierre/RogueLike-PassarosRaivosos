#pragma once
#include "raylib.h"
#include "Entities.h"

typedef enum stateSlingShot{SLOTHFUL, AIM, FIRED} stateSlingShot;

typedef struct SlingShot{
    Vector2 posicao;
    float height;
    float width;
    float radiusMax;
    float kinectEnergy;
    stateSlingShot state;
    //Entities projectile;
}SlingShot;

void updateSlingShot(SlingShot *SlingShot, int *delta); 
void DrawSlingShot(SlingShot *SlingShot);