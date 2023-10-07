#include <iostream>
#include <string>
#include "Clientes.h"

using namespace std;

struct Nodo{
	
	ListaString* datosNodo; 
	
	Nodo* siguiente;
	string nombreArchivo;
	
	Nodo(string pedidoTxt, ListaString* _datosNodo){
		
		datosNodo = _datosNodo;
		siguiente = NULL;
		nombreArchivo = pedidoTxt;
		
	}
	
	void imprimir(){
		
        cout << "Nombre: " << nombreArchivo << endl;
        datosNodo->imprimir();
        
	}
};

struct ColaPedidos {
	
	Nodo* frente; // Primer nodo.
	Nodo* fondo; // Último nodo.
	
	ColaPedidos(){
		frente = fondo = NULL;
	}
	
	// ¿Está vacía?
	bool isEmpty(){
		 return frente == NULL;
	}
	
	// Insertar al final.
	void encolar(Nodo* pedidoNuevo){
		if (isEmpty()){
			fondo = frente = pedidoNuevo;
		}else{
			fondo->siguiente = pedidoNuevo;
			fondo = pedidoNuevo;
		}
	}
	
	// Borrar al inicio.
	Nodo* desencolar(){
        Nodo* borrado = frente;

        if (not isEmpty()) {
            if (frente == fondo) // caso solo 1 nodo
                frente = fondo = NULL;
            else { 					// caso mas de un Nodo
                frente = frente->siguiente;
                borrado->siguiente = NULL;
            }
        }
        return borrado;
    }
    
    Nodo* peek(){
    	return frente;
	}
	
	// Imprimir lista.
	void imprimir() {
        Nodo* tmp = frente;
        while (tmp != NULL) {
            tmp->imprimir();
            tmp = tmp->siguiente;
        }
        cout << endl;
    }	
    
    
};


