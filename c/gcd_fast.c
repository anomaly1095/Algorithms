#include <stdio.h>
#include <stdlib.h>

#define ll long long

ll gcd_fast(ll a, ll b){
    if (a % b == 0)
        return a;
    return gcd_fast(b, a % b);
}

int main(int argc, char **argv){
    ll a = atoll(argv[1]), b = atoll(argv[2]), perm;
    if(a < 0 || b < 0){
        printf("Please give a positiver number.");
        exit(1);
    }
    if (a < b && b % a != 0) 
        perm = b;
        b = a;
        a = perm;
        printf("%lld", gcd_fast(a, b));
    if (a > b && a % b != 0) //good
        printf("%lld", gcd_fast(a, b));
    if (a % b == 0)
        printf("%lld", b);
    if (b % a == 0)
        printf("%lld", a);
    if (a == b)
        printf("%lld", a);
    else{
        printf("%lld", gcd_fast(a, b));
    }
    return 0;
}
