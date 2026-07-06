#include "Entities.h"
#include "raylib.h"

void DrawEntities(Vector2 *position, int *width, int *height, Color *color){
    DrawRectangle(position->x, position->y, *width, *height, *color);
}