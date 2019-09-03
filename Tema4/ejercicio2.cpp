/*
Ejercicio
    Sean XArEn y YArEn con valores enteros ordenados ascendentemente. 
    Intercale en un tercer vector ZArEn ambos vectores ordenadios también ascendentemente
*/
#include <iostream>
#define LONX 7
#define LONY 4

using namespace std;

void intercalaFn(int XArEn[LONX], int YArEn[LONY], int ZArEn[LONX+LONY]){
    int jEn = 0, iEn = 0, kEn=0;
    
    //Se puede comparar con la long de x o y
    //while (jEn < LONY)
    while (iEn < LONX)
    {
        //printf("X[%d] = %d, ", iEn, XArEn[iEn]);
        //printf("Y[%d] = %d\n\n", jEn, YArEn[jEn]);
        if (XArEn[iEn] < YArEn[jEn])
        {
            ZArEn[kEn++]=XArEn[iEn++];
        }else if (XArEn[iEn] == YArEn[jEn]){
            ZArEn[kEn++]=XArEn[iEn++];
            ZArEn[kEn++]=YArEn[jEn++];                
        }else{
            ZArEn[kEn++]=YArEn[jEn++];                                
        }
    }
}

int main(int argc, char const *argv[])
{
    // Los dos necesitan acabar en el mismo valor para que funcione
    int XArEn[LONX] = {1, 4, 6, 7 , 10, 25, 36};
    int YArEn[LONY] = {1, 2, 30, 36};
    int ZArEn[LONY+LONX];

    intercalaFn(XArEn, YArEn, ZArEn);
    
    for (size_t i = 0; i < LONX+LONY; i++)
        cout << ZArEn[i] << " ";
    cout << endl;
    
    return 0;
}
