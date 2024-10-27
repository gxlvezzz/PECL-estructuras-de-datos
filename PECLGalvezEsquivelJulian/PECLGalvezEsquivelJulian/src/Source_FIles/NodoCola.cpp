#include <src/Header_Files/NodoCola.hpp>

NodoCola::NodoCola(int v, NodoCola* sig){
	
	valor = v;
	siguiente = sig;
}
NodoCola::~NodoCola(){
	
}