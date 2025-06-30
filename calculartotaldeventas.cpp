void calcularTotalVentas() {
    float total = 0;
    for (int i = 0; i < cantidadVentas; i++) {
        total += listaVentas[i].precioTotal;
    }
    cout << "Total de ventas realizadas: " << total << endl;
}

