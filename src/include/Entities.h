#pragma once

#include "raylib/raylib.h"
#include <stdint.h>
#include <stdbool.h>

typedef enum TypeEntities {
    BIRDS,
    BLOCKS,
    PIGS
} TypeEntities;

typedef enum {
    WOOD,
    GLASS, 
    STONE
} TypeMaterial;

typedef struct CorpoSolido {
    Vector2 position;
    Vector2 vel;
    int force;      
    float inverseMass;      //como o chao vai ser um bloco de massa infinita, é mais facil calcular a massa invertida  para nao lidar 
} CorpoSolido;                // com divisões por zero

typedef struct MaterialDef {
    float densidade;
    float elasticidade;
    float friccao;
    int vida;
} MaterialDef;

typedef enum {
    ENTIDADE_CIRCULO,
    ENTIDADE_RETANGULO
} TypeTag;

typedef struct Colisor {
    TypeTag tag;
    union {
        float raio;
        struct Proporcao{
            float largura;
            float altura;
        }Proporcao;
    }Size;
} Colisor;

typedef struct Entites {
    CorpoSolido rb;
    Colisor colisor;
    int vida;
    uint32_t id;
    TypeEntities entityTypo;
    uint8_t subtypeID;
    bool active;
} Entities;
// se quiser adicionar efeito só colocar aqui


void DrawEntities(Vector2 position, int largura, int altura, Color color);

void updateEntities(Entities *ent, float delta);

Entities* searchEmptySlot(void);

Entities* CreateBlock(float x, float y, int typeMaterial);

MaterialDef getMaterialDef(TypeMaterial type);
