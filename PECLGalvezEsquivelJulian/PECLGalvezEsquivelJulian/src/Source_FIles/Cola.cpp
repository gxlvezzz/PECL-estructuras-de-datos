#include <src/Header_Files/Cola.hpp>
#include <iostream>

using namespace std;



Cola::Cola(){
	longitud=0;
	ultimo=NULL;
}
Cola::~Cola(){
	pnodoCola aux;
		while(ultimo){
			aux = ultimo;
			ultimo = ultimo->siguiente;
			delete aux;
    }
	longitud=0;	
}
	
	
void Cola::encolar(Proceso v){
	pnodoCola nuevo;
    nuevo = new NodoCola(v,ultimo);
    ultimo = nuevo;
    longitud++;	
}

/*void Cola::encolarProcesoNormal(Cola& c){
    pnodoCola aux = ultimo;
    while(aux){
        if(!aux->valor.getTipo()){
			c.encolar(aux->valor);			
		}		
        aux = aux->siguiente;
    }
    cout << endl;
}*/

int Cola::getLongitud(){
    return this->longitud;
}

void Cola::mostrar(){
	if(longitud==0){
		cout << "Esta cola se encuentra vacia." << endl;
	}else{
    pnodoCola aux = ultimo;
    while(aux){
        aux->valor.mostrar(true);
        aux = aux->siguiente;
    }
    cout << endl;
}}

void Cola::extraer(){
    pnodoCola nodo;
    if(!ultimo)
        return;
    nodo = ultimo;
    ultimo = nodo->siguiente;
    longitud--;
    delete nodo;
}

Proceso Cola::cima(){
    if(!ultimo){
        Proceso pro;
        pro.setVacio(true);
        return ultimo->valor;
    }
    return ultimo->valor;
}




