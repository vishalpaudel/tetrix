#include "raylib.h"
#include "raymath.h"

// draws and queries colors from scratch
// for more flexibility and low level control of the 
// block colors/
// prolly will eat on the cpu
// maybe cache the calculations?
// Vector2 pos = {10, 10}, size = {50, 50};
// example usage:   drawSingleSquare((Vector2){20, 20}, YELLOW)
void drawSingleSquare(const Vector2 pos, const Color col) {
    const double delta = 7;
    const Vector2 size = {40, 40};

    Vector2 innerPos = {pos.x + delta, pos.y + delta};
    Vector2 innerSize = {size.x - 2 * delta, size.y - 2 * delta};

    Vector2 center;
    center = Vector2Add(pos, Vector2Scale(size, 0.5));

    Vector2 leftUpper  = Vector2Add(center, Vector2Scale((Vector2){-1 * size.x, -1 * size.y}, 0.5));
    Vector2 leftLower  = Vector2Add(center, Vector2Scale((Vector2){-1 * size.x, +1 * size.y}, 0.5));
    Vector2 rightUpper = Vector2Add(center, Vector2Scale((Vector2){+1 * size.x, -1 * size.y}, 0.5));
    Vector2 rightLower = Vector2Add(center, Vector2Scale((Vector2){+1 * size.x, +1 * size.y}, 0.5));

    //DrawCircleV(center, 4, VIOLET);
    //DrawCircleV(leftUpper, 4, RED);
    //DrawCircleV(leftLower, 4, BLUE);
    //DrawCircleV(rightUpper, 4, GREEN);
    //DrawCircleV(rightLower, 4, YELLOW);
    //DrawCircleV(center, 4, ORANGE);

    //DrawRectangleV(pos, size, col);

    float r1 = 0.5, r2 = 0.45, r3 = 0.75;

    Vector3 whiteVec = {WHITE.r, WHITE.g, WHITE.b};
    Vector3 blackVec = {BLACK.r, BLACK.g, BLACK.b};
    Vector3 colVec   = {col.r  , col.g  , col.b  };

    Vector3 lightVec   = Vector3Add(Vector3Scale(whiteVec, r1), Vector3Scale(colVec, (1-r1)));
    Vector3 darkerVec  = Vector3Add(Vector3Scale(blackVec, r2), Vector3Scale(colVec, (1-r2)));
    Vector3 darkestVec = Vector3Add(Vector3Scale(blackVec, r3), Vector3Scale(colVec, (1-r3)));

    Color lightCol   = {lightVec.x, lightVec.y, lightVec.z, col.a};
    Color darkerCol  = {darkerVec.x , darkerVec.y , darkerVec.z , col.a};
    Color darkestCol = {darkestVec.x, darkestVec.y, darkestVec.z, col.a};

    DrawTriangle(center, leftUpper , leftLower , darkerCol  );
    DrawTriangle(center, leftLower , rightLower, darkestCol );
    DrawTriangle(center, rightLower, rightUpper, darkerCol  );
    DrawTriangle(center, rightUpper, leftUpper , lightCol   );

    DrawRectangleV(innerPos, innerSize, col);

    return;
}
