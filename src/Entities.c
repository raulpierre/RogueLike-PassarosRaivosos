#include "Entities.h"
#include "Physics.h"
#include "raylib/raylib.h"

// static uint32_t global_id_count = 1;

// Entities* CreateBlock(float x, float y, int typeMaterial) {

// }

void DrawEntities(Vector2 position, int width, int height, Color color){
    DrawRectangle(position.x, position.y, width, height, color);
}

void updateEntities(Entities *ent, float delta) {

}
