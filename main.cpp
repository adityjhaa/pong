#include "raylib.h"

int main(){

    InitWindow(1600,1000,"PONG");
    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(WHITE);
        DrawRectangle(10,10,1580,980,BLACK);
        EndDrawing();
    }
    CloseWindow();

    return 0;
}