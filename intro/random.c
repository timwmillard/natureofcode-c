#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <raylib.h>

// Application Name
#define APP_NAME "Nature of Code - Random"

// Frames per second
#define FPS 60

int main(int argc, char *argv[])
{
   // Initialisation of Window
   const int screenWidth = 640;
   const int screenHeight = 480;

   // Start x, y in center
   float x = screenWidth / 2;
   float y = screenHeight / 2;

   InitWindow(screenWidth, screenHeight, APP_NAME);

   SetTargetFPS(FPS);

   srand(time(0));

   // Main Game Loop
   while (!WindowShouldClose()) {
      BeginDrawing();
      ClearBackground(RAYWHITE);

      // Randomly move in the x direction
      x = rand() % screenWidth;
      DrawCircle(x, y, 20, DARKBLUE);

      EndDrawing();
   }

   CloseWindow();

   return 0;
}
