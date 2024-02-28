#include <iostream>

int get_int_arr_sum(int int_arr[], size_t len) {
  int count = int_arr[0];
  for (size_t i = 1; i < len; i++) {
    count += int_arr[i];
  }
  return count;
}

int get_int_arr_sum_rec(int arr[], size_t len) {
  if (len == 0) return 0;

  return arr[len - 1] + get_int_arr_sum_rec(arr, len - 1);
}
 
int main() {
  size_t len = 5;
  int int_arr[] = { 1, 2, 3, 4, 5 };
  int count = get_int_arr_sum(int_arr, len);
  printf("Sum of int_arr is: %d\n", count);

  count = get_int_arr_sum_rec(int_arr, len);
  printf("Sum of int_arr recursive is: %d\n", count);

  int int_arr_b[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

  count = get_int_arr_sum(int_arr_b, 10);
  printf("Sum of int_arr is: %d\n", count);

  count = get_int_arr_sum_rec(int_arr_b, 10);
  printf("Sum of int_arr recursive is: %d\n", count);

  return 0;
}