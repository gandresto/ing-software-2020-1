#include <iostream>
#include <stdlib.h>
//
using namespace std;
/*
	La clase CsBase
*/
template <class Gn>
class CsBase {
public:
	virtual Gn BaseFaGn(void) = 0;
};
//
template <class Gn>
class CsBaseEn : public CsBase<Gn> {
public:
	Gn BaseFaGn(void) {
		return rand()%100;
	}
};
//
template <class Gn>
class CsBaseFo : public CsBase<Gn> {
public:
	Gn BaseFaGn(void) {
		float ValorFo = float(rand()%100)/100;
		return float((rand()%100)) + ValorFo;
	}
};
//
template <class Gn>
class CsBaseCa : public CsBase<Gn> {
public:
	Gn BaseFaGn(void) {
		static int iEn = 0;
		return char (int('A') + iEn++);;
	}
};
/*
	La clase CsNotaMex 
*/
template <class Gn>
class CsNotaMex {
public:
	CsNotaMex(void);
	~CsNotaMex(void);
	void CreaFa(CsBase<Gn> &);
	void ExhibeFa(void);
	void SuprimeDatosDinamicosFa(void);
private:
	Gn *(*(*pApArApArApGn)[2])[3];
	Gn (*pApFaGn)(void);
};
//
template <class Gn>
void CsNotaMex<Gn>::CreaFa(CsBase<Gn> &LaCsBaseGn) {
	pApArApArApGn = (Gn *(*(*)[2])[3])new (Gn *(*[2])[3]);
	
	
	(*pApArApArApGn)[0] = (Gn *(*)[3])new (Gn *[3]);
	(*pApArApArApGn)[1] = (Gn *(*)[3])new (Gn *[3]);
	
	for(int iEn = 0; iEn < 2; iEn++)
		for(int jEn = 0; jEn < 3; jEn++) {
			(*(*pApArApArApGn)[iEn])[jEn] = new Gn;
			*(*(*pApArApArApGn)[iEn])[jEn] = LaCsBaseGn.BaseFaGn();
		}
}
//
template <class Gn>
CsNotaMex<Gn>::CsNotaMex(void) {
	pApArApArApGn = NULL;
}
//
template <class Gn>
CsNotaMex<Gn>::~CsNotaMex(void) {
	for(int iEn = 0; iEn < 2; iEn++) {
		for(int jEn = 0; jEn < 3; jEn++) {
			delete (*(*pApArApArApGn)[iEn])[jEn];
		}
		delete [](*pApArApArApGn)[iEn];
	}

	delete []pApArApArApGn;
}
//
template <class Gn>
void CsNotaMex<Gn>::SuprimeDatosDinamicosFa(void) {
	for(int iEn = 0; iEn < 2; iEn++) {
		for(int jEn = 0; jEn < 3; jEn++) {
			delete (*(*pApArApArApGn)[iEn])[jEn];
			(*(*pApArApArApGn)[iEn])[jEn] = NULL;	// El operador delete no resetea el apuntador a nulo, el algunos
													// sistemas si. Como una buena practica, lo mejor es hacerlo 
													// explicitamente como aquí se muestra.
		}
		delete [](*pApArApArApGn)[iEn];
		(*pApArApArApGn)[iEn] = NULL;				// Idem
	}

	delete []pApArApArApGn;
	pApArApArApGn = NULL;							// Idem
}
//
template <class Gn>
void CsNotaMex<Gn>::ExhibeFa(void) {
	if(pApArApArApGn != NULL) {
		for(int iEn = 0; iEn < 2; iEn++) {
			cout << endl;
			for(int jEn = 0; jEn < 3; jEn++) {
				cout << *(*(*pApArApArApGn)[iEn])[jEn] << " ";
			}
		}
	}else
		cout << "\n\nEstructura suprimida\n";
}
/*
	El programa principal
*/
main(void) {
	CsBaseEn<int> LaCsBaseEn;
	CsNotaMex<int> LaCsNotaMexEn;
	LaCsNotaMexEn.CreaFa(LaCsBaseEn);
	LaCsNotaMexEn.ExhibeFa();
	LaCsNotaMexEn.SuprimeDatosDinamicosFa();
	LaCsNotaMexEn.ExhibeFa();
	puts("\n");
	
	CsBaseFo<float> LaCsBaseFo;
	CsNotaMex<float> LaCsNotaMexFo;
	LaCsNotaMexFo.CreaFa(LaCsBaseFo);
	LaCsNotaMexFo.ExhibeFa();
	LaCsNotaMexFo.SuprimeDatosDinamicosFa();
	LaCsNotaMexFo.ExhibeFa();
	puts("\n");

	CsBaseCa<char> LaCsBaseCa;
	CsNotaMex<char> LaCsNotaMexCa;
	LaCsNotaMexCa.CreaFa(LaCsBaseCa);
	LaCsNotaMexCa.ExhibeFa();
	LaCsNotaMexCa.SuprimeDatosDinamicosFa();
	LaCsNotaMexCa.ExhibeFa();		
}

