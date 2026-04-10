#include <raylib.h>

int main() {
    
    // Window variables
    const int windowWidth = 1200;
    const int windowHeight = 600;
    const char* title = "C-Pong";

    // Window constructor
    InitWindow(windowWidth, windowHeight, title);

    SetTargetFPS(60);

    // Game Objects
    const Vector2 maceSize = { 20, 150};
    const int maceSpeed = 2.0f;
    const int marginY = 20;

    Vector2 leftMacePosition = { 15, windowHeight / 2 - 70};
    const Color leftMaceColor = BLUE;
    
    Vector2 rightMacePosition = { windowWidth - 35, windowHeight / 2 - 70};
    const Color rightMaceColor = RED;
    
    
    const int ballRadius = 15;
    const float ballSpeed = 3.0f;
    Vector2 ballPosition = { windowWidth / 2, windowHeight / 2};
    const Color ballColor = BLACK;

    // Gameloop
    while(!WindowShouldClose()) {
        // Input
        if(IsKeyDown(KEY_UP) && leftMacePosition.y > marginY) leftMacePosition.y -= maceSpeed;
        if(IsKeyDown(KEY_DOWN) && leftMacePosition.y + maceSize.y + marginY < windowHeight) leftMacePosition.y += maceSpeed;

        // Update

        // Draw
        BeginDrawing();

        ClearBackground(WHITE);

        DrawRectangleV(leftMacePosition, maceSize, leftMaceColor);
        DrawRectangleV(rightMacePosition, maceSize, rightMaceColor);
        DrawCircleV(ballPosition, ballRadius, ballColor);

        EndDrawing();
    }
}