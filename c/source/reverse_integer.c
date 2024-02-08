#include <stdio.h>
#include <stdlib.h>

const int MAX_DIGITS = 10;

void reverse_int(int x){
    char *s = (char*)calloc(sizeof(char), MAX_DIGITS); //10 character is the size of max size 32 bit unsigned int
    snprintf(s, MAX_DIGITS, "%d", x);
    if (*s == '-'){
        printf("-");
        for(int i = MAX_DIGITS-1; i >= 1; i--){
            if(*(s + i) != '\0')
                printf("%c", *(s + i));
        }
    }else{
        for(int i = MAX_DIGITS-1; i >= 0; i--){
            if(*(s + i) != '\0')
                printf("%c", *(s + i));
        }
    }
    printf("\n");
}

int main(int argc, char **argv){
    int x = atoi(argv[1]);
    reverse_int(x);
    return 0;
}
