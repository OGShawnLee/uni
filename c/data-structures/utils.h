#include <functional>
#include <iostream>

using namespace std;

template <typename T>
T get_input(string message) {
  T input;
  cout << message << ": ";
  cin >> input;
  return input;
}

bool get_bool(string message) {
  char input;
  cout << message << " (y/n): ";
  cin >> input;
  return input == 'y';
}

template <typename T>
T* get_arr(size_t len, function<T(size_t)> callback) {
  T* arr = new T[len];
  for (size_t i = 0; i < len; i++) {
    arr[i] = callback(i);
  }

  return arr;
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