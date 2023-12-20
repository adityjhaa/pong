#include "raylib.h"

int main(){

    InitWindow(1600,1000,"PONG");
    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(WHITE);
        EndDrawing();
    }
    CloseWindow();

    return 0;
}