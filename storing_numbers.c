#include <stdio.h>
#include <stdlib.h>

int* generate_array_of_ints(int upper_limit);

int main(){
  int* a = generate_array_of_ints(100);
  printf("%lu\n", sizeof(a));
  int length = 101;
  for(int i=0; i<length; i++){
    printf("%d\n", a[i]);
  }
  return 0;
}

int* generate_array_of_ints(int upper_limit){
  int* int_array = (int*) calloc(sizeof(int) * upper_limit);
  for(int i=0; i<upper_limit; i++){
    int_array[i] = i + 1;
  }
  return int_array;
}
