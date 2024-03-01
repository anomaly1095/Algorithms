#include <stdio.h>
#include <stdlib.h>

char _check_d(char *arr1, char *arr2){
    char i = 00, j = 00;
    while (arr1[i] != 00){
        if (arr1[i] != 0x30 && arr1[i] != 0x31 && arr1[i] != 0x32 && arr1[i] != 0x33 && arr1[i] != 0x34 && arr1[i] != 0x2D
         && arr1[i] != 0x35 && arr1[i] != 0x36 && arr1[i] != 0x37 && arr1[i] != 0x38 && arr1[i] != 0x39 && arr1[i] != 0x2E){
            return 0x1;
        }
        ++i;
    }
    while (arr2[j] != 00){
        if (arr2[j] != 0x30 && arr2[j] != 0x31 && arr2[j] != 0x32 && arr2[j] != 0x33 && arr2[j] != 0x34 && arr2[j] != 0x2D
         && arr2[j] != 0x35 && arr2[j] != 0x36 && arr2[j] != 0x37 && arr2[j] != 0x38 && arr2[j] != 0x39 && arr2[j] != 0x2E){
            return 0x1;
        }
        ++j;
    }
    return 00;
}

double set_exponent(char *arr){
    char x = 0b110000, i;
    double val = 0.0, coeff = 1.0;

    for ( i = 0; arr[i] != 0x2E; i++){} // find position before .
    i--;
    // setting the exponent
    while (i >= 00){
        while (arr[i] == 0x30){ 
            coeff *= 0xA;
            --i;
        }
        val += (double)(x ^ arr[i]) * coeff;
        coeff *= 0xA;
        --i;
        if (i == 0 && arr[i] == 0x2D){
            val*=-1;
            break;
        }
    }
    return val;
}

double set_mantissa(char *arr){ 
    char x = 0b110000, i;
    double val = 0.0, coeff = 0.1;

    for (i = 0; arr[i] != 0x2E; i++){} // find position of .
    i++;
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

double _atod(char *arr, double *exponent_exp, double *mantissa_exp){
    char i = 00, *arr1;
    double val = 0.0;
    while (arr[i] != 0x0){
        if (arr[i] == 0x2E){
            goto fraction_present; 
        }
        ++i;
    }


    insert_fraction:
        arr1 = (char*)calloc(sizeof(char), ++i);
        for (i = 00; arr[i] != 00; ++i){
            arr1[i] = arr[i];
        }
        arr1[i] = 0x2E;
        *exponent_exp = set_exponent(arr1);
        *mantissa_exp = set_mantissa(arr1);
        
        val += *exponent_exp;
        if (val < 00){
            val -= *mantissa_exp;
        }
        if (val >= 00){
            val += *mantissa_exp;
        }
        free(arr1);
        return val;

    fraction_present:
        *exponent_exp = set_exponent(arr);
        *mantissa_exp = set_mantissa(arr);
        val += *exponent_exp;
        if (val < 00){
            val -= *mantissa_exp;
        }
        if (val >= 00){
            val += *mantissa_exp;
        }
        return val;
}

/// @brief calc pow
/// @param base          value to operate on
/// @param exponent_exp  exponent part of the exponent
/// @param mantissa_exp  mantissa part of the exponent
/// @return base**exponent
double _pow_d(double base, double exponent_exp, double mantissa_exp) {
    double res = 1.0;

    if (exponent_exp > 0) {
        for (int i = 0; i < exponent_exp; ++i) {
            res *= base;
        }
        return res * mantissa_exp;
    } else if (exponent_exp < 0) {
        for (int i = 0; i > exponent_exp; --i) {
            res *= base;
        }
        return 1.0 / (res * mantissa_exp);
    } else {
        // Handle case where exponent_exp is 0
        return mantissa_exp != 0.0 ? mantissa_exp : 1.0;
    }
}

// ####################################

int main(int argc, char **argv){
    if (argc != 0x3)
        return 0x1;
    if (_check_d(argv[01], argv[02]))
        return 0x1;
    
    char *base = argv[1], *exp = argv[2];

    double exponent_exp = 0, mantissa_exp = 0;
    double x = _atod(base, &exponent_exp, &mantissa_exp); // we should pu NULL NULL but we get segfault
    double y = _atod(exp, &exponent_exp, &mantissa_exp);
    
    double res = _pow_d(x, exponent_exp, mantissa_exp);
    printf("base: %lf \nexp: %lf \nres: %lf\n", x, y, res);

    return 00;
}