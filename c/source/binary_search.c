#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int lower, int upper){
    int pivot_index = rand() % (upper - lower + 1) + lower;
    int pivot = arr[pivot_index];

    swap(&arr[pivot_index], &arr[upper]);
    
    int i = lower - 1;

    for (int j = lower; j < upper; j++) {
        if (arr[j] > pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[upper]);
    return i + 1;
}

void quick_sort(int *arr, int lower, int upper){
    if (upper > lower){
        int pivot_index = partition(arr, lower, upper);

        quick_sort(arr, lower, pivot_index - 1);
        quick_sort(arr, pivot_index + 1, upper);
    }
}

int binary_search(int *arr, int lower, int upper, int target){
    if (upper > lower){
        int mid = (upper+lower)/2;

        if (*(arr+mid) > target){
            binary_search(arr, mid+1, upper, target);
        }else if (*(arr+mid) > target){
            binary_search(arr, lower, mid-1, target);
        }else{
            return mid;
        }
    }
    return upper; // returns index where the target should be inserted 
}



void populate_array(int *arr, int size){
    int min = 0, max = 10000;
    unsigned seed = (unsigned)time(NULL);
    srand(seed);
    for (int i = 0; i < size; i++){
        *(arr+i) = rand() % (max-min+1) - min;
    }
}

int main(int argc, char **argv){
    int size = 100, target;
    int *arr = (int*)calloc(sizeof(int), size);
    populate_array(arr, size);
    quick_sort(arr, 0, size-1);
    for (int i = 0; i < size; i++){
        printf("%d ", *(arr+i));
    }printf("\n");
    scanf("%d", &target);
    printf("%d", binary_search(arr, 0, size-1, target));
    return 0;
}