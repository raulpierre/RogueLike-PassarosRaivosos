#include "Entities.h"
#include "Physics.h"
#include "raylib/raylib.h"

#define MAX_ENTITIES 200

static PhysicalEntity entityPool[MAX_ENTITIES];

static uint32_t global_id_count = 1;

PhysicalEntity* searchEmptySlot(void) {

    for (int i = 0; i < MAX_ENTITIES; i++) {

        if (!entityPool[i].active) {
            return &entityPool;
        }
    }

    return NULL;
}

// Entities* CreateBlock(float x, float y, int typeMaterial) {

    Entities* newBlock = searchEmptySlot();

    if (newBlock == NULL) {
        return NULL;
    }

    newBlock->id = global_id_count;

    global_id_count++;

    newBlock->active = true;

    //falta coisa ainda, mas nao sei o que

    return &newBlock;
}

void DrawEntities(Vector2 position, int width, int height, Color color){
    DrawRectangle(position.x, position.y, width, height, color);
}

void updateEntities(Entities *ent, float delta) {

}
