/**
 * @file GameWorld.c
 * @author Prof. Dr. David Buzatto
 * @brief GameWorld implementation.
 * 
 * @copyright Copyright (c) 2026
 */

//imports padrao
#include <stdio.h>
#include <stdlib.h>

//imports local
#include "Entities.h"
#include "SlingShot.h"
#include "ResourceManager.h"
#include "GameWorld.h"
#include "MapGeneration.h"

//imports raylib
#include "raylib/raylib.h"
//#include "raylib/raymath.h"
//#define RAYGUI_IMPLEMENTATION    // to use raygui, comment these three lines.
//#include "raylib/raygui.h"       // other compilation units must only include
//#undef RAYGUI_IMPLEMENTATION     // raygui.h


/**
 * @brief Creates a dinamically allocated GameWorld struct instance.
 */
GameWorld *createGameWorld( void ) {

    GameWorld *gw = (GameWorld*) malloc( sizeof( GameWorld ) );

    gw->dummy = 0;

    return gw;

}

/**
 * @brief Destroys a GameWindow object and its dependecies.
 */
void destroyGameWorld( GameWorld *gw ) {
    free( gw );
}

/**
 * @brief Reads user input and updates the state of the game.
 */
void updateGameWorld( GameWorld *gw, float delta ) {

}

/**
 * @brief Draws the state of the game.
 */
void drawGameWorld( GameWorld *gw ) {

    BeginDrawing();
    ClearBackground( WHITE );

    Vector2 teste;
    teste.x = GetScreenWidth() / 5 - 50;
    teste.y = GetScreenHeight() * 0.75f;  // sempre desenha o estilingue apartir de 75% de altura da tela 
    Estilingue estilingue = {
        .posicao = teste,
        .altura = 100,
        .largura = 50,
        .raioMax = 50,
        .energiaCinetica = 0,
        //.projectile = (Entities),
        .state = AIM
    };
    DrawSlingShot(&estilingue);
    
    Floor floor = {
        .origem.x = 0,
        .origem.y = GetScreenHeight() * 0.75,
        .largura = GetScreenWidth(),
        .altura = GetScreenHeight()
    };
    drawFloor(floor);

    uint32_t seed_escolhida = 322; 
    definirSemente(seed_escolhida);

    inicializarMapa();
    rodarWFC();
    desenharMapa();

    EndDrawing();

}