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

