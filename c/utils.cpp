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

int get_int(string prompt) {
    int i;
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

template <typename T>
void report_value(string name, T value) {
    cout << name << ": " << value << endl;
}