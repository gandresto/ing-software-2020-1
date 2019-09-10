/*
Ejercicio
    Sean a b y c variables enteras, exhiba la de menor valor o 
    los valores de dos de ellas si son iguales 
    o los valores de las tres si son iguales
*/

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    char resp='n';
    do{
        int a, b, c;
        cout << "Dame tres valores: ";
        cin >> a  >> b >> c;

        if(a==b && b==c)
            cout<<"Los tres valores son iguales: " << a << ", " << b << ", " << c << endl;
        else{
            if(a<b && b<=c) cout << "a es menor: " << a << endl;
            else if(b<c && b<=a) cout << "b es menor: " << b << endl;
            else if(c<b && b<=a) cout << "c es menor: " << c << endl;
            else if (a==b) cout << "Valores a y b iguales: " << a << " " << b << endl;
            else if (a==c) cout << "Valores a y c iguales: " << a << " " << c << endl;
            else if (c==b) cout << "Valores b y c iguales: " << c << " " << b << endl;
        }
        cout << "Quieres ingresar valores nuevamente? (s/n): ";
        cin >> resp;
    }while(resp == 's' || resp=='S');
    return 0;
}
