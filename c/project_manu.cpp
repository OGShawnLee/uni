#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

// Nota: Se cargan y se guardan los productos en un archivo de texto llamado "catalogo.txt"
// El formato de cada producto es: proveedor, nombre, precio, cantidad;

struct Producto {
  // La clave es generada a partir del proveedor y el numero de producto en el sistema
  string clave;
  // No puede haber datos vacios
  string proveedor;
  string nombre;
  // El precio no puede ser negativo
  float precio;
  // La cantidad no puede ser negativa
  int cantidad;
};

// Funciones Auxiliares

// Para imprimir un mensaje en la consola y añadir un salto de linea 
void imprimirLinea(string mensaje) {
  cout << mensaje << '\n';
}

// Para imprimir un mensaje en la consola
void imprimir(string mensaje) {
  cout << mensaje;
}

/*
  - Verifica si un string esta vacio.
  1. Itera sobre cada caracter del string.
  2. Si encuentra un caracter que no sea un espacio, retorna falso (no esta vacio).
  3. Si no encuentra ningun caracter que no sea un espacio, retorna verdadero (esta vacio).
*/
bool estaVacio(string texto) {
  for (int i = 0; i < texto.length(); i++) {
    if (texto[i] != ' ') {
      return false;
    }
  }

  return true;
}

/*
  1. Para obtener una linea de texto del usuario.
  2. Se valida que no este vacia, sino se vuelve a preguntar.
  3. Se elimina los espacios al principio y al final.
  - Se usa para obtener los datos de un producto
*/
string obtenerLinea(string mensaje) {
  string texto;
  
  while (true) {
    // Imprimir mensaje y obtener texto del usuario
    imprimir(mensaje + ": ");
    getline(cin, texto);

    // Validar que no este vacio
    if (estaVacio(texto)) {
      imprimirLinea("Entrada vacia, intente de nuevo");
    } else {
      break;
    }
  }

  return texto;
}

/* 
  1. Para obtener un booleano del usuario.
  2. Se valida que sea 's' o 'n', sino se vuelve a preguntar.
  - Se usa para confirmar si se desea agregar un producto  
*/
bool obtenerBooleano(string mensaje) {
  string texto;

  while (true) {
    imprimir(mensaje + " (s/n): ");
    cin >> texto;
    // Validar que sea 's' o 'n'
    if (texto == "s") {
      return true;
    } else if (texto == "n") {
      return false;
    } else {
      cout << "Entrada invalida, asegurese de introducir 's' o 'n'" << endl;
    }
  }
}

/*
  1. Para obtener un numero entero del usuario.
  2. Se valida que sea un numero entero, sino se vuelve a preguntar.
  - Se usa para obtener la cantidad de productos
*/
int obtenerEntero(string mensaje) {
  int entero;

  while (true) {
    imprimir(mensaje + ": ");
  
    cin >> entero;
    
    if (entero >= 0) {
      break;
    } else {
      imprimirLinea("Entrada invalida, asegurese de introducir un numero entero positivo");
    }
  }

  return entero;
}

/*
  1. Para obtener un numero flotante del usuario.
  2. Se valida que sea un numero flotante positivo, sino se vuelve a preguntar.
  - Se usa para obtener el precio de un producto
*/
float obtenerFlotante(string mensaje) {
  float flotante;

  while (true) {
    imprimir(mensaje + ": ");

    cin >> flotante;
    if (flotante >= 0) {
      break;
    } else {
      imprimirLinea("Entrada invalida, asegurese de introducir un numero positivo");
    }
  }

  return flotante;
}

// - Limpiar la pantalla de la consola
void limpiarPantalla() {
  cout << "\033[2J\033[1;1H";
}

// - Imprimir un producto con formato en la consola
void imprimirProducto(Producto producto) {
  imprimirLinea("  Producto {");
  if (producto.clave != "") {
    imprimirLinea("    Clave: " + producto.clave);
  }
  imprimirLinea("    Proveedor: " + producto.proveedor);
  imprimirLinea("    Nombre: " + producto.nombre);
  imprimirLinea("    Precio: " + to_string(producto.precio) + " MXN");
  imprimirLinea("    Cantidad: " + to_string(producto.cantidad));
  imprimirLinea("  }");
}

// Generar Clave
/*
  1. Para generar una clave unica para un producto.
  2. La clave se genera a partir del proveedor y el numero de producto en el sistema.
  Ejemplos: 
    proveedor = "Coca Cola", numero = 1 -> "CC001"
    proveedor = "Farmacias Guadalajara", numero = 2 -> "FG002"
      - Nota: (Se usa la inicial de cada palabra del proveedor)
  - Se usa para identificar un producto en el sistema
*/

