void registrarProducto() {
    if (cantidadProductos >= MAX_PRODUCTOS) {
        cout << "No se pueden registrar más productos."<<endl;
        return;
    }
    cout << "Nombre del producto: ";
    getline(cin, listaProductos[cantidadProductos].nombre);
    cout << "Precio: ";
    cin >> listaProductos[cantidadProductos].precio;
    cin.ignore();

    cantidadProductos++;
    cout << "Producto registrado con éxito."<<endl;
}
