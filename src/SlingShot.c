#include "raylib.h"
#include "SlingShot.h"

void updateSlingShot(SlingShot *SlingShot, int *delta){}

void DrawSlingShot(SlingShot *SlingShot){
    Rectangle rec;
    rec.x = SlingShot->posicao.x;
    rec.y = SlingShot->posicao.y;
    rec.height = SlingShot->height;
    rec.width = SlingShot->width;

    Vector2 seila;
    seila.x = 20;
    seila.y = 20;
    DrawRectanglePro(rec, seila, 0.0f, BLACK);
}