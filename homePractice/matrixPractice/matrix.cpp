#include <iostream>

int main() {
    int rows, cols;
    int** matrix = nullptr;
    int** transpose = nullptr;

    // Get matrix dimensions
    std::cout << "Enter the number of rows: ";
    std::cin >> rows;

    std::cout << "Enter the number of columns: ";
    std::cin >> cols;

    // Allocate memory for the matrix
    matrix = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }

    // Input matrix elements
    std::cout << "Enter the elements of the matrix:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << "Element [" << i << "][" << j << "]: ";
            std::cin >> matrix[i][j];
        }
    }

    // Display original matrix
    std::cout << "\nOriginal Matrix:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Allocate memory for transpose matrix
    transpose = new int*[cols];
    for (int i = 0; i < cols; ++i) {
        transpose[i] = new int[rows];
    }

    // Compute transpose
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            transpose[j][i] = matrix[i][j];
        }
    }

    // Display transposed matrix
    std::cout << "\nTransposed Matrix:\n";
    for (int i = 0; i < cols; ++i) {
        for (int j = 0; j < rows; ++j) {
            std::cout << transpose[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Free allocated memory
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    for (int i = 0; i < cols; ++i) {
        delete[] transpose[i];
    }
    delete[] transpose;

    return 0;
}
