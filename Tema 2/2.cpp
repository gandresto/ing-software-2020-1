#include <iostream>
using namespace std;

int *AlphaFnApEn(int AEnt){
    int *pApEn = new int;
    *pApEn = AEnt;
    return pApEn;
}

int main(void){
    // 2. Funciones que devuelven un apuntador  
    cout << *AlphaFnApEn(100) << endl; 

    int *(*pApFnApEn)(int) = AlphaFnApEn;
    cout << *(pApFnApEn)(100) << endl; 
    //getchar();
    return 0;
}