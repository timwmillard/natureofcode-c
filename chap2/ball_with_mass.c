#include <stdio.h>
#include <stdlib.h>
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
   // Initialisation of Window
   const int screenWidth = 640;
   const int screenHeight = 480;
   Vect center = vect(screenWidth / 2, screenHeight / 2);

   float ballRadius = 20;

   Body *ball = body_create(center, 1.0f);
   Body *ball2 = body_create_xy(screenWidth / 4, screenHeight / 2, 3.0f);
   Body *ball3 = body_create_xy(screenWidth * 3 / 4, screenHeight / 2, 0.5f);

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
   
      body_apply_force(ball, gravity);
      body_apply_force(ball2, gravity);
      body_apply_force(ball3, gravity);

      body_update(ball);
      body_update(ball2);
      body_update(ball3);

      // Bounce the ball of the edges
      checkEdges(ball, ballRadius * ball->mass, screenWidth, screenHeight);
      checkEdges(ball2, ballRadius * ball2->mass, screenWidth, screenHeight);
      checkEdges(ball3, ballRadius * ball3->mass, screenWidth, screenHeight);

      // Draw the balls
      DrawCircle(ball->pos.x, ball->pos.y, ballRadius * ball->mass, DARKBLUE);
      DrawCircle(ball2->pos.x, ball2->pos.y, ballRadius * ball2->mass, DARKBLUE);
      DrawCircle(ball3->pos.x, ball3->pos.y, ballRadius * ball3->mass, DARKBLUE);

      EndDrawing();
   }

   CloseWindow();

   return 0;
}
