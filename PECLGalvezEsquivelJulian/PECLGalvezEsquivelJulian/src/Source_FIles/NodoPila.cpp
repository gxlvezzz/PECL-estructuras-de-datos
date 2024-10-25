#include "src/Header_Files/NodoPila.hpp"

NodoPila::NodoPila(Proceso v, NodoPila* sig)
{
    valor = v;
    siguiente = sig;
}

NodoPila::~NodoPila()
{
}
//NodoPila.cpp