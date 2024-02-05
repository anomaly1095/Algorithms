#include <stdio.h>
#include <math.h>




int fact(int n){
    if (n == 0 || n == 1)
        return 1;
    return fact(n-1) * n;
}




int main(){
    int n = 5;
    printf("%d", fact(n));
    return 0;
}
