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
    const Vector2 maceSize = { 10, 150};
    const float maceSpeed = 2.0f;
    const int marginY = 20;

    Vector2 leftMacePosition = { 15, windowHeight / 2 - 70};
    const Color leftMaceColor = BLUE;
    
    Vector2 rightMacePosition = { windowWidth - 35, windowHeight / 2 - 70};
    const Color rightMaceColor = RED;
    
    
    const int ballRadius = 15;
    const float ballSpeed = 8.0f;
    Vector2 ballPosition = { windowWidth / 2, windowHeight / 2};
    const Color ballColor = WHITE;
    int ballDirectionX = 1;
    int ballDirectionY = 1;

    // Gameloop
    while(!WindowShouldClose()) {
        // Input
        if(IsKeyDown(KEY_W) && leftMacePosition.y > marginY) leftMacePosition.y -= maceSpeed;
        if(IsKeyDown(KEY_S) && leftMacePosition.y + maceSize.y + marginY < windowHeight) leftMacePosition.y += maceSpeed;

        if(IsKeyDown(KEY_UP) && rightMacePosition.y > marginY) rightMacePosition.y -= maceSpeed;
        if(IsKeyDown(KEY_DOWN) && rightMacePosition.y + maceSize.y + marginY < windowHeight) rightMacePosition.y += maceSpeed;

        // Update
        if(ballPosition.x >= rightMacePosition.x || ballPosition.x <= leftMacePosition.x) {
            ballPosition.x = windowWidth / 2;
            ballPosition.y = windowHeight / 2;
        }


        ballPosition.x += (ballSpeed * ballDirectionX); 
        ballPosition.y += (ballSpeed * ballDirectionY);

        if(ballPosition.x - ballRadius < 0 || ballPosition.x + ballRadius > windowWidth) {
            ballDirectionX *= -1;
        }

        if(ballPosition.y - ballRadius < 0 || ballPosition.y + ballRadius > windowHeight) {
            ballDirectionY *= -1;
        }

        // Mace collision
        if(
            ballPosition.x + ballRadius >= rightMacePosition.x &&
            ballPosition.y + ballRadius <= rightMacePosition.y + maceSize.y &&
            ballPosition.y - ballRadius >= rightMacePosition.y
        ) {
            ballDirectionX *= -1;
        }

        if(
            ballPosition.x - ballRadius <= leftMacePosition.x + maceSize.x &&
            ballPosition.y + ballRadius <= leftMacePosition.y + maceSize.y &&
            ballPosition.y - ballRadius >= leftMacePosition.y
        ) {
            ballDirectionX *= -1;
        }


        // Draw
        BeginDrawing();

        ClearBackground(BLACK);

        DrawRectangleV(leftMacePosition, maceSize, leftMaceColor);
        DrawRectangleV(rightMacePosition, maceSize, rightMaceColor);
        DrawCircleV(ballPosition, ballRadius, ballColor);

        EndDrawing();
    }
}