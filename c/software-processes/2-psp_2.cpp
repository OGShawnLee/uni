#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
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

enum class Shape {
  CIRCLE,
  INVALID,
  RECTANGLE,
  SQUARE,
  TRIANGLE_EQUILATERAL,
  TRIANGLE_ISOSCELES,
  TRIANGLE_SCALENE,
  UNSET,
};

enum class Option {
  CHECK_FIGURE,
  CALCULATE_FIGURE_AREA,
  EXIT,
};

const std::map<Shape, std::string> SHAPE_NAME_MAPPING = {
  {Shape::CIRCLE, "CIRCULO"},
  {Shape::INVALID, "INVALIDA"},
  {Shape::RECTANGLE, "RECTÁNGULO"},
  {Shape::SQUARE, "CUADRADO"},
  {Shape::TRIANGLE_EQUILATERAL, "TRIÁNGULO EQUILÁTERO"},
  {Shape::TRIANGLE_ISOSCELES, "TRIÁNGULO ISÓSCELES"},
  {Shape::TRIANGLE_SCALENE, "TRIÁNGULO ESCALENO"},
  {Shape::UNSET, "INDETERMINADA"},
};

std::string get_shape_name(const Shape &shape) {
  return SHAPE_NAME_MAPPING.at(shape);
}

std::string lowercase(const std::string &text) {
  std::string result = text;
  std::transform(result.begin(), result.end(), result.begin(), ::tolower);
  return result;
}

double get_circle_area(const double &big) {
  return M_PI * std::pow(big, 2);
}

Option get_option() {
  while (true) {
    println("1. Determine figura");
    println("2. Calcule área");
    println("3. Salir");

    auto option = get_input<std::string>("Seleccione una opción: ");
    if (option == "1" or option == "2" or option == "3") {
      return static_cast<Option>(std::stoi(option) - 1);
    } else {
      println("Opción inválida, intente de nuevo");
    }
  }
}

double get_rectangle_area(const double &big, const double &medium) {
  return big * medium;
}

double get_square_area(const double &big) {
  return std::pow(big, 2);
}

double get_triangle_area(const double &big, const double &medium, const double &small) {
  double s = (big + medium + small) / 2; // Semiperimeter
  return std::sqrt(s * (s - big) * (s - medium) * (s - small)); // Heron's formula
}

int main() {
  println("Examinador de Figuras y Calculador de Áreas");
  double big, medium, small;
  Shape figure = Shape::UNSET;

  while (true) {
    Option option = get_option();

    if (option == Option::EXIT) {
      println("Hasta la próxima");
      break;
    }

    if (option == Option::CHECK_FIGURE) {
      big = get_input<double>("Introduzca un valor para A: ");
      medium = get_input<double>("Introduzca un valor para B: ");
      small = get_input<double>("Introduzca un valor para C: ");
      order_descending(big, medium, small);
    
      if (is_invalid(big, medium, small)) {
        figure = Shape::INVALID;
        println("Los valores no indican figura");
      } else if (is_triangle(big, medium, small)) {
        if (small == medium && medium == big) {
          figure = Shape::TRIANGLE_EQUILATERAL;
          println("La figura es un triángulo equilátero");
        } else if (small == medium || medium == big) {
          figure = Shape::TRIANGLE_ISOSCELES;
          println("La figura es un triángulo isósceles");
        } else {
          figure = Shape::TRIANGLE_SCALENE;
          println("La figura es un triángulo escaleno");
        }
      } else if (is_square(big, medium, small)) {
        figure = Shape::SQUARE;
        println("La figura es un cuadrado");
      } else if (is_rectangle(big, medium, small)) {
        figure = Shape::RECTANGLE;
        println("La figura es un rectángulo");
      } else if (is_circle(big, medium, small)) {
        figure = Shape::CIRCLE;
        println("La figura es un círculo");
      } else {
        figure = Shape::INVALID;
        println("Los valores no indican figura");
      }
    } else if (option == Option::CALCULATE_FIGURE_AREA) {
      if (figure == Shape::INVALID or figure == Shape::UNSET) {
        println("Primero deberá determinar la figura en la opción 1");
      } else {
        double area = 0;
        switch (figure) {
          case Shape::CIRCLE:
            area = get_circle_area(big);
            break;
          case Shape::RECTANGLE:
            area = get_rectangle_area(big, medium);
            break;
          case Shape::SQUARE:
            area = get_square_area(big);
            break;
          case Shape::TRIANGLE_EQUILATERAL:
          case Shape::TRIANGLE_ISOSCELES:
          case Shape::TRIANGLE_SCALENE:
            area = get_triangle_area(big, medium, small);
            break;
          default:
            break;
        }
        println("El área del " + get_shape_name(figure) + " es " + std::to_string(area));
      }
    }
  }

  return 0;
}