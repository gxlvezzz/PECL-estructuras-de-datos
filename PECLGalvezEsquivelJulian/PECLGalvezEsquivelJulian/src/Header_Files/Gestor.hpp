#ifndef GESTOR_HPP
#define GESTOR_HPP

#include "proceso.hpp"
#include "pila.hpp"
#include "cola.hpp"
#include "lista.hpp"
#include <iostream>
using namespace std;

class Gestor{
    public:
        void ProcesosEnPila();
        void ProcesosEnGPU0();
        void ProcesosEnGPU1();
        void ProcesosEnGPU2();
        void ProcesosEnGPU3();  
        void ProcesosEnListaNormal();
        void ProcesosEnListaTiempoReal();
        void ProcesosEnArbol();
        void genera12Procesos();
        void muestraProcesos();
        void borraProcesosPila();
        void encolarProcesos();
        void muestraProcesosGPUs0y1();
        void muestraProcesosGPUs2y3();
        void borraProcesosColas();
        void enlistarProcesos();
        void muestraProcesosNormal();
        void muestraProcesosTiempoReal(); 
        void buscarProcesos();
        void buscarProcesoPorNombreUsuario();
        void eliminarProcesoPorPID();
        void cambiarPrioridadProcesoPorPID();
        void reiniciar();
        
    private:
        
};
#endif