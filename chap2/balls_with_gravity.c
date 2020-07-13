#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <raylib.h>
#include "../core/body.h"

// Application Name
#define APP_NAME "Nature of Code - Ball with Mass"

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

   const int noBalls = 8;
   Body *balls[noBalls];
   printf("RAND_MAX = %d\n", RAND_MAX);
   for (int i = 0; i < noBalls; i++) {
      float x = (i + 1) * screenWidth / (noBalls + 1);
      float y = screenHeight / 3;
      float mass = 2.7 * (float) rand() / RAND_MAX + 0.3;
      balls[i] = body_create_xy(x, y, mass);
   }

   InitWindow(screenWidth, screenHeight, APP_NAME);

   SetTargetFPS(FPS);

   // Main Game Loop
   while (!WindowShouldClose()) {
      BeginDrawing();
      ClearBackground(RAYWHITE);

      int mouseX = GetMouseX();
      int mouseY = GetMouseY();

      Vect mouse = vect(mouseX, mouseY);
      
      Vect gravity = vect(0.0, 0.3);
      Vect wind = vect(0.2, 0);

      for (int i = 0; i < noBalls; i++) {
         Body *ball = balls[i];
         body_apply_gravity(ball, gravity);
         body_apply_force(ball, wind);
         body_update(ball);
         checkEdges(ball, ballRadius * ball->mass, screenWidth, screenHeight);
         Color blue = DARKBLUE;
         blue.a = 150;
         DrawCircle(ball->pos.x, ball->pos.y, ballRadius * ball->mass, blue);
      }

      EndDrawing();
   }

   CloseWindow();

   return 0;
}
