#include "include/Entities.h"
#include "raylib/raylib.h"





//static uint32_t global_id_count = 1;


// Entities* CreateBlock(float x, float y, int typeMaterial) {

//     Entities* newBlock = searchEmptySlot();

//     if (newBlock == NULL) {
//         return NULL;
//     }

//     newBlock->id = global_id_count;

//     global_id_count++;

//     newBlock->active = true;

//     //falta coisa ainda, mas nao sei o que

//     return &newBlock;
// }

void DrawEntities(Vector2 position, int width, int height, Color color){
    DrawRectangle(position.x, position.y, width, height, color);
}

void updateEntities(Entities *ent, float delta) {

}
