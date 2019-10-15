#include "ListaDoblementeLigada.h"
#include <iostream>

using namespace std;

void ExibeListaFn(EsNodo *ProApEsNodo){
    EsNodo *pApEsNodo = ProApEsNodo;
    while (pApEsNodo != NULL)
    {
        cout << "[" << pApEsNodo->DatoCa << "|*]->";
        pApEsNodo = pApEsNodo->SigApEsNodo;
    }
    cout << "[" << pApEsNodo->DatoCa << "|/]" << endl;    
}

EsNodo * CreaListaFnApEsNodo(int NumIteamsEn){
    if(NumIteamsEn<1) return NULL;
    EsNodo *pApEsNodo = new EsNodo;
    EsNodo *qApEsNodo, *ProApEsNodo; // ProApEsNodo : Nodo Primero
    ProApEsNodo = pApEsNodo;
    for(int i = 0; i<NumIteamsEn; i++){
        cout << "Ingresa un caracter: ";
        cin >> pApEsNodo->DatoCa;
        qApEsNodo = new EsNodo;
        pApEsNodo->SigApEsNodo=qApEsNodo;        
        pApEsNodo=qApEsNodo;
    }
    pApEsNodo->SigApEsNodo=NULL;
    return ProApEsNodo;
}

