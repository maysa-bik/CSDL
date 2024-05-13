#include <raylib.h>
#include "grid.hpp"

// Définition des constantes pour les boutons
const int BUTTON_WIDTH = 150;
const int BUTTON_HEIGHT = 40;
const int BUTTON_MARGIN_X = 10;
const int BUTTON_MARGIN_Y = 10;
const Color BUTTON_COLOR = DARKGRAY; // Couleur des boutons

int main() {
    Color GREY = BLACK; // Fond noir
    const int WINDOW_WIDTH = 750;
    const int WINDOW_HEIGHT = 750;
    const int CELL_SIZE = 25;
    int FPS = 12;

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Jeu de la vie");
    SetTargetFPS(FPS);
    Grid grid(WINDOW_WIDTH, WINDOW_HEIGHT, CELL_SIZE);
    fillGridRandom(grid); // Initialisez la grille avec des valeurs aléatoires

    Rectangle nextButton = {BUTTON_MARGIN_X, WINDOW_HEIGHT - 2 * (BUTTON_HEIGHT + BUTTON_MARGIN_Y), BUTTON_WIDTH, BUTTON_HEIGHT};
    Rectangle clearButton = {2 * (BUTTON_WIDTH + BUTTON_MARGIN_X) + BUTTON_MARGIN_X, WINDOW_HEIGHT - 2 * (BUTTON_HEIGHT + BUTTON_MARGIN_Y), BUTTON_WIDTH, BUTTON_HEIGHT};
    Rectangle startButton = {BUTTON_MARGIN_X, WINDOW_HEIGHT - (BUTTON_HEIGHT + BUTTON_MARGIN_Y), BUTTON_WIDTH, BUTTON_HEIGHT};
    Rectangle randomButton = {2 * (BUTTON_WIDTH + BUTTON_MARGIN_X) + BUTTON_MARGIN_X, WINDOW_HEIGHT - (BUTTON_HEIGHT + BUTTON_MARGIN_Y), BUTTON_WIDTH, BUTTON_HEIGHT};
    Rectangle stopButton = {4 * (BUTTON_WIDTH + BUTTON_MARGIN_X) + BUTTON_MARGIN_X, WINDOW_HEIGHT - (BUTTON_HEIGHT + BUTTON_MARGIN_Y), BUTTON_WIDTH, BUTTON_HEIGHT};
    Rectangle quitButton = {5 * (BUTTON_WIDTH + BUTTON_MARGIN_X) + BUTTON_MARGIN_X, WINDOW_HEIGHT - (BUTTON_HEIGHT + BUTTON_MARGIN_Y), BUTTON_WIDTH, BUTTON_HEIGHT};

    while (!WindowShouldClose()) {
        // Gestion des événements
        if (CheckCollisionPointRec(GetMousePosition(), nextButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            // Action pour le bouton "Génération suivante"
        }
        if (CheckCollisionPointRec(GetMousePosition(), clearButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            // Action pour le bouton "Grille vierge"
        }
        if (CheckCollisionPointRec(GetMousePosition(), startButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            // Action pour le bouton "Démarrer l'automate"
        }
        if (CheckCollisionPointRec(GetMousePosition(), randomButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            // Action pour le bouton "Tirage aléatoire"
        }
        if (CheckCollisionPointRec(GetMousePosition(), stopButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            // Action pour le bouton "Arrêter l'automate"
        }
        if (CheckCollisionPointRec(GetMousePosition(), quitButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            // Action pour le bouton "Quitter"
            break; // Quitter la boucle principale
        }

        // Mise à jour de l'état

        // Dessin
        BeginDrawing();
        ClearBackground(GREY);
        drawGrid(grid); // Dessinez la grille

      
        // Dessinez les boutons
        DrawRectangleRec(nextButton, BUTTON_COLOR); // Génération suivante
        DrawRectangleRec(clearButton, BUTTON_COLOR); // Grille vierge
        DrawRectangleRec(startButton, BUTTON_COLOR); // Démarrer l'automate
        DrawRectangleRec(randomButton, BUTTON_COLOR); // Tirage aléatoire
        DrawRectangleRec(stopButton, BUTTON_COLOR); // Arrêter l'automate
        DrawRectangleRec(quitButton, BUTTON_COLOR); // Quitter

        DrawText("Génération suivante", nextButton.x + 10, nextButton.y + 10, 20, WHITE);
        DrawText("Grille vierge", clearButton.x + 10, clearButton.y + 10, 20, WHITE);
        DrawText("Démarrer l'automate", startButton.x + 10, startButton.y + 10, 20, WHITE);
        DrawText("Tirage aléatoire", randomButton.x + 10, randomButton.y + 10, 20, WHITE);
        DrawText("Arrêter l'automate", stopButton.x + 10, stopButton.y + 10, 20, WHITE);
        DrawText("Quitter", quitButton.x + 10, quitButton.y + 10, 20, WHITE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
