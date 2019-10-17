#include <iostream>
#include <string>
using namespace std;

struct CuentastrEsDatos{
    int cuentaEn;
    string palabraSt;
};

struct ListaStrEsDatos{
    int tam;
    string * pApStr; 
};

ListaStrEsDatos * SeparaPalabrasFnListaStrEsDatos(string cadena){
    int i =0, tamLista = 0, contPalEn = 0, contLetrasPalEn=0;
    string * pApStr = new string[tamLista];
    string palabra = "";
    while(cadena[i] != '\0'){  
        if((cadena[i] != ' ') and (cadena[i] != '.') and (cadena[i] != ',') and (cadena[i] != '\n')){
            palabra += cadena[i];
            contLetrasPalEn ++;
        } else if (contLetrasPalEn>0){// Si hay letras en la palabra, lo agregamos a la lista
            string * qApStr = new string[++tamLista];
            qApStr[tamLista-1] = palabra;
            //cout << tamLista  << " : " << qApStr[tamLista-1]  << endl;
            for(int k=0; k<tamLista-1;k++) {
                qApStr[k] = pApStr[k];
            }
            //cout << endl;
            pApStr = new string[tamLista];
            pApStr = qApStr;
            palabra = "";
            contLetrasPalEn = 0;
        } 
        i++;
    }

    string * qApStr = new string[++tamLista];
    qApStr[tamLista-1] = palabra;
    //cout << tamLista  << " : " << qApStr[tamLista-1]  << endl;
    for(int k=0; k<tamLista-1;k++) {
        qApStr[k] = pApStr[k];
    }
    //cout << endl;
    pApStr = new string[tamLista];
    pApStr = qApStr;
    palabra = "";
    contLetrasPalEn = 0;

    ListaStrEsDatos * listaStr = new ListaStrEsDatos;
    listaStr->pApStr = pApStr;
    listaStr->tam = tamLista;
    
    return listaStr;
}

int main(int argc, char const *argv[])
{
    string texto = "Este es un texto de prueba. \
    Cuenta el numero de veces que aparece en el \
    texto la palabra";

    ListaStrEsDatos * pApStr = SeparaPalabrasFnListaStrEsDatos(texto);

    return 0;
}
