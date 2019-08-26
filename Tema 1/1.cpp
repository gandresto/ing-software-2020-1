// Apuntadores a arreglos
#include <iostream>
using namespace std;

int main(void){
    // Inicializar en tiempo de compilacion
    int AEn = 5;
    // & es un aoperador unario yuxtapuesto que precede a una variable 
    int *pApEn = &AEn; // &AEn direccion de memoria de AEn
    //int *p1ApEn = 10; // desreferenciar
    //pApEn = 10;
    int * qApEn;
    int XArEn[2]={10, 5};
    qApEn = XArEn; //El nombre actua como un apuntador constante al primer elemento del arreglo
    for(int i=0; i<2; i++) cout << qApEn[i] << endl;
    for(int i=0; i<2; i++) cout << *(qApEn + i )<< endl;
}