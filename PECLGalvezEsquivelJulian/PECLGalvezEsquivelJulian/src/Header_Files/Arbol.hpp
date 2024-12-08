#ifndef ARBOL_HPP
#define ARBOL_HPP

#include "NodoArbol.hpp"
#include "Proceso.hpp"
#include "Lista.hpp"

#include <vector>
using namespace std;

class Arbol
{
public:
    Arbol();
    void insertar(Proceso val);
	int  contarNodos(pnodoAbb nodo);
	int  contarNodos();
	void mostrarProcesosEnInorden();
	void mostrarProcesosEnInorden(pnodoAbb nodo);
	void mostrar();
    void pintar();
    void dibujar();
	void mostrarProcesosNormalesPrioridadMayor();
	void mostrarProcesosTiempoRealPrioridadMayor();
	void mostrarProcesosNormales(pnodoAbb nodo);
	void mostrarProcesosTiempoReal(pnodoAbb nodo);
	void mostrarProcesoNormalMenorTiempoRealMayor();
	void mostrarProcesosEnHojas();
	void mostrarProcesosEnHojas(pnodoAbb nodo);
	void eliminarProcesoPorPrioridad(int prioridad, Lista& listaNormal, Lista& listaTiempoReal);
	
    ~Arbol();
	

private:
	
    pnodoAbb raiz;
    pnodoAbb insertar(pnodoAbb nodo, Proceso val);
	pnodoAbb eliminarProceso(pnodoAbb nodo, int prioridad, Proceso& eliminado);
	pnodoAbb encontrarMin(pnodoAbb nodo);

    void pintar(pnodoAbb);
    int altura(pnodoAbb);
    void dibujarNodo(vector<string>& output, vector<string>& linkAbove, pnodoAbb nodo, int nivel, int minPos,
                     char linkChar);

};


#endif // ARBOL_HPP