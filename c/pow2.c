#include <stdio.h>
#include <stdlib.h>

// x is the base. n is the exponent.
long long pow(long long x, long long n){
    long long val = x;
    if (x == 0)
        return 0;
    if (n == 0)
        return 1;
    if (n == 1)
        return x;
    for(long long i = 1; i < n; i++){
        x *= val;
    }
    printf("%lld", x);
}


int main(int argc, char **argv){
    pow(atoll(argv[1]), atoll(argv[2]));
    return 0; 
}



