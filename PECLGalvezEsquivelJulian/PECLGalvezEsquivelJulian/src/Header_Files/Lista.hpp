#ifndef LISTA_HPP
#define LISTA_HPP

#include <iostream>
#include <src/Header_Files/NodoLista.hpp> 
using namespace std;

class Lista {
private:
    NodoLista* cabeza;

public:
    // Constructor
    Lista();
	~Lista();
	
	

    // Método para insertar un proceso en la lista
	void enlistar(Proceso v);
    // Método para mostrar la lista de procesos normales en formato tabla
    void muestraProcesosNormal() ;
	
	// Método para mostrar la lista de procesos en tiempo real en formato tabla
    void muestraProcesosTiempoReal() ;
	
	//Método para buscar los procesos del usuario
	void buscarProcesosUsuario(string user) ;
	
	// Método para vaciar la lista al reiniciar
    void extraer();
	int getLongitud();
	
private:
	int longitud;
	pnodoLista ultimo;
};

#endif // LISTA_H
