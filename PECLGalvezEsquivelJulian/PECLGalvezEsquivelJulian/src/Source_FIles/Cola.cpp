#include <src/Header_Files/Cola.hpp>
#include <iostream>

using namespace std;



Cola::Cola(){
	longitud=0;
	ultimo=NULL;
}
Cola::~Cola(){
	
}
	
	
void Cola::encolar(Proceso v){
	pnodoCola nuevo;
    nuevo = new NodoCola(v,ultimo);
    ultimo = nuevo;
    longitud++;
	
}

void Cola::encolarProcesoNormal(Cola& c){
    pnodoCola aux = ultimo;
    while(aux){
        if(!aux->valor.getTipo()){
			c.encolar(aux->valor);			
		}		
        aux = aux->siguiente;
    }
    cout << endl;
}

int Cola::getLongitud(){
    return this->longitud;
}

void encolarGPU0(){
	
}




