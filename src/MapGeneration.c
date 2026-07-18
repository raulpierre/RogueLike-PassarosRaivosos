#include "MapGeneration.h"

static uint32_t estadoMapa = 1;
Tiles mapa[8][8];

static const int regras[3][3] = {
    {1, 1, 0},
    {1, 1, 1},
    {0, 1, 1}
};

void definirSemente(uint32_t semente){
    estadoMapa = semente;
}

uint32_t obterAleatorio(){
    estadoMapa = (LCG_A * estadoMapa) + LCG_C; 
    return estadoMapa;
}

int intervaloAleatorio(int min, int max){
    return min + (obterAleatorio() % (max - min + 1));
}

void inicializarMapa(){
    for (int y = 0; y < 8; y++){
        for (int x = 0; x < 8; x++){
            mapa[y][x].colapsada = false;
            mapa[y][x].entropia = 3;
            mapa[y][x].pecaFinal = -1;                
            for (int i = 0; i < 3; i++){
                mapa[y][x].possibilidades[i] = true;
            }
            
        }
        
    }
    
}

bool acharMenorEntropia(int *outX, int *outY){
    int menor = 9999;
    bool achou = false;

    for (int y = 0; y < 8; y++){
        for (int x = 0; x < 8; x++){
            if (!mapa[y][x].colapsada && mapa[y][x].entropia < menor){
                menor = mapa[y][x].entropia;
                *outX = x;
                *outY = y;
                achou = true;
            }
        }
    }
    
    return achou;
}

void propagarVizinho(int x, int y, int escolhida){
    if(x >= 8 || x < 0 || y < 0 || y >= 8) return;
    if(mapa[y][x].colapsada) return;

    int novaEntropia = 0;
    for (int i = 0; i < 3; i++){
        if(mapa[y][x].possibilidades[i] && regras[escolhida][i] == 0){
            mapa[y][x].possibilidades[i] = false;
        }

        if(mapa[y][x].possibilidades[i]){
            novaEntropia++;
        }
    }
    mapa[y][x].entropia = novaEntropia;
}

void rodarWFC(){
    int x, y;
    
    while(acharMenorEntropia(&x, &y)){

        if(mapa[y][x].entropia == 0){
            return; 
        }
        int escolhasValidas[3];
        int qtdValidas = 0;

        for (int p = 0; p < 3; p++){
            if(mapa[y][x].possibilidades[p]){
                escolhasValidas[qtdValidas] = p;
                qtdValidas++;
            }
        }

        int indiceSorteado = intervaloAleatorio(0, qtdValidas - 1);
        int pecaDecidida = escolhasValidas[indiceSorteado];

        mapa[y][x].colapsada = true;
        mapa[y][x].pecaFinal = pecaDecidida;

    
        propagarVizinho(x, y - 1, pecaDecidida);
        propagarVizinho(x, y + 1, pecaDecidida);
        propagarVizinho(x - 1, y, pecaDecidida);
        propagarVizinho(x + 1, y, pecaDecidida);
    }
}

void desenharMapa(){
    Vector2 posicao = {
        .x = 342,
        .y =0
    };
    for (int y = 0; y < 8; y++){
        posicao.x = 342;
        for (int x = 0; x < 8; x++){
            if(mapa[y][x].colapsada && mapa[y][x].pecaFinal == 0){
                DrawRectangle(posicao.x, posicao.y, 64, 64,BROWN);
            }else if(mapa[y][x].colapsada && mapa[y][x].pecaFinal == 1){
                DrawRectangle(posicao.x, posicao.y, 64, 64,YELLOW);
            }else if(mapa[y][x].colapsada && mapa[y][x].pecaFinal == 2){
                DrawRectangle(posicao.x, posicao.y, 64, 64,BLUE);
            }else{
                DrawRectangle(posicao.x, posicao.y, 64, 64,RED);
            }
            posicao.x = posicao.x + 64;
        }

        posicao.y = posicao.y + 64;
    }
}
void drawFloor(Floor floor){
    DrawRectangle(floor.origem.x, floor.origem.y, floor.largura, floor.altura, GREEN);
}