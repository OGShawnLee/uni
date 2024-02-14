#include <iostream>
#include <functional>

using namespace std;

template <typename T>
T get_input(string message) {
  T input;
  cout << message << ": ";
  cin >> input;
  return input;
}

template <typename T>
T* get_arr(size_t len, function<T(size_t)> callback) {
  T* arr = new T[len];
  for (size_t i = 0; i < len; i++) {
    arr[i] = callback(i);
  }

  return arr;
}

template <typename T>
bool is_included(size_t len, T arr[], T value) {
  for (size_t i = 0; i < len; i++) {
    if (arr[i] == value) return true;
  }

  return false;
}

int get_biggest(size_t len, int arr[]) {
  int biggest = arr[0];
  for (size_t i = 1; i < len; i++) {
    if (arr[i] > biggest) biggest = arr[i];
  }

  return biggest;
}

template <typename T>
void print_arr(size_t len, T arr[]) {
  cout << "[" << arr[0];
  for (size_t i = 1; i < len - 1; i++) {
    cout << ", " << arr[i];
  }
  cout << ", " << arr[len - 1] << "]" << endl;
}

void println(string message) {
  cout << message << endl;
}

bool is_sorted(size_t len, int arr[]) {
  for (size_t i = 1; i < len; i++) {
    if (arr[i] < arr[i - 1]) return false;
  }

  return true;
}

int main() {
  auto len = get_input<size_t>("Enter the length of the array");
  auto arr = get_arr<int>(len, [](size_t i) {
    return get_input<int>("Enter a number");
  });
  auto value = get_input<int>("Enter a number to search");
  
  printf("The array is: ");
  print_arr(len, arr);

  if (is_included(len, arr, value)) {
    printf("The number %d is in the array\n", value);
  } else {
    printf("The number %d is not in the array\n", value);
  }

  if (is_sorted(len, arr)) {
    println("The array is sorted");
  } else {
    println("The array is not sorted");
  }

  delete[] arr;

  return 0;
}