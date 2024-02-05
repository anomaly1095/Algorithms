#include <stdio.h>
#include <stdlib.h>



long long gcd(long long x, long long y, long long ctr){
    if (x % ctr == 0 && y % ctr == 0)
        return ctr;
    return gcd(x, y, ctr-1);
}




int main(int argc, char **argv){
    long long x = atoll(argv[1]), y = atoll(argv[2]);
    if (x > y)
        printf("%lld", gcd(x, y, y));
    if(y > x)
        printf("%lld", gcd(x, y, x));
    if (x == y)
        printf("%lld", x);
    return 0;
}
