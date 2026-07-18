#include <stdio.h>

#include "Entities.h"
#include "raylib/raylib.h"

#define MAX_ENTITIES  200
// static Entities entityPool[MAX_ENTITIES];



// static uint32_t global_id_count = 1;

//tabelas para
// static const MaterialDef materialTable[] = {
//     [WOOD] = {.densidade = 0.6f, .elasticidade = 0.4f, .friccao = 0.5f, .vida = 1},
//     [GLASS] = {.densidade = 0.6f, .elasticidade = 0.4f, .friccao = 0.5f, .vida = 1},
//     [STONE] = {.densidade = 0.6f, .elasticidade = 0.4f, .friccao = 0.5f, .vida = 1},

// };

// MaterialDef getMaterialDef(TypeMaterial type) {

// }


// Entities* searchEmptySlot(void) {

//     for (int i = 0; i < MAX_ENTITIES; i++) {

//         if (!entityPool[i].active) {
//             return &entityPool;
//         }
//     }

//     return NULL;
// }

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

void DrawEntities(Vector2 position, int largura, int altura, Color color){
    DrawRectangle(position.x, position.y, largura, altura, color);
}

// void updateEntities(Entities *ent, float delta) {

// }
