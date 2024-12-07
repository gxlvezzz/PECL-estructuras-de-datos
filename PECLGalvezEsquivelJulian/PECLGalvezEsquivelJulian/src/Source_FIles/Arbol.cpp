#include <src/Header_Files/Arbol.hpp>
#include <src/Header_Files/Lista.hpp>

Proceso dato;
/*Lista listaTiempoReal;
Lista listaNormal;*/


Arbol::Arbol(){ 
	raiz = nullptr; 

	}
	
void Arbol::insertar(Proceso val) { 
	raiz = insertar(raiz, val); 
	}
	int Arbol::contarNodos(pnodoAbb nodo) {
    if (!nodo) return 0;
    return 1 + contarNodos(nodo->izq) + contarNodos(nodo->der);
}

int Arbol::contarNodos() {
    return contarNodos(raiz);
}
pnodoAbb Arbol::insertar(pnodoAbb nodo, Proceso val)
{
    if(!nodo)
        return new NodoArbol(val);
    if(val.getPrioridad() <= nodo->dato.getPrioridad())
        nodo->izq = insertar(nodo->izq, val);
    else
        nodo->der = insertar(nodo->der, val);
    return nodo;
}
void Arbol::mostrarProcesosEnInorden() {
    mostrarProcesosEnInorden(raiz);
    cout << endl;
}

void Arbol::mostrarProcesosEnInorden(pnodoAbb nodo) {
    if (!nodo)
        return;

    // Recorrer el subárbol izquierdo
    mostrarProcesosEnInorden(nodo->izq);

    // Mostrar el valor del nodo actual
    nodo->dato.mostrar(true); // Si el valor es un proceso, utiliza el método apropiado como nodo->dato.getPrioridad()

    // Recorrer el subárbol derecho
    mostrarProcesosEnInorden(nodo->der);
}



void Arbol::pintar()
{
    pintar(raiz);
    cout << '\n';
}
void Arbol::pintar(pnodoAbb nodo)
{
    if(!nodo)
        return;
    pintar(nodo->izq);
    nodo->dato.mostrar(false);
    pintar(nodo->der);
}
int Arbol::altura(pnodoAbb nodo)
{
    if(!nodo)
        return 0;
    return 1 + max(altura(nodo->izq), altura(nodo->der));
}

void Arbol::dibujarNodo(vector<string>& output, vector<string>& linkAbove, pnodoAbb nodo, int nivel, int p,
                        char linkChar)
{
    if(!nodo)
        return;

    int h = output.size();
    string SP = " ";

    if(p < 0) {
        string extra(-p, ' ');
        for(string& s : output)
            if(!s.empty())
                s = extra + s;
        for(string& s : linkAbove)
            if(!s.empty())
                s = extra + s;
    }
    if(nivel < h - 1)
        p = max(p, (int)output[nivel + 1].size());
    if(nivel > 0)
        p = max(p, (int)output[nivel - 1].size());
    p = max(p, (int)output[nivel].size());

    if(nodo->izq) {
        int numeroQueQuieroImprimirEnElArbol =
            nodo->izq->dato.getPrioridad(); // En vez de este valor, tenéis que coger el número de la habitación del paciente.
        string izqdato = SP + to_string(numeroQueQuieroImprimirEnElArbol) + SP;
        dibujarNodo(output, linkAbove, nodo->izq, nivel + 1, p - izqdato.size(), 'L');
        p = max(p, (int)output[nivel + 1].size());
    }

    int space = p - output[nivel].size();
    if(space > 0)
        output[nivel] += string(space, ' ');
    int numeroQueQuieroImprimirEnElArbol =
        nodo->dato.getPrioridad(); // En vez de este valor, tenéis que coger el número de la habitación del paciente.
    string nododato = SP + to_string(numeroQueQuieroImprimirEnElArbol) + SP;
    output[nivel] += nododato;

    space = p + SP.size() - linkAbove[nivel].size();
    if(space > 0)
        linkAbove[nivel] += string(space, ' ');
    linkAbove[nivel] += linkChar;

    if(nodo->der)
        dibujarNodo(output, linkAbove, nodo->der, nivel + 1, output[nivel].size(), 'R');
}
void Arbol::dibujar()
{
    int h = altura(raiz);
    vector<string> output(h), linkAbove(h);
    dibujarNodo(output, linkAbove, raiz, 0, 5, ' ');

    for(int i = 1; i < h; i++) {
        for(int j = 0; j < linkAbove[i].size(); j++) {
            if(linkAbove[i][j] != ' ') {
                int size = output[i - 1].size();
                if(size < j + 1)
                    output[i - 1] += string(j + 1 - size, ' ');
                int jj = j;
                if(linkAbove[i][j] == 'L') {
                    while(output[i - 1][jj] == ' ')
                        jj++;
                    for(int k = j + 1; k < jj - 1; k++)
                        output[i - 1][k] = '_';
                } else if(linkAbove[i][j] == 'R') {
                    while(output[i - 1][jj] == ' ')
                        jj--;
                    for(int k = j - 1; k > jj + 1; k--)
                        output[i - 1][k] = '_';
                }
                linkAbove[i][j] = '|';
            }
        }
    }

    cout << '\n' << '\n';
    for(int i = 0; i < h; i++) {
        if(i)
            cout << linkAbove[i] << '\n';
        cout << output[i] << '\n';
    }
    cout << '\n' << '\n';
}

void Arbol::mostrarProcesosNormalesPrioridadMayor() {
    mostrarProcesosNormales(raiz);
}

void Arbol::mostrarProcesosTiempoRealPrioridadMayor() {
    mostrarProcesosTiempoReal(raiz);
}

