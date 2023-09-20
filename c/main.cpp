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

int main() {
    // run_first_task_solution();
    // run_second_task_solution();
    run_third_task_solution();

    return 0;
}