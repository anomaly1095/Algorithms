#include <stdio.h>
#include <stdlib.h>

#define llu unsigned long long 

void sum_is_target(size_t size, llu target, llu *my_array){
    for (size_t i = 0; i < size; i++){
        for (size_t j = i; j < size; j++){
            if (*(my_array+i) + *(my_array+j) == target){
                printf("%llu, %llu", *(my_array+i), *(my_array+j));
                return;
            }
        }
    }
    printf("No possible combinations found!\n");
}


void fill_array(size_t size, llu *my_array){
    llu val = 276;
    for (size_t i = 0; i < size; i++){
        *(my_array+i) = val + 7 + i;
    }
}


int main(){
    size_t size = 30;
    llu* my_array = (llu*)calloc(size, sizeof(llu));
    fill_array(size, my_array);
    sum_is_target(size, *(my_array +3) + *(my_array+7), my_array);
    return 0;
}
