#include <iostream>
#include <string>
using namespace std;

struct Producto {
    string nombre;
    float precio;
};

struct Venta {
    int idVenta;
    string producto;
    int cantidad;
    float precioTotal;
};

const int MAX_PRODUCTOS = 100;
const int MAX_VENTAS = 100;

Producto listaProductos[MAX_PRODUCTOS];
Venta listaVentas[MAX_VENTAS];

int cantidadProductos = 0;
int cantidadVentas = 0;
int siguienteIdVenta = 1;

void registrarProducto() {
    if (cantidadProductos >= MAX_PRODUCTOS) {
        cout << "No se pueden registrar mas productos."<<endl;
        return;
    }
    cout << "Nombre del producto: ";
    getline(cin, listaProductos[cantidadProductos].nombre);
    cout << "Precio: ";
    cin >> listaProductos[cantidadProductos].precio;
    cin.ignore();

    cantidadProductos++;
    cout << "Producto registrado con exito."<<endl;
}

void listarProductos() {
    if (cantidadProductos == 0) {
        cout << "No hay productos registrados."<<endl;
        return;
    }
    for (int i = 0; i < cantidadProductos; i++) {
        cout << i + 1 << ". " << listaProductos[i].nombre<<endl;
        cout << "Precio: " << listaProductos[i].precio<<endl;
    }
}

void buscarProducto() {
    string nombre;   
    if (cantidadProductos == 0) {
        cout << "No hay productos registrados."<<endl;
        return;
    }
    cout << "Ingrese el nombre del producto a buscar: ";
    getline(cin, nombre);

    for (int i = 0; i < cantidadProductos; i++) {
        if (listaProductos[i].nombre == nombre) {
            cout << "Producto encontrado: " << listaProductos[i].nombre<<endl;
            cout << "Precio: " << listaProductos[i].precio<<endl;
            return;
        }
    }
    cout<<"Producto no encontrado."<<endl;
}

void actualizarProducto() {
    string nombre;
    if (cantidadProductos == 0) {
        cout << "No hay productos registrados."<<endl;
        return;
    }
    cout << "Ingrese el nombre del producto a actualizar: ";
    getline(cin, nombre);

    for (int i = 0; i < cantidadProductos; i++) {
        if (listaProductos[i].nombre == nombre) {
            cout << "Nuevo nombre: ";
            getline(cin, listaProductos[i].nombre);
            cout << "Nuevo precio: ";
            cin >> listaProductos[i].precio;
            cin.ignore();
            cout << "Producto actualizado."<<endl;
            return;
        }
    }
    cout << "Producto no encontrado."<<endl;
}

void eliminarProducto() {
    string nombre;
    if (cantidadProductos == 0) {
        cout << "No hay productos registrados."<<endl;
        return;
    }
    cout<< "Ingrese el nombre del producto a eliminar: ";
    getline(cin, nombre);

    for (int i = 0; i < cantidadProductos; i++) {
        if (listaProductos[i].nombre == nombre) {
            for (int j = i; j < cantidadProductos - 1; j++) {
                listaProductos[j] = listaProductos[j + 1];
            }
            cantidadProductos--;
            cout << "Producto eliminado."<<endl;
            return;
        }
    }
    cout<< "Producto no encontrado."<<endl;
}

void registrarVenta() {
    string nombreProducto;
    int cantidad;

    cout << "Nombre del producto vendido: ";
    getline(cin, nombreProducto);

    int validador = -1;
    for (int i = 0; i < cantidadProductos; i++) {
        if (listaProductos[i].nombre == nombreProducto) {
            validador = i;
            break;
        }
    }

    if (validador == -1) {
        cout << "Producto no encontrado."<<endl;
        return;
    }

    cout << "Cantidad: ";
    cin >> cantidad;
    cin.ignore();

    listaVentas[cantidadVentas].idVenta = siguienteIdVenta++;
    listaVentas[cantidadVentas].producto = nombreProducto;
    listaVentas[cantidadVentas].cantidad = cantidad;
    listaVentas[cantidadVentas].precioTotal = listaProductos[validador].precio * cantidad;

    cantidadVentas++;
    cout << "Venta registrada con exito."<<endl;
}

void listarVentas() {
    if (cantidadVentas == 0) {
        cout << "No hay ventas registradas."<<endl;
        return;
    }
    for (int i = 0; i < cantidadVentas; i++) {
        cout << "Venta " << listaVentas[i].idVenta;
        cout << ": " << listaVentas[i].producto<<endl;
        cout << "Cantidad: " << listaVentas[i].cantidad<<endl;
        cout << "Total: " << listaVentas[i].precioTotal<<endl;
    }
}

void calcularTotalVentas() {
    float total = 0;
    for (int i = 0; i < cantidadVentas; i++) {
        total += listaVentas[i].precioTotal;
    }
    cout << "Total de ventas realizadas: " << total << endl;
}


int main() {
    char opcion;
    do {
    	cout<<endl;
        cout << "MENU DE INVENTARIO Y VENTAS"<<endl;
        cout << "A. Registrar nuevo producto"<<endl;
        cout << "B. Listar productos"<<endl;
        cout << "C. Buscar producto"<<endl;
        cout << "D. Actualizar producto"<<endl;
        cout << "E. Eliminar producto"<<endl;
        cout << "F. Registrar venta"<<endl;
        cout << "G. Listar ventas"<<endl;
        cout << "H. Calcular total de ventas"<<endl;
        cout << "S. Salir"<<endl;
        cout << "Seleccione una opcion: "<<endl;
        cin >> opcion; cin.ignore();

        switch (opcion) {
            case A: case a: registrarProducto(); break;
            case B: case b: listarProductos(); break;
            case C: case c: buscarProducto(); break;
			case D: case d: actualizarProducto(); break;
			case E: case e: eliminarProducto(); break;
			case F: case f: registrarVenta(); break;
			case G: case g: listarVentas(); break;
			case H: case h: calcularTotalVentas(); break;
            case S: case s: cout << "Saliendo del programa..."<<endl; break;
            default: cout << "Opcion no valida."<<endl;
        }

    } while (opcion != S && opcion != s);
	cout<<endl;
    return 0;
}


