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

typedef enum {
    WOOD,
    GLASS, 
    STONE
} TypeMaterial;

typedef struct RigidBody {
    Vector2 position;
    Vector2 vel;
    int force;      
    float inverseMass;      //como o chao vai ser um bloco de massa infinita, é mais facil calcular a massa invertida  para nao lidar 
} RigidBody;                // com divisões por zero

typedef struct MaterialDef {
    float density;
    float elasticity;
    float fricction;
    int hp;
} MaterialDef;

typedef enum {
    CIRCLE_ENTITY,
    RECTANGLE_ENTITY
} TypeTag;

typedef struct Collider {
    TypeTag tag;
    union {
        float radius;
        struct {
            float widgth;
            float height;
        };
    } Size;
} Collider;

typedef struct Entites {
    RigidBody rb;
    Collider colider;
    int hp;
    uint32_t id;
    TypeEntities entityTypo;
    uint8_t subtypeID;
    bool active;
} Entities;
// se quiser adicionar efeito só colocar aqui


void DrawEntities(Vector2 position, int width, int height, Color color);

void updateEntities(Entities *ent, float delta);

Entities* searchEmptySlot(void);

Entities* CreateBlock(float x, float y, int typeMaterial);

MaterialDef getMaterialDef(TypeMaterial type);
