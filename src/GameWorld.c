/**
 * @file GameWorld.c
 * @author Prof. Dr. David Buzatto
 * @brief GameWorld implementation.
 * 
 * @copyright Copyright (c) 2026
 */
#include <stdio.h>
#include <stdlib.h>
#include <Entities.h>
#include "SlingShot.h"

#include "raylib/raylib.h"
//#include "raylib/raymath.h"
//#define RAYGUI_IMPLEMENTATION    // to use raygui, comment these three lines.
//#include "raylib/raygui.h"       // other compilation units must only include
//#undef RAYGUI_IMPLEMENTATION     // raygui.h

#include "GameWorld.h"
#include "ResourceManager.h"

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
    teste.x = GetScreenWidth() / 5;
    teste.y = GetScreenHeight() * 0.60f;  
    SlingShot estilingue = {
        .posicao = teste,
        .height = 150,
        .width = 50,
        .radiusMax = 50,
        .kinectEnergy = 0,
        //.projectile = (Entities),
        .state = AIM
    };
    DrawRectangle(0, GetScreenHeight(), GetScreenWidth(), teste.y, GREEN);
    DrawFPS( 20, 20 );

    DrawSlingShot(&estilingue);
    EndDrawing();

}