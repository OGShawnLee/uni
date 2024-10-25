#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
T get_input(const std::string &prompt) {
  T value;
  std::cout << prompt;
  std::cin >> value;
  return value;
}

void order_descending(double &a, double &b, double &c) {
  std::vector<double> values = {a, b, c};
  std::sort(values.begin(), values.end(), std::greater<double>());
  a = values[0];
  b = values[1];
  c = values[2];
}

void println(const std::string &message) {
  std::cout << message << std::endl;
}

bool is_circle(const double &big, const double &medium, const double &small) {
  return big > 0 and medium == 0 and small == 0;
}

bool is_invalid(const double &big, const double &medium, const double &small) {
  return big <= 0 and medium <= 0 and small <= 0;
}

bool is_rectangle(const double &big, const double &medium, const double &small) {
  return big > 0 and medium > 0 and small == 0;
}

bool is_square(const double &big, const double &medium, const double &small) {
  return big == medium && small == 0;
}

bool is_triangle(const double &big, const double &medium, const double &small) {
  return big > 0 && medium > 0 && small > 0 && big + medium > small && big + small > medium && medium + small > big;
}

int main() {
  println("Examinador de Figuras y Calculador de Áreas");

  while (true) {
    auto big = get_input<double>("Introduzca un valor para A: ");
    auto medium = get_input<double>("Introduzca un valor para B: ");
    auto small = get_input<double>("Introduzca un valor para C: ");
    order_descending(big, medium, small);
  
    if (is_invalid(big, medium, small)) {
      println("Los valores no indican figura");
    } else if (is_triangle(big, medium, small)) {
      if (small == medium && medium == big) {
        println("La figura es un triángulo equilátero");
      } else if (small == medium || medium == big) {
        println("La figura es un triángulo isósceles");
      } else {
        println("La figura es un triángulo escaleno");
      }
    } else if (is_square(big, medium, small)) {
      println("La figura es un cuadrado");
    } else if (is_rectangle(big, medium, small)) {
      println("La figura es un rectángulo");
    } else if (is_circle(big, medium, small)) {
      println("La figura es un círculo");
    } else {
      println("Los valores no indican figura");
    }
  }

  return 0;
}