#include <iostream>
#include <string>
#include "ListaString.h"
using namespace std;

//-------------------------------Clientes-----------------------------------------
struct Cliente{
	string codigo;
	string nombreCliente;
	int prioridad;
	
	Cliente(){
		codigo = "";
		nombreCliente = "";
		prioridad = 0;		
	}
	Cliente(string _codigo, string _nombre, int _prioridad){
		codigo = _codigo;
		nombreCliente = _nombre;
		if (_prioridad > 0 && _prioridad < 11){
			prioridad = _prioridad;
		} else prioridad = 0;
		
	}
	
	void imprimir(){
		cout << "Codigo: " << "\t" << codigo << endl;
		cout << "Nombre: " << "\t" << nombreCliente << endl;
		cout << "Prioridad: " << "\t" << prioridad << endl;
	}
	
};

struct NodoCliente{
	
	NodoCliente* siguiente;
	Cliente * cliente;
	
	//Constructores----------------------------------
	NodoCliente(){
		siguiente = NULL;
		cliente = new Cliente();
	}
	NodoCliente(Cliente * _cliente){
		siguiente = NULL;
		cliente  = _cliente;
	}
	NodoCliente(string codigo, string nombre, int prioridad){
		siguiente = NULL;
		cliente = new Cliente(codigo, nombre, prioridad);
	}
	
	//Metodos-------------------------------------
	void imprimir(){
        cliente->imprimir(); 
	}
	
	
};

struct ListaCliente{
	NodoCliente* pn; // Primer nodo.
	NodoCliente* un; //Ultimo Nodo
	
	ListaCliente(){
		pn = NULL;
		un = NULL;
	}
	
	// ¿Está vacía?
	bool isEmpty(){
		 return pn == NULL;
	}
	
	// Insertar al final.
	void insertarAlFinal(Cliente * cliente){
		
		NodoCliente* nuevo = new NodoCliente(cliente);
		
		if (isEmpty()){
			pn = un = nuevo;
			
		}else{
			un->siguiente = nuevo;
			un = nuevo;
		}
	}
	
	// Imprimir lista.
	void imprimir() {
        NodoCliente* tmp = pn;
        while (tmp != NULL) {
            tmp->imprimir();
            tmp = tmp->siguiente;
        }
        cout << endl;
    }
    
    Cliente * buscarPorCodigo(string cod){
    	NodoCliente* tmp = pn;
        while (tmp != NULL) {
            if (tmp->cliente->codigo == cod) 
				return tmp->cliente;
            tmp = tmp->siguiente;
        }
        return NULL;
	}
	
	//TODO----------------------getPrioridadPorPedido
    
};