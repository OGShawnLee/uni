#include "iostream"

using namespace std;

// Funciones de Utilidad
// Imprime una linea en la consola como en Python!
void print(string line) {
  cout << line << endl;
}

// Obtiene un booleano desde la consola
bool getBool(string mensaje) {
  string valor;
  cout << mensaje + " (s/n): ";
  
  while (true) {
    cin >> valor;

    if (valor == "s" || valor == "S") {
      return true;
    } else if (valor == "n" || valor == "N") {
      return false;
    } else {
      cout << "Por favor ingrese s o n: ";
    }
  }  
}

// Obtiene un entero desde la consola
int getInt(string mensaje) {
  int valor;
  cout << mensaje + ": ";
  cin >> valor;
  return valor;
}

// Obtiene una cadena de texto desde la consola
string getString(string mensaje) {
  string valor;
  cout << mensaje + ": ";
  cin.ignore();
  getline(cin, valor);
  return valor;
}

// Obtiene un flotante desde la consola
float getFloat(string mensaje) {
  float valor;
  cout << mensaje + ": ";
  cin >> valor;
  return valor;
}

// Convierte un string a minusculas como en JavaScript!
string toLowerCase(string texto) {
  string resultado = "";
  for (int i = 0; i < texto.length(); i++) {
    resultado += tolower(texto[i]);
  }
  return resultado;
}

void limpiarPantalla() {
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}

struct Producto {
  string clave;
  string proveedor;
  string nombre;
  int cantidad;
  float precio;
};

// Inventario de Productos
Producto inventario[50];
// Cantidad de Productos
int len = 0;

// Imprime un producto en la consola con formato de diccionario
void imprimirProducto(Producto producto) {
  print("Producto {");
  if (producto.clave != "") {
    print("  clave: " + producto.clave);
  }
  print("  proveedor: " + producto.proveedor);
  print("  nombre: " + producto.nombre);
  print("  cantidad: " + to_string(producto.cantidad));
  print("  precio: " + to_string(producto.precio));
  print("}");
}

string getClave(string proveedor) {
  string clave;
  clave += toupper(proveedor[0]);

  // Añade la primera letra de cada palabra en el proveedor 
  for (int i = 0; i < proveedor.length() - 1; i++) {
    char character = proveedor[i];
    if (character == ' ' && i + 1 < proveedor.length()) {
      char nextCharacter = proveedor[i + 1];
      if (nextCharacter == ' ') continue;
      clave += toupper(proveedor[i + 1]);
    }
  }

  print("Clave: " + clave);

  // + 1 para empezar en 1 
  int length = len + 1; 
  // Añade el numero de producto correspondiente
  if (length < 9) {
    clave += "00" + to_string(length);
  } else {
    clave += "0" + to_string(length);
  }

  return clave;
}

// 1: Alta del producto
void crearProducto() {
  if (len == 50) {
    print("No se pueden agregar más productos. El cupo ha llegado a su limite.");
    return;
  }
  
  Producto producto;

  producto.proveedor = getString("Cual es el proveedor del producto?");
  producto.nombre = getString("Cual es el nombre del producto?");
  producto.cantidad = getInt("Cual es la cantidad del producto?");
  producto.precio = getFloat("Cual es el precio del producto?");

  imprimirProducto(producto);

  bool correcto = getBool("Los datos son correctos?");
  if (correcto) {
    print("Producto Registrado");
    producto.clave = getClave(producto.proveedor);
    inventario[len] = producto;
    len++;
  } else {
    print("Producto no Registrado");
  }
}

// 2: Modificacion de un producto
void modificarProducto() {
  string id = getString("Cual es la clave del producto a modificar?");
  int index = -1;

  for (int i = 0; i < len; i++) {
    if (inventario[i].clave == id) {
      index = i;
      break;
    }
  }

  if (index == -1) {
    print("Producto no Encontrado");
    return;
  }

  Producto producto = inventario[index];
  print("Producto a Modificar");
  imprimirProducto(producto);

  if (getBool("Desea modificar el proveedor?")) {
    producto.proveedor = getString("Cual es el proveedor del producto?");
  }

  if (getBool("Desea modificar el nombre?")) {
    producto.nombre = getString("Cual es el nombre del producto?");
  }

  if (getBool("Desea modificar la cantidad?")) {
    producto.cantidad = getInt("Cual es la cantidad del producto?");
  }

  if (getBool("Desea modificar el precio?")) {
    producto.precio = getFloat("Cual es el precio del producto?");
  }

  print("Producto Modificado");
  imprimirProducto(producto);
}


// 3: Catalogo de Productos
void imprimirCatalogo() {
  for (int i = 0; i < len; i++) {
    imprimirProducto(inventario[i]);
  }
}

// 4: Productos con existencia menor a la ingresada
void imprimirProductosMenorCantidadA() {
  int cantidad = getInt("Cual es la cantidad?");
  bool encontrado = false;

  for (int i = 0; i < len; i++) {
    if (inventario[i].cantidad < cantidad) {
      imprimirProducto(inventario[i]);
      encontrado = true;
    }
  }

  if (not encontrado) {
    print("No se encontraron productos con cantidad menor a " + to_string(cantidad));
  }
}

// 5: Productos de un proveedor especifico
void imprimirProductosProveedor() {
  string proveedor = getString("Cual es el proveedor?");
  string proveedorMinusculas = toLowerCase(proveedor);
  bool encontrado = false;

  for (int i = 0; i < len; i++) {
    if (toLowerCase(inventario[i].proveedor) == proveedorMinusculas) {
      imprimirProducto(inventario[i]);
      encontrado = true;
    }
  }

  if (not encontrado) {
    print("No se encontraron productos del proveedor " + proveedor);
  }
}

// 6: Productos con un precio mayor al ingresado
void imprimirProductosPrecioMayorA() {
  float precio = getFloat("Cual es el precio?");
  bool encontrado = false;

  for (int i = 0; i < len; i++) {
    if (inventario[i].precio > precio) {
      imprimirProducto(inventario[i]);
      encontrado = true;
    }
  }

  if (not encontrado) {
    print("No se encontraron productos con precio mayor a " + to_string(precio));
  }
}

int main() {
  print("Programa de Administración de Productos");


  while (true) {
    print("\tFarmacia Xalapa");
    print("1 - Alta del producto");
    print("2 - Modificacion de un producto");
    print("3 - Catalogo de Productos");
    print("4 - Productos con existencia menor a la ingresada");
    print("5 - Productos de un proveedor especifico");
    print("6 - Productos con un precio mayor al ingresado");
    print("7 - Salir del programa");

    int option = getInt("Ingrese una opción");

    if (option == 7) break;

    limpiarPantalla();

    switch (option) {
      case 1: {
        print("Alta de Producto");
        crearProducto();
        break;
      }
      case 2: {
        print("Modificacion de un Producto");
        modificarProducto();
        break;
      }
      case 3: {
        print("Catalogo de Productos");
        imprimirCatalogo();
        break;
      }
      case 4: {
        print("Productos con existencia menor a la ingresada");
        imprimirProductosMenorCantidadA();
        break;
      }
      case 5: {
        print("Productos de un proveedor especifico");
        imprimirProductosProveedor();
        break;
      }
      case 6: {
        print("Productos con un precio mayor al ingresado");
        imprimirProductosPrecioMayorA();
        break;
      }
      default: {
        print("Opción Invalida");
        break;
      }
    }
  }

  limpiarPantalla();
  print("Gracias por usar el programa de Administración de Productos");

  return 0;
}