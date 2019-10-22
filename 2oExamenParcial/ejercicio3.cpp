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

struct ListaCuentasStrEsDatos{
    int tam;
    CuentastrEsDatos * pApCuentastrEsDatos;
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

void ExhibeListaFn(ListaStrEsDatos * lista){
    cout << '[';
    for (int i=0; i<lista->tam; i++){
        cout << '"' << lista->pApStr[i] << '"';
        if (i != lista->tam-1 ) cout << ", ";
    }
    cout << ']'<< endl;
}

ListaCuentasStrEsDatos * OrdenaFnApCuentaStrEsDatos(ListaStrEsDatos * apListaNoOrd){
    ListaCuentasStrEsDatos * pApListaCuenta = new ListaCuentasStrEsDatos;
    pApListaCuenta->tam=0;
    for(int i = 0; i < apListaNoOrd->tam; i++){
        // Bandera que se reinicia en cada palabra que indica si la encontro en la cuenta
        bool encontrada = false;
        string palabra = apListaNoOrd->pApStr[i];

        // cout << palabra << endl;
        for(int j=0; j < pApListaCuenta->tam; j++){
            // cout << palabra << " = ";
            // cout << pApListaCuenta->pApCuentastrEsDatos[j].palabraSt << " ?" << endl;
            if(pApListaCuenta->pApCuentastrEsDatos[j].palabraSt == palabra){
                pApListaCuenta->pApCuentastrEsDatos[j].cuentaEn ++;
                encontrada = true;

                cout << pApListaCuenta->pApCuentastrEsDatos[j].cuentaEn << " : ";
                cout << pApListaCuenta->pApCuentastrEsDatos[j].palabraSt << endl;
                break;
            }
        }

        if(!encontrada){
            //pApListaCuenta = 0;
            // Creo un nuevo apuntador a una lista de mayor tamano
            CuentastrEsDatos * qApCuentastrEsDatos = new CuentastrEsDatos[pApListaCuenta->tam+1];
            for(int k=0; k<pApListaCuenta->tam; k++){
                qApCuentastrEsDatos[k].cuentaEn = pApListaCuenta->pApCuentastrEsDatos[k].cuentaEn;
                qApCuentastrEsDatos[k].palabraSt = pApListaCuenta->pApCuentastrEsDatos[k].palabraSt;
            }
            qApCuentastrEsDatos[pApListaCuenta->tam].palabraSt = palabra;
            qApCuentastrEsDatos[pApListaCuenta->tam].cuentaEn = 1;

            cout << qApCuentastrEsDatos[pApListaCuenta->tam].cuentaEn << " : ";
            cout << qApCuentastrEsDatos[pApListaCuenta->tam].palabraSt << endl;
            pApListaCuenta->pApCuentastrEsDatos = qApCuentastrEsDatos;
            pApListaCuenta->tam++;
        }

    }
    
    return pApListaCuenta;
}

int main(int argc, char const *argv[])
{
    string texto = "Este es un texto de prueba. \
    Cuenta el numero de veces que aparece en el \
    texto la palabra. Este numero es una palabra";

    ListaStrEsDatos * pApListaStrEsDatos = SeparaPalabrasFnListaStrEsDatos(texto);
    ExhibeListaFn(pApListaStrEsDatos);
    ListaCuentasStrEsDatos * pApListaCuenta = OrdenaFnApCuentaStrEsDatos(pApListaStrEsDatos);
    return 0;
}
