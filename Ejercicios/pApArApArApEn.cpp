#include <iostream>

using namespace std;

int main(int argc, char const *argv[]){

    int Ent1 = 1;
    int Ent2 = 1;
    int Ent3 = 1;
    int Ent4 = 1;

    int *p1ApEn = &Ent1;
    int *p2ApEn = &Ent2;
    int *p3ApEn = &Ent3;
    int *p4ApEn = &Ent4;

    int *XArApEn[2] = {p1ApEn, p2ApEn};
    int *YArApEn[2] = {p3ApEn, p4ApEn};

    int *(*(XArApArApEn[2])[2]);
    int *(*(YArApArApEn[2])[2]);
    
    // p es un apuntador a un arreglo de apuntadores a 
    // arreglos de apuntadores a enteros
    int *(*(*pApArApArApEn[2])[2]);

    return 0;
}