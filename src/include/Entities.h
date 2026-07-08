#pragma once

#include "raylib/raylib.h"
#include "Physics.h"
#include <stdint.h>
#include <stdbool.h>

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
    bool active;
    bool isMaterial;
    TypeEntities entityTypo;
}Entities;

void DrawEntities(Vector2 position, int width, int height, Color color);

void updateEntities(Entities *ent, float delta);

PhysicalEntity* searchEmptySlot(void);

Entities* CreateBlock(float x, float y, int typeMaterial);