// Función auxiliar para recorrer y mostrar los procesos normales en orden descendente
void Arbol::mostrarProcesosNormales(pnodoAbb nodo) {
    if (!nodo) return; // Base de la recursión

    // Cambiamos el orden de recorrido a derecha, raíz, izquierda
    mostrarProcesosNormales(nodo->der);

    if (!nodo->dato.getTipo() && nodo->dato.getPrioridad() > 100) {
        nodo->dato.mostrar(true);
    }

    mostrarProcesosNormales(nodo->izq);
}

// Función auxiliar para recorrer y mostrar los procesos de tiempo real en orden descendente
void Arbol::mostrarProcesosTiempoReal(pnodoAbb nodo) {
    if (!nodo) return; // Base de la recursión

    // Cambiamos el orden de recorrido a derecha, raíz, izquierda
    mostrarProcesosTiempoReal(nodo->der);

    if (nodo->dato.getTipo() && nodo->dato.getPrioridad() < 100) {
        nodo->dato.mostrar(true);
    }

    mostrarProcesosTiempoReal(nodo->izq);
}

void Arbol::mostrarProcesoNormalMenorTiempoRealMayor() {
    pnodoAbb nodoNormalMin = nullptr;
    pnodoAbb nodoTiempoRealMax = nullptr;

    // Buscar el proceso normal con prioridad más baja
    pnodoAbb actual = raiz;
    while (actual) {
        if (!actual->dato.getTipo() && actual->dato.getPrioridad() > 100) {
            nodoNormalMin = actual; // Guardar el nodo candidato
            actual = actual->izq;   // Continuar hacia la izquierda
        } else {
            actual = actual->der;   // No cumple, ir hacia la derecha
        }
    }

    // Buscar el proceso de tiempo real con prioridad más alta
    actual = raiz;
    while (actual) {
        if (actual->dato.getTipo() && actual->dato.getPrioridad() < 100) {
            nodoTiempoRealMax = actual; // Guardar el nodo candidato
            actual = actual->der;       // Continuar hacia la derecha
        } else {
            actual = actual->izq;       // No cumple, ir hacia la izquierda
        }
    }

    // Mostrar los resultados
    cout << "-El proceso normal cuya prioridad es la mas baja:" << endl;
    if (nodoNormalMin) {
        nodoNormalMin->dato.mostrar(true); // Mostrar información del proceso normal
    } else {
        cout << "No hay procesos normales con prioridad válida." << endl;
    }

    cout << "-El proceso de tiempo real cuya prioridad es la mas alta:" << endl;
    if (nodoTiempoRealMax) {
        nodoTiempoRealMax->dato.mostrar(true); // Mostrar información del proceso en tiempo real
    } else {
        cout << "No hay procesos en tiempo real con prioridad válida." << endl;
    }
}

void Arbol::mostrarProcesosEnHojas() {
    cout << "Procesos almacenados en nodos hojas:" << endl;
    mostrarProcesosEnHojas(raiz);
    cout << endl;
}

void Arbol::mostrarProcesosEnHojas(pnodoAbb nodo) {
    if (!nodo) return; 

    // Si el nodo es una hoja (no tiene hijos izquierdo ni derecho)
    if (!nodo->izq && !nodo->der) {
        nodo->dato.mostrar(true); // Mostrar información del proceso en la hoja
    }
    // Llamada recursiva para recorrer el subárbol izquierdo y derecho
    mostrarProcesosEnHojas(nodo->izq);
    mostrarProcesosEnHojas(nodo->der);
}

void Arbol::eliminarProcesoPorPrioridad(int prioridad) {
    cout << "Arbol antes de eliminar el proceso con prioridad " << prioridad << ":" << endl;
    dibujar(); // Mostrar el árbol antes de la eliminación

    raiz = eliminarProceso(raiz, prioridad);

    cout << "Arbol despues de eliminar el proceso con prioridad " << prioridad << ":" << endl;
    dibujar(); // Mostrar el árbol después de la eliminación
}

pnodoAbb Arbol::eliminarProceso(pnodoAbb nodo, int prioridad) {
    // Caso base: si el nodo es nulo, no hay nada que eliminar
    if (!nodo) return nodo;

    // Recorrer el árbol para encontrar el nodo a eliminar
    if (prioridad < nodo->dato.getPrioridad()) {
        nodo->izq = eliminarProceso(nodo->izq, prioridad);
    } else if (prioridad > nodo->dato.getPrioridad()) {
        nodo->der = eliminarProceso(nodo->der, prioridad);
    } else {
        // Nodo encontrado, caso de eliminación
		/*
			// Insertar el proceso eliminado en la lista correspondiente
        if (nodo->dato.getTipo()) { // Proceso de tiempo real
            listaTiempoReal.insertarOrdenado(nodo->dato);
        } else { // Proceso normal
            listaNormal.insertarOrdenado(nodo->dato);
        }
*/
        // Caso 1: Nodo con un solo hijo o sin hijos
        if (!nodo->izq) {
            pnodoAbb temp = nodo->der;
            delete nodo;
            return temp;
        } else if (!nodo->der) {
            pnodoAbb temp = nodo->izq;
            delete nodo;
            return temp;
        }

        // Caso 2: Nodo con dos hijos, buscar el sucesor en el subárbol derecho
        pnodoAbb minNode = encontrarMin(nodo->der);
        nodo->dato = minNode->dato; // Copiar el valor del sucesor al nodo actual
        nodo->der = eliminarProceso(nodo->der, minNode->dato.getPrioridad());
    }

    return nodo;
}

pnodoAbb Arbol::encontrarMin(pnodoAbb nodo) {
    while (nodo && nodo->izq) {
        nodo = nodo->izq;
    }
    return nodo;
}


Arbol::~Arbol() {}