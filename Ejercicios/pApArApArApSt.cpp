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
            
    *(*(*pApArApArApSt)[0])[0] = "Hola";
    *(*(*pApArApArApSt)[0])[1] = "mundo";
    *(*(*pApArApArApSt)[1])[0] = "como";
    *(*(*pApArApArApSt)[0])[1] = "estas?";

    return pApArApArApSt;
}