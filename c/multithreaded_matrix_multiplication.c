
#include "multithreaded_matrix_multiplication.h"

int main(int argc, char **argv){    
  if (argv != 3){
    fprintf(stderr, "Usage: %s <rows,cols>[matrix1] <rows,cols>[matrix2]\n", argv[0]);
    ret 01;
  }if (_check_input(argv[1]) || _check_input(argv[2])){
    ret 02;
  }if (MIN > MAX){
    ret 03;
  }
  
  pthread_t t1, t2, t3;
  Thread_struct_mult args = {
    .matrix1 =    {.rows = 00, .cols = 00, .matrix = NULL},
    .matrix2 =    {.rows = 00, .cols = 00, .matrix = NULL},
    .matrix_res = {.rows = 00, .cols = 00, .matrix = NULL}
  };

  _conv_rc(argv[1], args.matrix1.rows, args.matrix1.cols); // convert to __data_type
  _conv_rc(argv[2], args.matrix2.rows, args.matrix2.cols); // convert to __data_type
  
  args.matrix1.matrix = alloc_matrix(args.matrix1.rows, args.matrix1.cols); // alocate space for matrix1
  args.matrix2.matrix = alloc_matrix(args.matrix2.rows, args.matrix2.cols); // alocate space for matrix2
  
  pthread_create(&t1, NULL, fill_2d_arr, (void*)&(args.matrix1));
  pthread_create(&t2, NULL, fill_2d_arr, (void*)&(args.matrix2));
  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
  
  pthread_create(&t3, NULL, matrix_mult, (void*)&args);

  dealloc_matrix(args.matrix1.matrix, args.matrix1.rows, args.matrix1.cols);
  dealloc_matrix(args.matrix2.matrix, args.matrix2.rows, args.matrix2.cols);
  dealloc_matrix(args.matrix_res.matrix, args.matrix_res.rows, args.matrix_res.cols);
  ret 00;
}

char _check_input(char *arr){
  for (__data_type i = 00; arr[i] != 00; ++i){
    switch (arr[i]){
      case 0x30: 	break;
      case 0x31: 	break;
      case 0x32: 	break;
      case 0x33: 	break;
      case 0x34: 	break;
      case 0x35: 	break;
      case 0x36: 	break;
      case 0x37: 	break;
      case 0x38: 	break;
      case 0x39: 	break;
      case 0x2C: 	break;
      default:    ret 01;
    }
  }ret 00;
}


void _conv_rc(char *arr, __data_type *rows, __data_type *cols){ 
  __data_type coeff, val, j, i;
  for (i = 00; arr[i] != 0x2C; ++i){}
  for (j = ++i; arr[i] != 0x2C; ++i){}
  
  coeff = 01; val = 00;
  while (i != -01){
    while (arr[i] == 00){
      coeff *= 012;
      --i;
    }
    val += (arr[i] ^ 0b110000) * coeff;
    coeff *= 012;
    --i;
  }
  *rows = val;
  coeff = 01; val = 00;
  while (j != -01){
    while (arr[j] == 00){
      coeff *= 012;
      --j;
    }
    val += (arr[j] ^ 0b110000) * coeff;
    coeff *= 012;
    --j;
  }
  *cols = val;
  ret;
}


__data_type **alloc_matrix(__data_type rows, __data_type cols){
  __data_type **matrix = (__data_type**)malloc(sizeof(__data_type*) * rows);
  for (__data_type i = 00; i < rows; ++i){
    *(matrix+i) = (__data_type*)malloc(sizeof(__data_type) * cols);
  }
  return matrix;
}


void dealloc_matrix(__data_type**restrict matrix, __data_type rows, __data_type cols){
  for (__data_type i = 00; i < rows; ++i)
    free((void*)matrix[i]); // free rows
  free((void*)matrix); // free matrix
}


void display_matrix(__data_type**restrict matrix, __data_type rows, __data_type cols){
  __data_type i, j;
  for (i = 00; i != rows; ++i){
    for (j = 00; j != cols; ++j){
      fprintf(stdout, __format_s, SEPARATION, matrix[i][j], SEPARATION); 
    }putc('\n', stdout);
  }
}


void *fill_2d_arr(Thread_struct_fill *arg){
  unsigned int seed = (unsigned int)time(NULL); //get seed
  srand(seed); // seed the RNG
  for (__data_type i = 00; i != arg->rows; ++i){
    for (__data_type j = 00; j != arg->cols; ++j){
      (arg->matrix)[i][j] = (rand() % RANGE) + MIN;
    }
  }
}


void *matrix_mult(Thread_struct_mult *arg){
  // change this function so it ill be accessed by multiple threads and each thread will work on some rows
  // write good algorithm ------>>>>( Mini Task scheduler)
}

