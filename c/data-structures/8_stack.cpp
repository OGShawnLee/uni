#include <iostream>

void println(std::string line) {
  std::cout << line << std::endl;
} 

void print(std::string line) {
  std::cout << line;
}

struct Element {
	int data;
	Element* previous = nullptr;

	Element(int data) {
		this->data = data;
	}
};

struct Stack {
	size_t cap;
	size_t len = 0;
	Element *top= nullptr;
  
	Stack(size_t cap) {
		this->cap = cap;
	}
};

Stack* create_stack(size_t cap) {
	return new Stack(cap);
}

Element* create_element(int data) {
	return new Element(data);
}

// deletes all elements in the stack, stack still exists
void clear(Stack *stack) {
	Element* top = stack->top;

	if (top == nullptr) return;

	while (top != nullptr) {
		Element* previous = top->previous;
		delete top;
		top = previous;
	}

	stack->top = nullptr;
}

// replaces the element at the top of the stack and returns it
Element* pop(Stack *stack) {
	if (stack->top == nullptr) return nullptr;
	
	Element* top = stack->top;
	stack->top = top->previous;
	stack->len--;
	
	// dont allow access to all the previous items
	top->previous = nullptr; 
	
	return top;
}

// replaces top | throws if stack is full
void push(Stack *stack, int data) {
	if (stack->len == stack->cap) {
		throw std::runtime_error("Stack is full");
	}
	
	Element* node = create_element(data);
	Element* top = stack->top;
	
	if (top == nullptr) {
		stack->top = node;
	}	else {
		stack->top = node;
		node->previous = top;
	}
	
	stack->len++;
}

bool has_top(const Stack *stack) {
	return stack->top != nullptr;	
}

bool is_empty(const Stack *stack) {
	return stack->len == 0;
}

bool is_full(const Stack *stack) {
  return stack->len == stack->cap;
}

void print_element(Element* element, size_t indentation = 0) {
	if (element == nullptr) return;

	if (element->previous == nullptr) {
		printf("Element { data: %i }\n", element->data);
	} else {
		std::string indent = std::string(indentation, ' ');
		println("Element {");
		println(indent + "    data: " + std::to_string(element->data));
		print(indent + "    previous: ");
		print_element(element->previous, indentation + 2);
		println(indent + "  }");
	}
}

void print_stack(const Stack *stack) {
	Element* current = stack->top;
	println("Stack {");
	println("  cap: " + std::to_string(stack->cap));
	println("  len: " + std::to_string(stack->len));
	if (current == nullptr) {
		println("  top: nullptr");
	} else {
		print("  top: ");
		print_element(current);
	}
	println("}");
}

int get_int(std::string prompt) {
  int value;
  std::cout << prompt;
  std::cin >> value;
  return value;
}

int main() {
  size_t cap = get_int("Enter the capacity of the stack: ");
  Stack *stack = create_stack(cap);

  while (true) {
    println("1. Push");
    println("2. Pop");
    println("3. Print");
    println("4. Exit");
    int choice = get_int("Enter your choice: ");

    switch (choice) {
      case 1: {
        if (is_full(stack)) {
          println("Stack is full");
          println("Pop an element to make space");
          break;
        }

        int data = get_int("Enter the data: ");
        push(stack, data);
        break;
      }
      case 2: {
        Element *element = pop(stack);
        if (element == nullptr) {
          println("Stack is empty");
        } else {
          println("Popped element: ");
          print_element(element);
          delete element;
        }
        break;
      }
      case 3: {
        print_stack(stack);
        break;
      }
      case 4: {
        clear(stack);
        delete stack;
        return 0;
      }
      default: {
        println("Invalid choice");
      }
    }
  }

  return 0;
}