#include <stdio.h>
#include <stdlib.h>

#define SIZE 12

int palindrom(int n){
    char *s1 = (char*)calloc(sizeof(char), SIZE);
    char *s2 = (char*)calloc(sizeof(char), SIZE);
    sprintf(s1, "%d", n);
    int size = 0;
    for (int i = 0; i < SIZE; i++){
        if (*(s1+i) == '\0'){break;}
        size++;
    }
    int j = size-1;
    for (int i = 0; i <= size-1; i++){
        *(s2+i) = *(s1+j);
        j--;
    }
    for (int i = 0; i <= size-1; i++){
        if (*(s1+i) != *(s2+i))
            return 0;
    }
    return 1;
}


int main(){
    int n = 70017;
    if (palindrom(n) == 1){
        printf("%d is palindrom.", n);
    }else{
        printf("%d is not palindrom.", n);
    }
}