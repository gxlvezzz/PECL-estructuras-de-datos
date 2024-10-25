#include "NodoPila.hpp"

NodoPila::NodoPila(Proceso v, NodoPila* sig)
{
    valor = v;
    siguiente = sig;
}

NodoPila::~NodoPila()
{
}
NodoPila.cpp