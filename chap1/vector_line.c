#include <stdio.h>
#include <stdlib.h>
#include <raylib.h>
#include <raymath.h>

// Application Name
#define APP_NAME "Nature of Code - Vector Line"

// Frames per second
#define FPS 60


int main(int argc, char *argv[])
{
   // Initialisation of Window
   const int screenWidth = 640;
   const int screenHeight = 480;
   
   Vector2 center = {screenWidth / 2, screenHeight / 2};

   InitWindow(screenWidth, screenHeight, APP_NAME);

   SetTargetFPS(FPS);

   // Main Game Loop
   while (!WindowShouldClose()) {
      BeginDrawing();
      ClearBackground(RAYWHITE);

      int mouseX = GetMouseX();
      int mouseY = GetMouseY();

      Vector2 mouse = {mouseX, mouseY};
      mouse = Vector2Subtract(mouse, center);
      mouse = Vector2Scale(mouse, 0.5);
      mouse = Vector2Add(center, mouse);
      
      DrawLineV(center, mouse, DARKBLUE);

      EndDrawing();
   }

   CloseWindow();

   return 0;
}
