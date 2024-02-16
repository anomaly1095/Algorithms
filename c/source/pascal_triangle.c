#include <stdio.h>
#include <stdlib.h>

// x are the rows and y are the columns
void fill_element(int **arr, int rows, int x, int y){

    if (y == 0 || y == x){  // we take care of case where items have not parents or 
        *(arr+x)[y] = 1;    // one of the parents are missing
    }else{
        *(arr+x)[y] = *(arr+x-1)[y-1] + *(arr+x-1)[y]; // element is equal to both elements on top of it
    }
    
    //deciding to go right or to go down or end
    if (x == rows-1 && y == x){ // reached last item in triangle
        return;
    }
    else if (x != rows-1){ // reached last item in row
        fill_element(arr, rows, x+1, 0);
    }
    else{
        fill_element(arr, rows, x, ++y); 
    }
}

int **pascal_triangle(int rows){
    if (rows == 1) {
        int **arr = (int **)calloc(sizeof(int *), 1);
        *arr = (int *)calloc(sizeof(int), 1);
        *(arr)[0] = 1;
        return arr;
    }
    int i, **arr = (int**)calloc(sizeof(int*), rows); // allocating a list of pointers

    for (i = 0; i < rows; i++){
        *(arr+i) = (int*)calloc(sizeof(int), i+1); // allocating the memory fo each pointer
    }
    fill_element(arr, rows, 0, 0);
    return arr;
}



int main(int argc, char **argv){
    // if (argc != 2){
    //     return -1;
    // }
    // int **arr = pascal_triangle(atoi(argv[1]));
    int **arr = pascal_triangle(5);
    free(arr);
    return 0;
}