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
void append(Node* &node, int data) {
	if (node == nullptr) {
		// Si el nodo es nulo, lo creamos
		node = create(data);
	} else {
		append(node->next, data);
	}
}

// Clona una lista recursivamente
void clone(Node* original, Node* &target) {
	if (original == nullptr) return;
	if (target == nullptr) {
		target = create(original->data);
	}

	clone(original->next, target->next);
}

// Inserta un nodo de manera ordenada (menor a mayor) recursivamente
void insert_sorted(Node* &head, int data) {
	// Hay que crear un nuevo nodo
	Node* new_node = create(data);	
	if (head == nullptr) {
		// La lista está vacía, el nuevo nodo será el primero
		head = new_node;		
	} else if (head->data > data) {
		/* 
			Se encuentra el primer nodo mayor que el nuevo nodo ...
			hay que insertar antes de él
			1. Guardar referencia al nodo mayor
			2. Remplazarlo por el nuevo nodo
			3. Apuntar el nuevo nodo al nodo remplazado (reconectar la lista)
		*/		
		Node* next = head; 
		
		new_node->next = next;
		head = new_node;
	} else {
		insert_sorted(head->next, data);
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
	if (head == nullptr) return;
	
	callback(head);
	each_child(head, callback);
} 

// Busca un nodo en la lista recursivamente
Node* find(Node* head, int data) {
	if (head == nullptr) return nullptr;
	if (head->data == data) return head;
	return find(head->next, data);
}

// Elimina un nodo de la lista recursivamente
void destroy(Node* &head) {
	if (head == nullptr) return;
	destroy(head->next);
	delete head;
	head = nullptr;
}

// Elimina un nodo hijo determinado de la lista recursivamente y reasigna los punteros
void destroy_child(Node *node, int data) {
	if (node->next == nullptr) return;
	if (node->next->data == data) {
		/*
			Hay que eliminar el nodo dado y sustituirlo con su hijo ...
			para no perder la referencia al resto de la lista
			1. Guardar el puntero al hijo
			2. Eliminar el padre
			3. Remplazar el padre con el hijo 
		*/
		Node *next = node->next->next;
		delete node->next;
		node->next = next;
	} else {
		destroy_child(node->next, data);
	}
}

// Verifica si un valor existe en la lista recursivamente
bool has_value(Node *node, int data) {
	if (node == nullptr) return false;
	if (node->data == data) return true;

	return has_value(node->next, data);
}

// Imprime un nodo en la consola e imprime sus nodos hijos si existen recursivamente
void display(Node* node, size_t indentation = 0) {
	if (node == nullptr) {
		println("No hay ningún nodo para mostrar");
		return;
	}
	
	std::string indent = std::string(indentation, ' ');

	if (node->next == nullptr) {
		println("Node { data: " + std::to_string(node->data) + " }");
	} else {
		println("Node {");
		println(indent + "  data: " + std::to_string(node->data));
		print(indent + "  next: ");
		display(node->next, indentation + 2);
		println(indent + "}");
	}
}

void update(Node* node, int target, int data) {
  if (node == nullptr) return;
  if (node->data == target) {
    node->data = data;
  } else {
    update(node->next, target, data);
  }
}

int get_int(std::string message) {
	int input;
	print(message + ": ");
	std::cin >> input;
	return input;
}

int main() {
	Node *head = nullptr;
	println("Lista Enlazada (Nodos + Pointers)");
	do {
		println();
		println("Elija una operación");
		println("1. Crear");
		println("2. Buscar");
		println("3. Eliminar");
		println("4. Mostrar");
		println("5. Verificar");
		println("6. Insertar Ordenadamente");
		println("7. Clonar");
		println("-1. Salir");
		println();

		int option = get_int(">>> Seleccione opcion");

		if (option == -1) return 0;

		switch (option) {
			case 1: {
				int value = get_int("Introduzca el valor del nodo");
				append(head, value);
			} break;
			case 2: {
				int value = get_int("Introduzca el valor del nodo a buscar");
				Node *node = find(head, value);
				if (node != nullptr) {
					display(node);
				} else {
					println("Nodo no ha sido encontrado");
				}
			} break;
			case 3: {
				int value = get_int("Introduzca el valor del nodo a eliminar");
				destroy_child(head, value);
			} break;
			case 4:
				display(head);
				break;
			case 5: {
				int value = get_int("Introduzca el valor del nodo a verificar existencia");
				bool exists = has_value(head, value);
				println(exists ? "Valor Existente" : "Valor Inexistente");
			} break;
			case 6: {
				int value = get_int("Introduzca el valor a insertar ordenadamente");
				insert_sorted(head, value);		
			} break;
			case 7: {
				Node* copy = nullptr;
				clone(head, copy);
				println("Copia:");
				display(copy);
				destroy(copy);
			} break;
			default:
				println("Opción Invalida");
				break;
		}
	} while (true);
}