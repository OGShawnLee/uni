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

int main() {
  printf("Factorial of 5 is: %d\n", factorial(5));
  printf("Fibonacci of 10 is: %d\n", fibonacci(10));

  std::cout << "Countdown" << std::endl;
  countdown(10);

  std::cout << "Countup to 100" << std::endl;
  countup(1);

  std::cout << "Countup to 10" << std::endl;
  countup_to(1, 10);
}
