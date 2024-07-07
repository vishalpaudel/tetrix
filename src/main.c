#include "raylib.h"

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib hello world!");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("Hello World!", 190, 200, 20, LIGHTGRAY);
            drawSingleSquare((Vector2){20, 20}, YELLOW);
            drawSingleSquare((Vector2){60, 20}, GREEN);
            drawSingleSquare((Vector2){100, 20}, RED);
            drawSingleSquare((Vector2){140, 20}, ORANGE);
            drawSingleSquare((Vector2){220, 120}, BLUE);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
