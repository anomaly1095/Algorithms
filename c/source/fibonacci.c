#include <stdio.h>


#define llu unsigned long long

// O(2**n) time complexity, 0(n) space complexity with risk of stack verflow
llu fibonacci_recursive(llu n){
    if (n <= 1)
        return n;
    if (n < 0)
        return -1;
    return fibonacci_recursive(n-1)+fibonacci_recursive(n-2);
}

// O(n) time complexity, 0(1) space complexity
llu fibonacci_loop(llu n){
    if (n < 0)
        return -1;
    llu previous = 0, current = 1, x;
    if (n <= 1)
        return n;
    for (llu i = 2; i <= n; i++){
        x = current;
        current += previous;
        previous = x;
    }
    return current;
}

int main(){
    llu n;
    scanf("%llu", &n);
    printf("result: %llu\n", fibonacci_recursive(n));
    printf("faster result: %llu\n", fibonacci_loop(n));
    return 0;
}
