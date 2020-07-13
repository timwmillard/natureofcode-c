#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <raylib.h>
#include "../core/physics.h"

// Application Name
#define APP_NAME "Nature of Code - Random Walker"

// Frames per second
#define FPS 60.0

#define MOVE_BY 1

typedef enum {
   Up = 0,
   Right,
   Down,
   Left
} Direction;


int main()
{
   // Initialisation of Window
   const int screenWidth = 640;
   const int screenHeight = 480;

   InitWindow(screenWidth, screenHeight, APP_NAME);

   SetTargetFPS(FPS);

   srand(time(0));
   int x = screenWidth / 2;
   int y = screenHeight / 2;

   // Main Game Loop
   while (!WindowShouldClose()) {
      BeginDrawing();
      ClearBackground(RAYWHITE);
      
      DrawCircle(x, y, 3, DARKGREEN);

      Direction dir = rand() % 4;
      switch (dir)
      {
      case Up:
         y -= MOVE_BY;
         break;
      case Right:
         x += MOVE_BY;
         break;
      case Down:
         y += MOVE_BY;
         break;
      case Left:
         x -= MOVE_BY;
         break;
      }

      EndDrawing();
   }

   CloseWindow();

   return 0;
}
