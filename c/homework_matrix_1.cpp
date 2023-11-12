#include <iostream>

using namespace std;

const size_t MAX_LEN = 15;

void prompt(string str = "") {
  if (str != "") cout << str << ": ";
}

char get_char(string message = "") {
  char ch;
  prompt(message);
  cin >> ch;
  return ch;
}

size_t get_matrix_len(string message = "") {
  size_t len;
  prompt(message);
  cin >> len;

  if (len > MAX_LEN) {
    printf("Length must be less than %zu. Length truncated to %zu\n", MAX_LEN, MAX_LEN);
  }

  return len;
}

void println(string str = "") {
  cout << str << endl;
}

void print_array(size_t len, int arr[]) {
  if (len == 0) {
    cout << "[]" << endl;
    return;
  }

  if (len == 1) {
    cout << "[" << arr[0] << "]" << endl;
    return;
  }

  cout << "[" << arr[0] << ", ";
  for (size_t i = 1; i < len - 1; i++) {
    cout << arr[i] << ", ";
  }
  cout << arr[len - 1] << "]" << endl;
}

// find an element in a matrix and prints its position
// if not found, prints a message
void print_found_matrix_element(size_t rows, size_t cols, int matrix[MAX_LEN][MAX_LEN], int integer) {
  bool not_found = true;

  for (size_t i = 0; i < rows; i++) {
    for (size_t j = 0; j < cols; j++) {
      if (matrix[i][j] == integer) {
        printf("Found %d at position (%zu, %zu)\n", integer, i, j);
        not_found = false;
      }
    }
  }

  if (not_found) {
    printf("Integer %d not found\n", integer);
  }
}

void print_matrix(size_t rows, size_t cols, int matrix[MAX_LEN][MAX_LEN]) {
  for (size_t i = 0; i < rows; i++) {
    print_array(cols, matrix[i]);
  }
}

int get_int(string message = "") {
  int num;
  prompt(message);
  cin >> num;
  return num;
}

int get_random_in_range(int min, int max) {
  return rand() % (max - min + 1) + min;
}

// fill a matrix with random integers or manually
void fill_matrix(size_t size, int matrix[MAX_LEN][MAX_LEN], char fill_mode) {
  if (fill_mode == 'a') {
    for (size_t i = 0; i < size; i++) {
      for (size_t j = 0; j < size; j++) {
        matrix[i][j] = get_random_in_range(0, 9);
      }
    }
  } else if (fill_mode == 'm') {
    for (size_t i = 0; i < size; i++) {
      for (size_t j = 0; j < size; j++) {
        printf("Enter the element at position (%zu, %zu): ", i, j);
        matrix[i][j] = get_int();
      }
    }
  } else {
    println("Invalid fill mode");
    fill_matrix(size, matrix, get_char("Enter the fill mode (a - auto, m - manual)"));
  }
}

void set_addition(
  size_t size, 
  int a[MAX_LEN][MAX_LEN], 
  int b[MAX_LEN][MAX_LEN], 
  int c[MAX_LEN][MAX_LEN]
) {
  for (size_t i = 0; i < size; i++) {
    for (size_t j = 0; j < size; j++) {
      c[i][j] = a[i][j] + b[i][j];
    }
  }
}

int main() {
  println("1. Filling matrix manually");
  size_t size = get_matrix_len("Enter the size of the matrix");
  int matrix[MAX_LEN][MAX_LEN];
  fill_matrix(size, matrix, 'm');
  println("Matrix A:");
  print_matrix(size, size, matrix);

  println("2. Finding integer in matrix");
  int target = get_int("Enter the target to find");
  print_found_matrix_element(size, size, matrix, target);

  println("3. Filling matrix with random integers");
  int matrix_random[MAX_LEN][MAX_LEN];
  fill_matrix(size, matrix_random, 'a');
  println("Matrix B:");
  print_matrix(size, size, matrix_random);

  println("4. Performing matrix addition with previous matrices");
  int matrix_addition[MAX_LEN][MAX_LEN];
  set_addition(size, matrix, matrix_random, matrix_addition);
  println("Matrix C (A + B):");
  print_matrix(size, size, matrix_addition);

  return 0;
}