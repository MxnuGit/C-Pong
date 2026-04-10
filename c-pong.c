#include <raylib.h>

int main() {
    
    // Window variables
    const int windowWidth = 900;
    const int windowHeight = 600;
    const char* title = "C-Pong";

    // Window constructor
    InitWindow(windowWidth, windowHeight, title);

    SetTargetFPS(60);

    // Game Objects
    const Vector2 maceSize = { 20, 150};

    Vector2 leftMacePosition = { 15, windowHeight / 2 - 70};
    const Color leftMaceColor = BLUE;

    Vector2 rightMacePosition = { windowWidth - 35, windowHeight / 2 - 70};
    const Color rightMaceColor = RED;

    // Gameloop
    while(!WindowShouldClose()) {
        // Input


        // Update
        

        // Draw
        BeginDrawing();

        ClearBackground(WHITE);

        DrawRectangleV(leftMacePosition, maceSize, leftMaceColor);
        DrawRectangleV(rightMacePosition, maceSize, rightMaceColor);

        EndDrawing();
    }
}