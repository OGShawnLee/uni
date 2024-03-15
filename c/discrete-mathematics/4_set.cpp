// Edgar Vazquez Garcia - Conjuntos

#include <iostream>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

// Imprime un string en la consola y agrega un salto de linea
void println(string str = "") {
  cout << str << endl;
}

// Imprime un string en la consola
void print(string str) {
  cout << str;
}

// Verifica si un numero es un duplicado en un conjunto
bool is_duplicate(const set<int> &collection, int number) {
  return collection.find(number) != collection.end();
}

// Lee un string desde la consola
string get_string(string prompt) {
  string str;
  cout << prompt + ": ";
  cin >> str;
  return str;
}

// Lee un entero desde la consola
int get_int(string prompt) {
  int number;
  cout << prompt + ": ";
  cin >> number;
  return number;
}

// Lee un entero desde la consola y verifica que no sea un duplicado en un conjunto
int get_unique_int(string prompt, const set<int> &collection) {
  int number;
  
  while (true) {
    number = get_int(prompt);

    if (is_duplicate(collection, number) == false) break;
    
    println("El numero ya existe en el conjunto");
    println("Intente de nuevo");
    println();
  }

  return number;
}


bool is_in_range(int number, int min, int max) {
  return number >= min && number <= max;
}

int main() {
  set<int> collection_a;
  set<int> collection_b;

  println("Conjuntos");

  int size_a = get_int("Introduzca la longitud para los sets A y B (2-6)");

  if (is_in_range(size_a, 2, 6) == false) {
    println("La longitud debe estar entre 2 y 6");
    return 1;
  }

  for (int i = 0; i < size_a; i++) {
    collection_a.insert(
      get_unique_int("Introduzca un numer para el set A", collection_a)
    );
  }

  for (int i = 0; i < size_a; i++) {
    collection_b.insert(
      get_unique_int("Introduzca un numero para el set B", collection_b)
    );
  }

  println();

  // 1: Subset - Subconjunto 
  println("1: Subset - Subconjunto");

  bool is_a_subset_of_b = true;

  for (int number : collection_a) {
    if (collection_b.find(number) == collection_b.end()) {
      is_a_subset_of_b = false;
      break;
    }
  }

  if (is_a_subset_of_b) {
    println("A es subconjunto de B");
  } else {
    println("A no es subconjunto de B");
  }

  println();

  // 2: Cardinality - Cardinalidad
  println("2: Cardinalidad - Cardinalidad");

  set<int> collection_cardinality;
  
  while (true) {
    int number = get_unique_int(
      "Introduzca un numero para determinar cardinalidad de un conjunto", 
      collection_cardinality
    );
    string end = get_string("Desea introducir otro numero? (S/N)");

    collection_cardinality.insert(number);
    
    if (end == "N" || end == "n") break;
  }

  int cardinality = collection_cardinality.size();
  println("Cardinalidad: " + to_string(cardinality));

  println();

  // 3: Power Set - Conjunto Potencia
  // Mother of all sets

  // 4: Cartesian Product - Producto Cartesiano
  println("4: Producto Cartesiano");
  println("A x B");

  print("[");
  for (int a : collection_a) {
    for (int b : collection_b) {
      printf("(%d, %d) ", a, b);
    }
  }
  print("]");

  return 0;
}