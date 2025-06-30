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

