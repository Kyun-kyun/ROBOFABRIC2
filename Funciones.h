#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <thread>
#include <windows.h>

#include "archivos.h"
#include "productos.h"
using namespace std;
using namespace std::this_thread;
using namespace std::chrono;


//---Por temas de inclusiones circulares metodos como extraer clientes se desarrollan aqui----
//*
//*
//*
//*
//-------------------------------------------CLIENTES-------------------------------------------//


//-----Extraer los datos del cliente de la linea del txt------//
Cliente * extraerCliente(string linea){
	string codigo = "";
	string nombre = "";
	int prioridad = 0;
	
	int cont = 0;
	string dato = "";
	
	while(linea != "" ){
		char letra = linea[0];
		linea = linea.substr(1);
		if (letra != '\t') {
			dato += letra;
		}
		
		else {
			if (cont == 0) codigo = dato;
			else if (cont == 1) nombre = dato;
			dato = "";
			cont ++;
		}
	} 
	prioridad = strToInt(dato);
	return new Cliente(codigo, nombre, prioridad);
}

//------Agregar cliente del txt a la lista de clientes-------//
ListaCliente * agregarClientes(string ubicacion){
	ListaCliente * clientes = new ListaCliente();
	
	ListaString * stringClientes = leerTXT(ubicacion);
	NodoStr * tmp = stringClientes->pn;
	while (tmp != NULL) {
        clientes->insertarAlFinal(extraerCliente(tmp->dato));
        tmp = tmp->siguiente;
    }
    return clientes;
}



//-------------------------------------------PRODUCTOS-------------------------------------------//

//----Extraer articulo---//
Articulo * extraerArticulo(string linea){
	//---Atributos del articulo---//
	string codigo = "";
	int cantidadAlmacen = 0;
	int segundosFabricacion = 0;
	string categoria = "";
	string ubicacionBodega = "";
	
	int cont = 0;
	string dato = "";
	
	while(linea != "" ){
		char letra = linea[0];
		linea = linea.substr(1);
		if (letra != '\t') {
			dato += letra;
		}
		
		else {
			if (cont == 0) 
				codigo = dato;
			else if (cont == 1) 
				cantidadAlmacen = strToInt(dato);
			else if (cont == 2) 
				segundosFabricacion = strToInt(dato);
			else if (cont == 3)
				categoria = dato;
			dato = "";
			cont ++;
		}
	} 
	ubicacionBodega = dato;
	return new Articulo(codigo, cantidadAlmacen, segundosFabricacion, categoria, ubicacionBodega);
}

//------Agregar articulos al almacen de productos-------//
ListaProductos * agregarArticulos(string ubicacion){
	ListaProductos * productos = new ListaProductos();
	
	ListaString * stringArticulos = leerTXT(ubicacion);
	NodoStr * tmp = stringArticulos->pn;
	while (tmp != NULL) {
        productos->insertarAlFinal(extraerArticulo(tmp->dato));
        tmp = tmp->siguiente;
    }
    return productos;
}










// ------------ Cliente prio ------------ //
int clientePrio(string nombreCliente){
	
	
	ListaString* clientes = leerTXT("C:\\Users\\Hellish\\Desktop\\Programa1_CPP\\ROBOFABRIC\\Sistema\\Clientes.txt");
	clientes->imprimir();
	
	int prio = clientes->prioCliente(nombreCliente);
	
	
	
	return prio;
}


// --------- Timer ------------ //
void tick() {
    while (true) {
    	
        cout << "Tick" << endl;
        
        analizarCarpeta("C:/Users/Hellish/Desktop/Programa1_CPP/Sistema/Pedidos/Pendientes");
        
        sleep_for(seconds(1));
    }
}





