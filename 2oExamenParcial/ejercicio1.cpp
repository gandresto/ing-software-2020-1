#include <iostream>
using namespace std;

void ExhibeFn(int n){
    for(int i=1; i<=n; i++){
        //cout << i << " ";
        if(i%3==0 && i%5==0) cout << "Hola mundo" << endl;
        else if(i%3==0) cout << "Hola" << endl;
        else if(i%5==0) cout << "mundo" << endl;
        else cout << "No Hola mundo" << endl;
    }
}

int main(int argc, char const *argv[])
{
    ExhibeFn(100);
    return 0;
}
