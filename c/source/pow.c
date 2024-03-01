#include <stdio.h>

//####################################
#define uint unsigned int

char _upper_index(char *arr){
    char i = 00;
    while (arr[i] != 00){
        ++i;
    }
    return --i;
}

char _check_i(char *arr1, char *arr2){
    char i = 00, j = 00;
    while (arr1[i] != 00){
        if (arr1[i] != 0x30 && arr1[i] != 0x31 && arr1[i] != 0x32 && arr1[i] != 0x33 && arr1[i] != 0x34
         && arr1[i] != 0x35 && arr1[i] != 0x36 && arr1[i] != 0x37 && arr1[i] != 0x38 && arr1[i] != 0x39){
            return 0x1;
        }
        ++i;
    }
    while (arr2[j] != 00){
        if (arr2[j] != 0x30 && arr2[j] != 0x31 && arr2[j] != 0x32 && arr2[j] != 0x33 && arr2[j] != 0x34
         && arr2[j] != 0x35 && arr2[j] != 0x36 && arr2[j] != 0x37 && arr2[j] != 0x38 && arr2[j] != 0x39){
            return 0x1;
        }
        ++j;
    }
    return 00;
}

uint _atoi(char *arr){
    char x = 0b110000, i = _upper_index(arr);
    uint val = 00, coeff = 1;
    while (i >= 00){
        while (arr[i] == 0x30){
            coeff *= 0xA;
            --i;
        }
        val += (uint)(x ^ arr[i]) * coeff; // xor transforms 0x3N to 0xN
        coeff *= 0xA;
        --i;
    }
    return val;
}

//####################################

//####################################

char check_d(char *arr1, char *arr2){
    char i = 00, j = 00;
    while (arr1[i] != 00){
        if (arr1[i] != 0x30 && arr1[i] != 0x31 && arr1[i] != 0x32 && arr1[i] != 0x33 && arr1[i] != 0x34
         && arr1[i] != 0x35 && arr1[i] != 0x36 && arr1[i] != 0x37 && arr1[i] != 0x38 && arr1[i] != 0x39 && arr1[i] != 0x2E){
            return 0x1;
        }
        ++i;
    }
    while (arr2[j] != 00){
        if (arr2[j] != 0x30 && arr2[j] != 0x31 && arr2[j] != 0x32 && arr2[j] != 0x33 && arr2[j] != 0x34
         && arr2[j] != 0x35 && arr2[j] != 0x36 && arr2[j] != 0x37 && arr2[j] != 0x38 && arr2[j] != 0x39 && arr1[i] != 0x2E){
            return 0x1;
        }
        ++j;
    }
    return 00;

double set_exponent(char *arr){
    char x = 0b110000, i;
    double val = 0.0, coeff = 1.0;

    for ( i = 0; arr[i] != 0x2E; i++){} // find position before .
    
    // setting the exponent
    while (i >= 00){
        while (arr[i] == 0x30){ 
            coeff *= 0xA;
            --i;
        }
        val += (double)(x ^ arr[i]) * coeff;
        coeff *= 0xA;
        --i;
    }
    return val;
}

double set_mantissa(char *arr){ //18027.19018
    char x = 0b110000, i;
    double val = 0.0, coeff = 0.1;

    for (i = 0; arr[i] == 0x2E; i++){} // find position of .
    ++i; // index after the .

    while (arr[i] != 00){
        while (arr[i] == 0x30){ 
            coeff /= 0xA;
            ++i;
        }
        val += (double)(x ^ arr[i]) * coeff;
        coeff /= 0xA;
        ++i;
    }
    return val;
}

double _atod(char *arr){
    double val = set_exponent(arr);
    val += set_mantissa(arr);
    return val;
}

//####################################

int main(int argc, char **argv){
    if (argc != 3)
        return 0x1;
    if (_check_i(argv[1], argv[2]))
        return 1;
    if (_check_d(argv[1], argv[2]))
        return 1;

    printf("%u %lf\n", _atoi(argv[1]), _atod(argv[1]));
    
    return 00;
}