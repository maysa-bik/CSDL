#pragma once
#include <vector>
#include <cstdlib> // Pour la fonction rand()
#include <ctime>   // Pour initialiser le générateur de nombres aléatoires

struct Grid {
    std::vector<std::vector<int>> cells;
    int rows;
    int columns;
    int cellSize;

    Grid(int width, int height, int cellSize)
    : rows(height / cellSize), columns(width / cellSize), cellSize(cellSize) {
        cells.resize(rows, std::vector<int>(columns, 0));
    }
};

void initializeGrid(Grid& grid, int width, int height, int cellSize) {
    grid.rows = height / cellSize;
    grid.columns = width / cellSize;
    grid.cellSize = cellSize;
    grid.cells.resize(grid.rows, std::vector<int>(grid.columns, 0));
}

void setCellValue(Grid& grid, int row, int column, int value) {
    if (row >= 0 && row < grid.rows && column >= 0 && column < grid.columns) {
        grid.cells[row][column] = value;
    }
}

int getCellValue(const Grid& grid, int row, int column) {
    if (row >= 0 && row < grid.rows && column >= 0 && column < grid.columns) {
        return grid.cells[row][column];
    }
    return 0; // ou une valeur par défaut appropriée
}

bool isWithinBounds(const Grid& grid, int row, int column) {
    return (row >= 0 && row < grid.rows && column >= 0 && column < grid.columns);
}

void fillGridRandom(Grid& grid) {
    srand(static_cast<unsigned int>(time(nullptr))); // Initialisation du générateur de nombres aléatoires
    for (int row = 0; row < grid.rows; ++row) {
        for (int col = 0; col < grid.columns; ++col) {
            grid.cells[row][col] = rand() % 2; // Remplit chaque cellule avec 0 ou 1
        }
    }
}

void clearGrid(Grid& grid) {
    for (int row = 0; row < grid.rows; ++row) {
        for (int col = 0; col < grid.columns; ++col) {
            grid.cells[row][col] = 0;
        }
    }
}

void toggleCell(Grid& grid, int row, int column) {
    if (isWithinBounds(grid, row, column)) {
        grid.cells[row][column] = (grid.cells[row][column] == 0) ? 1 : 0; // Inverse la valeur de la cellule
    }
}

#include <raylib.h>

void drawGrid(const Grid& grid)
{
    for(int row = 0; row < grid.rows; row ++)
    {
        for(int column = 0; column < grid.columns; column++)
        {
            Color color = grid.cells[row][column] ? Color{0,255,0,255} : Color{55,55,55,255};
            DrawRectangle(column * grid.cellSize, row * grid.cellSize, grid.cellSize - 1, grid.cellSize - 1, color);
        }
    }
}

struct Simulation
{
    Grid grid;
    Grid tempGrid;
    bool run;

    Simulation(int width, int height, int cellSize)
    : grid(width, height, cellSize), tempGrid(width, height, cellSize), run(false) {};

    void Draw();
    void SetCellValue(int row, int column, int value);
    int CountLiveNeighbors(int row, int column);
    void Update();
    bool IsRunning() { return run; }
    void Start() { run = true; }
    void Stop() { run = false; }
    void ClearGrid();
    void CreateRandomState();
    void ToggleCell(int row, int column);
};

void Simulation::Draw()
{
    drawGrid(grid);
}

void Simulation::SetCellValue(int row, int column, int value)
{
    grid.cells[row][column] = value;
}

int Simulation::CountLiveNeighbors(int row, int column)
{
    // Compter les voisins vivants
}

void Simulation::Update()
{
    // Mettre à jour l'état de la simulation
}

void Simulation::ClearGrid()
{
    clearGrid(grid);
}

void Simulation::CreateRandomState()
{
    fillGridRandom(grid);
}

void Simulation::ToggleCell(int row, int column)
{
    toggleCell(grid, row, column);
}

#include "grid.hpp" // Incluez la définition de la structure Grid et ses fonctions

int main()
{
    Color GREY = {29, 29, 29, 255};
    const int WINDOW_WIDTH = 750;
    const int WINDOW_HEIGHT = 750;
    const int CELL_SIZE = 25;
    int FPS = 12;

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Jeu de la vie");
    SetTargetFPS(FPS);
    Grid grid(WINDOW_WIDTH, WINDOW_HEIGHT, CELL_SIZE);
    fillGridRandom(grid); // Initialisez la grille avec des valeurs aléatoires

    while (!WindowShouldClose())
    {
        // Gestion des événements

        // Mise à jour de l'état

        // Dessin
        BeginDrawing();
        ClearBackground(GREY);
        drawGrid(grid); // Dessinez la grille
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
