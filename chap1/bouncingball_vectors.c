#include <stdio.h>
#include <stdlib.h>
#include <raylib.h>
#include <raymath.h>

// Application Name
#define APP_NAME "Nature of Code - Boucing Ball with Vectors"

// Frames per second
#define FPS 60


int main(int argc, char *argv[])
{
   // Initialisation of Window
   const int screenWidth = 640;
   const int screenHeight = 480;

   float ballRadius = 20;

   Vector2 pos = {screenWidth / 2, screenHeight / 2};
   Vector2 vel = {3.5, 3};

   InitWindow(screenWidth, screenHeight, APP_NAME);

   SetTargetFPS(FPS);

   // Main Game Loop
   while (!WindowShouldClose()) {
      BeginDrawing();
      ClearBackground(RAYWHITE);

      pos = Vector2Add(pos, vel);

      if (pos.x - ballRadius < 0 || pos.x + ballRadius > screenWidth)
         vel.x *= -1;
      
      if (pos.y - ballRadius < 0 || pos.y + ballRadius > screenHeight)
         vel.y *= -1;
      
      DrawCircle(pos.x, pos.y, ballRadius, DARKBLUE);

      EndDrawing();
   }

   CloseWindow();

   return 0;
}
