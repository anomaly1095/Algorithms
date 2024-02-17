#include <stdio.h>
#include <stdlib.h>

//              EXAMPLE USAGE
// Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
// Output: true

int _strlen(char *_s);
void leftshift(char *_s, int i);

void _parseinput(char *_s){
    int i = 0;
    while (*(_s+i) != '\0'){
        if (*(_s+i) == 91 || *(_s+i) == 93 || *(_s+i) == 44){ // 91 = '[' 93 =  ']' 44 = ','
            leftshift(_s, i);
        }
        i++;
    }
}

int main(int argc, char **argv){
    if (argc != 2)
    {
        printf("Usage: %s <array[[],[]]>\n", argv[0]);
        return -1;
    }
    _parseinput(argv[1]);
    printf("%s\n", argv[1]);
    return 0;
}


int _strlen(char *_s){
    int i = 0;
    while (*(_s + i) != '\0'){
        i++;
    }
    return i;
}

void leftshift(char *_s, int i){
    while (_s[i] != '\0'){
        *(_s + i) = *(_s + i + 1);
        i++;
    }
}
