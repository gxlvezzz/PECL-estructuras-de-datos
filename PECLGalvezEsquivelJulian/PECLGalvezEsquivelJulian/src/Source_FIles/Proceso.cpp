#include "src/Header_Files/Proceso.hpp"
#include "src/Header_Files/Pila.hpp"
#include <algorithm>
#include <iomanip>

int Proceso::n=300;
int Proceso::cadenaPID[12] = {};
int Proceso::cadenaPrioridadNormal[40] = {};
int Proceso::cadenaPrioridadTiempoReal[100] = {};


Proceso::Proceso(){
	int pid = 0;
	this->PID = pid;
	int num = rand() % 10;
    this-> usuario = ("user" + to_string(num));
	this->tipo = (rand() % 2);
}
int Proceso::generarPID(){
	
	for (int i=0; i<12; i++){
		cadenaPID[i]= i+n;
	}
	random_shuffle(cadenaPID,cadenaPID+12);	
	n+=12;
    return 0;
}

int Proceso::generarPrioridadNormal(){
	for (int i=0; i<40; i++){
		cadenaPrioridadNormal[i]= (i-19)+120;
	}
	random_shuffle(cadenaPrioridadNormal,cadenaPrioridadNormal+39);	
    return 0;
}

int Proceso::generarPrioridadTiempoReal(){
	for (int i=0; i<100; i++){
		cadenaPrioridadTiempoReal[i]= i;
	}
	random_shuffle(cadenaPrioridadTiempoReal,cadenaPrioridadTiempoReal+100);
    return 0;
}

void Proceso::setVacio(bool v){
    this->vacio = v;
}

bool Proceso::getVacio(){
    return this->vacio;
}

void Proceso::mostrar(bool mostrartodo){
    string Tipo;
    if(!tipo){
        Tipo = "normal";
    }else {
        Tipo = "tiempo real";
    }
    
    cout << "\tEl proceso cuyo PID es "<< PID << " es de tipo " << Tipo;
    
    if(mostrartodo){
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

void Proceso::setTipo(bool t){
    this->tipo = t;
}

string Proceso::getUsuario(){
    return this->usuario;
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

int Proceso::getPID(){
	return PID;
}

void Proceso::setPID(int a){
	this->PID = a;
}

void Proceso::mostrarEnTabla(){
	string Tipo = (tipo == 0) ? "normal" : "tiempo real";
    string estado = (this->estado == true) ? "ejecucion" : "parado";

    // Alineación y espacio para cada columna
    cout << setw(3) << PID        
         << setw(10) << usuario  
         << setw(17) << Tipo      
         << setw(19) << estado    
         << setw(10) << prioridad 
         << endl;
}

Proceso::~Proceso()
{
}
//Proceso.cpp	