#include <iostream>

int factorial(int n) {
  if (n <= 1) return 1;

  return n * factorial(n - 1);
}

int fibonacci(int n) {
  if (n <= 1) return n;

  return fibonacci(n - 1) + fibonacci(n - 2);
}

// n - 1, n - 2, ... 1
int countdown(int n){
  std::cout << n << std::endl;

  if (n <= 1) return 1;

  return countdown(n - 1);
}

// 1, 2, ... n
int countup(int n){
  std::cout << n << std::endl;

  if (n >= 100) return n;

  return countup(n + 1);
}

// 1, 2, 3, 4, 5, ...n - 1, n
int countup_to(int n, int max) {
  std::cout << n << std::endl;

  if (n >= max) return n;

  return countup_to(n + 1, max);
}

int power(int base, int exponent) {
  if (exponent == 0) return 1;

  return base * power(base, exponent - 1);
}

int digit_len(int n) {
  if (n < 10) return 1;

  return 1 + digit_len(n / 10);
}

int main() {
  printf("Factorial of 5 is: %d\n", factorial(5));
  printf("Fibonacci of 10 is: %d\n", fibonacci(10));

  std::cout << "Countdown" << std::endl;
  countdown(10);

  std::cout << "Countup to 100" << std::endl;
  countup(1);

  std::cout << "Countup to 10" << std::endl;
  countup_to(1, 10);

  printf("3 pow 3 is: %d\n", power(3, 3));
  printf("9 pow 2 is: %d\n", power(9, 2));
  printf("The digit length of 14 is: %d\n", digit_len(14));
  printf("The digit length of 149 is: %d\n", digit_len(149));
  printf("The digit length of 1492 is: %d\n", digit_len(1492));
}