// Obtener las iniciales de un proveedor
string obtenerIniciales(string proveedor) {
  string proveedorSeparado;
  // Agregar la primera letra del proveedor en mayuscula
  proveedorSeparado += toupper(proveedor[0]);

  /*
    1. Iterar sobre cada caracter del proveedor.
    2. Si encuentra un espacio, agrega la siguiente letra si es valida al proveedor separado.
  */
  for (int i = 1; i < proveedor.length(); i++) {
    if (
      proveedor[i] == ' ' &&
      // Validar que haya un caracter despues del espacio
      i + 1 < proveedor.length() &&
      // Validar que el caracter despues del espacio no sea otro espacio
      proveedor[i + 1] != ' '
    ) {
      proveedorSeparado += toupper(proveedor[i + 1]);
    }
  }
  return proveedorSeparado;
}

string generarClave(string proveedor, int numeroDeProducto) {
  string clave = obtenerIniciales(proveedor);
  // Agregar un guion
  
  // Agregar el numero del producto
  if (numeroDeProducto < 10) {
    clave += "00";
  } else if (numeroDeProducto < 100) {
    clave += "0";
  }

  clave += to_string(numeroDeProducto);
  return clave;
}

// Imprime las opciones del programa y obtiene la opcion seleccionada
int obtenerIndicacion() {
  int indicacion;

  while (true) {
    // Imprimir opciones
    imprimirLinea("Menu:");
    imprimirLinea("1. Agregar producto");
    imprimirLinea("2. Modificar producto");
    imprimirLinea("3. Mostrar catalogo");
    imprimirLinea("4. Productos con menor precio a cierto valor");
    imprimirLinea("5. Productos de cierto proveedor");
    imprimirLinea("6. Productos con mayor precio a cierto valor");
    imprimirLinea("7. Salir");

    // Obtener indicacion
    cout << ">>> Seleccione una opcion: ";
    cin >> indicacion;

    // Validar indicacion (hay opciones del 1 al 7)
    if (indicacion >= 1 && indicacion <= 7) {
      limpiarPantalla();
      break;
    } else {
      limpiarPantalla();
      cout << "Opcion invalida" << endl;
    }
  }

  return indicacion;
}

// Funciones Principales (una para cada opcion del menu en orden)

// Declaramos protipo aqui por que esta function se usa antes de ser declarada
void mostrarCatalogo(Producto productos[], int cantidadProductos);

// 1. Agregar Producto
// Nota: Se pasa la cantidad de productos por referencia para modificarla
void agregarProducto(Producto productos[], int &cantidadProductos) {
  // Informar al usuario que se esta agregando un producto
  imprimirLinea("1. Agregando Producto - Ingrese los datos del producto:");

  // Validar que haya espacio en el arreglo
  if (cantidadProductos >= 50) {
    imprimirLinea("No hay espacio para mas productos");
    return;
  }

  // Crear un nuevo producto
  Producto producto;
  cin.ignore(); // si no se hace esto, getline no funciona correctamente a veces
  producto.proveedor = obtenerLinea("Proveedor");
  producto.nombre = obtenerLinea("Nombre");
  // Convertir string a float (stof)
  producto.precio = obtenerFlotante("Precio (debe ser positivo)");
  // Convertir string a int (stoi)
  producto.cantidad = obtenerEntero("Cantidad (debe ser positiva)");

  imprimirProducto(producto);
  bool correcto = obtenerBooleano("Desea agregar este producto?");
  if (correcto) {
    // Generar clave
    producto.clave = generarClave(producto.proveedor, cantidadProductos + 1);
    // Agregar producto al arreglo
    productos[cantidadProductos] = producto;
    // Incrementar la cantidad de productos
    cantidadProductos++;
    limpiarPantalla();
    imprimirLinea("Producto agregado con exito con clave: " + producto.clave);
  } else {
    limpiarPantalla();
    imprimirLinea("Producto no agregado");
  }
}

