#include <iostream>
using namespace std;

template <class Gn> class CsGenera{
    public:
        CsGenera(void);
        CsGenera(Gn *(*(*)[2])[3]);
        ~CsGenera(void);
        //Gn *(*(*CreaFaApArApArApGn())[2])[3];
        void ExhibeFn(void);
    private:
        Gn *(*(*pApArApArApEn)[2])[3];
};
template <class Gn> CsGenera<Gn>::CsGenera(){
    this->pApArApArApEn = (Gn *(*(*)[2])[3]) new (Gn *(*[2])[3]);
    for(int i; i<2; i++){
        *(this->pApArApArApEn)[i] = (Gn *(*)[3]) new (Gn *[3]);
        for(int j; j<3; j++){
            //*pApGn = i+j;
            (*(*this->pApArApArApEn)[i])[j]=new Gn;
        }
    }    
}
template <class Gn> CsGenera<Gn>::CsGenera(Gn *(*(*pApArApArApGn)[2])[3]){
    this->pApArApArApGn = pApArApArApGn;
}

template <class Gn> CsGenera<Gn>::~CsGenera(){
    for(int i; i<2; i++){
        for(int j; j<3; j++){
            delete (*(*this->pApArApArApEn)[i])[j];
        }
        delete *(this->pApArApArApEn)[i];
    } 
    delete this->pApArApArApEn;
}

template <class Gn> 
void CsGenera<Gn>::ExhibeFn(){
    for(int i; i<2; i++){
        *(this->pApArApArApEn)[i] = (Gn *(*)[3]) new (Gn *[3]);
        for(int j; j<3; j++){
            cout << *(*(*this->pApArApArApEn)[i])[j] << endl;
        }
    }    
}

// template <class Gn> Gn CsGenera<Gn>::*(*(*CreaFaApArApArApGn())[2])[3]{
//     this->pApArApArApEn = (Gn *(*(*)[2])[3]) new (Gn *(*[2])[3]);
//     for(int i; i<2; i++){
//         *(this->pApArApArApEn)[i] = (Gn *(*)[3]) new (Gn *[3]);
//         for(int j; j<3; j++){
//             //*pApGn = i+j;
//             (*(*this->pApArApArApEn)[i])[j]=new Gn;
//         }
//     }     
// }

int main(int argc, char const *argv[])
{
    CsGenera<int> test;
    return 0;
}
