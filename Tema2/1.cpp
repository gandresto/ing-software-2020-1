#include <iostream>
using namespace std;

void HolaFn(void){
    cout << "Hola mundo!" << endl;
}

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

int main(void){
    // a) Apuntadores a funciones
    cout << "a) Apuntadores a funciones" << endl;
    cout << "Mandando a llamar una función desde un apuntador a ella..." <<endl;
    void (*pApFn)(void) = HolaFn;
    (*pApFn)();

    cout << endl << "Mandando a llamar funciones con argumentos desde apuntadores a ellas..." <<endl;
    int (*pApFnEn)(int, int) = SumaFnEn;
    cout << (*pApFnEn)(5, 10) << endl;
    // Es lo mismo que: cout << SumaFnEn(5, 10) << endl;    
    pApFnEn = RestaFnEn;
    cout << (*pApFnEn)(5, 10) << endl;
    pApFnEn = ProductoFnEn;
    cout << (*pApFnEn)(5, 10) << endl;
    pApFnEn = DivisionFnEn;
    cout << (*pApFnEn)(5, 10) << endl;
    //getchar();
    return 0;
}