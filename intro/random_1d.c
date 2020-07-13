#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <raylib.h>

// Application Name
#define APP_NAME "Nature of Code - Random 1D"

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

   // Seed random
   srand(time(0));


   // Create the line vector
   Vector2 lines[screenWidth];
   for (int x = 0; x < screenWidth; x++) {
      
      y = rand() % screenHeight;
     
      Vector2 v = {x, y};
      lines[x] = v;
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
