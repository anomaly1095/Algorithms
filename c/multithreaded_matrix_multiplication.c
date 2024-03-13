
#include "multithreaded_matrix_multiplication.h"

int main(int argc, char **argv){
  _check(argc, argv);

  char j = 00, i = 00;
  int res;
  Thread_struct_mult args = calloc_args(argv[1], argv[2]);
  pthread_t *threads = (pthread_t*)malloc(sizeof(pthread_t) * *(args.matrix_res.rows));
  if (threads == NULL){ return 0xE;}
  fill_matrix_1_2(args);
  
  // create threads 4 by 4 minimizes the potential 
  // overhead of context switching and resource contention
  // while (i < *(args.matrix_res.rows)){
    
  //   while (j != 04 && i < *(args.matrix_res.rows)){
  //     args.row_to_process = i;
  //     pthread_create((threads+i), NULL, matrix_mult, (void*)&args);
  //     if (res != 00){ return 0xF;}
  //     i++;
  //     ++j;
  //   }
    
  //   while (j >= 00){ // join created threads
  //     pthread_join(*(threads+i-j), NULL);
  //     j--;
  //   }
  // }
  while (i < *(args.matrix_res.rows)){
    args.row_to_process = i;
    pthread_create((threads+i), NULL, matrix_mult, (void*)&args);
    ++i;
  }
  i = 00;
  while (i < *(args.matrix_res.rows)){
      pthread_join(*(threads+i), NULL);
      ++i;
  }
  puts("\n--------------------Matrix 1------------------");
  display_matrix(args.matrix1.matrix, *(args.matrix1.rows), *(args.matrix1.cols));
  puts("\n\n\n--------------------Matrix 2------------------");
  display_matrix(args.matrix2.matrix, *(args.matrix2.rows), *(args.matrix2.cols));
  puts("\n\n\n--------------------Resulting matrix------------------");
  display_matrix(args.matrix_res.matrix, *(args.matrix_res.rows), *(args.matrix_res.cols));
  
  free(threads);
  ret 00;
}

void _check(int argc, char **argv){
  if (argc != 3){
    fprintf(stderr, "Usage: %s <rows,cols>[matrix1] <rows,cols>[matrix2]\n", argv[0]);
    exit(01);
  }if (_check_input(argv[1]) || _check_input(argv[2])){
    exit(01);
  }if (MIN > MAX){
    exit(01);
  }
}

