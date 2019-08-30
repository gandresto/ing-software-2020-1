#include <iostream>

using namespace std;

struct EsDatos
{
    int XArEn[3];
    string NombreStr;
};


int main(int argc, char const *argv[])
{
    EsDatos xEsDatos = {{1,2,3}, "Pepe"};
    for (size_t i = 0; i < 3; i++)
    {
        cout << xEsDatos.XArEn[i] << " ";
    }
    cout << endl;
    cout << xEsDatos.NombreStr << endl;

    /* Objetivo b1 */
    cout << endl << "--- Objetivo b1 ---" << endl;
    cout << "Imprimiendo a partir de un apuntador estático..." << endl;
    EsDatos * pApEsDatos = &xEsDatos; // Estructura estática
    for (size_t i = 0; i < 3; i++)
    {
        cout << pApEsDatos->XArEn[i] << " ";
    }
    cout << endl;
    cout << pApEsDatos->NombreStr << endl;

    cout << endl << "Imprimiendo a partir de un apuntador dinámico..." << endl;
    EsDatos * p2ApEsDatos = new EsDatos;
    for (size_t i = 0; i < 3; i++)
    {
        p2ApEsDatos->XArEn[i] = i*3;
    }
    p2ApEsDatos->NombreStr = "Otro nombre";
    for (size_t i = 0; i < 3; i++)
    {
        cout << p2ApEsDatos->XArEn[i] << " ";
    }
    cout << endl;
    cout << p2ApEsDatos->NombreStr << endl;

    return 0;
}
