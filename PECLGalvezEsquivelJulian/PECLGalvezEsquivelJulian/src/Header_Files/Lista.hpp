#ifndef LISTA_HPP
#define LISTA_HPP

#include <iostream>
#include <iomanip> // Para std::setw y std::left
#include "NodoLista.hpp" // Archivo de cabecera para NodoLista y Proceso

class Lista {
private:
    NodoLista* cabeza;

public:
    // Constructor
    Lista();

    // Método para insertar un proceso en la lista
    void insertar(Proceso v);

    // Método para mostrar la lista de procesos normales en formato tabla
    void muestraProcesosNormal() const;
	
	// Método para mostrar la lista de procesos en tiempo real en formato tabla
    void muestraProcesosTiempoReal() const;
	
	//Método para buscar los procesos del usuario
	void buscarProcesosUsuario() const;
	
	// Método para vaciar la lista al reiniciar
    void vaciar() const;

    // Otros métodos (buscar, eliminar, etc.) se pueden declarar aquí
	
	
};

#endif // LISTA_H
