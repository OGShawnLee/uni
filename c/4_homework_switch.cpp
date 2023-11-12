#include "utils.cpp"
#include <string>

int main() {
    println("Currency Converter (from USD)");
    println("1. EUR");
    println("2. GBP");
    println("3. JPY");
    println("4. MXN");
    println("5. Exit");

    int option = get_input<int>("Enter an option");

    if (option != 5) {
        double amount = get_input<double>("Enter the amount of USD");
        double converted_amount;
        std::string name;
        
        switch (option) {
            case 1:
                name = "EUR";
                converted_amount = amount * 0.94;
                break;
            case 2:
                name = "GBP";
                converted_amount = amount * 0.82;
                break;
            case 3:
                name = "JPY";
                converted_amount = amount * 148.88;
                break;
            case 4:
                name = "MXN";
                converted_amount = amount * 18.04;
                break;
            default:
                println("Invalid option");
        }

        printf("%.3f USD = %.3f %s\n", amount, converted_amount, name.c_str());
    }

    println("Area Calculator");
    println("1. Square");
    println("2. Rectangle");
    println("3. Triangle");
    println("4. Circle");
    println("5. Trapazoid");
    println("6. Exit");

    option = get_input<int>("Enter an option");

    if (option != 6) {
        double area;
        std::string shape_name;

        switch (option) {
        case 1: {
            double side = get_input<double>("Enter the side length");
            area = side * side;
            shape_name = "Square";
            break;
        }
        case 2: {
            double length = get_input<double>("Enter the length");
            double width = get_input<double>("Enter the width");
            area = length * width;
            shape_name = "Rectangle";
            break;
        }
        case 3: {
            double base = get_input<double>("Enter the base");
            double height = get_input<double>("Enter the height");
            area = base * height / 2;
            shape_name = "Triangle";
            break;
        }
        case 4: {
            double radius = get_input<double>("Enter the radius");
            area = 3.14159 * radius * radius;
            shape_name = "Circle";
            break;
        }
        case 5: {
            double base1 = get_input<double>("Enter the first base");
            double base2 = get_input<double>("Enter the second base");
            double height = get_input<double>("Enter the height");
            area = (base1 + base2) / 2 * height;
            shape_name = "Trapazoid";
            break;
        }
        default:
            println("Invalid option");
        }

        printf("The area of the %s is %.3f\n", shape_name.c_str(), area);
    }

    return 0;
}