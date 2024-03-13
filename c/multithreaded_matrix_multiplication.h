#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

//    Simple program that: 
//    - takes two args from the command line 
//    - creates 2 2d array
//    - fills the arrays with random numbers between MIN and MAX
//    - Calculates the resulting matrix
//    - displays the result

#ifndef MATRIX_MULT_H

  #define MATRIX_MULT_H 1
  #define MAX 100
  #define MIN -100
  #define SEPARATION 0x7C
  #define ret return

  #if MIN < 00
    typedef signed long long __data_type;
    const char *__format_s = "%c %lld %c";
    const char *__format_impo = "Matrix multiplication impossible: M1(%lld, %lld) M2(%lld, %lld)\n";
    #define MAX_RC 0x1E

  #else // if min and max positive
    typedef unsigned long long __data_type;
    const char *__format_s = "%llu %c";
    const char *__format_impo = "Matrix multiplication impossible: M1(%llu, %llu) M2(%llu, %llu)\n";
    #define MAX_RC 0x1E
  #endif

  const __data_type RANGE = (MAX - MIN) - 1; // calc range for generating random numbers in the range
  
  typedef struct Thread_struct_fill{ // struct will be passed as thread args to t1 and t2
    __data_type **matrix;
    __data_type *rows;
    __data_type *cols;
  }Thread_struct_fill;
  
  typedef struct Thread_struct_mult{ //struct will be passed as thread args to t3
    Thread_struct_fill matrix1;
    Thread_struct_fill matrix2;
    Thread_struct_fill matrix_res;
    __data_type row_to_process;
  }Thread_struct_mult;

#endif // MATRIX_MULT_H

/// @brief main entry point for the compiler 
/// @param argc (int) cmd line argument counter
/// @param argv (char **) cmd line arguments should be formatter: rows_m1,rows_m2, cols_m1,cols_m2
/// @return exit code (standard defined in errno)
int main(int argc, char **argv);

/// @brief 
/// @param argc 
/// @param argv 
void _check(int argc, char **argv);

/// @brief check for invalid chars in inputs 
/// @param arr (char *) cmd line args
/// @return (char) 1 if invalid 0 if valid
char _check_input(char *arr);

/// @brief convert args to integers
/// @param arr (char *) array to convert
/// @param rows (__data_type *) rows of the matrix 
/// @param cols (__data_type *) cols of the matrix
void _conv_rc(char *arr, __data_type *rows, __data_type *cols);

/// @brief allocate memory space for 2D array
/// @param rows (__data_type) rows 
/// @param cols (__data_type) cols
/// @return (__data_type **) 2D array (matrix)
__data_type **calloc_matrix(__data_type rows, __data_type cols);

/// @brief allocates all memory and sets up values 
/// @param arr1 
/// @param arr2 
/// @return 
Thread_struct_mult calloc_args(char *arr1, char *arr2);

void fill_matrix_1_2(Thread_struct_mult args);

/// @brief 
/// @param argptr 
/// @return 
void *fill_2d_arr(void *argptr);

/// @brief 
/// @param matrix 
/// @param rows 
/// @param cols 
void display_matrix(__data_type** restrict matrix, __data_type rows, __data_type cols);

void dealloc_args(Thread_struct_mult args);

/// @brief 
/// @param matrix 
/// @param rows 
/// @param cols 
void dealloc_matrix(__data_type** restrict matrix, __data_type rows, __data_type cols);

/// @brief 
/// @param argptr 
/// @return 
void* matrix_mult(void* argptr);