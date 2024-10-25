#ifndef PROCESO_HPP
#define PROCESO_HPP
#include <iostream>
using namespace std;
class Proceso
{
public:
    Proceso();
    ~Proceso();
    void mostrar();
    bool getVacio();
    void setVacio(bool v);
    void crearProceso(int pid);
    bool getTipo();
    bool getEstado();
    void setEstado(bool e);
    int getPrioridad();
    void setPrioridad(int p);
    
private:
    bool tipo;
    int PID;
    string nombreUsuario;
    bool estado;
    int prioridad;
    bool vacio;
};

#endif // PROCESO_HPP