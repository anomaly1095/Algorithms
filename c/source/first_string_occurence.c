#include <stdio.h>
#include <stdlib.h>

/// @brief search _s1 in _s2
/// @param _s1 array
/// @param _s2 subarray
/// @return index of the first occurence of the subarray in the array or -1 if not found
int firstoccurence(char *_s1, char *_s2, int size_s1, int size_s2){
    int i, j;
    if (size_s2 > size_s1){
        goto errorsize;
    }
    for (i = 0; i < size_s1; i++){
        for (j = 0; j < size_s2; j++){  // Complexity remains linear and only becomes O(n*m) once the two arrays are fully traversed so success
            if (_s1[i+j] != _s2[j]){
                break;
            }
            if (_s1[i+j] == _s2[j] && j == size_s2-1){
                goto success;
            }
        }
    }
    goto invalidinput;
    success:
        printf("Starting index of %s: %d\n", _s2, i);
        return 0;
    errorsize:
        printf("Invalid input size: %d %d\n", size_s1, size_s2);
        return -1;   
    invalidinput:
        printf("Invalid input: %s/%s\n", _s1, _s2);
        return -1;
}


/// @brief iterates over the memory segment allocated to the pointer 
/// @param _s char pointer
/// @return size of char pointer's array
int _strlen(char *_s){
    int i = 0;
    while (_s[i] != '\0'){
        i++;
    }
    return i;
}


int main(int argc, char **argv){
    if (argc != 3){
        printf("Usage: %s <subarray> <array>\n", argv[0]);
        return -1;
    }
    firstoccurence(argv[1], argv[2], _strlen(argv[1]), _strlen(argv[2]));
    return 0;
}