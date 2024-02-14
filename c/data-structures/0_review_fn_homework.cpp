#include <iostream>

using namespace std;

int find_index_of(int arr[], int len, int value) {
  for (int i = 0; i < len; i++) {
    if (arr[i] == value) return i;
  }

  return -1;
}

void sort(int arr[], int len) {
  for (int i = 0; i < len - 1; i++) {
    int minimum = i;
   
    for (int j = i + 1; j < len; j++) {
      if (arr[j] < arr[minimum]) minimum = j;
    }

    if (minimum != i) {
      int current = arr[i];
      arr[i] = arr[minimum];
      arr[minimum] = current;
    }
  }
}

void print_arr(string message, int arr[], int len) {
  cout << message << ": ";
  cout << "[" << arr[0];
  for (int i = 1; i < len - 1; i++) {
    cout << ", " << arr[i];
  }
  cout << ", " << arr[len - 1] << "]" << endl;
}

void println(string message) {
  cout << message << endl;
}

int LENGTH = 5;

int main() {
  int arr_int[] = { 3, 4, 1, 2, 5 };
  print_arr("Array used", arr_int, LENGTH);
  int index = find_index_of(arr_int, LENGTH, 1);

  // value exists
  printf("Index of 1: %d\n", index); 
  if (index == -1) {
    println("Value not found");
  } else {
    println("Value found");
  }

  // value does not exist
  index = find_index_of(arr_int, LENGTH, 6);
  printf("Index of 6: %d\n", index);
  if (index == -1) {
    println("Value not found"); 
  } else {
    println("Value found");
  }

  print_arr("Before sort", arr_int, LENGTH);
  sort(arr_int, LENGTH);
  print_arr("After sort", arr_int, LENGTH);

  return 0;
}