#include <stdio.h>
#include <stdlib.h>

//                                  S(n) = ((n+1)*n)/2
long long int sum(long long int n){
    if (n == 0)
        return 0;
    return n + sum(n-1);
}





int main(int argc, char **argv){
    printf("%lld\n", sum(atoll(argv[1]))); // sum of converted to long long first argument from stdin of the main function
    return 0;
}
