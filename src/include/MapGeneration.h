#include "raylib/raylib.h"

typedef enum DefLineUp{
    BASE, //pode ter uma construção em cima 
    TOP // nao pode ter nada em cima 
}DefLineUp;

int MapDivision(int ScrennHeight, int Screenwidht); // dividde cada espaco do mapa para que facilite a geração
int MapInsertion(); // 