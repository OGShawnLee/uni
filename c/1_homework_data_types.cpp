#include "utils.cpp"
#include <iostream>
#include <string>
#include <cmath>

int main() {
    println("Criminal Database");
    auto name = get_input<std::string>("What is your name?");
    auto age = get_input<int>("What is your age?");
    auto height = get_input<float>("What is your height in metres?");
    auto weight = get_input<float>("What is your weight in kilograms?");
    auto gender = get_input<char>("What is your gender? (M/F)");
    auto crime = get_input<std::string>("What was your crime?");

    name = capitalise(name);
    gender = toupper(gender);
    crime = capitalise(crime);

    println();

    report_value("Name", name);
    printf("Age: %d years\n", age);
    printf("Height: %.3f metres\n", height);
    printf("Weight: %.3f kilograms\n", weight);
    report_value("Gender", gender);
    report_value("Crime", crime);

    println();

    println("Mathematical Expressions");
    auto a = get_input<float>("Enter a number for a");
    auto b = get_input<float>("Enter a number for b");
    auto c = get_input<float>("Enter a number for c");
    auto d = get_input<float>("Enter a number for d");
    auto e = get_input<float>("Enter a number for e");
    auto f = get_input<float>("Enter a number for f");

    println();

    float result = (a + b) / (c + d);
    printf("(a + b) / (c + d) = %.3f\n", result);

    result = (a + (b / c)) / (d + (e / f));
    printf("(a + (b / c)) / (d + (e / f)) = %.3f\n", result);

    result = a + (b / (c - d));
    printf("a + (b / (c - d)) = %.3f\n", result);

    println();

    auto x = get_input<double>("Enter a number fo x");
    auto y = get_input<double>("Enter a number fo y");
    auto z = get_input<double>("Enter a number fo z");
    double total = pow(a, 3) + pow(b, 4) + sqrt(z);

    println();
    
    printf("pow(a, 3) + pow(b, 4) + sqrt(z) = %.3f\n", total);

    return 0;
}