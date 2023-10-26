#include "utils.cpp"

struct min_max {
    int min;
    int max;
};

min_max minmax(int a, int b, int c) {
    min_max result;

    if (a > b && a > c) {
        result.max = a;
        result.min = b > c ? c : b;
    } else if (b > a && b > c) {
        result.max = b;
        result.min = a > c ? c : a;
    } else {
        result.max = c;
        result.min = a > b ? b : a;
    }

    return result;
}

int main() {
    println("Mathematical Expressions");
    int a = get_input<int>("Enter a number for a");
    int b = get_input<int>("Enter a number for b");

    if (a < 0 || b < 0) {
        println("a and b must be positive");
    } else {
        printf("a + b = %d\n", a + b);
    }

    println();

    println("Cinema Tickets");
    uint age = get_input<uint>("Enter your age in years");
    uint tickets = get_input<uint>("Enter the number of tickets");
    const float PRICE_PER_TICKET = 2.5;
    float discount = 1;

    println();

    if (age <= 15) {
        println("You have a discount of 50%!");
        discount = 0.5;
    } 

    printf("Price per ticket: %.2f\n", PRICE_PER_TICKET);
    printf("Total: %.2f dollars\n", tickets * PRICE_PER_TICKET * discount);

    println();

    println("Secret Token");
    const uint SECRET_TOKEN = 1234;
    uint token = get_input<uint>("Enter the secret token");

    if (token == SECRET_TOKEN) {
        println("Access granted");
        a = get_input<int>("Enter a number for a");
        b = get_input<int>("Enter a number for b");

        printf("a + b = %d\n", a + b);
    } else {
        println("Access denied");
    }

    println();

    println("Minimum and Maximum");
    a = get_input<int>("Enter a number for a");
    b = get_input<int>("Enter a number for b");
    int c = get_input<int>("Enter a number for c");
    min_max min_n_max = minmax(a, b, c);

    printf("Minimum: %d\n", min_n_max.min);
    printf("Maximum: %d\n", min_n_max.max);

    return 0;
}