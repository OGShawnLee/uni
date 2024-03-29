#include <string>
#include <iostream>

using namespace std;

string capitalise(string str) {
    str[0] = toupper(str[0]);
    return str;   
}

double get_double(string prompt) {
    double d;
    cout << prompt << ": ";
    cin >> d;
    return d;
}

float get_float(string prompt) {
    float f;
    cout << prompt << ": ";
    cin >> f;
    return f;
}

template<typename T>
T get_input(string prompt) {
    T input;
    cout << prompt << ": ";
    cin >> input;
    return input;
}

int get_int(string prompt) {
    int i;
    cout << prompt << ": ";
    cin >> i;
    return i;
}


uint get_uint(string prompt) {
    uint i;
    cout << prompt << ": ";
    cin >> i;
    return i;
}

string get_string(string prompt) {
    string s;
    cout << prompt << ": ";
    cin >> s;
    return s;
}

bool is_in_range(int value, int min, int max) {
    return value >= min && value <= max;
}

bool is_outside_range(int value, int min, int max) {
    return value < min || value > max;
}

void println(string str = "") {
    cout << str << endl;
}

template <typename T>
void report_value(string name, T value) {
    cout << name << ": " << value << endl;
}