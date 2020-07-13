#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <raylib.h>
#include "../core/noise.h"

// Application Name
#define APP_NAME "Nature of Code - Perlin Noise"

// Frames per second
#define FPS 60

int main(int argc, char *argv[])
{
   // Initialisation of Window
   const int screenWidth = 640;
   const int screenHeight = 480;

   float x = screenWidth / 2;
   float y = screenHeight / 2;
   float t = 0;

   InitWindow(screenWidth, screenHeight, APP_NAME);

   SetTargetFPS(FPS);

   noise_seed(time(0));

   // Main Game Loop
   while (!WindowShouldClose()) {
      BeginDrawing();
      ClearBackground(RAYWHITE);

      x = noise(t);
      x = (x + 1) / 2;
      x = x * screenWidth;
      DrawCircle(x, y, 20, DARKBLUE);
      t += 0.02;
   
      EndDrawing();
   }

   CloseWindow();

   return 0;
}
