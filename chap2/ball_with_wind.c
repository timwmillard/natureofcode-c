#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <raylib.h>
#include "../core/body.h"
#include "../core/lib.h"

// Application Name
#define APP_NAME "Nature of Code - Ball with Wind"

// Frames per second
#define FPS 60

void checkEdges(Body *ball, float radius, float width, float heigh)
{
   if (ball->pos.x - radius < 0) {
      ball->vel.x *= -1;
      ball->pos.x = radius;
   } else if (ball->pos.x + radius > width) {
      ball->vel.x *= -1;
      ball->pos.x = width - radius;
   }

   if (ball->pos.y - radius < 0) {
      ball->vel.y *= -1;
      ball->pos.y = radius;
   } else if (ball->pos.y + radius > heigh) {
      ball->vel.y *= -1;
      ball->pos.y = heigh - radius;
   }
}

int main(int argc, char *argv[])
{
   srand(time(0));

   // Initialisation of Window
   const int screenWidth = 640;
   const int screenHeight = 480;
   Vect center = vect(screenWidth / 2, screenHeight / 2);

   float ballRadius = 20;

   Body *ball = body_create_xy(screenWidth / 2, screenWidth / 3, 1);

   InitWindow(screenWidth, screenHeight, APP_NAME);

   SetTargetFPS(FPS);

   // Main Game Loop
   while (!WindowShouldClose()) {
      BeginDrawing();
      ClearBackground(RAYWHITE);

      if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
         int mouseX = GetMouseX();
         int mouseY = GetMouseY();

         Vect mouse = vect(mouseX, mouseY);

         Vect wind = vect_sub(ball->pos, mouse);
         float windMag = vect_mag(wind) * 0.1;
         wind = vect_set_mag(wind, 1 / windMag);
         body_apply_force(ball, wind);
      }

      Vect gravity = vect(0.0, 0.3);
      body_apply_gravity(ball, gravity);

      body_update(ball);
      
      checkEdges(ball, ballRadius * ball->mass, screenWidth, screenHeight);
      DrawCircle(ball->pos.x, ball->pos.y, ballRadius * ball->mass, DARKBLUE);

      EndDrawing();
   }

   CloseWindow();

   return 0;
}
