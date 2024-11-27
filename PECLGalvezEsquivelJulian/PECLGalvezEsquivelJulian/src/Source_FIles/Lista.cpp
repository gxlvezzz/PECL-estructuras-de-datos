#include "src/Header_Files/Lista.hpp"
#include "src/Header_Files/Proceso.hpp"
#include "src/Header_Files/NodoLista.hpp"
#include "src/Header_Files/Pila.hpp"
#include <iostream>
using namespace std;

// Constructor
Lista::Lista() {
    longitud=0;
	primero=ultimo=nullptr;
}

	
	


// Método para mostrar los procesos normales en formato tabla
void Lista::muestraProcesos()  {
   if(longitud==0){
		return;
	}else{
		cout << "PID\tUsuario\t\tTipo\t\tEstado\t\tPrioridad" << endl;
    cout << "-----------------------------------------------------------------" << endl; // Línea de separación
    pnodoLista aux = primero;
    while(aux!=nullptr){
        aux->valor->mostrarEnTabla();
        aux = aux->siguiente;
    }
    cout << endl;
    }

    
}


void Lista::ordenarListaPorPrioridad() {
    if (longitud < 2) return; // No hay necesidad de ordenar si la lista tiene menos de 2 elementos

    pnodoLista i, j;

    // Ordenamiento tipo burbuja, iterando sobre los nodos de la lista
    for (i = primero; i != nullptr; i = i->siguiente) {
        for (j = i->siguiente; j != nullptr; j = j->siguiente) {
            if (i->valor->getPrioridad() > j->valor->getPrioridad()) {
                // Intercambiar los valores de los nodos
                Proceso* temp = i->valor;
                i->valor = j->valor;
                j->valor = temp;
            }
        }
    }
}


Proceso Lista::obtenerMenorPrioridad() {
	ordenarListaPorPrioridad();
    return getPrimero();
}

Proceso Lista::obtenerMayorPrioridad() {
	ordenarListaPorPrioridad();
    return getUltimo();
}

void Lista::ordenarPorPrioridadMayor() {
     if (longitud < 2) return; // No hay necesidad de ordenar si la lista tiene menos de 2 elementos

    pnodoLista i, j;

    // Ordenamiento tipo burbuja, iterando sobre los nodos de la lista
    for (i = primero; i != nullptr; i = i->siguiente) {
        for (j = i->siguiente; j != nullptr; j = j->siguiente) {
            // Cambiar la condición de comparación para ordenar de mayor a menor
            if (i->valor->getPrioridad() < j->valor->getPrioridad()) {
                // Intercambiar los valores de los nodos
                Proceso* temp = i->valor;
                i->valor = j->valor;
                j->valor = temp;
            }
        }
    }
}

void Lista::ordenarListaProcesosPrioridadMayor() {
if (longitud < 2) return; 

    ordenarPorPrioridadMayor();
	pnodoLista actual = primero;
    while (actual != nullptr) {
        Proceso* proceso = actual->valor;
        // Mostramos los detalles de cada proceso en formato de tabla
        cout << "El proceso cuyo PID es " << proceso->getPID()
             << ", es de tipo " << (proceso->getTipo() ? "tiempo real" : "normal")
             << ", su estado es " << (proceso->getEstado() ? "ejecucion" : "parado")
             << " y su prioridad es " << proceso->getPrioridad() << endl;
        actual = actual->siguiente; // Avanzamos al siguiente nodo
    }
}


void Lista::buscarProcesosUsuario(string user){
     if (longitud < 1) {
        cout << "No hay procesos en esta lista." << endl;
        return;
    }

    bool encontrado = false; // Variable para verificar si se encuentran procesos
    pnodoLista aux = primero;

    while (aux != nullptr) {
        if (aux->valor->getUsuario() == user) {
            aux->valor->mostrarEnTabla(); // Mostrar el proceso en formato tabla
            encontrado = true;
        }
        aux = aux->siguiente;
    }

    if (!encontrado) {
        cout << "No se encontraron procesos para el usuario \"" << user << "\" en esta lista." << endl;
    }
}

