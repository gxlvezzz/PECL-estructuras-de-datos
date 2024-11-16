#include "src/Header_Files/Proceso.hpp"
#include "src/Header_Files/Pila.hpp"
#include <algorithm>


int Proceso::n=300;
int Proceso::cadenaPID[12] = {};
int Proceso::cadenaPrioridadNormal[39] = {};
int Proceso::cadenaPrioridadTiempoReal[99] = {};


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
	for (int i=0; i<39; i++){
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
    if(true){
        string e = "parado";
        if(estado){
            e = "ejecucion";
        }
        cout << ", su estado es " << e << " y su prioridad es: " << prioridad;
    }
	}
    cout << endl;
}



bool Proceso::getTipo(){
    return this->tipo;
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
	string Tipo;
	string e ;
	if(!tipo){
        Tipo = "normal";
    }else{
        Tipo = "tiempo real";
    }
    
    if(true){
        e = "parado";
        if(estado){
            e = "ejecucion";
        }
    }

	cout << PID << "\t";
    cout << usuario << "\t";

    cout << Tipo << "\t";

    cout << e;
    if (e == "parado"){
		cout << "\t\t";
	}else{
		cout << "\t";
	}

    cout << prioridad << endl;
}

Proceso::~Proceso()
{
}
//Proceso.cpp