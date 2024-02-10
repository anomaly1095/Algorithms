#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int MAX = 100, MIN = 0;
const int RANGE = MAX - MIN + 1;

int find_or_insert_position(int *arr, int size, int target) {
    int i = 0, j;

    while (i < size - 1) {
        if (*(arr + i) == target && i == size - 1) {
            return size;
        } else if (*(arr + i) == target) {
            for (j = i + 1; j < size; j++) {
                if (*(arr + j) != target) {
                    return (j == size - 1) ? size : j;
                }
            }
        }
        i++;
    }

    return -1;
}

int fill_list(int *arr, int size) {
    srand(time(NULL));  // Seed the random number generator

    for (int i = 0; i < size; i++) {
        int seed = rand() % RANGE + MIN;
        *(arr + i) = seed * 7 + (i * 5);
        printf("%d\n", *(arr + i));

        if (*(arr + i) < 0) { // Overflow or unexpected inputs
            return -1;
        }
    }

    return 0;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <size> <target>\n", argv[0]);
        return 1;
    }

    int size = atoi(argv[1]), target = atoi(argv[2]);
    int *arr = (int *)calloc(sizeof(int), size);

    if (!arr) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    if (fill_list(arr, size) == -1) {
        printf("Integer overflow or unexpected input.\n");
        free(arr);
        return 1;
    }

    int result = find_or_insert_position(arr, size, target);

    if (result == -1) {
        printf("No results found.\nInsert %d in %d\n", target, result);
    } else {
        printf("%d found in %d\n", target, result);
    }

    free(arr);
    return 0;
}
