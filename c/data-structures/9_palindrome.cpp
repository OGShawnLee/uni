#include <iostream>

void print(std::string str) {
  std::cout << str;
}

void println(std::string line) {
  std::cout << line << std::endl;
}

struct SElement {
  char data;
  SElement* previous = nullptr;

  SElement(char data) {
    this->data = data;
  }
};

struct Stack {
  size_t cap;
  size_t len = 0;
  SElement *top= nullptr;
};

bool is_full(Stack *stack) {
  return stack->len == stack->cap;
}

void append(Stack *stack, char data) {
  if (is_full(stack)) {
    println("Stack is full");
    return;
  }

  SElement *element = new SElement(data);
  element->previous = stack->top;
  stack->top = element;
  stack->len++;
}

SElement* pop(Stack *stack) {
  if (stack->top == nullptr) {
    println("Stack is empty");
    return nullptr;
  }

  SElement *element = stack->top;
  stack->top = element->previous;
  stack->len--;
  return element;
}

void clear(Stack *stack) {
  while (stack->top != nullptr) {
    SElement *element = pop(stack);
    delete element;
  }
}

void print_element(SElement* element, size_t indentation = 0) {
	if (element == nullptr) return;

	if (element->previous == nullptr) {
		printf("Element { data: %c }\n", element->data);
	} else {
		std::string indent = std::string(indentation, ' ');
		println("Element {");
    printf("%s    data: %c\n", indent.c_str(), element->data);
		print(indent + "    previous: ");
		print_element(element->previous, indentation + 2);
		println(indent + "  }");
	}
}

void print(Stack *stack) {
  println("Stack {");
  println("  cap: " + std::to_string(stack->cap));
  println("  len: " + std::to_string(stack->len));
  if (stack->top == nullptr) {
    println("  top: nullptr");
  } else {
    print("  top: ");
    print_element(stack->top);
  }
  println("}");
}

struct QElement {
  char data;
  QElement* next = nullptr;

  QElement(char data) {
    this->data = data;
  }
};

struct Queue {
  size_t cap;
  size_t len = 0;
  QElement *front = nullptr;
  QElement *back = nullptr;
};

bool is_full(Queue *queue) {
  return queue->len == queue->cap;
}

void enqueue(Queue *queue, char data) {
  if (is_full(queue)) {
    println("Queue is full");
    return;
  }

  QElement *element = new QElement(data);
  
  if (queue->front == nullptr) {
    queue->front = element;
  } else {
    queue->back->next = element;
  }

  queue->back = element;
  queue->len++;
}

QElement* dequeue(Queue *queue) {
  if (queue->front == nullptr) {
    println("Queue is empty");
    return nullptr;
  }

  QElement *element = queue->front;
  queue->front = element->next;
  queue->len--;
  return element;
}

void clear(Queue *queue) {
  while (queue->front != nullptr) {
    QElement *element = dequeue(queue);
    delete element;
  }
}

void print_element(QElement* element, size_t indentation = 0) {
  if (element == nullptr) return;

  if (element->next == nullptr) {
    printf("Element { data: %c }\n", element->data);
  } else {
    std::string indent = std::string(indentation, ' ');
    println("Element {");
    printf("%s    data: %c\n", indent.c_str(), element->data);
    print(indent + "    next: ");
    print_element(element->next, indentation + 2);
    println(indent + "  }");
  }
}

void print(Queue *queue) {
  println("Queue {");
  println("  cap: " + std::to_string(queue->cap));
  println("  len: " + std::to_string(queue->len));
  if (queue->front == nullptr) {
    println("  front: nullptr");
  } else {
    print("  front: ");
    print_element(queue->front);
  }
  if (queue->back == nullptr) {
    println("  back: nullptr");
  } else {
    print("  back: ");
    print_element(queue->back);
  }
  println("}");
}

bool is_whitespace(char character) {
  return character == ' ' || character == '\t' || character == '\n';
}

bool is_palindrome(Stack *stack, Queue *queue, std::string line) {
  for (size_t i = 0; i < line.length(); i++) {
    char character = toupper(line[i]);

    if (is_whitespace(character) || isalpha(character) == false) continue;

    append(stack, character);
    enqueue(queue, character);
  }

  bool result = true;

  for (size_t i = 0; i < stack->len; i++) {
    SElement *top = pop(stack);
    QElement *back = dequeue(queue);
    
    result = top->data == back->data;

    delete top;
    delete back;

    if (result == false) {
      break;
    }
  }

  clear(stack);
  clear(queue);

  return result;
}

std::string get_line(std::string prompt) {
  std::string line;
  std::cout << prompt;
  std::getline(std::cin, line);
  return line;
}

int main() {
  Stack *stack = new Stack{ 50 };
  Queue *queue = new Queue{ 50 };

  while (true) {
    std::string line = get_line("Enter a line (-1 to exit): ");

    if (line.length() > 50) {
      println("Line is too long! (max 50 characters)");
      continue;
    }

    if (line == "-1") break;

    std::string message = is_palindrome(stack, queue, line) ? "is" : "is not";
    println("The line " + message + " a palindrome");
  }

  delete stack;
  delete queue;

  return 0;
}