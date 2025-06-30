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

