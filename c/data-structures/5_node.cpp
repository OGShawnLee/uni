#include <functional>
#include <iostream>

void print(std::string str) {
  std::cout << str;
}

void println(std::string str = "") {
  std::cout << str << std::endl;
}

struct Node {
  int data;
  Node* next;
};

// Crea un nodo con un valor dado
Node* create(int data) {
  Node* head = new Node();
  head->data = data;
  head->next = nullptr;
  return head;
}

// Agrega un nodo al final de la lista recursivamente
void append(Node* head, int data) {
  if (head->next == nullptr) {
    head->next = new Node();
    head->next->data = data;
    head->next->next = nullptr;
  } else {
    append(head->next, data);
  }
}

// Itera sobre los nodos de la lista recursivamente sin incluir el nodo cabeza
void each_child(Node* head, std::function<void(Node*)> callback) {
  if (head->next == nullptr) return;

  callback(head->next);
  each_child(head->next, callback);
}

// Itera sobre los nodos la lista incluyendo el nodo cabeza
void each(Node* head, std::function<void(Node*)> callback) {
  callback(head);
  each_child(head, callback);
} 

// Busca un nodo en la lista recursivamente sin incluir el nodo cabeza
Node* find(Node* head, int data) {
  if (head->next == nullptr) {
    return nullptr;
  } 
  
  if (head->next->data == data) {
    return head->next;
  } 

  return find(head->next, data);
}

// Elimina todos los nodos de la lista recursivamente sin incluir el nodo cabeza
void clear(Node* head) {
  Node* current = head->next;

  while (current != nullptr) {
    Node* next = current->next;
    delete current;
    current = next;
  }

  head->next = nullptr;
}

// Elimina todos los nodos de la lista recursivamente incluyendo el nodo cabeza
void nuke(Node* &head) {
  clear(head);
  delete head;
  head = nullptr;
}

// Elimina un nodo de la lista determinado por su valor recursivamente y recoloca los nodos
Node* remove(Node* head, int data) {
  if (head->next == nullptr) {
    return nullptr;
  } 
  
  if (head->next->data == data) {
    Node* target = head->next;
    head->next = head->next->next;
    delete target;
    return head;
  } 

  return remove(head->next, data);
}

// Imprime un nodo en la consola e imprime sus nodos hijos si existen recursivamente
void display(Node* head, size_t indentation = 0) {
  std::string indent = std::string(indentation, ' ');

  if (head->next == nullptr) {
    println("Node { data: " + std::to_string(head->data) + " }");
  } else {
    println("Node {");
    println(indent + "  data: " + std::to_string(head->data));
    print(indent + "  next: ");
    display(head->next, indentation + 2);
    println(indent + "}");
  }
}

int main() {
  Node* head = create(1);

  append(head, 2);
  append(head, 3);
  append(head, 4);

  display(head);

  Node* second = find(head, 2);

  display(second);

  println("All Children of Head");
  each_child(head, [](Node* node) {
    println("Node { data: " + std::to_string(node->data) + " }");
  });

  println("All Nodes");
  each(head, [](Node* node) {
    println("Node { data: " + std::to_string(node->data) + " }");
  });

  nuke(head);

  if (head == nullptr) {
    println("Head is null");
  }

  return 0;
}