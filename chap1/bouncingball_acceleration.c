#include <stdio.h>
#include <stdlib.h>
#include <raylib.h>
#include <raymath.h>

// Application Name
#define APP_NAME "Nature of Code - Boucing Ball with Vectors"

// Frames per second
#define FPS 60

void printVector(Vector2 vec)
{
   printf("Vect{x=%f,y=%f}\n", vec.x, vec.y);
}

Vector2 VectNorm(Vector2 v)
{
   float mag = Vector2Length(v);
   if (mag==0)
      return (Vector2) {0.0f, 0.0f};
   else
      return (Vector2) {v.x/mag, v.y/mag};
}

int main(int argc, char *argv[])
{
   // Initialisation of Window
   const int screenWidth = 640;
   const int screenHeight = 480;

   float ballRadius = 20;

   Vector2 center = {screenWidth / 2, screenHeight / 2};
   Vector2 pos = center;
   Vector2 vel = {0, 0};
   Vector2 acc = {0, 0};

   InitWindow(screenWidth, screenHeight, APP_NAME);

   SetTargetFPS(FPS);

   // Main Game Loop
   while (!WindowShouldClose()) {
      BeginDrawing();
      ClearBackground(RAYWHITE);

      int mouseX = GetMouseX();
      int mouseY = GetMouseY();

      Vector2 mouse = {mouseX, mouseY};

      mouse = Vector2Subtract(mouse, pos);
      // printVector(mouse);
      // printVector(pos);
      mouse = VectNorm(mouse);
      mouse = Vector2Scale(mouse, 0.05);

      acc = mouse;
      // acc = Vector2Normalize(acc);
      // acc = Vector2Scale(acc, 0.1);
      
      if (Vector2Length(vel) < 5) {
         vel = Vector2Add(vel, acc);
      }
      pos = Vector2Add(pos, vel);

      // Bounce the ball of the edges
      if (pos.x - ballRadius < 0 || pos.x + ballRadius > screenWidth) {
         vel.x *= -1;
         // acc.x *= -1;
      }
      
      if (pos.y - ballRadius < 0 || pos.y + ballRadius > screenHeight) {
         vel.y *= -1;
         // acc.y *= -1;
      }
      
      DrawCircleV(pos, ballRadius, DARKBLUE);

      EndDrawing();
   }

   CloseWindow();

   return 0;
}
