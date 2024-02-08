

#include <stdio.h>
#include <stdlib.h>

const int SIZE_ARRAY = 30, MIN = -100, MAX = 100; 

// we will not make use of Range values bcs they are supposed to be unknown
void max_subarray(int *A){
    int global_max = A[0], global_start = 0, global_end = 0;
    int current_max = A[0], current_start = 0, current_end = 0;
    for (int i = 0; i < SIZE_ARRAY; i++){
        if(A[i] > current_max && current_max <= 0){
            current_max = A[i];
            current_start = i;
            current_end = i;
        }
        else if(A[i] > 0){
            current_max += A[i];
            current_end = i;
        }
        else if(A[i] < 0){
            current_max = A[i];
        }
        if(current_max > global_max){
            global_max = current_max;
            global_start = current_start;
            global_end = current_end;
        }
    }
    printf("Max: %d\n[%d..%d]\n", global_max, global_start, global_end);
}

int custom_rand() {
    // Generate a random integer in the specified range
    int range = MAX - MIN + 1;
    int randomValue = rand() % range + MIN;
    return randomValue;
}

void fill_array(int *A){
    printf("[");
    for(int i = 0; i < SIZE_ARRAY; i++){
        *(A + i) = custom_rand();
        printf("%d, ", *(A + i));
    }
    printf("]\n");
}

int main(int argc, char **argv){
    int *A = (int*)calloc(sizeof(int), SIZE_ARRAY);
    fill_array(A);
    max_subarray(A);
    return 0;
}
