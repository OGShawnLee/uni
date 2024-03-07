#include <iostream>

void println(std::string line) {
  std::cout << line << std::endl;
}

struct Employee {
  std::string name;
  std::string last_name_1;
  std::string last_name_2;
  std::string address;
  std::string phone_number;
  std::string position;
  float salary;

  std::string get_full_name() const {
    return name + " " + last_name_1 + " " + last_name_2;
  }

  void print() const {
    std::string full_name = get_full_name();

    println(full_name + " {");
    println("  Address: " + address);
    println("  Phone Number: " + phone_number);
    println("  Position: " + position);
    println("  Salary: " + std::to_string(salary));
    println("}");
  }
};

std::string get_line(std::string prompt) {
  std::cout << prompt + ": ";
  std::string line;
  std::getline(std::cin, line);
  return line;
}

int get_int(std::string prompt) {
  std::cout << prompt + ": ";
  int number;
  std::cin >> number;
  std::cin.ignore();
  return number;
}

namespace db {
  Employee *collection[100];
  size_t len = 0;

  Employee *create() {
    Employee *employee = new Employee();
    employee->name = get_line("Name");
    employee->last_name_1 = get_line("First Last Name");
    employee->last_name_2 = get_line("Second Last Name");
    employee->address = get_line("Address");
    employee->phone_number = get_line("Phone Number");
    employee->position = get_line("Position");
    employee->salary = std::stof(get_line("Salary"));
    return employee;
  }

  // INSERTAR
  void insert(Employee *employee) {
    collection[len++] = employee;
  }

  // BUSCAR
  void search(std::string name, std::string last_name_1) {
    for (size_t i = 0; i < len; i++) {
      Employee *employee = collection[i];
      if (employee->name == name && employee->last_name_1 == last_name_1) {
        return collection[i]->print();
      }
    }

    println("Employee not Found");
  }

  // ELIMINAR
  void remove(std::string name, std::string last_name_1) {
    for (size_t i = 0; i < len; i++) {
      Employee *employee = collection[i];
      if (employee->name == name && employee->last_name_1 == last_name_1) {
        delete collection[i]; // FREE MEMORY
        len--;

        // SHIFT LEFT THE ARRAY
        for (size_t j = i; j < len; j++) {
          collection[j] = collection[j + 1];
        }

        // REMOVE LAST ELEMENT
        collection[len] = nullptr;

        return;
      }
    }

    println("Employee not found");
  }

  void print() {
    if (len == 0) {
      println("No Employees");
      return;
    }

    for (size_t i = 0; i < len; i++) {
      println("Employee " + std::to_string(i + 1));
      collection[i]->print();
    }
  }
};

int main() {
  do  {
    println("Employee Database");
    println("1. Create");
    println("2. Search");
    println("3. Remove");
    println("4. View All");
    println("5. Exit");
    int option = get_int(">>> Option");

    switch (option) {
      case 1: {
        Employee *employee = db::create();
        db::insert(employee);
        break;
      }
      case 2: {
        println("Enter (name) and (first last name) to search");
        std::string name = get_line("Name");
        std::string last_name = get_line("Last Name");
        db::search(name, last_name);
        break;
      }
      case 3: {
        println("Enter (name) and (first last name) to remove");
        std::string name = get_line("Name");
        std::string last_name = get_line("Last Name");
        db::remove(name, last_name);
        break;
      }
      case 4: {
        db::print();
        break;
      }
      case 5: {
        println("Goodbye!");
        return 0;
      }
      default: {
        throw std::runtime_error("Invalid Option");
      }
    }
  } while (true);

  return 0;
}
