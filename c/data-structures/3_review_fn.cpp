#include <iostream>

void clear_arr(int arr[], size_t len) {
  for (size_t i = 0; i < len; i++) {
    arr[i] = 0;
  }
}

void increment(int &count) {
  count++;
}

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

int main() {
  size_t len = 5;
  int arr[] = { 1, 2, 3, 4, 5 };
  
  printf("Before Swap:\n");
  printf("arr[0] is: %d\n", arr[0]);
  printf("arr[1] is: %d\n", arr[1]);
  
  swap(arr[0], arr[1]);
  
  printf("After Swap:\n");
  printf("arr[0] is: %d\n", arr[0]);
  printf("arr[1] is: %d\n", arr[1]);
  
  clear_arr(arr, len);
  
  int count = 0;
  
  increment(count);
  printf("Count is: %d\n", count);
  return 0;  
}