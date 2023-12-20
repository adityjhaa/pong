#include "raylib.h"

const int width = 1600, height = 1000;

int main(){

    InitWindow(width,height,"PONG");


    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(WHITE);
        DrawRectangle(10,10,1580,980,BLACK);
        DrawLine(800,10,800,990,WHITE);
        DrawCircle(800,500,20.f,WHITE);
        DrawRectangle(1550,350,15,300,WHITE);
        DrawRectangle(35,350,15,300,WHITE);
        EndDrawing();
    }
    CloseWindow();

    return 0;
}