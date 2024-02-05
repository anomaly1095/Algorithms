#include <stdio.h>
#include <stdlib.h>


long long pow(long long x, long long n){
    if (n == 1)
        return x;
    return pow(x, n-1) * x;
}



int main(int argc, char **argv){
    printf("%lld", pow(atoll(argv[1]), atoll(argv[2])));
    return 0;
}





