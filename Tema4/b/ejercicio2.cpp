/*
    Sumar dos matrices en forma de vector
*/

#include <iostream>
#include <iomanip>

using namespace std;

// Árbol reducido con regla del y lógico
int * SumaVectoresFnApEn(int *xApEn, int *yApEn, int longX, int longY){
    int iEn  = 0, jEn = 0, kEn = 0;
    //int longZ = LongVectorSumaFnEn(xApEn, yApEn, longX, longY);
    //int *zApEn = new int[longZ];
    int longZ = longY + longX;
    int *tempApEn = new int[longZ];
    while(iEn<longX){
        if((xApEn[iEn] < yApEn[jEn]) || (xApEn[iEn] == yApEn[jEn] && xApEn[iEn+1] < yApEn[jEn+1])){
            tempApEn[kEn] = xApEn[iEn];
            tempApEn[kEn+1] = xApEn[iEn+1];
            tempApEn[kEn+2] = xApEn[iEn+2];
            iEn += 3;
            kEn += 3;
        } else if ((xApEn[iEn] == yApEn[jEn] && xApEn[iEn+1] == yApEn[jEn+1]) && xApEn[iEn+2]+yApEn[iEn+2] == 0){
            jEn +=3;
            iEn +=3;
            longZ-=6;
        } else if (xApEn[iEn] == yApEn[jEn] && xApEn[iEn+1] == yApEn[jEn+1]){
            tempApEn[kEn] = xApEn[iEn];
            tempApEn[kEn+1] = xApEn[iEn+1];
            tempApEn[kEn+2] = xApEn[iEn+2]+yApEn[jEn+2];
            iEn += 3;
            kEn += 3;
            jEn += 3;
            longZ-=3;
        } else{
            tempApEn[kEn] = yApEn[jEn];
            tempApEn[kEn+1] = yApEn[jEn+1];
            tempApEn[kEn+2] = yApEn[jEn+2];
            jEn += 3;
            kEn += 3;
        }
    }
    int *zApEn = new int[longZ];
    for (size_t i = 0; i < longZ; i++)
    {
        zApEn[i]=tempApEn[i];
        cout << zApEn[i] << ' ';
    }
    cout << endl;
    return zApEn;
}

int LongVectorSumaFnEn(int *xApEn, int *yApEn, int longX, int longY){
    int iEn  = 0, jEn = 0;
    int longEn = longX + longY;
    while(longX < iEn){

        if((xApEn[iEn] == yApEn[jEn] && xApEn[iEn+1]==yApEn[jEn+1]) || (xApEn[iEn+2] + yApEn[jEn+2]) == 0)
            longEn -=3;
        iEn +=3;
    }
    
    return longEn;
}

int main(int argc, char const *argv[])
{
    int XMtEn[5][5] = { 
                        {0, 4, 0, 0, 0},
                        {0, -2, 0, 0, 4},
                        {0, 0, 1, 4, 0},
                        {0, 0, 0, 0, 0},
                        {0, 5, 0, 0, 0}
                    };
    int XVcEn[] = { 0, 2, 4, 
                    1, 1, -2, 
                    1, 4, 4, 
                    2, 2, 1, 
                    2, 3, 4, 
                    4, 1, 5, 
                    5, 5, 0};

    int YMtEn[5][5] = { 
                        {0, 0, 0, 0, 0},
                        {0, -2, 0, 0, 0},
                        {0, 0, -1, 6, 0},
                        {0, 0, 0, 2, 0},
                        {0, 0, 0, 0, 0}
                    };

    int YVcEn[] = { 1, 1, -2, 
                    2, 2, -1, 
                    2, 3, 6, 
                    3, 3, 2, 
                    5, 5, 0};
    int *xApEn = XVcEn;
    int *yApEn = YVcEn;

    int longX = 21, longY = 15;
    char repetir;

    do{
        int * resApEn;
        resApEn = SumaVectoresFnApEn(xApEn, yApEn, longX, longY);

        int k=0;
        cout << endl; 
        for (size_t i = 0; i < 5; i++)
        {
            for (size_t j = 0; j < 5; j++)
            {
                if(resApEn[k]=i && resApEn[k+1]==j){
                    cout << setw(4) << resApEn[k+2];
                    k+=3;
                }
                else cout << setw(4) << 0;
            }
            cout << endl;            
        }
        cout << endl; 
        
        

        cout << "Repetir programa? (s/n)" << endl;
        cin >> repetir;
        cout << endl;
    }while(repetir == 's' || repetir == 'S');

    system("pause");
    return 0;
}