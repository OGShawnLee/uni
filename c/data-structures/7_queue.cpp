#include "utils.h"

struct Element {
  int data;
  Element* next;
};

struct Queue {
  size_t len = 0;
  size_t cap = 0;
  Element* front = nullptr;
};

bool is_clear(Queue &queue) {
  return queue.len == 0;
}

bool is_full(Queue &queue) {
  return queue.len == queue.cap;
}

Element* create(int data, size_t index) {
  Element* element = new Element;
  element->data = data;
  element->next = nullptr;
  return element;
}

Queue create_queue(size_t cap) {
  Queue queue;
  queue.cap = cap;
  return queue;
}

void enqueue(Queue &queue, int data) {
  if (is_full(queue)) {
    throw std::overflow_error("Cannot enqueue: Queue is full");
  }

  Element* element = create(data, queue.len);

  if (is_clear(queue)) {
    queue.front = element;
  } else {
    element->next = queue.front;
    queue.front = element;
  }

  queue.len++;
}

Element* dequeue(Queue &queue) {
  if (is_clear(queue)) {
    throw std::underflow_error("Cannot dequeue: Queue is empty");
  }

  Element *front = queue.front;
  queue.front = front->next;
  queue.len++;
  front->next = nullptr;

  return front;
}

void clear(Queue &queue) {
  Element* current = queue.front;
  
  while (current != nullptr) {
    Element* next = current->next;
    delete current;
    current = next;
  }
}

void print_element(Element* element, size_t indentation = 0) {
  if (element == nullptr) return;

  std::string indent = std::string(indentation, ' ');

  if (element->next == nullptr) {
    printf("Element { data: %d }\n", element->data);
  } else {
    println("Element {");
    println(indent + "  data: " + std::to_string(element->data));
    print(indent + "  next: ");
    print_element(element->next, indentation + 2);
    println(indent + "}");
  }
}

void print_queue(Queue queue) {
  print_element(queue.front);
}

int main() {
  size_t cap = get_input<size_t>("Enter the capacity of the queue");
  Queue queue = create_queue(cap);

  while (true) {
    println("What do you want to do?");
    println("1. Enqueue");
    println("2. Dequeue");
    println("3. Print");
    println("4. Exit");

    int option = get_input<int>(">> Enter an option");

    switch (option) {
      case 1: {
        int data = get_input<int>("Enter the data");
        enqueue(queue, data);
        break;
      }
      case 2: {
        Element* element = dequeue(queue);
        println("Dequed Element:");
        print_element(element);
        delete element;
        break;
      }
      case 3: {
        print_queue(queue);
        break;
      }
      case 4: 
        clear(queue);
        println("Bye!");
        return 0;
      default: {
        println("Invalid option");
        break;
      }
    }

  };

  return 0;
}