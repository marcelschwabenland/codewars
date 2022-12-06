#include <stdio.h>
#include <stddef.h>

void printArray(int *nums, int numsSize) {
  printf("[ ");
  for(size_t i = 0; i < numsSize; i++){
    if(i + 1 == numsSize) {
      printf("%d ", nums[i]);
    } else {
      printf("%d, ", nums[i]);
    }    
  }
  printf("]\n");
}

void move_zeros(size_t len, int *arr) {
  int remember;

  if(len == 0 || len == 1) {
    return;
  }

  for(int i = 0; i < len; i++) {
    if(arr[i] == 0) {
      int a = arr[i];
      for(int j = i; j < len; j++) {
        int b = arr[j];
        if(arr[j] != 0) {
          remember = arr[j];
          arr[j] = arr[i];
          arr[i] = remember;
          i++;
          printArray(arr, len);
        }
      }
    }
  }
}

int main(int argc, char const *argv[])
{
  int arr[] = {9, 0, 0, 9, 1, 2, 0, 1, 0, 1, 0, 3, 0, 1, 9, 0, 0, 0, 0, 9};

  move_zeros(20, arr);

  return 0;
}
