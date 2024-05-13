#pragma once

#include <vector>
#include <cstdlib>
#include <ctime>
#include <raylib.h> // Assurez-vous d'avoir les bonnes définitions pour Color

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

void initializeGrid(Grid& grid, int width, int height, int cellSize);

void setCellValue(Grid& grid, int row, int column, int value);

int getCellValue(const Grid& grid, int row, int column);

bool isWithinBounds(const Grid& grid, int row, int column);

void fillGridRandom(Grid& grid);

void clearGrid(Grid& grid);

void toggleCell(Grid& grid, int row, int column);

void drawGrid(const Grid& grid);

