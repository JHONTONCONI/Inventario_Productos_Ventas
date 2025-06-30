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
