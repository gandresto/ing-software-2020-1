#include <iostream>
using namespace std;

void SumadorBinarioFn(int aEn, int bEn, int * cEn, int * rEn){
    // cout << "Antes: a = " << aEn;    
    // cout << ", b = " << bEn;    
    // cout << ", c = " << *cEn << endl;    
    if(aEn==0 and bEn==0 and *cEn==0){
        *rEn = 0;
        *cEn = 0;
    } else 
    if ((aEn==0 and bEn==0 and *cEn==1) or
        (aEn==0 and bEn==1 and *cEn==0) or 
        (aEn==1 and bEn==0 and *cEn==0)){
            *rEn = 1;
            *cEn = 0;
    } else 
    if ((aEn==0 and bEn==1 and *cEn==1) or
        (aEn==1 and bEn==1 and *cEn==0) or 
        (aEn==1 and bEn==0 and *cEn==1)){
            *rEn = 0;
            *cEn = 1;
    } else 
    if (aEn==1 and bEn==1 and *cEn==1){
            *rEn = 1;
            *cEn = 1;
    }
    // cout << "Después: r = " << *rEn;
    // cout << ", c = " << *cEn << endl;
}

int main(int argc, char const *argv[])
{
    int nEn;
    cout << "Dame el número de dígitos que quieres sumar" << endl;
    cin >> nEn;
    int * XApEn = new int[nEn];
    int *YApEn = new int[nEn];
    int *ResApEn = new int[nEn];

    cout << "Dame los dígitos del primer número" << endl;
    for (int i=0; i<nEn; i++) cin >> XApEn[i];

    cout << "Dame los dígitos del segundo número" << endl;
    for (int i=0; i<nEn; i++) cin >> YApEn[i];

    int * cApEn = new int;
    *cApEn = 0;    
    for(int i=nEn-1; i>=0; i--) SumadorBinarioFn(YApEn[i], XApEn[i], cApEn, &ResApEn[i]);

    cout << "\nResultado: \n";
    for (int i=0; i<nEn; i++) cout << XApEn[i];
    cout  << " + ";
    for (int i=0; i<nEn; i++) cout << YApEn[i];
    cout << " = " ;
    for (int i=0; i<nEn; i++) cout << ResApEn[i];
    cout << "\nCon carry = " << *cApEn << endl;
   
    return 0;
}
