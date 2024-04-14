#include <iostream>

namespace utils {
  void print(std::string str) {
    std::cout << str;
  }

  void println(std::string line) {
    std::cout << line << std::endl;
  }
}

struct Element {
  int data;
  Element* previous = nullptr;

  Element(int data) {
    this->data = data;
  }

  ~Element() {
    delete previous;
  }

  void print(size_t indentation = 0) const {
    if (previous == nullptr) {
      printf("Element { data: %d }\n", data);
    } else {
      std::string indent = std::string(indentation, ' ');
      utils::println("Element {");
      utils::println(indent + "  data: " + std::to_string(data));
      utils::print(indent + "  previous: ");
      previous->print(indentation + 2);
      utils::println(indent + "}");
    }
  }
};

struct Stack {
  size_t cap;
  size_t len = 0;
  Element *top= nullptr;

  Stack(size_t cap) {
    this->cap = cap;
  }

  ~Stack() {
    delete top;
  }

  bool is_full() {
    return len == cap;
  }

  void clear() {
    delete top;
    top = nullptr;
    len = 0;
  }

  void push(int data) {
    if (is_full()) {
      utils::println("Stack is full");
      return;
    }

    Element* element = new Element(data);
    element->previous = top;
    top = element;
    len++;
  }

  Element* pop() {
    if (top == nullptr) return nullptr;

    Element* top = this->top;
    this->top = top->previous;
    top->previous = nullptr;
    len--;

    return top;
  }

  void print() const {
    utils::println("Stack {");
    utils::println("  cap: " + std::to_string(cap));
    utils::println("  len: " + std::to_string(len));
    if (top == nullptr) {
      utils::println("  top: nullptr");
    } else {
      utils::print("  top: ");
      top->print(2);
    }
    utils::println("}");
  }
};

int get_int(std::string prompt) {
  utils::print(prompt);
  int input;
  std::cin >> input;
  return input;
}

int main() {
  Stack* stack = new Stack(
    get_int("Enter the capacity of the stack: ")
  );

  while (true) {
    utils::println("1. Push");
    utils::println("2. Pop");
    utils::println("3. Print");
    utils::println("4. Clear");
    utils::println("5. Exit");
    int option = get_int(">>> Enter option: ");

    switch (option) {
      case 1: {
        stack->push(
          get_int("Enter the data: ")
        );
        break;
      }
      case 2: {
        Element* element = stack->pop();
        if (element == nullptr) {
          utils::println("Stack is empty");
        } else {
          utils::println("Popped element: ");
          element->print();
          delete element;
        }
        break;
      }
      case 3: {
        stack->print();
        break;
      }
      case 4: {
        stack->clear();
        utils::println("Stack has been cleared!");
        break;
      }
      case 5: {
        delete stack;
        utils::println("Au revoir!");
        return 0;
      }
      default: {
        utils::println("Invalid Option");
      }
    }
  }

  return 0;
}