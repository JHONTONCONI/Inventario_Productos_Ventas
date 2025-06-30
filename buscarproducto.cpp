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
