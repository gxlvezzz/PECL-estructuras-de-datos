#ifndef PILA_HPP
#define PILA_HPP

#include "NodoPila.hpp"

class Pila
{
public:
    Pila();
    ~Pila();
    void insertar(Proceso v);
    void extraer();
    Proceso cima();
    void mostrar();
    int getLongitud();
	bool buscarPID(int pid);
	bool buscarPrioridad(int prioridad);
private:
    pnodoPila ultimo;
    int longitud;
	void vaciar();
};

#endif // PILA_HPP