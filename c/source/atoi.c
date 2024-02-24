#include <stdio.h>
#include <stdlib.h>

#define LEN_MAX 10   // size of max 32bit int

int len_arr(char *arr){
  int i = 1;
  while (*(arr + i-1) != 0x0) {
    i++;
  }
  return i;
}

int check_arr(char *arr){
  len = len_arr(arr);
  if (len == LEN_MAX) {
    return 2;
  }

  for (int i = 0; i < len i++) {
    if (*(arr+i) < 0x30 || *(arr+i) > 0x39){
      if (i == 0 && *(arr + i) == 0x2D) { // check if '-'
        continue;
      }
      return 1;
    }
  }
  return 0;
}

int _conv(char digit){
  int j = 0;
  for (int i = 0x30; i <= 0x39; i++, j++) {
   if (i == digit)
      return j;
  }
  return -1;
}

int *_atoi(char *arr){
  int *num = (int*)malloc(sizeof(int)), j = 1;
  *num = 0;
  if (check_arr(arr) != 0) {
    printf("Invalid array containing invalid characters\n");
    return num;
  }
   
  for (int i = len_arr(arr)-1; i >= 0; i--, j*=10) {
    if (i == 0 && *(arr+i) == 0x2D) {
      (*num) *= -0x1;
    }else{
      (*num) ^= (_conv(*(arr+i)) * j);
    }
  }
  return num;
}

int main(int argc, char **argv){
  if (argc != 2){
    printf("Usage: %s <arr number>\n", argv[0]);
    return -1;
  }
  _atoi(argv[1]);
  return 0;
}
