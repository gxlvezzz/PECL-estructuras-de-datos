#include <src/Header_Files/NodoCola.hpp>

NodoCola::NodoCola(Proceso v, NodoCola* sig){
	
	valor = v;
	siguiente = sig;
}
NodoCola::~NodoCola(){
	
}