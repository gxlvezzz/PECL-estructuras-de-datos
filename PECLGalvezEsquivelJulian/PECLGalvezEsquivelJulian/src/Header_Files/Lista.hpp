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
    // Método para mostrar la lista de procesos en formato tabla
    void muestraProcesos() ;
	
	
	//Método para buscar los procesos del usuario
	void buscarProcesosUsuario(string user) ;
	
	// Método para vaciar la lista al reiniciar
    Proceso extraer(int pid);
	
	//Método para ordenar por menor prioridad
	Proceso menorPrioridad();
	
	//Método para ordenar por mayor prioridad
	Proceso mayorPrioridad();
	//Metodo para encontrar y eliminar un proceso 
	void buscarYEliminarProceso(int pid);
	//Metodo para encontrar un proceso por PID
	

	
	void buscarProcesosPID(int pid, bool b);
	
	int getLongitud();
	
private:
	int longitud;
	pnodoLista ultimo;
	int primero;
};

#endif // LISTA_H
