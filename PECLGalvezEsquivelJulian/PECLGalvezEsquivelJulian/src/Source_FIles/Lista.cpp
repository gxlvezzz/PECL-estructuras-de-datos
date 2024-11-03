#include "src/Header_Files/Lista.hpp"

// Constructor
Lista::Lista() {
    cabeza = nullptr;
}

// Método para insertar un proceso
void Lista::insertar(Proceso v) {
    pnodoLista nuevo = new NodoLista(v, cabeza);
    cabeza = nuevo;
}

// Método para vaciar la lista
void Lista::vaciar() {
    pnodoLista aux;
    while (cabeza) {
        aux = cabeza;
        cabeza = cabeza->siguiente;
        delete aux;
    }
}

// Método para mostrar los procesos normales en formato tabla
void Lista::muestraProcesosNormal() const {
    if (cabeza == nullptr) {
        std::cout << "No hay procesos en la lista." << std::endl;
        return;
    }

    std::cout << std::left << std::setw(10) << "PID" 
              << std::setw(15) << "Usuario" 
              << std::setw(15) << "Tipo" 
              << std::setw(15) << "Estado" 
              << std::setw(10) << "Prioridad" 
              << std::endl;

    std::cout << std::string(65, '-') << std::endl;

    pnodoLista actual = cabeza;
    while (actual != nullptr) {
        const Proceso& proceso = actual->valor; // Acceder al proceso del nodo
        if (!proceso.esTiempoReal()) { // Solo muestra si es un proceso normal
            std::cout << std::left << std::setw(10) << proceso.getPID()
                      << std::setw(15) << proceso.getUsuario()
                      << std::setw(15) << "Normal"
                      << std::setw(15) << (proceso.estaEnEjecucion() ? "En Ejecución" : "Parado")
                      << std::setw(10) << proceso.getPrioridad()
                      << std::endl;
        }
        actual = actual->siguiente;
    }
}

// Método para mostrar los procesos de tiempo real en formato tabla
void Lista::muestraProcesosTiempoReal() const {
    if (cabeza == nullptr) {
        std::cout << "No hay procesos en la lista de tiempo real." << std::endl;
        return;
    }

    std::cout << std::left << std::setw(10) << "PID" 
              << std::setw(15) << "Usuario" 
              << std::setw(15) << "Tipo" 
              << std::setw(15) << "Estado" 
              << std::setw(10) << "Prioridad" 
              << std::endl;

    std::cout << std::string(65, '-') << std::endl;

    pnodoLista actual = cabeza;
    while (actual != nullptr) {
        const Proceso& proceso = actual->valor; // Acceder al proceso del nodo
        if (proceso.esTiempoReal()) { // Solo muestra si es tiempo real
            std::cout << std::left << std::setw(10) << proceso.getPID()
                      << std::setw(15) << proceso.getUsuario()
                      << std::setw(15) << "Tiempo Real"
                      << std::setw(15) << (proceso.estaEnEjecucion() ? "En Ejecución" : "Parado")
                      << std::setw(10) << proceso.getPrioridad()
                      << std::endl;
        }
        actual = actual->siguiente;
    }
}

Proceso Lista::menorPrioridad(){
    if(longitud < 1){
        Proceso p;
        p.setVacio(1);
        return p;
    }
    pnodoLista aux = primero;
    pnodoLista maximo = primero;
    
    while(aux->siguiente != NULL){
        if(aux->siguiente->valor.getPrioridad() > maximo->valor.getPrioridad())
            maximo = aux->siguiente;
        aux = aux->siguiente;
    }
    return maximo->valor;
}

Proceso Lista::mayorPrioridad(){
    if(longitud < 1){
        Proceso p;
        p.setVacio(1);
        return p;
    }
    pnodoLista aux = primero;
    pnodoLista minimo = primero;
    
    while(aux->siguiente != NULL){
        if(aux->siguiente->valor.getPrioridad() < minimo->valor.getPrioridad())
            minimo = aux->siguiente;
        aux = aux->siguiente;
    }
    return minimo->valor;
}

void Lista::buscarProcesosUsuario(string user){
    if(longitud < 1)
        return;
    pnodoLista aux = primero;
    while(aux != NULL){
        if(aux->valor.getUsuario() == user){
            aux->valor.mostrar();
        }
        aux = aux->siguiente;
    }
}

// Destructor
Lista::~Lista() {
    vaciar(); // Llama a vaciar para liberar memoria
}
