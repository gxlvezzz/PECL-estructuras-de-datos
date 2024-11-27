#ifndef LISTA_HPP
#define LISTA_HPP

#include <iostream>
#include <src/Header_Files/NodoLista.hpp> 
using namespace std;

class Lista {

public:
    // Constructor
    Lista();
	~Lista();
	
	

    // Método para insertar un proceso en la lista
	void enlistar(Proceso v);
    // Método para mostrar la lista de procesos en formato tabla
    void muestraProcesos() ;
	
	void ordenarListaPorPrioridad();
	//Método para buscar los procesos del usuario
	void buscarProcesosUsuario(string user) ;
	
	// Método para vaciar la lista al reiniciar
    Proceso extraer(int pid);
	
	//Método para ordenar por menor prioridad
	Proceso menorPrioridad();
	
	//Método para ordenar por mayor prioridad
	Proceso mayorPrioridad();
	
	Proceso obtenerMenorPrioridad();
	
	Proceso obtenerMayorPrioridad();
	
	//Metodo para encontrar y eliminar un proceso 
	void buscarYEliminarProceso(int pid);
	//Metodo para ordenar lista de mayor a menor
	void ordenarPorPrioridadMayor();
	void ordenarListaProcesosPrioridadMayor();
	
	Proceso* buscarProcesosPID(int pid, bool b);
	Proceso getPrimero();
	Proceso getUltimo();
	int getLongitud();
	void insertarOrdenado(Proceso& proceso);
	
private:
	int longitud;
	pnodoLista ultimo;
	pnodoLista primero;
};

#endif // LISTA_H
