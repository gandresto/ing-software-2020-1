#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;

char *(*(*CreaFnApArApArApCd (void))[2])[2];

int main(void){
    // p es un Apuntador a un Arreglo de Apuntadores de 
    // Arreglos a Apuntadores a Cadenas
    char *(*(*pApArApArApCd)[2])[2] = CreaFnApArApArApCd();
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            // Cuando se imprimen cadenas, el último asterisco antes del tipo base se elimina
            cout << /* * */(*(*pApArApArApCd)[i])[j] << " ";
    cout << endl;
    
    return 0;
}

char *(*(*CreaFnApArApArApCd (void))[2])[2]{
    char *(*(*pApArApArApCd)[2])[2] = 
            (char*(*(*)[2])[2]) new (char *(*[2])[2]);
    char **XApApCd = new (char * [2]);
    char **YApApCd = new (char * [2]);
    //Inicializando los arreglos de apuntadores a cadenas
    //Pueden tener tamaños diferentes
    XApApCd[0] = new char[5];
    XApApCd[1] = new char[6];
    YApApCd[0] = new char[5];
    YApApCd[1] = new char[7];

    strcpy(XApApCd[0], "Hola");
    strcpy(XApApCd[1], "mundo");
    strcpy(YApApCd[0], "como");
    strcpy(YApApCd[1], "estas?");

    (*pApArApArApCd)[0] = (char *(*)[2]) XApApCd;
    (*pApArApArApCd)[1] = (char *(*)[2]) YApApCd;

    return pApArApArApCd;
}