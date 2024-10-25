#include "Proceso.hpp"


Proceso::Proceso() { PID = 1; }


void Proceso::crearProceso(int pid){
    this->PID = pid;
    int num = rand() % 10;
    this->nombreUsuario = "user" + (0 + num);
    this->tipo = (rand() % 2);
}

void Proceso::setVacio(bool v){
    this->vacio = v;
}

bool Proceso::getVacio(){
    return this->vacio;
}

void Proceso::mostrar(){
    string Tipo;
    if(!tipo){
        Tipo = "normal";
    }else{
        Tipo = "tiempo real";
    }
    
    cout << "\tEl proceso cuyo PID es "<< PID << " es de tipo " << Tipo;
    
    
    if(true){
        string e = "parado";
        if(estado){
            e = "ejecucion";
        }
        cout << ", su estado es " << e << " y su prioridad es: " << prioridad;
    }
    cout << endl;
}

bool Proceso::getTipo(){
    return this->tipo;
}

bool Proceso::getEstado(){
    return this->estado;
}

void Proceso::setEstado(bool e){
    this->estado = e;
}

int Proceso::getPrioridad(){
    return this->prioridad;
}

void Proceso::setPrioridad(int p){
    this->prioridad = p;
}

Proceso::~Proceso()
{
}
Proceso.cpp