#include "utils.h"

size_t binary_search(int arr[], size_t len, int value) {
  size_t left = 0;
  size_t right = len - 1;
  size_t middle;

  while (left <= right) {
    middle = (left + right) / 2;

    if (arr[middle] == value) {
      return middle;
    } else if (arr[middle] < value) {
      left = middle + 1;
    } else {
      right = middle - 1;
    }
  }

  return -1;
}

int main() {
  int arr_int[] = { 1, 2, 3, 4, 5 };

  print_arr("Array", arr_int, 5);

  while (true) {
    auto value = get_input<int>("Enter a number to search");
    size_t index = binary_search(arr_int, 5, value);

    if (index == -1) {
      println("Value not found");
    } else {
      println("Value found at index " + std::to_string(index));
    }

    if (get_bool("Do you want to search another number?") == false) {
      println("Goodbye!");
      break;
    }
  }

  return 0;
}