#include <fstream>
#include <map>
#include <vector>
#include "project-avl.h"

using namespace std;

/* Sistema de Visualizacion de Alumnos
  Caracteristicas: 
  - Base de Datos: 
    Alumnos son cargados y guardados en un archivo de texto (db.txt)
  - Eficiente
    Alumnos se guardan en un map cuya llave corresponde a su id,
      por lo que acceder a su valor es instantaneo si se conoce su id.
    Tambien se guardan en un AVL Tree para optimizar busqueda de alumnos
      basados en su calificacion.
    (
      Se podria crear un indice que contenga una relacion name -> id (map<string, size_t>)
      para acceder instantaneamente a un alumno si se conoce su nombre
    ) 
*/ 

// * Funciones de Utilidad

// - Limpiar la pantalla de la consola
void clear() {
  cout << "\033[2J\033[1;1H";
}

// Confirma si una string es unicamente espacios (esta vacia)
bool is_whitepace(string ln) {
  for (char character : ln) {
    if (character != ' ') return false;
  }

  return true;
}

// Obtiene una linea de texto hasta que sea valida (no vacia)
string get_line(string prompt) {
  string line;
  
  while (true) {
    print(prompt + ": ");
    getline(cin, line);

    if (is_whitepace(line)) {
      println("Entrada vacia, intente de nuevo");
    } else {
      break;
    }
  }

  return line;
}

// Obtiene un valor booleano hasta que el usuario escriba un valor de (s/n)
bool get_bool(string prompt) {
  string ln;

  while (true) {
    print(prompt + " (s/n): ");
    cin >> ln;
    // Validar que sea 's' o 'n'
    if (ln == "s") {
      return true;
    } else if (ln == "n") {
      return false;
    } else {
      println("Entrada invalida, asegurese de introducir 's' o 'n'");
    }
  }
}

// Obtiene un valor entero hasta que el usuario escriba un numero entero positivo
int get_int(string prompt) {
  int integer;

  while (true) {
    print(prompt + ": ");
  
    cin >> integer;
    
    if (integer >= 0) {
      break;
    } else {
      println("Entrada invalida, asegurese de introducir un numero entero positivo");
    }
  }

  return integer;
}

// Opciones del programa
enum Option {
  INSERT,
  SHOW_ALL,
  SHOW_LESS_THAN,
  SHOW_MORE_THAN,
  EXIT,
};

// Imprime las opciones del programa y obtiene la opcion seleccionada
Option get_option() {
  int option;

  while (true) {
    // Imprimir opciones
    println("Menu:");
    println("1. Agregar alumno");
    println("2. Mostrar alumnos");
    println("3. Alumnos con menor calificacion a cierto valor");
    println("4. Alumnos con mayor calificacion a cierto valor");
    println("5. Salir");

    // Obtener indicacion
    cout << ">>> Seleccione una opcion: ";
    cin >> option;

    // Validar indicacion (hay opciones del 1 al 5)
    if (option == 1) return Option::INSERT;
    if (option == 2) return Option::SHOW_ALL;
    if (option == 3) return Option::SHOW_LESS_THAN;
    if (option == 4) return Option::SHOW_MORE_THAN;
    if (option == 5) return Option::EXIT;
    
    clear();
    println("Opcion invalida intente de nuevo");
  }
}

struct Student {
  size_t id;
  string name;
  int grade;
};

void print_student(Student student) {
  println("  Estudiante {");
  println("    Clave: " + to_string(student.id));
  println("    Nombre: " + student.name);
  println("    Calificacion: " + to_string(student.grade));
  println("  }");
}

// 1. Agregar Student
void add_student(map<size_t, Student> &students, Node* &root) {
  // Informar al usuario que se esta agregando un producto
  println("1. Agregando Estudiante - Ingrese los datos del estudiante:");

  // Validar que haya espacio en el arreglo
  if (students.size() > 50) {
    println("No hay espacio para mas estudiantes");
    return;
  }

  // Crear un nuevo estudiante
  Student student;
  cin.ignore(); // si no se hace esto, getline no funciona correctamente a veces
  student.name = get_line("Nombre");
  student.grade = get_int("Calificacion (debe ser positiva)");
  // Generar clave
  student.id = students.size();

  print_student(student);
  bool correct = get_bool("Desea agregar este estudiante?");
  if (correct) {
    // Agregar estudiante al map
    students[student.id] = student;
    // Indexar estudiante en el arbol
    root = insert(root, student.grade, student.id);
    clear();
    println("Estudiante agregado con exito con clave: " + to_string(student.id));
  } else {
    clear();
    println("Estudiante no agregado");
  }
}

// 2. Mostrar Alumnos
void print_students(map<size_t, Student> students) {
  println("3. Mostrando Alumnos:");

  if (students.size() == 0) {
    println("No hay alumnos en la base de datos");
    return;
  }

  for (auto pair : students) {
    print_student(pair.second);
  }
}

vector<Student> find_all_less_than(
  map<size_t, Student> &db, 
  Node* root, 
  int grade
) {
  vector<Student> students;

  each_pre_order(root, [&](Node* node) {
    if (node->grade < grade) {
      Student student = db.at(node->id);
      students.push_back(student);
    }
  });

  return students;
}

