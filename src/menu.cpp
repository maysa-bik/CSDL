#include "raylib.h"

int main() {
    const int screenWidth = 1000;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "Menu du Jeu de la Vie");

    // Déclaration des rectangles de collision pour les boutons
    Rectangle launchButton = {200, 120, 200, 40};
    Rectangle optionsButton = {200, 160, 200, 40};
    Rectangle quitButton = {200, 200, 200, 40};

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        // Affichage du titre
        DrawText("Menu du Jeu de la Vie", 190, 50, 20, DARKGRAY);

        // Affichage des boutons du menu
        DrawText("1. Lancer le jeu", 200, 120, 20, DARKGRAY);
        DrawText("2. Options", 200, 160, 20, DARKGRAY);
        DrawText("6. Quitter", 200, 200, 20, DARKGRAY);

        // Vérification si le bouton "Lancer le jeu" est cliqué
        if (CheckCollisionPointRec(GetMousePosition(), launchButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            // Code à exécuter lorsque le bouton "Lancer le jeu" est cliqué
            // Par exemple, tu peux ouvrir une nouvelle fenêtre de jeu
            main(); // Ferme la fenêtre du menu
            // Ici tu mettras le code pour ouvrir une nouvelle fenêtre ou lancer une nouvelle page pour le jeu
        }

        // Vérification si le bouton "Options" est cliqué
        if (CheckCollisionPointRec(GetMousePosition(), optionsButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            // Code à exécuter lorsque le bouton "Options" est cliqué
            // Par exemple, tu peux ouvrir une nouvelle fenêtre pour les options
            CloseWindow(); // Ferme la fenêtre du menu
            // Ici tu mettras le code pour ouvrir une nouvelle fenêtre ou lancer une nouvelle page pour les options
        }

        // Vérification si le bouton "Quitter" est cliqué
        if (CheckCollisionPointRec(GetMousePosition(), quitButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            // Code à exécuter lorsque le bouton "Quitter" est cliqué
            break; // Sortie de la boucle pour fermer la fenêtre
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
