#include <iostream>
#include <math.h>

using namespace std;

// Alpha es una funcion que devuelve un flotante
float AlphaFnFl(float ValorFl){
    return sin(ValorFl)*0.5;
}

float BetaFnFl(float ValorFl){
    return cos(ValorFl);
}

void TabulaFn( float (*pApFnFl)(float)){
    float incrementoFl = 0.1;
    for(int i=0; i<10; i++){
        cout << incrementoFl << " " << (*pApFnFl)(incrementoFl) << endl;
        incrementoFl += 0.1;
    }
}

int main(void){
    // 3. Apuntadores a funciones como argumentos
    TabulaFn(AlphaFnFl);
    cout << endl;
    TabulaFn(BetaFnFl);

    return 0;
}

