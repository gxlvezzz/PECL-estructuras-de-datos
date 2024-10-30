#include <iostream>
#include <iomanip> // Para std::setw y std::left

class Lista {
private:
    NodoLista* cabeza;

public:
    Lista() : cabeza(nullptr) {}

    void insertar(Proceso p) {
        NodoLista* nuevo = new NodoLista(p);
        nuevo->siguiente = cabeza;
        cabeza = nuevo;
    }

    // Método para mostrar en formato tabla
    void muestraProcesoEnTabla() const {
        std::cout << std::left << std::setw(10) << "PID" 
                  << std::setw(15) << "Usuario" 
                  << std::setw(15) << "Tipo" 
                  << std::setw(15) << "Estado" 
                  << std::setw(10) << "Prioridad" 
                  << std::endl;
        
        std::cout << std::string(65, '-') << std::endl;

        NodoLista* actual = cabeza;
        while (actual != nullptr) {
            const Proceso& proceso = actual->proceso;
            std::cout << std::left << std::setw(10) << proceso.getPID()
                      << std::setw(15) << proceso.getUsuario()
                      << std::setw(15) << (proceso.esTiempoReal() ? "Tiempo Real" : "Normal")
                      << std::setw(15) << (proceso.estaEnEjecucion() ? "En Ejecución" : "Parado")
                      << std::setw(10) << proceso.getPrioridad()
                      << std::endl;

            actual = actual->siguiente;
        }
    }

    // Otros métodos para manejar la lista, como buscar, eliminar, etc.
};
