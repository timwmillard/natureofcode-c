#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <raylib.h>
#include "raylib_dep.h"
#include "../core/lib.h"

// Application Name
#define APP_NAME "Nature of Code - Random 2D"

// Frames per second
#define FPS 60

Image LoadImageEx_DEP(Color *pixels, int width, int height);

int main(int argc, char *argv[])
{
   // Initialisation of Window
   const int screenWidth = 640;
   const int screenHeight = 480;

   Color colorMap[screenWidth][screenHeight];

   InitWindow(screenWidth, screenHeight, APP_NAME);

   SetTargetFPS(FPS);

   // Seed random
   srand(time(0));

   for (int x = 0; x < screenWidth; x++) {
      for (int y = 0; y < screenHeight; y++) {
         Color rColor = DARKPURPLE;
         rColor.a = rand() % 255;
         colorMap[x][y] = rColor;
      }
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
