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
  #define MIN 00

  #define SEPARATION 0x7C
  #define ret return
  #if MIN < 0
    #if MAX >= 0
      #if MAX <= 0xF
        typedef signed char __data_type;  // Use signed data type
        const char *__format_s = "%c %hhd %c";
        #define MAX_RC 0x3
      #elif MAX > 0xF && MAX <= 0xFF
        typedef signed short __data_type;
        const char *__format_s = "%c %hd %c";
        #define MAX_RC 0x5
      #elif MAX > 0xFF && MAX <= 0xFFFF
        typedef signed int __data_type;
        const char *__format_s = "%c %d %c";
        #define MAX_RC 0xA
      #elif MAX > 0xFFFF
        typedef signed long long __data_type;
        const char *__format_s = "%c %ll %c";
        #define MAX_RC 0x1E
      #endif
    #else
      #if MAX >= -0xF
        typedef signed char __data_type;  // Use signed data type
        const char *__format_s = "%c %hhd %c";
        #define MAX_RC 0x3
      #elif MAX < -0xF && MAX >= -0xFF
        typedef signed short __data_type;
        const char *__format_s = "%c %hd %c";
        #define MAX_RC 0x5
      #elif MAX < -0xFF && MAX >= -0xFFFF
        typedef signed int __data_type;
        const char *__format_s = "%c %d %c";
        #define MAX_RC 0xA
      #elif MAX < -0xFFFF
        typedef signed long long __data_type;
        const char *__format_s = "%c %ll %c";
        #define MAX_RC 0x1E
      #endif
    #endif
  #else
    #if MAX <= 0xF
      typedef unsigned char __data_type;  // Use unsigned data type
      const char *__format_s = "%c %hhu %c";
      #define MAX_RC 0x3
    #elif MAX > 0xF && MAX <= 0xFF
      typedef unsigned short __data_type;
      const char *__format_s = "%c %hu %c";
      #define MAX_RC 0x5
    #elif MAX > 0xFF && MAX <= 0xFFFF
      typedef unsigned int __data_type;
      const char *__format_s = "%c %u %c";
      #define MAX_RC 0xA
    #elif MAX > 0xFFFF
      typedef unsigned long long __data_type;
      const char *__format_s = "%llu %c";
      #define MAX_RC 0x1E
    #endif
  #endif
  
  const __data_type RANGE = (MAX - MIN) - 1;
  
  typedef struct Thread_struct_fill{
    __data_type **matrix;
    __data_type *rows;
    __data_type *cols;
  }Thread_struct_fill;
  
  typedef struct Thread_struct_mult{
    Thread_struct_fill matrix1;
    Thread_struct_fill matrix2;
    Thread_struct_fill matrix_res;
  }Thread_struct_mult;

#endif // MATRIX_MULT_H

/// @brief main entry point for the compiler 
/// @param argc (int) cmd line argument counter
/// @param argv (char **) cmd line arguments should be formatter: rows_m1,rows_m2, cols_m1,cols_m2
/// @return exit code (standard defined in errno)
int main(int argc, char **argv);

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
/// @param rows (__data_type *) rows 
/// @param cols (__data_type *) cols
/// @return (__data_type **) 2D array (matrix)
__data_type **alloc_matrix(__data_type rows, __data_type cols);

/// @brief populate the matrix with ra,dom values [MIN .. MAX]
/// @param matrix (__data_type **) 2D array
/// @param rows (__data_type *) rows 
/// @param cols (__data_type *) cols 
/// @return (void *)
void *fill_2d_arr(Thread_struct_fill *arg);

/// @brief display the content of the matrix
/// @param matrix (__data_type**) 2D array
void display_matrix(__data_type** restrict matrix, __data_type rows, __data_type cols);

/// @brief free the memory space allocated for the matrix
/// @param matrix (__data_type**) resulting array
/// @param rows (__data_type *) rows of the matrix 
/// @param cols (__data_type *) cols of the matrix
/// @param  (__data_type *) cols of the matrix
void dealloc_matrix(__data_type** restrict matrix, __data_type rows, __data_type cols);

/// @brief multiply two matrixes and fill it with the last array
/// @param matrix1 (__data_type **) 2D array 
/// @param matrix2 (__data_type **) 2D array 
/// @param res_matrix (__data_type **) resulting array
/// @param r1c1r2c2 (__data_type *) row1 col1 row2 col2
/// @return 
void *matrix_mult(Thread_struct_mult *arg);