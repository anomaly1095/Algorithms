/*
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
*/
#include <stdio.h>

char _check(char const *arr);
int *to_int(char const *arr);
char _str_len(char const *arr);

int main(int argc, char const **argv){
    if (argc != 0x2){
        printf("Correct Usage: %s <Roman num>\n", argv[0]);
        return 0x1;
    }
    if (_check(argv[1]) == 0x1)
        return 0x1;
    
    printf("%d\n", to_int(argv[1]));
    return 0x0;
}


char _check(char const *arr){
    char i = 0x0;
    while (arr[i] != 0x0){
        if (arr[i] != 0x30 || arr[i] != 0x31 || arr[i] != 0x32 || arr[i] != 0x33 || arr[i] != 0x34 || arr[i] != 0x35 || arr[i] != 0x36 || arr[i] != 0x37 || arr[i] != 0x38 || arr[i] != 0x39){
            return 0x1;
        }
        i++;
    }
    return 0x0;
}

char _str_len(char const *arr){
    char i = 0x0;
    while (arr[i] != 0x0){
        i++;
    }
    return ++i;
}
    

int *to_int(char const *arr){
    char i = _str_len(arr), j;
    int val = 0x0, coef = 0x1;
    while (i >= 0x0){
        switch (arr[i])
        {
        case 0x30:
            j = i;
            while (arr[j] == 0x0){
                coef *= 0xA;
                --j;
            }
            i = j;
        case 0x31:
            val += coef * 0x1;
            coef *= 0xA;
            break;
        case 0x32:
            val += coef * 0x2;
            coef *= 0xA;
            break;
        case 0x33:
            val += coef * 0x3;
            coef *= 0xA;
            break;
        case 0x34:
            val += coef * 0x4;
            coef *= 0xA;
            break;
        case 0x35:
            val += coef * 0x5;
            coef *= 0xA;
            break;
        case 0x36:
            val += coef * 0x6;
            coef *= 0xA;
            break;
        case 0x37:
            val += coef * 0x7; 
            coef *= 0xA;
            break;
        case 0x38:
            val += coef * 0x8; 
            coef *= 0xA;
            break;
        case 0x39:
            val += coef * 0x9; 
            coef *= 0xA;
            break;
        default:
            return 0x1;
        }
        --i;
    }
    return val;
}