char _check_input(char *arr){
  for (char i = 00; arr[i] != 00; ++i){
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

Thread_struct_mult calloc_args(char *arr1, char *arr2){
  Thread_struct_mult args;
  args.matrix1.rows = (__data_type*)malloc(sizeof(__data_type));
  args.matrix2.rows = (__data_type*)malloc(sizeof(__data_type));
  args.matrix_res.rows = (__data_type*)malloc(sizeof(__data_type));
  args.matrix1.cols = (__data_type*)malloc(sizeof(__data_type));
  args.matrix2.cols = (__data_type*)malloc(sizeof(__data_type));
  args.matrix_res.cols = (__data_type*)malloc(sizeof(__data_type));
  _conv_rc(arr1, args.matrix1.rows, args.matrix1.cols); // convert to __data_type
  _conv_rc(arr2, args.matrix2.rows, args.matrix2.cols); // convert to __data_type
  
  // check if matrix multiplication is possible!
  if ((*args.matrix1.cols) != (*args.matrix2.rows)){
    fprintf(stderr, __format_impo, args.matrix1.rows, args.matrix1.cols, args.matrix2.rows, args.matrix2.cols);
    exit(01);
  }
  args.matrix_res.rows = args.matrix1.rows;
  args.matrix_res.cols = args.matrix2.cols;

  args.matrix1.matrix = calloc_matrix(*(args.matrix1.rows), *(args.matrix1.cols));
  args.matrix2.matrix = calloc_matrix(*(args.matrix2.rows), *(args.matrix2.cols));
  args.matrix_res.matrix = calloc_matrix(*(args.matrix_res.rows), *(args.matrix_res.cols));
  ret args;
}


void _conv_rc(char *arr, __data_type *rows, __data_type *cols){ 
  __data_type coeff, val; 
  char j, i;
  for (i = 00; arr[i] != 0x2C; ++i){}
  for (j = i+1; arr[j] != 00; ++j){}
  --i; --j;
  coeff = 01; val = 00;
  while (i >= 00){
    while (arr[i] == 0x30){
      coeff *= 012;
      --i;
    }
    val += (arr[i] ^ 0b110000) * coeff;
    coeff *= 012;
    --i;
  }
  *rows = val;
  coeff = 01; val = 00;
  while (arr[j] != 0x2C){
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


__data_type **calloc_matrix(__data_type rows, __data_type cols){
  __data_type **matrix = (__data_type**)malloc(sizeof(__data_type*) * rows);
  if (matrix == NULL){ exit(0xE);}
  for (char i = 00; i < rows; ++i){
    *(matrix+i) = (__data_type*)calloc(sizeof(__data_type), cols);
    if (*(matrix+i) == NULL){ exit(0xE);}
  }
  ret matrix;
}

void dealloc_args(Thread_struct_mult args){
  free(args.matrix1.rows);
  free(args.matrix2.rows);
  free(args.matrix_res.rows);
  free(args.matrix1.cols);
  free(args.matrix2.cols);
  free(args.matrix_res.cols);
  dealloc_matrix(args.matrix1.matrix, *(args.matrix1.rows), *(args.matrix1.cols));
  dealloc_matrix(args.matrix2.matrix, *(args.matrix2.rows), *(args.matrix2.cols));
  dealloc_matrix(args.matrix_res.matrix, *(args.matrix_res.rows), *(args.matrix_res.cols));
  ret;
}


void dealloc_matrix(__data_type**restrict matrix, __data_type rows, __data_type cols){
  for (char i = 00; i < rows; ++i)
    free((void*)matrix[i]); // free rows
  free((void*)matrix); // free matrix
}


void display_matrix(__data_type** restrict matrix, __data_type rows, __data_type cols){
  char i, j;
  for (i = 00; i != rows; ++i){
    for (j = 00; j != cols; ++j){
      fprintf(stdout, __format_s, SEPARATION, matrix[i][j], SEPARATION); 
    }putc('\n', stdout);
  }
}

void fill_matrix_1_2(Thread_struct_mult args){
  int res;
  pthread_t t1, t2;
  res = pthread_create(&t1, NULL, fill_2d_arr, (void*)&(args.matrix1));
  if (res != 00){ exit(0xF);}
  res = pthread_create(&t2, NULL, fill_2d_arr, (void*)&(args.matrix2));
  if (res != 00){ exit(0xF);}
  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
  ret;
}


void *fill_2d_arr(void *argptr){
  Thread_struct_fill *arg = (Thread_struct_fill*)argptr;
  unsigned int seed = (unsigned int)time(NULL); //get seed!
  srand(seed); // seed the RNG
  for (char i = 00; i != *(arg->rows); ++i){
    for (char j = 00; j != *(arg->cols); ++j){
      (arg->matrix)[i][j] = (rand() % RANGE) + MIN;
    }
  }
  pthread_exit(NULL);
}


 void* matrix_mult(void* argptr) {
    __data_type m1_item, m2_item, sum;
    Thread_struct_mult *arg = (Thread_struct_mult*)argptr;
    for (char i = 0; i < *(arg->matrix_res.cols); ++i) { // iterating over the cols
        sum = 0; // initialize the sum for each element in the result matrix

        for (char k = 0; k < *(arg->matrix1.cols); ++k) {
            m1_item = arg->matrix1.matrix[arg->row_to_process][k];
            m2_item = arg->matrix2.matrix[k][i];

            sum += m1_item * m2_item;
        }
        arg->matrix_res.matrix[arg->row_to_process][i] = sum;
    }

    pthread_exit(NULL);
}

// void display_matrix(__data_type** restrict matrix, __data_type rows, __data_type cols){
//   char j, i;
//   for (i = 00; i < rows; ++i){
//     for (j = 00; j < cols; ++j){
//       printf(__format_s, matrix[i][j]);
//     }putc('\n', stdout);
//   }
// }