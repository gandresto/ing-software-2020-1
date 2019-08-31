#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;

string *(*(*CreaFnApArApArApSt (void))[2])[2];

int main(void){
    // p es un Apuntador a un Arreglo de Apuntadores de 
    // Arreglos a Apuntadores a Strings
    string *(*(*pApArApArApSt)[2])[2] = CreaFnApArApArApSt();
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            // Cuando se imprimen strings, el último asterisco antes del tipo base se elimina
            cout << *(*(*pApArApArApSt)[i])[j] << " ";
    cout << endl;
    
    return 0;
}

string *(*(*CreaFnApArApArApSt (void))[2])[2]{
    string *(*(*pApArApArApSt)[2])[2] = 
            (string*(*(*)[2])[2]) new (string *(*[2])[2]);

    string **XApApSt = new (string * [2]);
    string **YApApSt = new (string * [2]);

    //Inicializando los arreglos de apuntadores a strings
    XApApSt[0] = new string;
    XApApSt[1] = new string;
    YApApSt[0] = new string;
    YApApSt[1] = new string;

    *XApApSt[0] = "Hola";
    *XApApSt[1] = "mundo";
    *YApApSt[0] = "como";
    *YApApSt[1] = "estas?";

    (*pApArApArApSt)[0] = (string *(*)[2]) XApApSt;
    (*pApArApArApSt)[1] = (string *(*)[2]) YApApSt;

    return pApArApArApSt;
}