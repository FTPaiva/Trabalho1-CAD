#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Multiplies a matrix by an array (assuming they have compatible dimensions)
void matrixMultiply(int **matrix, int *array, int rows, int cols, int *result) {
    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows; i++) {
            result[i] += matrix[i][j] * array[j];
        } 
    }
}

int main() {
    clock_t start, end;
    float total_time;
    srand(time(NULL));   // Initialization, should only be called once.
    
    // Gets the dimensions of the matrix and array
    int rows;
    int cols;
    printf("Enter the number of rows/columns:\n");
    scanf("%d", &rows);
    cols = rows;
    
    // Creates the matrix
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }
    
    // Creates the array
    int *array = (int *)malloc(cols * sizeof(int));
    int *result = (int *)malloc(rows * sizeof(int));
    
    if (matrix == NULL || array == NULL || result == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Populates the matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 101;
        }
    }

    // Populates the array
    for (int i = 0; i < cols; i++) {
        array[i] = rand() % 101;
    }
    
    printf("Starting operation...\n");
    start = clock(); // Initial time

    matrixMultiply(matrix, array, rows, cols, result); // Executes A * X
    
    end = clock(); // Final time
    total_time = ((float)(end - start)) / CLOCKS_PER_SEC; // Gets total time taken by the operation

    printf("Time taken: %f\n", total_time);

    // Free allocated memory
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
    free(array);
    free(result);

    return 0;
}

