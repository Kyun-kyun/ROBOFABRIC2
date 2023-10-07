#include <cstdlib>
#include <iostream>
#include "basicAuxiliar.h"
using namespace std;

 


struct Articulo{
	string categorias[3] = {"A", "B", "C"};
	string codigo;
	int cantidadAlmacen;
	int segundosFabricacion;
	string categoria;
	string ubicacionBodega;
	string errores[3];
	
	Articulo(){
		codigo = "";
		cantidadAlmacen = 0;
		segundosFabricacion = 0;
		categoria = "";
		ubicacionBodega = "";
		errores[0] = ""; errores[1] = ""; errores[2] = "";
		
	}
	Articulo(string _codigo, int cantAlmacen, int secFabrica, string _categoria, string ubicacion ){
		codigo = _codigo;
		cantidadAlmacen = cantAlmacen;
		segundosFabricacion = secFabrica;
		if (inCategorias(_categoria)) 
			categoria = _categoria;
		else{
			cout << "La categoria no es valida" << endl;
			errores[2] = "Categoria Invalida";
		}
			

		ubicacionBodega = ubicacion;
	}
	void imprimir(){
		cout << "Codigo: " << "\t" << codigo << endl;
		cout << "Almacen: " << "\t" << cantidadAlmacen << endl;
		cout << "Tiempo Fabricacion: " << "\t" << segundosFabricacion<< endl;
		cout << "Categoria: " << "\t" << categoria << endl;
		cout << "Ubicacion Bodega: " << "\t" << ubicacionBodega << endl;
		cout << "Errores: " << "\t";
		cout << errores[0] << "\t" << errores[1] << "\t" << errores[2] << endl;
		cout << "////////////////////////////////////////////" << endl;
	}
	bool inCategorias(string categoria){
		for (int i = 0; i < 3 ; i++){
			if (categorias[i] == categoria) return true;
		}
		return false;
	}
	
	
};

struct NodoProducto{
	Articulo * articulo;
	NodoProducto * siguiente;
	NodoProducto * anterior;
	
	NodoProducto(Articulo * _articulo)
	{
		articulo = _articulo;
		siguiente = anterior = NULL;
	}
	
	NodoProducto()
	{
		articulo = NULL;
		siguiente = anterior = NULL;
	}
	
	void imprimir (){
		cout << "Articulo: " << endl;
		articulo->imprimir();
	}
};

struct ListaProductos{
	NodoProducto * primerNodo;
	NodoProducto * ultimoNodo;
	
	ListaProductos(){ 
		primerNodo = ultimoNodo = NULL;
	}	
	
	bool isEmpty(){
		return primerNodo == NULL;
	}
	
	//----Buscar articulo por codigo----//
	Articulo * buscarArticulo(string cod){
		NodoProducto * tmp = primerNodo;
		while (tmp != NULL){
			if (tmp->articulo->codigo == cod) 
				return tmp->articulo;
			tmp = tmp->siguiente; 		
		}
		return NULL;
	}
	
	
	void insertarAlFinal (Articulo * articulo){
		if (buscarArticulo(articulo->codigo) == NULL){
			if (isEmpty()){
				primerNodo = ultimoNodo = new NodoProducto (articulo);
			}
				
			else{
				NodoProducto * nuevo = new NodoProducto (articulo);
				nuevo->anterior = ultimoNodo;
				ultimoNodo->siguiente = nuevo;
				ultimoNodo = nuevo;
			}	
		} else cout << "\nNo se pudo agregar el articulo: " << articulo->codigo << ". Esta repetido" << endl;
		
	}

	// IMPRIMIR LISTA
	void imprimir(){
		NodoProducto * tmp = primerNodo;
		while (tmp != NULL){
			tmp->imprimir();
			tmp = tmp->siguiente; 		
		}
		cout <<endl;
	}
	
	/*
	Nodo * borrarAlInicio(){
		Nodo * borrado = primerNodo;
		
		if (primerNodo != NULL)
		{
			// caso solo 1 nodo
			if (primerNodo == ultimoNodo)
				primerNodo = ultimoNodo = NULL;
			else{ // caso mas de un Nodo
				primerNodo = primerNodo->siguiente;
				borrado ->siguiente = NULL;
				primerNodo->anterior = NULL;
			}
		}
		return borrado;
	}
	
	Nodo * borrarAlFinal(){
		Nodo * borrado = ultimoNodo;
		
		if (ultimoNodo != NULL)
		{
			// caso solo 1 nodo
			if (primerNodo == ultimoNodo)
				primerNodo = ultimoNodo = NULL;
			else{ // caso mas de un Nodo
				ultimoNodo = ultimoNodo->anterior;
				borrado->anterior = NULL;
				ultimoNodo->siguiente = NULL;
			}
		}
		return borrado;
	}
	*/
	
	int largo(){
		
		int contador = 0;
		NodoProducto * tmp = primerNodo;
		
		while(tmp != NULL){
			contador++;
		
			tmp = tmp->siguiente;
		}
		return contador;
	}
	
}; 
