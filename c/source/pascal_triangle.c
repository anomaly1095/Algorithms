#include <stdio.h>
#include <stdlib.h>

// x are the rows and y are the columns
void fill_element(int **arr, int rows, int x, int y) {
    if (y == 0 || y == x) {
        *(*(arr + x) + y) = 1;
    } else {
        *(*(arr + x) + y) = *(*(arr + x - 1) + y - 1) + *(*(arr + x - 1) + y);
    }

    // deciding to go right or to go down or end
    if (x == rows - 1 && y == x) {
        return;
    } else if (y == x) {
        fill_element(arr, rows, ++x, 0); // increment x, not y
    } else {
        fill_element(arr, rows, x, ++y);
    }
}


int **mem_alloc(int rows){
    if (rows == 1) {
        int **arr = (int**)calloc(sizeof(int*), rows);
        *arr = (int *)calloc(sizeof(int), 1);
        *(*(arr)) = 1;
        return arr;
    }
    int i, **arr = (int**)calloc(sizeof(int*), rows); // allocating a list of pointers

    for (i = 0; i < rows; i++){
        *(arr+i) = (int*)calloc(sizeof(int), i+1); // allocating the memory for each pointer
    }
    return arr;
}

int **pascal_triangle(int rows){

    int **arr = mem_alloc(rows); // allocate the memory for the triangle
    fill_element(arr, rows, 0, 0); // populate the triangle with the correct values
    return arr;
}


void print_triangle(int **arr, int rows){
    if (rows == 1){
        printf("1\n");
    }
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < (rows-i); j++){ // printing spaces
            printf(" ");
        }
        for (int t = 0; t < i+1; t++){
            printf("%d ", *(*(arr+i)+t));
        }
        printf("\n");
    }
}

void mem_dealloc(int **arr, int rows) {
    for (int i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);
}

int main(int argc, char **argv){
    if (argc != 2){
        return -1;
    }
    int rows = atoi(argv[1]);
    int **arr = pascal_triangle(rows);
    print_triangle(arr, rows);
    

    free(arr);
    return 0;
}