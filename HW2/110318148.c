#include <stdio.h>
#include <stdlib.h>
#include <math.h>


// Print arrat
void Print_matrix(char** M, int row){
    for(int i = 0 ; i < row ; i++){
        for(int j = 0; j < row; ++j) {
            printf("%s\t", *(M + (i * row + j)));
        }
        printf("\n");
    }
}

// exchange first row and third row
char** swap_row(char** M, int row){
      
    char **tmp = (char**)malloc(sizeof(char*) * row);
    for(int i = 0; i < row; ++i) {
        *(tmp + i) = *(M + (0 * row + i));
        *(M + (0 * row + i)) = *(M + (2 * row + i));
        *(M + (2 * row + i)) = *(tmp + i);
    }
    return M;
}


// exchange first col and third col
char** swap_col(char** M, int row){
      
    char **tmp = (char**)malloc(sizeof(char*) * row);
    for(int i = 0; i < row; ++i) {
        *(tmp + i) = *(M + (i * row + 0));
        *(M + (i * row + 0)) = *(M + (i * row + 2));
        *(M + (i * row + 2)) = *(tmp + i);
    }
    return M;
}

int main(int argc, char *argv[]) {
    char **arr;
    arr = argv;
    int size = atoi(*(arr + 1)); // get the input size
    int row = sqrt(size); // get the matrix size
    int col = row;

    // check matrix size must be > 3
    if(row < 3){
        printf("Error: Input number must be larger than 3");
        return -1;
    }


    // create 3 matrix, which size is same as input size
    char **matrix = (char**)malloc(size * sizeof(char));
    char **matrix2 = (char**)malloc(size * sizeof(char));
    char **matrix3 = (char**)malloc(size * sizeof(char));


    // get the matrix values from argv, then store to matrix
    for (int i = 0; i < size; ++i) {
        *(matrix + i) = *(arr + 2 + i);
    }

    // Show thr original matrix 
    Print_matrix(matrix, row);   
    
    printf("--------------------------------\n");

    // Swap row
    matrix2 =  swap_row(matrix, row);  

    Print_matrix(matrix2, row);

    // Swap col
    matrix3 = swap_col(matrix2, row);

    printf("--------------------------------\n");

    Print_matrix(matrix3, row);
    
    // return memory 
    free(matrix);
    free(matrix2);
    free(matrix3);
    return 0;
}