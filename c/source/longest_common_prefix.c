#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *compare(char *arr1, char *arr2, int min_len) {
    char *arr = (char*)calloc(sizeof(char), min_len + 1);
    
    for (int i = 0; i < min_len; i++) {
        if (arr1[i] == arr2[i]) {
            arr[i] = arr1[i];
        } else {
            break;
        }
    }

    return arr;
}

char *smallestarray(int argc, char **argv) {
    char *min_arr = strdup(argv[1]);  // Use strdup to duplicate the string
    for (int i = 2; i < argc; i++) {
        if (strlen(argv[i]) < strlen(min_arr)) {
            free(min_arr);  // Free previous memory before reassigning
            min_arr = strdup(argv[i]);
        }
    }
    return min_arr;
}

char *longest_prefix(int argc, char **argv) {
    if (argc <= 1) {
        return NULL;
    }

    char *min_arr = smallestarray(argc, argv);
    char *arr;

    for (int i = 1; i < argc; i++) {
        arr = compare(min_arr, argv[i], strlen(min_arr));

        free(min_arr);  // Free previous memory before reassigning

        min_arr = arr;
    }
    return min_arr;
}

int main(int argc, char **argv) {
    if (argc <= 1) {
        return 1;
    }

    char *result = longest_prefix(argc, argv);

    if (result != NULL) {
        printf("%s\n", result);
        free(result);  // Free allocated memory
    } else {
        printf("No common prefix\n");
    }

    return 0;
}
