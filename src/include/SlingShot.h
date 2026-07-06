#pragma once;
#include "raylib.h"
#include "Entities.h"

enum stateSlingShot{SLOTHFUL, AIM, FIRED};

typedef struct SlingShot{
    Vector2 posicao;
    float radiusMax;
    float kinectEnergy;
    stateSlingShot state;
    Entities projectile;
}SlingShot;

void updateSlingShot(SlingShot *SlingShot, int *delta, Entities *Entities); 