#include "raylib.h"

#define GRID_COUNT 4    // Nombre de grilles de Conway à afficher
#define WIDTH 80        // Largeur de chaque grille
#define HEIGHT 60       // Hauteur de chaque grille
#define DELTA_TIME 0.1f // Temps d'attente entre les générations en secondes

int grids[GRID_COUNT][HEIGHT][WIDTH];
int ngrids[GRID_COUNT][HEIGHT][WIDTH];

// Initialise toutes les grilles
void init_grids() {
    for (int k = 0; k < GRID_COUNT; k++) {
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                grids[k][i][j] = ngrids[k][i][j] = GetRandomValue(0, 1);
            }
        }
    }
}

// Calcule le nombre de voisins pour une cellule donnée dans une grille donnée
int count_neighbours(int k, int y, int x) {
    int count = 0;

    for (int j = -1; j <= 1; j++) {
        for (int i = -1; i <= 1; i++) {
            if (!(i == 0 && j == 0)) {
                count += grids[k][(y + HEIGHT + j) % HEIGHT][(x + WIDTH + i) % WIDTH];
            }
        }
    }

    return count;
}

// Calcule la prochaine génération pour une grille donnée
void next_generation(int k) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int neighbours = count_neighbours(k, y, x);

            if (grids[k][y][x] == 1) {
                if (neighbours < 2 || neighbours > 3) {
                    ngrids[k][y][x] = 0;
                } else {
                    ngrids[k][y][x] = 1;
                }
            } else {
                if (neighbours == 3) {
                    ngrids[k][y][x] = 1;
                } else {
                    ngrids[k][y][x] = 0;
                }
            }
        }
    }

    // Copie la nouvelle grille dans la grille principale
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            grids[k][y][x] = ngrids[k][y][x];
        }
    }
}

// Dessine une grille donnée
void draw_grid(int k) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (grids[k][y][x] == 1) {
                DrawRectangle(x * 10, k * HEIGHT * 10 + y * 10, 10, 10, WHITE);
            }
        }
    }
}

int main() {
    InitWindow(WIDTH * 10, GRID_COUNT * HEIGHT * 10, "Conway's Game of Life");
    SetTargetFPS(60);

    init_grids();

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        for (int k = 0; k < GRID_COUNT; k++) {
            next_generation(k);
            draw_grid(k);
        }

        EndDrawing();

        // Attente entre les générations
        while (GetTime() < DELTA_TIME) { }
    }

    CloseWindow();
    return 0;
}
