#include <stdio.h>
#include <stdlib.h>


int _sqrt(int n){
    if (n == 0 || n == 1)
        return n;
    if (n < 0)
        return -1;
    for (int i = 1; i < n; i++){
        if ((i+1)*(i+1) > n)
            return i;
    }
}



int main(int argc, char **argv){
    if (argc != 2){
        printf("Usage: %s <n>(int)\n", argv[0]);
        return -1;
    }
    printf("%d\n", _sqrt(atoi(argv[1])));
    return 0;
}