// 4. Alumnos con menor calificacion a cierto valor
/*
  1. Para mostrar los alumnos con menor calificacion a cierto valor.
  2. Se obtiene el valor del usuario.
  3. Se muestran los alumnos con menor calificacion al valor.
  4. Si no se encuentran alumnos, se informa al usuario.
*/
void print_students_with_lower_than_grade(map<size_t, Student> &db, Node* root) {
  println("4. Alumnos con menor calificacion a cierto valor:");

  if (db.size() == 0) {
    println("No hay alumnos en la base de datos");
    return;
  }

  cin.ignore();
  int grade = get_int("Ingrese la calificacion");
  vector<Student> students = find_all_less_than(db, root, grade);

  if (students.size() == 0) {
    println("No se encontraron alumnos con una calificacion menor a " + to_string(grade));
    return;
  }

  for (Student student : students) {
    print_student(student);
  }
}

vector<Student> find_all_more_than(
  map<size_t, Student> &db, 
  Node* root, 
  int grade
) {
  vector<Student> students;

  each_pre_order(root, [&](Node* node) {
    if (node->grade > grade) {
      Student student = db.at(node->id);
      students.push_back(student);
    }
  });

  return students;
}

// 4. Alumnos con mayor calificacion a cierto valor
/*
  1. Para mostrar los alumnos con mayor calificacion a cierto valor.
  2. Se obtiene el valor del usuario.
  3. Se muestran los alumnos con mayor calificacion al valor.
  4. Si no se encuentran alumnos, se informa al usuario.
*/
void print_students_with_higher_than_grade(map<size_t, Student> &db, Node* root) {
  println("4. Alumnos con mayor calificacion a cierto valor:");

  if (db.size() == 0) {
    println("No hay alumnos en la base de datos");
    return;
  }

  cin.ignore();
  int grade = get_int("Ingrese la calificacion");
  vector<Student> students = find_all_more_than(db, root, grade);

  if (students.size() == 0) {
    println("No se encontraron alumnos con una calificacion mayor a " + to_string(grade));
    return;
  }

  for (Student student : students) {
    print_student(student);
  }
}

/*
    
  1. Para cargar los productos de un archivo de texto.
  2. Se lee el archivo linea por linea.
  3. Se separan los datos de cada linea a partir de comas.
  4. Se crea un producto con los datos.
  5. Se agrega el producto al arreglo de productos.
  6. Se incrementa la cantidad de productos.
  - Se usa para cargar los productos al inicio del programa
  Nota: El formato de cada producto es:
    proveedor, nombre, precio, cantidad;
*/
void load_students(map<size_t, Student> &db, Node* &root) {
  ifstream file("db.txt");

  println("Cargando base de datos...");

  if (file.is_open()) {
    string ln;

    while (getline(file, ln)) {
      vector<string> properties;
      string property = "";
      
      /*
        1. Se itera sobre cada caracter de la linea y se acumula en la propiedad en ciertos casos.
        2. Si se encuentra una coma o un punto y coma, se agrega la propiedad al vector y se reinicia la propiedad.
        3. Se crea un producto con las propiedades y se agrega al arreglo de productos.
      */

      for (size_t i = 0; i < ln.length(); i++) {
        char character = ln[i];
        
        /*
          1. Si el caracter es una coma o un punto y coma, se agrega la propiedad al vector y se reinicia la propiedad.
          2. Si el caracter no es un espacio, se agrega a la propiedad.
        */
        if (character == ',' || character == ';') {
          // Se elimina el espacio al principio de la propiedad
          // El espacio se coloca para que sea mas facil leer las propiedades en el archive
          if (property[0] == ' ') {
            property = property.substr(1);
          }

          properties.push_back(property);
          property = "";
        } else {
          property += character;
        }
      }

      Student student;
      student.id = db.size();
      student.name = properties[0];
      student.grade = stoi(properties[1]);
      db[db.size()] = student;
      root = insert(root, student.grade, student.id);
    }

    println("Base de datos cargada con exito");

    file.close();
  } else {
    println("No se pudo cargar la base de datos");
  }
}

void save_students(map<size_t, Student> &db) {
  ofstream file("db.txt");

  println("Guardando base de datos...");

  if (file.is_open()) {
    for (auto pair : db) {
      string text;
      text += pair.second.name + ", ";
      text += to_string(pair.second.grade) + ";\n";
      file << text;
    }

    file.close();
    println("Base de datos guardada con exito");
  } else {
    println("No se pudo guardar la base de datos");
  }
}

int main() {
  println("Sistema de Visualizacion de Estudiantes");

  map<size_t, Student> db;
  Node *root = nullptr;

  load_students(db, root);

  while (true) {
    Option option = get_option();
    switch (option) {
      case Option::INSERT: {
        add_student(db, root);
        print(root);
      } break;
      case Option::SHOW_ALL: {
        print_students(db);
        print(root);
      } break;
      case Option::SHOW_LESS_THAN: {
        print_students_with_lower_than_grade(db, root);
      } break;
      case Option::SHOW_MORE_THAN: {
        print_students_with_higher_than_grade(db, root);
      } break;
      case Option::EXIT: {
        println("Gracias por usar el sistema!");
        clear(); 
        save_students(db);
        return 0;
      }
    }
  }

  return 0;
}