#include <stdio.h>
#include <stdlib.h>

long long fibo(long long x){
    long long val0, val1 = 0, val2 = 1;
    if (x == 0)
        return 0;
    for (long long i = 1; i < x; i++){
        val0 = val2;
        val2 += val1;
        val1 = val0;
    }
    printf("%llu %llu\n", val1, val2);
    return val2;
}

int main(int agrc, char **argv){
    printf("%lld", fibo(atoll(argv[1])));
    return 0;
}
