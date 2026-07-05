#pragma once

#include "raylib/raylib.h"
#include <stdbool.h>

typedef enum TypeEntities {
    BIRDS,
    BLOCKS,
    FLOOR
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
    CIRCLE_ENTITIE,
    RECTANGLE_ENTITIE
} TypeTag;

typedef struct Collider {
    TypeTag tag;
    union {
        float radius;
        typedef struct {
            float widgth;
            float height;
        };
    } Size;
} Collider;

typedef struct PhysicalEntity {
    RigidBody *rb;
    Collider *colider;
    int hp;



};
// se quiser adicionar efeito só colocar aqui



