#include <iostream>
#include <string>
using namespace std;

struct robotFabricante{
	string category;
	bool encendido;
	
	// ------- Constructor ------- //
	robotFabricante(string _category){
		this.encendido = true;
		this.category = _category;		
	}

	// Apagar.
	void apagar(){
		encendido = false;
	}
	// Encender.
	void encender(){
		encendido = true;
	}
		
};
