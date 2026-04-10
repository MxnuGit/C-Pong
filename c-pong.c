#include <raylib.h>

int main() {
    
    // Window variables
    const int width = 900;
    const int height = 600;
    const char* title = "C-Pong";

    // Window constructor
    InitWindow(width, height, title);

    // Gameloop
    while(!WindowShouldClose()) {
        // Input


        // Update


        // Draw
        BeginDrawing();

        ClearBackground(WHITE);

        EndDrawing();
    }
}