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
