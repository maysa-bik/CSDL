#include "grid.hpp"


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
    return 0; 
}

bool isWithinBounds(const Grid& grid, int row, int column) {
    return (row >= 0 && row < grid.rows && column >= 0 && column < grid.columns);
}

void fillGridRandom(Grid& grid) {
    srand(static_cast<unsigned int>(time(nullptr))); 
    for (int row = 0; row < grid.rows; ++row) {
        for (int col = 0; col < grid.columns; ++col) {
            grid.cells[row][col] = rand() % 2; 
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
        grid.cells[row][column] = (grid.cells[row][column] == 0) ? 1 : 0; 
    }
}
void drawGrid(const Grid& grid) {
    for(int row = 0; row < grid.rows; row ++) {
        for(int column = 0; column < grid.columns; column++) {
            Color color = grid.cells[row][column] ? BLACK : Color{55, 55, 55, 255};
            DrawRectangleLines(column * grid.cellSize, row * grid.cellSize, grid.cellSize, grid.cellSize, color);
        }
    }
}
