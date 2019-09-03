/*
Ejercicio
    Sean XArEn, YArEn y ZArEn con valores enteros ordenados ascendentemente. 
    Intercale en apuntador a enteros zApEn ambos vectores ordenadios también ascendentemente
*/
#include <iostream>

using namespace std;

int * intercalaFnApEn(int *XApEn, int *YApEn){
    ;
}

int main(int argc, char const *argv[])
{
    int tamArEn[3];

    for (size_t i = 0; i < 3; i++)
    {
        cout << "Dame tamaño del primer vector: ";
        cin >> tamArEn[i];
        int * xApEn = new int[tamArEn[i]];
        cout << "Dame los valores del arreglo #" << i << " en orden\n";
        for (size_t j = 0; j < tamArEn[i]; j++)
            cin >> xApEn[j];
        cout << endl;
    }

    return 0;
}
