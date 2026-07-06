#pragma once
#include <raylib.h>

typedef struct Entities{
    Vector2 *position;
    int *mass;
    int *width;
    int *height;
}Entities;

void DrawEntities(Vector2 *position, int *width, int *height, Color *color);