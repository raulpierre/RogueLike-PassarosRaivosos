#pragma once
#include "raylib/raylib.h"
#include <stdint.h>

typedef struct Entities {
    Vector2 position;
    int mass;
    int width;
    int height;
    uint32_t id;
}Entities;

void DrawEntities(Vector2 position, int width, int height, Color color);

void updateEntities(Entities *ent, float delta);

Entities* CreateBlock(float x, float y, int typeMaterial);
