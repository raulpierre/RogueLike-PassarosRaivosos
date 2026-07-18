#include "raylib.h"
#include "SlingShot.h"

void updateSlingShot(Estilingue *Estilingue, int *delta){}

void DrawSlingShot(Estilingue *Estilingue){
    Rectangle rec;
    rec.x = Estilingue->posicao.x;
    rec.y = Estilingue->posicao.y;
    rec.height = Estilingue->altura;
    rec.width = Estilingue->largura;

    Vector2 beginning; //serve de demarcação de onde deve começar a desenhar
    beginning.x = 0;
    beginning.y = 0;
    DrawRectanglePro(rec, beginning, 180.0f, BLACK);
}