Proceso* Lista::buscarProcesosPID(int pid, bool imprimir) {
    if (longitud < 1) {
        return nullptr;
    }
    pnodoLista aux = primero;
    while (aux != NULL) {
        if (aux->valor->getPID() == pid) {
            if (imprimir) {
                aux->valor->mostrarEnTabla();  
            }
            return (aux->valor);  
        }
        aux = aux->siguiente;
    }
    return nullptr; 
}



void Lista::enlistar(Proceso v) {
    // Crear un nuevo nodo y un nuevo Proceso dinámicamente
    pnodoLista nuevo = new NodoLista(new Proceso(v)); 

    // Inicializar los punteros del nodo
    nuevo->siguiente = nullptr; 
    nuevo->anterior = ultimo;  // Apuntar al nodo anterior (el último actual)

    // Actualizar el estado del proceso almacenado en el nodo
    nuevo->valor->setEstado(true);

    // Si la lista estaba vacía, este será el primer nodo
    if (longitud == 0) {
        primero = nuevo; // Actualizar el inicio de la lista
    } else {
        ultimo->siguiente = nuevo; // Actualizar el siguiente del último nodo actual
    }

    // Actualizar el puntero `ultimo` al nuevo nodo
    ultimo = nuevo;

    // Incrementar la longitud de la lista
    longitud++;
}


Proceso Lista::extraer(int pid){
    if (!ultimo) return Proceso();

    pnodoLista nodo = primero;
    pnodoLista anterior = nullptr;

    while (nodo->valor->getPID() != pid) {
        anterior = nodo;
        nodo = nodo->siguiente;
    }
    if (!nodo) return Proceso();
	Proceso procesoEliminado = *(nodo->valor);
    if (nodo == primero) {
        primero = nodo->siguiente;
    } else {

        anterior->siguiente = nodo->siguiente;
    }

    delete nodo;
    longitud--;
	return procesoEliminado;
}




Proceso Lista::getPrimero() {
    return *(this->primero->valor); // Retorna una copia del objeto
}

Proceso Lista::getUltimo() {
    return *(this->ultimo->valor); // Retorna una copia del objeto
}


int Lista::getLongitud(){
    return this->longitud;
}

void Lista::insertarOrdenado(Proceso& proceso) {
    pnodoLista nuevo = new NodoLista(new Proceso(proceso));

    if (this->longitud == 0) {
        // Caso especial: lista vacía
        this->primero = this->ultimo = nuevo;
    } else {
        pnodoLista actual = this->primero;
        pnodoLista anterior = nullptr;

        // Encontrar la posición correcta para insertar
        while (actual != nullptr && actual->valor->getPrioridad() < proceso.getPrioridad()) {
            anterior = actual;
            actual = actual->siguiente;
        }

        // Ajustar prioridades antes de insertar para evitar duplicados
        while (actual != nullptr && actual->valor->getPrioridad() == proceso.getPrioridad()) {
            proceso.setPrioridad(proceso.getPrioridad() + 1);
        }

        // Insertar el nuevo nodo en la posición correcta
        if (anterior == nullptr) {
            // Insertar al inicio
            nuevo->siguiente = this->primero;
            this->primero->anterior = nuevo;
            this->primero = nuevo;
        } else if (actual == nullptr) {
            // Insertar al final
            anterior->siguiente = nuevo;
            nuevo->anterior = anterior;
            this->ultimo = nuevo;
        } else {
            // Insertar en el medio
            anterior->siguiente = nuevo;
            nuevo->anterior = anterior;
            nuevo->siguiente = actual;
            actual->anterior = nuevo;
        }

        // Ajustar prioridades en cascada después de insertar
        pnodoLista iterador = nuevo->siguiente;
        while (iterador != nullptr) {
            if (iterador->valor->getPrioridad() <= nuevo->valor->getPrioridad()) {
                iterador->valor->setPrioridad(nuevo->valor->getPrioridad() + 1);
                nuevo = iterador; // Actualiza el nodo de referencia para la comparación
            }
            iterador = iterador->siguiente;
        }
    }

    this->longitud++;
}






// Destructor
Lista::~Lista() {
    pnodoLista aux;
		while(ultimo){
			aux = ultimo;
			ultimo = ultimo->siguiente;
			delete aux;
    }
	longitud=0;
}

