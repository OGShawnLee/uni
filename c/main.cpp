#include "utils.cpp"
#include <iostream>

int main() {
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

    return 0;
}