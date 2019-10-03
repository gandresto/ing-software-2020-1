#include "CsGenera.h"
#include <iostream>
#include <stdlib.h>

template <class Gn> CsGenera<Gn>::CsGenera(){
    this->pApArApArApEn = (Gn *(*(*)[2])[3]) new (Gn *(*[2])[3]);
    for(int i=0; i<2; i++){
        (*this->pApArApArApEn)[i] = (Gn *(*)[3]) new (Gn *[3]);
        for(int j=0; j<3; j++){
            //*pApGn = i+j;
            (*(*this->pApArApArApEn)[i])[j]= new Gn;
            *(*(*this->pApArApArApEn)[i])[j] = rand();
        }
    }    
}
template <class Gn> CsGenera<Gn>::CsGenera(Gn *(*(*pApArApArApGn)[2])[3]){
    this->pApArApArApGn = pApArApArApGn;
}

template <class Gn> CsGenera<Gn>::~CsGenera(){
    for(int i=0; i<2; i++){
        for(int j=0; j<3; j++){
            delete (*(*this->pApArApArApEn)[i])[j];
        }
        delete [] (*this->pApArApArApEn)[i];
    } 
    delete [] this->pApArApArApEn;
}

template <class Gn> 
void CsGenera<Gn>::ExhibeFn(){
    for(int i=0; i<2; i++){
        for(int j=0; j<3; j++){
            std::cout << *(*(*this->pApArApArApEn)[i])[j] << " ";
        }
        std::cout << std::endl;
    }    
}