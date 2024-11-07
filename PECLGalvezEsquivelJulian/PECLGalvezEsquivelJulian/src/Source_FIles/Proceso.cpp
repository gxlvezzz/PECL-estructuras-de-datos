#include "src/Header_Files/Proceso.hpp"
#include "src/Header_Files/Pila.hpp"

Pila pilaPID;
Pila pilaProcesos;

Proceso::Proceso() { PID = 1; }



void Proceso::crearProceso(){
	
	int pid = 300 + (rand() %48);
    this->PID = pid;
    int num = rand() % 10;
    this-> usuario = ("user" + to_string(num));
    this->tipo = (rand() % 2);
	if (tipo == true) {
		prioridad = -19 + (rand()%39);
	}else{
		prioridad = 120 + (rand()%100);
	}
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