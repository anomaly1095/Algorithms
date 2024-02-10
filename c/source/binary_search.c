#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int MAX = 100, MIN = 0;
const int RANGE = MAX - MIN + 1;                                        //not working

int binary_search_recursive(int *arr, int low, int high, int target) {
    if (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid; // Target found, return the index
        } else if (arr[mid] < target) {
            return binary_search_recursive(arr, mid + 1, high, target); // Search in the right half
        } else {
            return binary_search_recursive(arr, low, mid - 1, target); // Search in the left half
        }
    }
    return low;
}


int fill_list(int *arr, int size) {
    srand(time(NULL));  // Seed the random number generator
    printf("[");
    for (int i = 0; i < size; i++) {
        int seed = rand() % RANGE - MIN;
        *(arr + i) = seed * 7 + (i * 5);
        printf("%d, ", *(arr + i));

        if (*(arr + i) < 0) { // Overflow or unexpected inputs
            return -1;
        }
    }
    printf("]\n");
    return 0;
}

int main(int argc, char **argv){
    if (argc != 2)
    {
        printf("Usage %s <size>\n", argv[0]);
    }
    int target, size = atoi(argv[1]);
    int *arr = (int*)calloc(sizeof(int), size);
    fill_list(arr, size);
    printf("Enter target value: ");
    scanf("%d", &target);
    printf("%d", binary_search_recursive(arr, 0, size-1, target));
    return 0;
}