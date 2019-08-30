// Ejercicio 2

#include <iostream>

using namespace std;

// Las funciones de suma, resta, etc. deben devolver 
// un apuntador a un entero.
int *SumaFnApEn(int AEnt, int BEnt){
    int *pApEn = new int;
    *pApEn = AEnt + BEnt;
    return pApEn;
}
int *RestaFnApEn(int AEnt, int BEnt){
    int *pApEn = new int;
    *pApEn = AEnt - BEnt;
    return pApEn;    
}
int *ProductoFnApEn(int AEnt, int BEnt){
    int *pApEn = new int;
    *pApEn = AEnt * BEnt;
    return pApEn;
}
int *DivisionFnApEn(int AEnt, int BEnt){
    int *pApEn = new int;
    *pApEn = AEnt / BEnt;
    return pApEn;
}

// Crea es una funcion que devuelve un apuntador a un 
// arreglo de apuntadores a funciones que devuelven entero
int (*(*(*CreaFnApArApFnApEn(void))[4])(int, int)){
    int (*(*(*pApArApFnApEn)[4])(int, int)) = (int *((*(*)[4])(int, int))) new (int*(*[4]));
    (*pApArApFnApEn)[0] = SumaFnApEn; 
    (*pApArApFnApEn)[1] = RestaFnApEn; 
    (*pApArApFnApEn)[2] = ProductoFnApEn; 
    (*pApArApFnApEn)[3] = DivisionFnApEn; 

    return pApArApFnApEn;
}

int main(void){
    
    int (*(*(*pApArApFnApEn)[4])(int, int)) = CreaFnApArApFnApEn();
    for(int i=0; i<4; i++)
        cout << *(*(*pApArApFnApEn)[i])(10, 5) << endl;
    return 0;
}

