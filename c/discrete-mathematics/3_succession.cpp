#include <iostream>

// Rn = Rn + 4Rn - 1; n >= 1; R0 = 1

int main() {
  int count = 1;
  int limit = 10;

  for (int i = 1; i <= limit; i++) {
    printf("Mes %d: %d pares de conejos\n", i, count);
    count = count + 4 * count;
  }

  return 0;
}