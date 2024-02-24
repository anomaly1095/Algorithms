#include <stdio.h>
#include <stdlib.h>


int binary_search(int *arr, int size, float target){
    int lower = 0, upper = size-1, mid;
    while (upper >= lower){
        mid = (upper + lower)/2;
        if (*(arr + mid) == target){
            return mid;
        }else if (*(arr + mid) > target){
            upper = mid - 1;
        }else if (*(arr + mid) < target){
            lower = mid + 1;
        }
    }
    return -1;
}

int *generate_arr(int size){
    int *arr = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++){
        *(arr + i) = i+69;
    }
    return arr;
}


int main(int argc, char **argv){
    if (argc != 3){
        printf("Usage: %s <size> <target>\n", argv[0]);
        return 1;
    }
    int size = atoi(argv[1]), target = atof(argv[2]), *arr = generate_arr(size);
    printf("%d\n", binary_search(arr, size, target));
    free(arr);
    return 0;
}
