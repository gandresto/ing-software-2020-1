#include <iostream>

using namespace std;

// Usando árbol sistémico sin simplificar
int EncuentraValorFnEn(int *pApEn, int xEn, int yEn){
    int iEn = 0;
    //int valorEn = 0;
    while(1){
        if(pApEn[iEn]<xEn) iEn+=3;
        else if(xEn==pApEn[iEn]){
            if(pApEn[iEn+1]<yEn) iEn+=3;
            else if(yEn==pApEn[iEn+1]){
                //valorEn = pApEn[iEn+=2];
                return pApEn[iEn+2];
            }
            else{
                //valorEn = 0;
                //break;
                return 0;
            }
        }
        else{
            //valorEn = 0;
            //break;
            return 0;
        }
    }
    //return valorEn;
}

// Árbol reducido con regla del y lógico
int EncuentraValorYLogicoFnEn(int *pApEn, int xEn, int yEn){
    int iEn = 0;
    while(1){
        if(pApEn[iEn]<xEn) iEn+=3;
        else if(xEn==pApEn[iEn] && pApEn[iEn+1]<yEn) iEn+=3;
        else if(xEn==pApEn[iEn] && yEn==pApEn[iEn+1]) return pApEn[iEn+2];
        else if(xEn==pApEn[iEn]) return 0;
        else return 0;
    }
}

// Árbol reducido con regla del y lógico
int EncuentraValorOLogicoFnEn(int *pApEn, int xEn, int yEn){
    int iEn = 0;
    while(1){
        if(pApEn[iEn]<xEn || (xEn==pApEn[iEn] && pApEn[iEn+1]<yEn)) iEn+=3;
        else if(xEn==pApEn[iEn] && yEn==pApEn[iEn+1]) return pApEn[iEn+2];
        else return 0;
    }
}

int main(int argc, char const *argv[])
{
    int XMtEn[5][5] = { 
                        {0, 0, 0, 0, 1},
                        {0, 2, 0, 3, 0},
                        {0, 0, 0, 0, 0},
                        {0, 3, 0, 5, 0},
                        {0, 2, 0, 0, 0}
                    };
    int XVcEn[] = {0, 4, 1, 1, 1, 2, 1, 3, 3, 1, 3, 3, 5, 4 ,1, 2, 5, 5, 0};
    int *pApEn = XVcEn;
    int valorEn = 0;
    int cols = 0, rows = 0;

    cout << "Dame valor de columnas y renglones para buscar en la matriz. (valores de 0 a 4)" << endl;
    cin >> cols >> rows;

    valorEn = EncuentraValorFnEn(pApEn, cols, rows);
    cout << "Arbol sin reducir." << endl;
    cout << "\tEl valor en esa posicion es: " << valorEn << endl << endl;

    valorEn = EncuentraValorYLogicoFnEn(pApEn, cols, rows);
    cout << "Arbol reducido con regla de y logico." << endl;
    cout << "\tEl valor en esa posicion es: " << valorEn << endl << endl;

    valorEn = EncuentraValorOLogicoFnEn(pApEn, cols, rows);
    cout << "Arbol reducido con regla de o logico." << endl;
    cout << "\tEl valor en esa posicion es: " << valorEn << endl << endl;

    system("pause");
    return 0;
}