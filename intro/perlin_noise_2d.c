#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <raylib.h>
#include "raylib_dep.h"
#include "../core/noise.h"
#include "../core/lib.h"

// Application Name
#define APP_NAME "Nature of Code - Perlin Noise 2D"

// Frames per second
#define FPS 60


int main(int argc, char *argv[])
{
   // Initialisation of Window
   const int screenWidth = 640;
   const int screenHeight = 480;

   Color colorMap[screenWidth][screenHeight];

   InitWindow(screenWidth, screenHeight, APP_NAME);

   SetTargetFPS(FPS);

   // Seed noise
   noise_seed(time(0));

   float xoff, yoff = 0;
   for (int x = 0; x < screenWidth; x++) {
      yoff = 0;
      for (int y = 0; y < screenHeight; y++) {
         Color rColor = DARKPURPLE;
         float a = noise2(xoff, yoff);
         a = map(a, -1, 1, 0, 255);
         rColor.a = (int) a;
         colorMap[x][y] = rColor;
         yoff += 0.01;
      }
      xoff += 0.01;
   }

   Image image = LoadImageEx_DEP((Color *)&colorMap, screenWidth, screenHeight);
   Texture2D texture = LoadTextureFromImage(image);
   UnloadImage(image);

   // Main Game Loop
   while (!WindowShouldClose()) {
      BeginDrawing();
      ClearBackground(RAYWHITE);

      DrawTexture(texture, 0, 0, WHITE);

      EndDrawing();
   }

   CloseWindow();

   return 0;
}
