#include "raylib.h"

const int width = 1600, height = 1000;

struct rect{
    float posx,posy;
    float width,height;
};


int main(){

    InitWindow(width,height,"PONG");
    rect player{1550,350,15,300};
    rect ai{35,350,15,300};

    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(WHITE);
        DrawRectangle(10,10,1580,980,BLACK);
        DrawLine(800,10,800,990,WHITE);
        DrawCircle(800,500,20.f,WHITE);
        DrawRectangle(player.posx,player.posy,player.width,player.height,WHITE);
        DrawRectangle(ai.posx,ai.posy,ai.width,ai.height,WHITE);
        EndDrawing();
    }
    CloseWindow();

    return 0;
}