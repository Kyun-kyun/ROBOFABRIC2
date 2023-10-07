#include <iostream>
#include <string>
using namespace std;

struct NodoStr{
	
	NodoStr* siguiente;
	string dato;
	
	NodoStr(string dato){
		siguiente = NULL;
		this->dato = dato;
	}
	
	void imprimir(){
        cout << dato << endl;  
	}
	
	// obtener nombre Nodo
	string nombreCliente(){
		string cadena = "";
		int leerCont = 0;
		
		for (char ch : dato){
			if (ch == '\t'){
				cout << "Tab ";
				leerCont++;	
			}
			
			if (leerCont == 1){
				cadena = cadena + ch;
			}	
		}
		
		return cadena;	
	}
	
	// obtener prio Nodo
	int prioCliente(){
		
		string cadena = "";
		int leerCont = 0;
		
		for (char ch : dato){
			if (ch == '\t'){
				cout << "Tab ";
				leerCont++;	
			}
			
			if (leerCont == 2){
				cadena = cadena + ch;
			}
		}
		
		int prio = stoi(cadena);
		return prio;
	}
};

struct ListaString {
	
	NodoStr* pn; // Primer nodo.
	NodoStr* un; //Ultimo Ndo
	
	ListaString(){
		pn = NULL;
		un = NULL;
	}
	
	// ¿Está vacía?
	bool isEmpty(){
		 return pn == NULL;
	}
	
	// Insertar al final.
	void insertar(string datoStr){
		
		NodoStr* nuevo = new NodoStr(datoStr);
		
		if (isEmpty()){
			pn = un = nuevo;
			
		}else{
			un->siguiente = nuevo;
			un = nuevo;
		}
	}
	
	// Imprimir lista.
	void imprimir() {
        NodoStr* tmp = pn;
        while (tmp != NULL) {
            tmp->imprimir();
            tmp = tmp->siguiente;
            
        }
        cout << endl;
    }
    
    int largo(){
    	int contador = 0;
    	NodoStr * tmp = pn;
    	while (tmp != NULL) {
            contador++;
            tmp = tmp->siguiente;
        }
        return contador;
	}
	
<<<<<<< HEAD

=======
	int prioCliente(string _nombreCliente){
		
		NodoStr* tmp = pn;
		
		while (tmp != NULL){
			
			cout << "Nombre: " + tmp->nombreCliente() + "--- >>> " + _nombreCliente<< endl;
			if (tmp->nombreCliente() == _nombreCliente){
				
				cout << _nombreCliente;
				return tmp->prioCliente();
			}
			tmp = tmp->siguiente;
		}
	}	
>>>>>>> b790eb44e8e975718306a47f034ca7486ab4df60
};
