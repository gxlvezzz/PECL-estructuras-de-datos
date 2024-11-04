#ifndef GESTOR_HPP
#define GESTOR_HPP

#include "Proceso.hpp"
#include "Pila.hpp"
#include "Cola.hpp"
#include "Lista.hpp"


class Gestor{
    public:
		Gestor();
		~Gestor();
        int ProcesosEnPila();
        int ProcesosEnGPU0();
        int ProcesosEnGPU1();
        int ProcesosEnGPU2();
        int ProcesosEnGPU3();  
        int ProcesosEnListaNormal();
        int ProcesosEnListaTiempoReal();
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