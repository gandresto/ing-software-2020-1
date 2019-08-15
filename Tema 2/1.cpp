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
    void (*pApFn)(void) = HolaFn;
    (*pApFn)();

    int (*pApFnEn)(int, int) = SumaFnEn;
    cout << (*pApFnEn)(5, 10) << endl;
    // Es lo mismo que: cout << SumaFnEn(5, 10) << endl;
    
    int (*p2ApFnEn)(int, int) = RestaFnEn;
    cout << (*p2ApFnEn)(5, 10) << endl;
    int (*p3ApFnEn)(int, int) = ProductoFnEn;
    cout << (*p3ApFnEn)(5, 10) << endl;
    int (*p4ApFnEn)(int, int) = DivisionFnEn;
    cout << (*p4ApFnEn)(5, 10) << endl;



    //getchar();
    return 0;


}