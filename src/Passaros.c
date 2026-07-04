#include "raylib.h"

typedef enum {NORMAL, EXPLOSIVE, EXPANSION, BUBBLESSUSPENSION, MULTIPLICATION, ACCELERATION, BOOMERANG, BOMBER, BIGGESTPROPOCION } BirdsType;

typedef struct Birds{
    Vector2 position;
    int mass;
    BirdsType type;
    bool skillUsed;
}Birds;

void DrawBirds(int *delta){
    
}
void updateBird(int *delta){}
void clickTimeEvent(){}