#ifndef NODOPILA_HPP
#define NODOPILA_HPP
#include <src/Header_Files/Proceso.hpp>

class NodoPila
{
public:
    NodoPila(Proceso v, NodoPila* sig = NULL);
    ~NodoPila();
private:
    Proceso valor;
    NodoPila* siguiente;
    friend class Pila;
};
typedef NodoPila* pnodoPila;
#endif // NODOPILA_HPP