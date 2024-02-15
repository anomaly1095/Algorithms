#include <stdio.h>
#include <stdlib.h>

typedef enum bool{
    false = 0,
    true = 1
} bool;

int _strlen(char *s){
    int i = 0;
    while (*(s+i) != '\0'){
        i++;
    }
    return i;
}

bool valid(char *arr){
    int i1 = 0, i2 = 0, i3 = 0;
    for (int i = 0; i < _strlen(arr); i++){
        if (*(arr+i) == '(' || *(arr+i) == ')'){i1++;}
        else if (*(arr+i) == '{' || *(arr+i) == '}'){i2++;}
        else if (*(arr+i) == '[' || *(arr+i) == ']'){i3++;}
    }
    if (i1 % 2 == 0 && i2 % 2 == 0 && i3 % 2 == 0){
        return true;
    }
    return false;
}

bool validity_test(int argc, char **argv){
    for (int i = 1; i < argc; i++){
        for (int j = 0; j < _strlen(argv[i]); j++){
            if (valid(argv[i]) == false){
                return false;
            }
        }
    }
    return true;
}


int main(int argc, char **argv){
    printf("%d\n", validity_test(argc, argv));
    return 0;
}