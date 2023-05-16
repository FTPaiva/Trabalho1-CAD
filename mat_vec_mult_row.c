#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Multiplica a matriz pelo vetor (assumindo que eles possuem dimensões compatíveis)
void matrixMultiply(int **matrix, int *array, int rows, int cols, int *result) {
    for (int i = 0; i < rows; i++) { // Iterates through all columns within each row
        result[i] = 0;
        for (int j = 0; j < cols; j++) {
            result[i] += matrix[i][j] * array[j];
        }
    }
}

int main() {
    // Inicialização das variáveis do timer
    clock_t start, end;
    float total_time;
    // seed para o gerador de números aleatórios
    srand(time(NULL));
    
    // Obtém o tamanho da matriz
    int rows;
    int cols;
    printf("Número de linhas/colunas:\n");
    scanf("%d", &rows);
    cols = rows;
    
    // Cria a matriz
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }
    
    // Cria o vetor
    int *array = (int *)malloc(cols * sizeof(int));
    int *result = (int *)malloc(rows * sizeof(int));
    
    if (matrix == NULL || array == NULL || result == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    // Popula a matriz com números aleatórios variando de 0 a 100
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 101;
        }
    }

    // Popula o vetor com números aleatórios variando de 0 a 100
    for (int i = 0; i < cols; i++) {
        array[i] = rand() % 101;
    }
    
    printf("Começando operação...\n");
    start = clock(); // Começa o timer

    matrixMultiply(matrix, array, rows, cols, result); // Executa a operação A * X
    
    end = clock(); // Termina o timer
    total_time = ((float)(end - start)) / CLOCKS_PER_SEC; // Calcula tempo total da operação
    printf("Tempo total: %f\n", total_time);

    // Libera memória alocada
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
    free(array);
    free(result);

    return 0;
}



