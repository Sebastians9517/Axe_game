#include <raylib.h>

int main() {
    // Window dimensions
    int window_width = 800;
    int window_height = 450;    
    InitWindow(window_width, window_height, "Axe game");
    // Circle position coordinates and size
    int circle_x = 200;
    int circle_y = 200;
    int circle_radius = 25;
    // Circle edges
    int left_circle_edge = (circle_x - circle_radius);
    int right_circle_edge = (circle_x + circle_radius);
    int top_circle_edge = (circle_y - circle_radius);
    int bottom_circle_edge = (circle_y + circle_radius);
    // Axe position coordinates and size
    int axe_x = 300;
    int axe_y = 0;
    int axe_length = 50;
    // Axe direction of movement
    int direction = 10;
    // Axe edges
    int left_axe_edge = (axe_x);
    int right_axe_edge = (axe_x + axe_length);
    int top_axe_edge = (axe_y);
    int bottom_axe_edge = (axe_y + axe_length);
    // Collision detection
    bool collision_with_axe = ((bottom_axe_edge >= top_circle_edge) &&
                               (top_axe_edge <= bottom_circle_edge) &&
                               (right_axe_edge >= left_circle_edge) &&
                               (left_axe_edge <= right_circle_edge));

    SetTargetFPS(60);
    // While loop to prevent window from closing unless X or ESC are pressed.
    while (!WindowShouldClose()){
        BeginDrawing(); // Initialize our canvas
        ClearBackground(WHITE); // Clearing background to prevent flickering
        if (collision_with_axe) {
            DrawText("GAME OVER", (window_width/2), (window_height/2), 35, PURPLE);
        } else {
            // Game logic begins
            DrawCircle(circle_x, circle_y, circle_radius, RED);
            DrawRectangle(axe_x, axe_y, axe_length, axe_length, BLUE);
            // Falling axe
            axe_y += direction;
            if ((axe_y > window_height) || (axe_y < 0)){
                direction = -direction;
            }
            // Moving the dot        
            if (IsKeyDown(KEY_D) && ((circle_x) < window_width)){
                circle_x += 10;
            } else if (IsKeyDown(KEY_A) && ((circle_x) > 0)){
                circle_x -= 10;   
            } else if (IsKeyDown(KEY_W) && ((circle_y) > 0)){
                circle_y -= 10;
            } else if (IsKeyDown(KEY_S) && ((circle_y) < window_height)){
                circle_y += 10;
            }
        }
            // Game logic ends
        EndDrawing();
    }
}