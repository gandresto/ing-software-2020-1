// Ejercicio 1

#include <iostream>
#include <math.h>

using namespace std;

int SumaFnEn(int AEnt, int BEnt){
    return AEnt + BEnt;
}
int RestaFnEn(int AEnt, int BEnt){
    return AEnt - BEnt;
}
int ProductoFnEn(int AEnt, int BEnt){
    return AEnt * BEnt;
}
int DivisionFnEn(int AEnt, int BEnt){
    return AEnt / BEnt;
}

// Crea es una funcion que devuelve un apuntador a un 
// arreglo de apuntadores a funciones que devuelven entero
int (*(*CreaFnApArApFnEn(void))[4])(int, int){
    int (*(*pApArApFnEn)[4])(int, int) = (int (*(*)[4])(int, int)) new (int*[4]);
    (*pApArApFnEn)[0] = SumaFnEn; 
    (*pApArApFnEn)[1] = RestaFnEn; 
    (*pApArApFnEn)[2] = ProductoFnEn; 
    (*pApArApFnEn)[3] = DivisionFnEn; 

    return pApArApFnEn;
}

int main(void){
    
    int (*(*pApArApFnEn)[4])(int, int) = CreaFnApArApFnEn();
    for(int i=0; i<4; i++)
        cout << (*(*pApArApFnEn)[i])(10, 5) << endl;

    return 0;
}

