#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quicksort(int *arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // Recursive call on the left and right sub-arrays
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}


void rng(int *arr, int size, int min, int max){
    int range = max - min + 1;
    for (int i = 0; i < size-1; i++){
        *(arr + i) = rand() % range + min;
    }
}


int main(int argc, char **argv){
    if (argc != 4){
        printf("correct usage: %s <size> <min> <max>\n", argv[0]);
        return 1;
    }
    int size = atoi(argv[1]), min = atoi(argv[2]), max = atoi(argv[3]);

    int *arr = (int*)calloc(sizeof(int), size);
    
    rng(arr, size, min, max);
    quicksort(arr, 0, size-1);
    for (int i = 0; i < size-1; i++){
        printf("%d ", *(arr+i));
    }
    printf("\n");
    free(arr);
    return 0;
}