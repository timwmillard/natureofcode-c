#include <stdio.h>
#include <stdlib.h>
#include <raylib.h>
#include "../core/body.h"

// Application Name
#define APP_NAME "Nature of Code - Ball with Force"

// Frames per second
#define FPS 60


int main(int argc, char *argv[])
{
   // Initialisation of Window
   const int screenWidth = 640;
   const int screenHeight = 480;
   Vect center = vect(screenWidth / 2, screenHeight / 2);

   float ballRadius = 20;

   Body *ball = body_create(center, 1.0f);

   InitWindow(screenWidth, screenHeight, APP_NAME);

   SetTargetFPS(FPS);

   // Main Game Loop
   while (!WindowShouldClose()) {
      BeginDrawing();
      ClearBackground(RAYWHITE);

      int mouseX = GetMouseX();
      int mouseY = GetMouseY();

      Vect mouse = vect(mouseX, mouseY);
      
      Vect force = vect(0.0, 0.3);

   
      body_apply_force(ball, force);
      body_update(ball);

      // Bounce the ball of the edges
      if (ball->pos.x - ballRadius < 0) {
         ball->vel.x *= -1;
         ball->pos.x = ballRadius;
      } else if (ball->pos.x + ballRadius > screenWidth) {
         ball->vel.x *= -1;
         ball->pos.x = screenWidth - ballRadius;
      }

      if (ball->pos.y - ballRadius < 0) {
         ball->vel.y *= -1;
         ball->pos.y = ballRadius;
      } else if (ball->pos.y + ballRadius > screenHeight) {
         ball->vel.y *= -1;
         ball->pos.y = screenHeight - ballRadius;
      }
      
      DrawCircle(ball->pos.x, ball->pos.y, ballRadius, DARKBLUE);

      EndDrawing();
   }

   CloseWindow();

   return 0;
}
