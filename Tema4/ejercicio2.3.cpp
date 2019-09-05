/*

*/
#include <iostream>

using namespace std;

struct EsDatos
{
    int *pApEn;
    int longEn;
};


EsDatos * intercalaFnApEsDatos(EsDatos * pApEsDatos, EsDatos *qApEsDatos){
    EsDatos *resApEsDatos = new EsDatos;

    int jEn = 0, iEn = 0, kEn=0;
    
    resApEsDatos->longEn = pApEsDatos->longEn+qApEsDatos->longEn;
    resApEsDatos->pApEn = new int[resApEsDatos->longEn];

    while (iEn < pApEsDatos->longEn)
    {
        if (pApEsDatos->pApEn[iEn] < qApEsDatos->pApEn[jEn])
        {
            resApEsDatos->pApEn[kEn++]=pApEsDatos->pApEn[iEn++];
        }else if (pApEsDatos->pApEn[iEn] == qApEsDatos->pApEn[jEn]){
            resApEsDatos->pApEn[kEn++]=pApEsDatos->pApEn[iEn++];
            resApEsDatos->pApEn[kEn++]=qApEsDatos->pApEn[jEn++];                
        }else{
            resApEsDatos->pApEn[kEn++]=qApEsDatos->pApEn[jEn++];                                
        }
    }
    return resApEsDatos;
}

EsDatos *LeeVectorFnApEsDatos(){
    EsDatos *pApEsDatos = new EsDatos;

    cout << "Dame tamaño del vector: ";
    cin >> pApEsDatos->longEn;

    pApEsDatos->pApEn = new int[pApEsDatos->longEn];
    cout << "Dame los valores del vector en orden\n";
    for (size_t j = 0; j < pApEsDatos->longEn; j++){
        cin >> (pApEsDatos->pApEn)[j];
    }
    return pApEsDatos;
}

int main(int argc, char const *argv[])
{
    char resp;
    do{
        EsDatos *(XArrApEsDatos[3]);
        for (size_t i = 0; i < 3; i++)
        {
            XArrApEsDatos[i] = LeeVectorFnApEsDatos();
        }

        EsDatos *tempApEsDatos = new EsDatos;
        EsDatos *resApEsDatos = new EsDatos;
        tempApEsDatos = intercalaFnApEsDatos(XArrApEsDatos[0], XArrApEsDatos[1]);
        resApEsDatos = intercalaFnApEsDatos(tempApEsDatos, XArrApEsDatos[2]);

        cout << "Arreglo de resultado" <<endl;
        for (size_t i = 0; i < resApEsDatos->longEn; i++)
        {
            cout << resApEsDatos->pApEn[i] << " ";
        }
        cout << endl;
        
        cout << endl << "Quieres repetir el programa? (s/n): ";
        cin >> resp;
    }while(resp == 's' || resp=='S');
    return 0;
}
