#include "utils.cpp"

int main() {
    int age = get_input<int>("Enter your age in years");
    
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

    int rating = get_input<int>("What was your rating?");

    if (is_outside_range(rating, 0, 10)) {
        println("Your rating must be between 0 and 10");
    } else {
        if (rating == 10 || rating == 9) println("Notable");
        else if (rating == 8) println("Aproved");
        else if (rating == 7 || rating == 6) println("Good");
        else println("You must study more!");
    }

    float x = get_input<float>("Enter a float for x");
    float y = get_input<float>("Enter a float for y");

    if (x == 0 || y == 0) {
        println("x and y must be non-zero");
    } else {
        printf("2 + (3 * %.3f) = %.3f\n", x, 2 + (3 * x));
        printf("3 * (2 + %.3f) = %.3f\n", y, 3 * (2 + y));
    }

    int a = get_input<int>("Enter an integer for a");
    int b = get_input<int>("Enter an integer for b");
    int c = get_input<int>("Enter an integer for c");

    if (a == b && b == c) {
        println("Ordered the same");
    } else if (a >= b && b >= c) {
        println("Descending Order");
    } else if (a <= b && b <= c) {
        println("Ascending Order");
    } else {
        println("Unordered");
    }

    return 0;
}