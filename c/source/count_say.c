#include <stdio.h>
#include <stdlib.h>


char *_count(const char *arr);
void _say(char *rep);

int main(int argc, char const **argv){
    if (argc != 2){
        printf("Usage: %s <Number>\n", argv[1]);
        return 0X1;
    }
    int number = atoi(argv[1]);
    char *repetition = _count(argv[1]);
    _say(repetition);

    free(repetition);
    return 0;
}

char *_count(const char *arr){
    char *repetition = (char*)calloc(sizeof(char), 10), i = 0x0;
    char index, x = 0b110000;
    while (arr[i] != 0x0){
        index = arr[i] ^ x; // set the 4th 5th bit to 0
        repetition[index]++;
        ++i;
    }
    return repetition;
}

void _say(char *rep){
    char i = 0x0;
    while (i != 10){
        if (rep[i] != 0x0)
            printf("%d%d", rep[i], i);
        ++i;
    }
    printf("\n");
}