#include "raylib.h"
#include "SlingShot.h"

void updateSlingShot(SlingShot *SlingShot, int *delta){}

void DrawSlingShot(SlingShot *SlingShot){
    Rectangle rec;
    rec.x = SlingShot->posicao.x;
    rec.y = SlingShot->posicao.y;
    rec.height = SlingShot->height;
    rec.width = SlingShot->width;

    Vector2 beginning; //serve de demarcação de onde deve começar a desenhar
    beginning.x = 0;
    beginning.y = 0;
    DrawRectanglePro(rec, beginning, 180.0f, BLACK);
}