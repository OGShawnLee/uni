#include <iostream>
#include <functional>
#include <cmath>

using namespace std;

// get limit for a summation
size_t get_limit(string message) {
  cout << message << ": ";
  size_t len;
  cin >> len;
  return len;
}

int get_random_int_in_range(int min, int max) {
  return rand() % (max - min + 1) + min;
}

void println(string message) {
  cout << message << endl;
}

int main() {
  size_t limit_n = get_limit("Enter the limit of the first summation");
  int count = 0;
  // get the sum
  for (size_t i = 1; i <= limit_n; i++) {
    for (size_t j = 1; j <= i; j++) {
      count += pow(i, 2) * j;
    }
  }
  println("The sum is: " + to_string(count));

  size_t limit_m = get_limit("Enter the limit of the second summation");
  count = 0;
  int matrix[limit_m][limit_n];
  // fill the matrix and get the sum
  for (size_t i = 0; i < limit_m; i++) {
    for (size_t j = 0; j < limit_n; j++) {
      // set a random number in the matrix
      matrix[i][j] = get_random_int_in_range(1, 10);
      // add the number to the sum
      count += matrix[i][j];
    }
  }

  // print the matrix
  println("The matrix is:");
  for (size_t i = 0; i < limit_m; i++) {
    printf("[%d, ", matrix[i][0]);
    for (size_t j = 1; j < limit_n - 1; j++) {
      printf("%d, ", matrix[i][j]);
    }
    printf("%d]\n", matrix[i][limit_n - 1]);
  }

  println("The matrix sum is: " + to_string(count));

  return 0;
}