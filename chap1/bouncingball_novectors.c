#include <stdio.h>
#include <stdlib.h>
#include <raylib.h>

// Application Name
#define APP_NAME "Nature of Code - Boucing Ball No Vectors"

// Frames per second
#define FPS 60


int main(int argc, char *argv[])
{
   // Initialisation of Window
   const int screenWidth = 640;
   const int screenHeight = 480;

   float ballRadius = 20;

   float x = screenWidth / 2;
   float y = screenHeight / 2;
   float tx = 3.5;
   float ty = 3;

   InitWindow(screenWidth, screenHeight, APP_NAME);

   SetTargetFPS(FPS);

   // Main Game Loop
   while (!WindowShouldClose()) {
      BeginDrawing();
      ClearBackground(RAYWHITE);

      x += tx;
      y += ty;

      if (x - ballRadius < 0 || x + ballRadius > screenWidth)
         tx *= -1;
      
      if (y - ballRadius < 0 || y + ballRadius > screenHeight)
         ty *= -1;
      
      DrawCircle(x, y, ballRadius, DARKBLUE);

      EndDrawing();
   }

   CloseWindow();

   return 0;
}
