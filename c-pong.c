#include <raylib.h>

int main() {
    
    // Window variables
    const int windowWidth = 900;
    const int windowHeight = 600;
    const char* title = "C-Pong";

    // Window constructor
    InitWindow(windowWidth, windowHeight, title);

    // Game Objects
    const Vector2 maceSize = { 20, 150};

    const Vector2 leftMacePosition = { 15, windowHeight / 2 - 70};
    const Color leftMaceColor = BLUE;

    const Vector2 rightMacePosition = { windowWidth - 35, windowHeight / 2 - 70};
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