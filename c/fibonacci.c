#include <stdio.h>
#include <stdlib.h>



int fibonacci(int x){
    if (x < 0){
        fprintf(stderr, "Please enter a positive number.");
        exit(EXIT_FAILURE);
    }
    else if (x == 0)
        return 0;
    else if(x == 1)
        return 1;
    return fibonacci(x - 1) + fibonacci(x - 2);
}



int main(int argc, char **argv){
    int x = atoi(argv[1]);
    printf("%d", fibonacci(x));
    return 0;
}
