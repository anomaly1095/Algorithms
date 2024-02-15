#include <stdio.h>
#include <stdlib.h>


int *perfect_combination(int c1, int c2, int c3, int change){
    int B_c, m_c, s_c, val = 0, temp_change = change; // big coin, mid coin, small coin
    if (c1 > c2){
        if (c3 > c1)
            b_c, m_c, s_m = c3, c1, c2;
        else{
            if (c3 > c2)
                b_c, m_c, s_c = c1, c3, c2;
            else{
                b_c, m_c, s_c = c1, c2, c3;
            }
        }
    }else{
        if(c3 > c2)
            b_c, m_c, s_c = c3, c2, c1;
        else{
            if (c3 > c1)
                b_c, m_c, s_c = c2, c3, c1;
            else{
                b_c, m_c, s_c = c2, c1, c3;
            }    
        }
    }
    // first list gets allocated
    int* coins = (int*)calloc(sizeof(int), change/s_c), temp = (int*)calloc(sizeof(int), change/s_c);
    for (int i = 0; i < change; i++){
        if
    }
    return coins;
}


int main(int argc, char **argv){
    if (argc!=5)
        return 1;
    int c1 = atoi(argv[1]),c2 = atoi(argv[2]), c3 = atoi(argv[3]), change = atoi(argv[4]);
    perfect_combination(c1, c2, c3, change);

    
    return 0;
}