// 2. Modificar Producto
/*
  1. Para modificar un producto en el catalogo.
  2. Se muestra el catalogo de productos.
  3. Se selecciona el producto a modificar.
  4. Se obtienen los nuevos datos del producto.
  5. Se muestra el producto modificado.
  6. Se confirma si se desea modificar el producto.
  7. Se modifica el producto en el arreglo.
*/
void modificarProducto(Producto productos[], int cantidadProductos) {
  imprimirLinea("2. Modificando Producto:");

  if (cantidadProductos == 0) {
    imprimirLinea("No hay productos en el catalogo");
    return;
  }

  // Mostrar catalogo
  mostrarCatalogo(productos, cantidadProductos);

  // Seleccionar producto
  string clave;
  imprimir("Ingrese la clave del producto a modificar: ");
  cin >> clave;

  /*
    1. Iterar sobre cada producto en el catalogo.
    2. Si se encuentra el producto, se guarda el indice y se sale del ciclo.
  */
  bool encontrado = false;
  int indice = 0;

  for (int i = 0; i < cantidadProductos; i++) {
    if (productos[i].clave == clave) {
      encontrado = true;
      indice = i;
      break;
    }
  }

  // No se encontro, nos salimos de la funcion
  if (!encontrado) return;

  Producto original = productos[indice];

  imprimirLinea("Producto a modificar:");
  imprimirProducto(original);

  Producto remplazo;
  remplazo.clave = clave;

  /* 
    Preguntamos si se desea modificar cada campo
    Si no se desea modificar, se mantiene el valor original
  */

  if (obtenerBooleano("Desea modificar el proveedor?")) {
    cin.ignore();
    remplazo.proveedor = obtenerLinea("Proveedor");
  } else {
    remplazo.proveedor = original.proveedor;
  }

  if (obtenerBooleano("Desea modificar el nombre?")) {
    cin.ignore();
    remplazo.nombre = obtenerLinea("Nombre");
  } else {
    remplazo.nombre = original.nombre;
  }

  if (obtenerBooleano("Desea modificar el precio?")) {
    cin.ignore();
    remplazo.precio = obtenerFlotante("Precio (debe ser positivo)");
  } else {
    remplazo.precio = original.precio;
  }

  if (obtenerBooleano("Desea modificar la cantidad?")) {
    cin.ignore();
    remplazo.cantidad = obtenerEntero("Cantidad (debe ser positiva)");
  } else {
    remplazo.cantidad = original.cantidad;
  }

  imprimirLinea("Producto original:");
  imprimirProducto(original);

  imprimirLinea("Producto modificado:");
  imprimirProducto(remplazo);

  bool correcto = obtenerBooleano("Desea actualizar este producto?");
  if (correcto) {
    productos[indice] = remplazo; // Substituir el producto
    limpiarPantalla();
    imprimirLinea("Producto modificado con exito");
  } else {
    limpiarPantalla();
    imprimirLinea("Producto no modificado");
  }
}

// 3. Mostrar Catalogo
void mostrarCatalogo(Producto productos[], int cantidadProductos) {
  imprimirLinea("3. Mostrando Catalogo:");

  if (cantidadProductos == 0) {
    imprimirLinea("No hay productos en el catalogo");
    return;
  }

  for (int i = 0; i < cantidadProductos; i++) {
    imprimirProducto(productos[i]);
  }
}

// 4. Productos con menor precio a cierto valor
/*
  1. Para mostrar los productos con un precio menor a cierto valor.
  2. Se obtiene el valor del usuario.
  3. Se muestran los productos con un precio menor al valor.
  4. Si no se encuentran productos, se informa al usuario.
*/
void productosMenorPrecio(Producto productos[], int cantidadProductos) {
  imprimirLinea("4. Productos con menor precio a cierto valor:");

  if (cantidadProductos == 0) {
    imprimirLinea("No hay productos en el catalogo");
    return;
  }

  cin.ignore();
  float valor = obtenerFlotante("Ingrese el valor");
  bool ningunoEncontrado = true;

  for (int i = 0; i < cantidadProductos; i++) {
    if (productos[i].precio < valor) {
      imprimirProducto(productos[i]);
      ningunoEncontrado = false; // Se encontro al menos un producto
    }
  }

  if (ningunoEncontrado) {
    imprimirLinea("No se encontraron productos con un precio menor a " + to_string(valor) + " MXN");
  }
}

// 5. Productos de cierto proveedor
/*
  1. Para mostrar los productos de un proveedor.
  2. Se obtiene el proveedor del usuario.
  3. Se muestran los productos del proveedor.
  4. Si no se encuentran productos, se informa al usuario.
*/
void productosProveedor(Producto productos[], int cantidadProductos) {
  imprimirLinea("5. Productos de cierto proveedor:");

  if (cantidadProductos == 0) {
    imprimirLinea("No hay productos en el catalogo");
    return;
  }

  string proveedor = obtenerLinea("Ingrese el proveedor");
  bool ningunoEncontrado = true;

  for (int i = 0; i < cantidadProductos; i++) {
    if (productos[i].proveedor == proveedor) {
      imprimirProducto(productos[i]);
      ningunoEncontrado = false; // Se encontro al menos un producto
    }
  }

  if (ningunoEncontrado) {
    imprimirLinea("No se encontraron productos del proveedor " + proveedor);
  }
}

