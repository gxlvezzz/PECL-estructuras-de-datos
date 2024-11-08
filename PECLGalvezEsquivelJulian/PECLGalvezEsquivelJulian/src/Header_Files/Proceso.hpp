#ifndef PROCESO_HPP
#define PROCESO_HPP
#include <iostream>
using namespace std;
class Proceso
{
public:
    Proceso();
    ~Proceso();
    void mostrar(bool mostrartodo);
    bool getVacio();
    void setVacio(bool v);
    void crearProceso();
    bool getTipo();
	string getUsuario();
    bool getEstado();
    void setEstado(bool e);
    int getPrioridad();
    void setPrioridad(int p);
    int getPID();
	void mostrarEnTabla();
private:
    bool tipo;
    int PID;
    string usuario;
    bool estado;
    int prioridad;
    bool vacio;
};

#endif // PROCESO_HPP