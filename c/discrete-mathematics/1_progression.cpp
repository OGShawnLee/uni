#include <iostream>
#include <cmath>

using namespace std;

void print(string message) {
  cout << message;
}

void println(string message) {
  cout << message << endl;
}

template <typename T>
void print_arr(T arr[], int LEN) {
  cout << "[" << arr[0];
  for (int i = 1; i < LEN - 1; i++) {
    cout << ", " << arr[i];
  }
  cout << ", " << arr[LEN - 1] << "]" << endl;
}

int main() {
  int LEN = 6;
  int arr_int[LEN];

  // (-1) ^ i , i >= 1
  for (int i = 0; i < LEN; i++) {
    arr_int[i] = pow((-1), i + 1);
  }

  print_arr(arr_int, LEN);

  string arr_str[LEN];

  // i - 1 / i pow 2 , i >= 2 
  for (int i = 0; i < LEN; i++) {
    int i_sqr = static_cast<int>(pow(i + 2, 2));
    arr_str[i] = to_string((i + 2) - 1) + " / " + to_string(i_sqr);
  }

  print_arr(arr_str, LEN);

  // 0, 1, -2, 3, -3, 5 
  // UFF
  
  // i pow 2 / 3 pow i , i >= 1
  for (int i = 0; i < LEN; i++) {
    int i_sqr = static_cast<int>(pow(i + 1, 2));
    int i_pow_3 = static_cast<int>(pow(3, i + 1));
    arr_str[i] = to_string(i_sqr) + " / " + to_string(i_pow_3);
  }

  print_arr(arr_str, LEN);

  return 0;
}