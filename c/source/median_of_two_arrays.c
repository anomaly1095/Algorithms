#include <stdio.h>
#include <stdlib.h>

//#########################################################

int *merge(int *arr1, int *arr2, int total){

}

void merge_sort(int *arr, int lower, int upper){

}
//#########################################################

char _test(char c){
    if (c == 0x30 || c == 0x31 || c == 0x32 || c == 0x33 || c == 0x34 || c == 0x35 ||
    c == 0x36 || c == 0x37 || c == 0x38 || c == 0x39)
        return 01;
    return 00;
}

void reset_num(char *num){
    char i = 00;
    while (num[i] != 00){
        num[i] = 00;
        i++;
    }
}

//conv buffer to int
int _conv(char *num){
    char i;
    int coeff = 01, val = 00;
    for (i = 00; num[i] != 00; i++){}
    while (i != 00){
        if (num[i] == 0x30){ // offsetting for handling zero
            coeff *= 0xA;
            --i;
        }
        val += (num[i] ^ 0x30) * coeff;
        coeff *= 0xA;
        --i;
    }
    reset_num(num);
    return val;
}

int *_parse(char *arr){
    int i = 00, j = 00, t = 00;
    char *num = (char*)calloc(sizeof(char), 0xA); // max size of int (10)
    int *p = (int*)malloc(sizeof(int) * 0x3E8);   // 3.90625 Kb heap memory
    
    while (arr[i] != 00){
        while (_test(arr[i])){
            num[t] = arr[i];
            ++i;
            t++;
            if (!_test(i)){
                --i;                 // iterator for input buffer
                *(p+j) = _conv(num); // convert chars to int
                j++;                 // iterator for int list
                t = 00;
                break;
            }
        }
        i++;
    }
    free(num);
    return p;
}
//#########################################################

//sorted array
int _med(int *arr){

}
//#########################################################

int main(int argc, char **argv){
    if (argc != 03)
        return 01;
    
    int i, j, median, *arr, *arr1 = _parse(argv[01]), *arr2 = _parse(argv[02]);
    printf("%d\n", arr1[0]);
    //for (i = 0; arr1[i] != 00 ; i++){}
    //for (j = 0; arr2[j] != 00 ; j++){}
    //merge_sort(arr1, 00, i);
    //merge_sort(arr2, 00, j);
    //arr = merge(arr1, arr2, i+j);
    //median = _med(arr);
    free(arr1);
    free(arr2);
    return 0;
}
