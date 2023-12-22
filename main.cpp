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
    float velocity = 700.f;
    
    float circle_x = 800.f;
    float circle_y = 500.f;
    float circle_rad = 20.f;
    float cir_vel_x = 500.f;
    float cir_vel_y = 500.f;
    

    SetTargetFPS(360);
    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(WHITE);
        float dt = GetFrameTime();
        DrawRectangle(10,10,1580,980,BLACK);
        DrawLine(800,10,800,990,WHITE);
        DrawCircle(circle_x,circle_y,circle_rad,WHITE);

        float player_vel{},ai_velocity{};
        if(IsKeyDown(KEY_DOWN) and player.posy<=675){
            player.posy+=velocity*dt;
            player_vel=velocity;
        }
        if(IsKeyDown(KEY_UP) and player.posy>=25){
            player.posy-=velocity*dt;
            player_vel=-velocity;    
        }
        
        if(circle_y<=30.f){cir_vel_y*=-1.f;}
        if(circle_y>=970.f){cir_vel_y*=-1.f;}

        if(ai.posy+150>circle_y and ai.posy>=25 and cir_vel_x<0){
            ai.posy-=velocity*dt;
            ai_velocity=-velocity;
        }
        if(ai.posy+150<circle_y and ai.posy<=675 and cir_vel_x<0){
            ai.posy+=velocity*dt;
            ai_velocity=velocity;
        }

        if(CheckCollisionCircleRec(Vector2{circle_x,circle_y},circle_rad,
        Rectangle{player.posx,player.posy,player.width,player.height})){
            cir_vel_x*=-1.f;
            cir_vel_y+=player_vel;
        }
        if(CheckCollisionCircleRec(Vector2{circle_x,circle_y},circle_rad,
        Rectangle{ai.posx,ai.posy,ai.width,ai.height})){
            cir_vel_x*=-1.f;
            cir_vel_y+=ai_velocity;
        }

        circle_x += cir_vel_x*dt;
        circle_y += cir_vel_y*dt;
        DrawRectangle(player.posx,player.posy,player.width,player.height,WHITE);
        DrawRectangle(ai.posx,ai.posy,ai.width,ai.height,WHITE);
        EndDrawing();
    }
    CloseWindow();

    return 0;
}