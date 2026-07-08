#pragma once
#include "raylib/raylib.h"
#include <stdint.h>

typedef enum TypeEntities {
    BIRDS,
    BLOCKS,
    FLOOR,
    PIGS
} TypeEntities;

typedef enum TypeMaterial{
    WOOD,
    GLASS, 
    STONE
} TypeMaterial;

typedef struct Entities {
    Vector2 position;
    int mass;
    TypeEntities typeEntitie;
    TypeMaterial typeMaterial;
    uint32_t id;
}Entities;

void DrawEntities(Vector2 position, int width, int height, Color color);

void updateEntities(Entities *ent, float delta);

Entities* CreateBlock(float x, float y, int typeMaterial);
