#include "raylib.h"
#include "main.cpp" // Inclure le contenu de main.cpp pour accéder à la fonction principale

int main() { // Changer le nom de la fonction main en menuMain
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

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(BLACK);

        // Affichage de l'image du menu uniquement dans la partie supérieure de la fenêtre
        DrawTexturePro(menuImage, sourceRec, destRec, (Vector2){ 0, 0 }, 0.0f, WHITE);

        // Affichage des boutons du menu
        Rectangle launchButton = { screenWidth / 2 - 100, topHeight + 200, 200, 40 };
        Rectangle optionsButton = { screenWidth / 2 - 100, topHeight + 240, 200, 40 };
        Rectangle quitButton = { screenWidth / 2 - 100, topHeight + 280, 200, 40 };

        // Dessin des boutons
        DrawRectangleRec(launchButton, BLACK);
        DrawRectangleRec(optionsButton, BLACK);
        DrawRectangleRec(quitButton, BLACK);

        // Texte des boutons
        DrawText("1. Lancer le jeu", launchButton.x + 0, launchButton.y + 10, 36, PINK);
        DrawText("2. Options/Consignes", optionsButton.x + 0, optionsButton.y + 10, 36, PINK);
        DrawText("3. Quitter", quitButton.x + 0, quitButton.y + 10, 36, PINK);

        // Gestion des clics sur les boutons
        if (CheckCollisionPointRec(GetMousePosition(), launchButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            // Code à exécuter lorsque le bouton "Lancer le jeu" est cliqué
            // Par exemple, tu peux ouvrir une nouvelle fenêtre de jeu
            main(); // Appel à la fonction main du fichier main.cpp
            // Ici tu mettras le code pour ouvrir une nouvelle fenêtre ou lancer une nouvelle page pour le jeu
        }
        else if (CheckCollisionPointRec(GetMousePosition(), optionsButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            // Code à exécuter lorsque le bouton "Options" est cliqué
            // Ouvrir le lien YouTube
            OpenURL("https://youtu.be/jvSp6VHt_Pc?feature=shared");
        }
        else if (CheckCollisionPointRec(GetMousePosition(), quitButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
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




