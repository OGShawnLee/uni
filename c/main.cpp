#include "utils.cpp"
#include <iostream>
#include <cmath>

void run_first_task_solution() {
    string name = get_string("What is your name?");
    int age = get_int("What is your age?");
    float height = get_float("What is your height? (metres)");
    string gender = get_string("What is your gender? (M/F)");
    string crime = get_string("What was your crime?");

    name = capitalise(name);
    gender = capitalise(gender);
    crime = capitalise(crime);

    report_value("Name", name);
    report_value("Age", age);
    report_value("Height", height);
    report_value("Gender", gender);
    report_value("Crime", crime);
}

void run_second_task_solution() {
    float a = get_float("Enter a number for a");
    float b = get_float("Enter a number for b");
    float c = get_float("Enter a number for c");
    float d = get_float("Enter a number for d");
    float e = get_float("Enter a number for e");
    float f = get_float("Enter a number for f");

    float result = (a + b) / (c + d);
    report_value("Result of (a + b) / (c + d)", result);
    
    result = (a + (b / c)) / (d + (e / f));
    report_value("Result of (a + (b / c)) / (d + (e / f))", result);
    
    result = a + (b / (c - d));
    report_value("Result of a + (b / (c - d))", result);
}

void run_third_task_solution() {
    double a = get_double("Enter a number for a");
    double b = get_double("Enter a number for b");
    double z = get_double("Enter a number for z");

    double result = pow(a, 3) + pow(b, 4) + sqrt(z);
    report_value("Result of pow(a, 3) + pow(b, 4) + sqrt(z)", result);
}

void run_fourth_task() {
    uint age = get_uint("Enter your age in years");
    
    if (is_outside_range(age, 0, 130)) {
        println("Your age must be between 0 and 130");
    } else {
        if (is_in_range(age, 18, 25)) {
            println("You are in the 18-25 age group");
        } else if (is_in_range(age, 50, 55)) {
            println("You are in the 50-55 age group");
        } else {
            println("You are not in the 18-25 or 50-55 age groups");
        }
    }

    int rating = get_int("What was your rating?");

    if (is_outside_range(rating, 0, 10)) {
        println("Your rating must be between 0 and 10");
    } else {
        if (rating == 10 || rating == 9) println("Notable");
        else if (rating == 8) println("Aproved");
        else if (rating == 7 || rating == 6) println("Good");
        else println("You must study more!");
    }

    int x = get_float("Enter a number for x");
    int y = get_float("Enter a number for y");

    if (x == 0 || y == 0) {
        println("x and y must be non-zero");
    } else {
        printf("2 + (3 * %f) = %f\n", x, 2 + (3 * x));
        printf("3 * (2 + %f) = %f\n", y, 3 * (2 + y));
    }

    int a = get_int("Enter a number for a");
    int b = get_int("Enter a number for b");
    int c = get_int("Enter a number for c");

    if (a == b && b == c) {
        println("Ordered the same");
    } else if (a >= b && b >= c) {
        println("Descending Order");
    } else if (a <= b && b <= c) {
        println("Ascending Order");
    } else {
        println("Unordered");
    }
}

int main() {
    // run_first_task_solution();
    // run_second_task_solution();
    // run_third_task_solution();
    run_fourth_task();

    return 0;
}