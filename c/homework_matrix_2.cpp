#include <iostream>
#include <string>

using namespace std;

const size_t MAX_LEN = 15;

void prompt(string str = "") {
    if (str != "") cout << str << ": ";
}

void println(string str = "") {
    cout << str << endl; 
}

void print_array(size_t len, int arr[]) {
    if (len == 0) {
        cout << "[]" << endl;
        return;
    }

    if (len == 1) {
        cout << "[" << arr[0] << "]" << endl;
        return;
    }

    cout << "[" << arr[0] << ", ";
    for (size_t i = 1; i < len - 1; i++) {
        cout << arr[i] << ", ";
    }
    cout << arr[len - 1] << "]" << endl;
}

void print_matrix(size_t rows, size_t cols, int matrix[MAX_LEN][MAX_LEN]) {
    for (size_t i = 0; i < rows; i++) {
        print_array(cols, matrix[i]);
    }
}

char get_char(string message = "") {
    char ch;
    prompt(message);
    cin >> ch;
    return ch;
}

size_t get_matrix_len(string message = "") {
    size_t len;
    prompt(message);
    cin >> len;

    if (len > MAX_LEN) {
        printf("Length must be less than %zu. Length truncated to %zu\n", MAX_LEN, MAX_LEN);        
    }

    return len;
}

int get_int(string message = "") {
    int num;
    prompt(message);
    cin >> num;
    return num;
}

int get_random_int_in_range(int min, int max) {
    return rand() % (max - min + 1) + min;
}

bool includes(int value, int len, int arr[]) {
    for (int i = 0; i < len; i++) {
        if (arr[i] == value) {
            return true;
        }
    }

    return false;
}

bool is_repeated(int value, int len, int arr[]) {
    size_t count_found = 0;

    for (int i = 0; i < len; i++) {
        if (arr[i] == value) {
            count_found++;
        }

        if (count_found > 1) {
            return true;
        }
    }

    return false;

}

void fill_matrix(size_t rows, size_t cols, int matrix[MAX_LEN][MAX_LEN], char fill_mode) {
    if (fill_mode == 'a') {
        for (size_t i = 0; i < rows; i++) {
            for (size_t j = 0; j < cols; j++) {
                matrix[i][j] = get_random_int_in_range(10, 50);
            }
        }
    } else if (fill_mode == 'm') {
        for (size_t i = 0; i < rows; i++) {
            for (size_t j = 0; j < cols; j++) {
                printf("Enter integer for position (%zu, %zu)\n", i, j);
                matrix[i][j] = get_int();
            }
        }
    } else {
        printf("Invalid fill mode\n");
        fill_matrix(rows, cols, matrix, get_char("Enter fill mode (a - auto, m - manual)"));
    }
}

void filter_out_repeated(int &len, int arr[]) {
    int len_initial = len;
    int len_current = len;

    for (int i = 0; i < len_initial; i++) {
        int current = arr[i];

        if (is_repeated(current, len_current, arr)) {
            int len_local = len_current;
            len_current = 0;

            for (int j = 0; j < len_local; j++) {
                if (arr[j] != current) {
                    arr[len_current++] = arr[j];
                }
            }
        }
    }

    len = len_current;
}

size_t set_difference(
    size_t rows, 
    size_t cols, 
    int matricina[MAX_LEN][MAX_LEN], 
    int matricino[MAX_LEN][MAX_LEN], 
    int difference[MAX_LEN * MAX_LEN]
) {
    size_t difference_len = 0;

    for (size_t row = 0; row < rows; row++) {
        for (size_t col = 0; col < cols; col++) {
            int current = matricina[row][col];

            // current is in a therefore we dont add it to difference
            if (includes(current, cols, matricino[row])) continue;
            // current is already in difference therefore we dont add it again
            if (is_repeated(current, difference_len, difference)) continue;

            difference[difference_len++] = current;
        }
    }

    return difference_len;
}

int main() {
    println("1. Finding elements in matrix A that are not in matrix B");
    int matricina[MAX_LEN][MAX_LEN];
    int matricino[MAX_LEN][MAX_LEN];
    size_t rows = get_matrix_len("Enter number of rows");
    size_t cols = get_matrix_len("Enter number of columns");

    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            matricina[i][j] = get_random_int_in_range(10, 50);
            matricino[i][j] = get_random_int_in_range(10, 50);
        }
    }

    int difference[MAX_LEN * MAX_LEN];
    size_t difference_len = set_difference(rows, cols, matricina, matricino, difference);

    println("Matrix A");
    print_matrix(rows, cols, matricina);
    println("Matrix B");
    print_matrix(rows, cols, matricino);
    println("Difference");
    print_array(difference_len, difference);

    println("2. Filtering out repeated integers");
    int matricin[MAX_LEN][MAX_LEN];
    rows = 4;
    cols = 4;
    char fill_mode = get_char("Enter fill mode (a - auto, m - manual)");
    fill_matrix(rows, cols, matricin, fill_mode);    

    int length = rows * cols; // 16
    int vectorcin[length];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int len_current = i * cols + j;
            vectorcin[len_current] = matricin[i][j];
        }
    }

    println("Before filtering");
    print_array(length, vectorcin);

    filter_out_repeated(length, vectorcin);

    println("After filtering");
    print_array(length, vectorcin);

    return 0;
}
