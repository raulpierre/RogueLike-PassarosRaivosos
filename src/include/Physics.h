#pragma once

#include "raylib/raylib.h"
#include <stdbool.h>
#include <stdint.h>

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

typedef struct PhysicalEntity {
    RigidBody rb;
    Collider colider;
    int hp;
    uint32_t id;
    TypeEntities entityTypo;
    uint8_t materialID;
    bool active;
}PhysicalEntity;
// se quiser adicionar efeito só colocar aqui



