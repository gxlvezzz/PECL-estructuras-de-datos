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
private:
    pnodoPila ultimo;
    int longitud;
};

#endif // PILA_HPP