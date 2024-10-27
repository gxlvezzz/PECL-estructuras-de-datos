#ifndef GESTOR_HPP
#define GESTOR_HPP

#include "Proceso.hpp"
#include "Pila.hpp"
#include "Cola.hpp"
#include "Lista.hpp"
#include <iostream>
using namespace std;

class Gestor{
    public:
		Gestor();
		~Gestor();
        int ProcesosEnPila();
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