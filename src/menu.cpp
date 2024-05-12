#include "raylib.h"

int main() {
    const int screenWidth = 1000;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "Menu du Jeu de la Vie");

    // Chargement de l'image pour le menu
    Texture2D menuImage = LoadTexture("images/5faf5f00-e3c2-11e9-8c0c-8a396f6bc08c.png");

    // Hauteur de la partie supérieure où l'image sera affichée
    const int topHeight = 300;  // Modifiez cette valeur selon vos besoins
    const int topWidth = screenWidth; // La largeur est égale à la largeur de la fenêtre

    // Région source de l'image (partie de l'image à dessiner)
    Rectangle sourceRec = { 0, 0, (float)menuImage.width, (float)topHeight };

    // Région de destination (où l'image sera rendue à l'écran)
    Rectangle destRec = { 0, 0, (float)topWidth, (float)topHeight };

    // Origine de la rotation (pas nécessaire si vous ne faites pas pivoter l'image)
    Vector2 origin = { 0, 0 };

    // Déclaration des rectangles de collision pour les boutons
    Rectangle launchButton = { screenWidth / 2 - 400, topHeight + 200, 200, 40 };
    Rectangle optionsButton = { screenWidth / 2 - 350, topHeight + 260, 200, 40 };
    Rectangle quitButton = { screenWidth / 2 - 300, topHeight + 300, 200, 40 };

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        // Affichage de l'image du menu uniquement dans la partie supérieure de la fenêtre
        DrawTexturePro(menuImage, sourceRec, destRec, origin, 0.0f, WHITE);

        // Mise à jour de la couleur du bouton en fonction de l'état de la souris
        Color launchButtonColor = RAYWHITE;
        Color optionsButtonColor = RAYWHITE;
        Color quitButtonColor = RAYWHITE;

        if (CheckCollisionPointRec(GetMousePosition(), launchButton)) {
            launchButtonColor = IsMouseButtonDown(MOUSE_LEFT_BUTTON) ? MAROON : LIGHTGRAY;
        }

        if (CheckCollisionPointRec(GetMousePosition(), optionsButton)) {
            optionsButtonColor = IsMouseButtonDown(MOUSE_LEFT_BUTTON) ? MAROON : LIGHTGRAY;
        }

        if (CheckCollisionPointRec(GetMousePosition(), quitButton)) {
            quitButtonColor = IsMouseButtonDown(MOUSE_LEFT_BUTTON) ? MAROON : LIGHTGRAY;
        }

        // Affichage des boutons du menu
        DrawRectangleRec(launchButton, launchButtonColor);
        DrawRectangleRec(optionsButton, optionsButtonColor);
        DrawRectangleRec(quitButton, quitButtonColor);

        // Texte des boutons
        DrawText("1. Lancer le jeu", launchButton.x + 0, launchButton.y + 20, 50, BLACK);
        DrawText("2. Options", optionsButton.x + 0, optionsButton.y + 25, 50, BLACK);
        DrawText("3. Quitter", quitButton.x + 0, quitButton.y + 30, 50, BLACK);

        // Vérification si un bouton est cliqué
        if (CheckCollisionPointRec(GetMousePosition(), launchButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            // Code à exécuter lorsque le bouton "Lancer le jeu" est cliqué
            // Par exemple, ouvrir une nouvelle fenêtre de jeu
            CloseWindow();
        }

        if (CheckCollisionPointRec(GetMousePosition(), optionsButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            // Code à exécuter lorsque le bouton "Options" est cliqué
            // Par exemple, ouvrir une nouvelle fenêtre pour les options
        }

        if (CheckCollisionPointRec(GetMousePosition(), quitButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            // Code à exécuter lorsque le bouton "Quitter" est cliqué
            break; // Sortie de la boucle pour fermer la fenêtre
        }

        EndDrawing();
    }

    // Libération de la mémoire de l'image du menu
    UnloadTexture(menuImage);
    CloseWindow();

    return 0;
}