void productosMayorPrecio(Producto productos[], int cantidadProductos) {
  imprimirLinea("6. Productos con mayor precio a cierto valor:");

  if (cantidadProductos == 0) {
    imprimirLinea("No hay productos en el catalogo");
    return;
  }

  float valor = obtenerFlotante("Ingrese el valor");
  bool ningunoEncontrado = true;

  for (int i = 0; i < cantidadProductos; i++) {
    if (productos[i].precio > valor) {
      imprimirProducto(productos[i]);
      ningunoEncontrado = false; // Se encontro al menos un producto
    }
  }

  if (ningunoEncontrado) {
    imprimirLinea("No se encontraron productos con un precio mayor a " + to_string(valor));
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
void cargarProductos(Producto productos[], int &cantidadProductos) {
  ifstream archivo("catalogo.txt");

  imprimirLinea("Cargando catalogo...");

  if (archivo.is_open()) {
    string linea;

    while (getline(archivo, linea)) {
      vector<string> propiedades;
      string propiedad = "";
      
      /*
        1. Se itera sobre cada caracter de la linea y se acumula en la propiedad en ciertos casos.
        2. Si se encuentra una coma o un punto y coma, se agrega la propiedad al vector y se reinicia la propiedad.
        3. Se crea un producto con las propiedades y se agrega al arreglo de productos.
      */

      for (int i = 0; i < linea.length(); i++) {
        char caracter = linea[i];
        
        /*
          1. Si el caracter es una coma o un punto y coma, se agrega la propiedad al vector y se reinicia la propiedad.
          2. Si el caracter no es un espacio, se agrega a la propiedad.
        */
        if (caracter == ',' || caracter == ';') {
          // Se elimina el espacio al principio de la propiedad
          // El espacio se coloca para que sea mas facil leer las propiedades en el archivo
          if (propiedad[0] == ' ') {
            propiedad = propiedad.substr(1);
          }

          propiedades.push_back(propiedad);
          propiedad = "";
        } else {
          propiedad += caracter;
        }
      }

      Producto producto;
      producto.proveedor = propiedades[0];
      producto.nombre = propiedades[1];
      producto.precio = stof(propiedades[2]);
      producto.cantidad = stoi(propiedades[3]);
      producto.clave = generarClave(producto.proveedor, cantidadProductos + 1);
      productos[cantidadProductos] = producto;
      cantidadProductos++;
    }

    imprimirLinea("Catalogo cargado con exito");

    archivo.close();
  } else {
    imprimirLinea("No se pudo cargar el catalogo");
  }
}

void guardarProductos(Producto productos[], int cantidadProductos) {
  ofstream archivo("catalogo.txt");

  imprimirLinea("Guardando catalogo...");

  if (archivo.is_open()) {
    for (int i = 0; i < cantidadProductos; i++) {
      Producto producto = productos[i];
      string productoTexto;
      productoTexto += producto.proveedor + ", ";
      productoTexto += producto.nombre + ", ";
      productoTexto += to_string(producto.precio) + ", ";
      productoTexto += to_string(producto.cantidad) + ";";
      archivo << productoTexto << '\n';
    }

    archivo.close();
    imprimirLinea("Catalogo guardado con exito");
  } else {
    imprimirLinea("No se pudo guardar el catalogo");
  }
}

int main() {
  imprimirLinea("Bienvenido al sistema de gestion de productos");

  Producto productos[50];
  int cantidadProductos = 0; 
  cargarProductos(productos, cantidadProductos);

  // Programa principal
  /*
    Ciclo infinito que se rompe cuando el usuario selecciona la opcion de salir
  */
  while (true) {
    int indicacion = obtenerIndicacion();

    switch (indicacion) {
      case 1:
        agregarProducto(productos, cantidadProductos);
        break;
      case 2:
        modificarProducto(productos, cantidadProductos);
        break;
      case 3:
        mostrarCatalogo(productos, cantidadProductos);
        break;
      case 4:
        productosMenorPrecio(productos, cantidadProductos);
        break;
      case 5:
        productosProveedor(productos, cantidadProductos);
        break;
      case 6:
        productosMayorPrecio(productos, cantidadProductos);
        break;
      default:
        imprimirLinea("Gracias por usar el sistema de gestion de productos"); 
        guardarProductos(productos, cantidadProductos);
        return 0;
    }
  }

  return 0;
}