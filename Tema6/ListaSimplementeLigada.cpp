#include "ListaSimplementeLigada.h"
#include <iostream>

using namespace std;

void ExibeListaFn(EsNodo *ProApEsNodo){
    EsNodo *pApEsNodo = ProApEsNodo;
    while (pApEsNodo->SigApEsNodo != NULL)
    {
        cout << "[" << pApEsNodo->DatoCa << "|*]->";
        pApEsNodo = pApEsNodo->SigApEsNodo;
    }
    cout << "[" << pApEsNodo->DatoCa << "|/]" << endl;    
}

EsNodo * CreaListaFnApEsodo(int NumIteamsEn){
    if(NumIteamsEn<1) return NULL;
    EsNodo *pApEsNodo = new EsNodo;
    EsNodo *qApEsNodo, *ProApEsNodo; // ProApEsNodo : Nodo Primero
    //pApEsNodo->DatoCa = 'A';
    //pApEsNodo->SigApEsNodo = NULL;
    for(int i = 0; i<NumIteamsEn; i++){
        qApEsNodo = new EsNodo;
        cout << "Ingresa un caracter: ";
        cin >> qApEsNodo->DatoCa;
        pApEsNodo->SigApEsNodo=qApEsNodo;
        pApEsNodo=qApEsNodo;
    }
    qApEsNodo->SigApEsNodo=NULL;
    return ProApEsNodo;
}