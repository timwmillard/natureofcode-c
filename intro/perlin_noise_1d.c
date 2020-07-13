#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <raylib.h>
#include "../core/noise.h"

// Application Name
#define APP_NAME "Nature of Code - Perlin Noise 1D"

// Frames per second
#define FPS 60


int main(int argc, char *argv[])
{
   // Initialisation of Window
   const int screenWidth = 640;
   const int screenHeight = 480;

   float x = screenWidth / 2;
   float y = screenHeight / 2;

   InitWindow(screenWidth, screenHeight, APP_NAME);

   SetTargetFPS(FPS);

   // Seed noise
   noise_seed(time(0));

   // Create the line vector
   Vector2 lines[screenWidth];
   float xoff = 0;
   for (int x = 0; x < screenWidth; x++) {

      y = noise(xoff);
      y = (y + 1) / 2;
      y = y * screenHeight;

      Vector2 v = {x, y};
      lines[x] = v;

      xoff += 0.11;
   }

   // Main Game Loop
   while (!WindowShouldClose()) {
      BeginDrawing();
      ClearBackground(RAYWHITE);
      DrawLineStrip(lines, screenWidth, DARKBLUE);
      EndDrawing();
   }

   CloseWindow();

   return 0;
}
