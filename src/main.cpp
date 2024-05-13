#include "raylib.h"

#define WIDTH 80
#define HEIGHT 60
#define DELTA_TIME 0.1f // Temps d'attente entre les générations en secondes

int grid[HEIGHT][WIDTH];
int ngrid[HEIGHT][WIDTH];

void init() {
    for (int i = 0; i < HEIGHT; i++)
        for (int j = 0; j < WIDTH; j++)
            grid[i][j] = ngrid[i][j] = 0;

    // Initialisation d'un motif de départ
    grid[HEIGHT / 2 - 2][WIDTH / 2 - 2] = grid[HEIGHT / 2 - 2][WIDTH / 2 - 1] =
        grid[HEIGHT / 2 - 1][WIDTH / 2 - 2] = grid[HEIGHT / 2 - 1][WIDTH / 2 - 1] = 1;
}

int count_neighbours(int y, int x) {
    int count = 0;

    for (int j = -1; j <= 1; j++)
        for (int i = -1; i <= 1; i++)
            if (!(i == 0 && j == 0) && grid[(y + HEIGHT + j) % HEIGHT][(x + WIDTH + i) % WIDTH] == 1)
                count++;

    return count;
}

void next_generation() {
    for (int y = 0; y < HEIGHT; y++)
        for (int x = 0; x < WIDTH; x++) {
            int neighbours = count_neighbours(y, x);

            if (grid[y][x] == 1) {
                if (neighbours < 2 || neighbours > 3)
                    ngrid[y][x] = 0;
                else
                    ngrid[y][x] = 1;
            } else {
                if (neighbours == 3)
                    ngrid[y][x] = 1;
                else
                    ngrid[y][x] = 0;
            }
        }

    // Copie de la grille temporaire dans la grille principale
    for (int y = 0; y < HEIGHT; y++)
        for (int x = 0; x < WIDTH; x++)
            grid[y][x] = ngrid[y][x];
}

void draw_grid() {
    BeginDrawing();

    // Effacement de la fenêtre seulement si nécessaire
    ClearBackground(RAYWHITE);

    // Dessin des cellules vivantes
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (grid[y][x] == 1) {
                DrawRectangle(x * 10, y * 10, 10, 10, BLACK);
            }
        }
    }

    EndDrawing();
}

int main() {
    InitWindow(WIDTH * 10, HEIGHT * 10, "Game of Life");
    SetTargetFPS(60);

    init();

    while (!WindowShouldClose()) {
        next_generation();
        draw_grid();
        // Attente entre les générations
        WaitTime(DELTA_TIME);
    }
}    