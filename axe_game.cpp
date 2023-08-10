#include <raylib.h>

int main() {
    // Window dimensions
    int width = 800;
    int height = 450;    
    InitWindow(width, height, "Axe game");
    // Circle position coordinates and size
    int circle_x = 200;
    int circle_y = 200;
    int circle_radius = 20;
    // Axe position coordinates and size
    int axe_x = 300;
    int axe_y = 0;
    int axe_width = 50;
    int axe_height = 50;
    int direction = 10;

    SetTargetFPS(60);
    // While loop to prevent window from closing unless X or ESC are pressed.
    while (!WindowShouldClose()){
        BeginDrawing(); // Initialize our canvas
        ClearBackground(WHITE); // Clearing background to prevent flickering

        // Game logic begins
        DrawCircle(circle_x, circle_y, circle_radius, RED);
        DrawRectangle(axe_x, axe_y, axe_width, axe_height, BLUE);
        // Falling axe
        axe_y += direction;
        if ((axe_y > height-20) || (axe_y <= -30)){
            direction = -direction;
        }

        // Moving the dot        
        if (IsKeyDown(KEY_D) && ((circle_x + circle_radius) < width)){
            circle_x += 10;
        } else if (IsKeyDown(KEY_A) && (circle_x > 0)){
            circle_x -= 10;   
        } else if (IsKeyDown(KEY_W) && (circle_y > 0)){
            circle_y -= 10;
        } else if (IsKeyDown(KEY_S) && (circle_y < height)){
            circle_y += 10;
        }
    

        EndDrawing();
    }
}