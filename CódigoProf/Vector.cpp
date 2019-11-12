/*
	Aprendizaje por proyectos
		Progrmaci�n literaria
		La notaci�n M�x
		aprendizaje por proyectos escalonado
		
		reference at (size_type n);					
													Gn &at( int IndiceEn) {
															return _DbApGn[ IndiceEn];
													}
		const_reference at (size_type n) const;
		
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    Laboratorio CsVector (1era Fase), es un proyecto escalonado de aprendizaje por proyectos 

    El uso de vectores y matrices es una practica com�n en las ingenierias y las ciencias. En nuestros d�as, la computaci�n
    es la herramienta usual en la que se modelan y ejercitan sistemas f�sicos. El software, un componente escencial de la  
    computaci�n, hace posible esto. Hoy d�a existen paquetes de software que resuelven sistemas de ecuaciones, de todo tipo,
    que requieren, en sus actividades profesionales, los ingenieros y los cientificos alrededor del mundo.

    Consulte el siguiente enlace (referencia) para que le asista a realizar los requerimientos pedidos en clase.

    http://www.cplusplus.com/reference/vector/vector/
*/

#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <vector>
//
using namespace std;
//
typedef unsigned int Es;
//
void SeRequiereQueFn(bool ExpresionBo, string AlertaSt) {	// Se requiere que ExpresionBo sea cierta, sino se exhibe AlertaSt
    if(!ExpresionBo) {
        cout << AlertaSt << endl;
        system("pause");
        exit(1);
    }
}
//
template <class Gn>
class CsVector { 
public:
    // Operaciones b�sicas
    /*WVector(void);										//	Constructor por omisi�n
    WVector(size_t n);										//	Constructor 
    WVector(size_t n, const value_type& val);
    WVector(const WVector& x);
    WVector(WVector & x);*/

    CsVector( void );										// Constructor por omisi�n
    CsVector( int );                                     	// Constructor crea e inicia a ceros un vector
    CsVector( Es NoItemsEs, const Gn & );					// ***
    CsVector( const CsVector & ) ;                          // Constructor copia
    CsVector( CsVector & ) ;                           		// Constructor copia  ***
    
    ~CsVector( void );                                      // Destructor
    //
    Gn &operator[]( const int ) const;                 		// Operador subindice
    //
    Gn &operator[]( int );                 			   		// Operador subindice
	//
	const CsVector &operator+(const CsVector<Gn> &);

	const CsVector &operator=( const CsVector<Gn> & );
	//	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	void AsignaFa( int, const Gn & );
	//
	Gn &at( int IndiceEn ) {
		return _DbApGn[ IndiceEn ];
	}
    //
    Gn *DbFaApGn(void);
    //
    const Gn *DbFaApGn(void) const;
    //
    bool EsVacioFaBo( void ) const;
	/*
	size_t NoItemsMaxFaEs() const;
	*/
	size_t NoItemsMaxFaEs() const {
		return _NoItemsMaxEs;
	}
    //	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	friend istream &operator>>( istream &ingreso, CsVector<Gn> &ElCsVector ) {
	    for( int iEn = 0; iEn < ElCsVector._NoActualItemsEn; iEn++ ) 
	        ingreso >> ElCsVector[iEn];
	}
	//
	friend ostream &operator<<( ostream &salida, const CsVector<Gn> &ElCsVector ) {
	    int iEn;
	    for( iEn = 0; iEn < ElCsVector._NoActualItemsEn; iEn++ ) {
	        salida << "| "<< ElCsVector[ iEn ] << " ";
	        if( ( iEn + 1 )%10 == 0 ) salida << "|" << endl;
	    }
	    if( iEn%10 != 0 ) salida << endl;
	    
	    return salida;
	}

private:
    Gn *_DbApGn;                                    		// Apuntador base (al 1er item del vector)
    int _NoActualItemsEn;                                   // N�mero actual de items en el vector
    int _CapacidadEn;										// N�mero total de items en el vector
    size_t _NoItemsMaxEs;
    int _PotenciaEn;
};
// Constructor por omisi�n
template <class Gn>
CsVector<Gn>::CsVector( void ) {
	_DbApGn = NULL;
	_NoActualItemsEn = _CapacidadEn = 0;
	_NoItemsMaxEs = 1073741823;
}
//
template <class Gn>
void CsVector<Gn>::AsignaFa( int CapacidadEn, const Gn &DatoGn ) {
	_NoActualItemsEn = _CapacidadEn = CapacidadEn;
	_DbApGn = new Gn[_CapacidadEn];
	
    for(int i = 0; i < _CapacidadEn; i++) {
        _DbApGn[i] = DatoGn;
    }
}
// Constructor crea e inicia a ceros un vector
template <class Gn>
CsVector<Gn>::CsVector(int CapacidadEn): _CapacidadEn(CapacidadEn) {
    _DbApGn = new Gn[_CapacidadEn];
    
    for(int i = 0; i < _CapacidadEn; i++) {
        _DbApGn[i] = 0;
    }
	_NoActualItemsEn = _CapacidadEn;
	_NoItemsMaxEs = 1073741823;
}
// Constructor copia
template <class Gn>
CsVector<Gn>::CsVector(const CsVector &ElCsVector) {
	_NoItemsMaxEs = 1073741823;
    _DbApGn = new float[ElCsVector._CapacidadEn];
    for(int iEn = 0; iEn < ElCsVector._NoActualItemsEn; iEn++) {
        _DbApGn[iEn] = ElCsVector._DbApGn[iEn];
    }
}
//
template <class Gn>
CsVector<Gn>::~CsVector(void){
    delete [] _DbApGn;
}
// Para escritura en el arreglo
template <class Gn>
Gn &CsVector<Gn>::operator[]( const int indiceEn) const {
    SeRequiereQueFn( 0 <= indiceEn && indiceEn <= _NoActualItemsEn, "posEn fuera de rango: 0 > posEn O posEn > _NoMaxItemsEn\n" );
    return _DbApGn[indiceEn];
}
// Para lectura en el arreglo
template <class Gn>
Gn &CsVector<Gn>::operator[]( int indiceEn) {
    SeRequiereQueFn( 0 <= indiceEn && indiceEn <= _NoActualItemsEn, "posEn fuera de rango: 0 > posEn O posEn > _NoMaxItemsEn\n" );
    return _DbApGn[indiceEn];
}

template <class Gn>
const CsVector<Gn> &CsVector<Gn>::operator+(const CsVector<Gn> &IzqRfCsVector) {
	SeRequiereQueFn( _NoActualItemsEn == IzqRfCsVector._NoActualItemsEn, "Error Arreglos con diferente dimension\n" );
	CsVector<Gn>  *pApCsVector = new CsVector<Gn>(_NoActualItemsEn);
	for (int i = 0; i<_NoActualItemsEn; i++){
		pApCsVector->_DbApGn[i] = _DbApGn[i] + IzqRfCsVector._DbApGn[i];
		//cout << pApCsVector->_DbApGn[i];
	}
	return *pApCsVector;
}
// 
template <class Gn>
const CsVector<Gn> &CsVector<Gn>::operator=(const CsVector<Gn> &DerCsVector) {
	if(&DerCsVector != this) {
		delete [] this->_DbApGn;
		_NoActualItemsEn = DerCsVector._NoActualItemsEn;
		_CapacidadEn = DerCsVector._CapacidadEn;
		this->_DbApGn = new Gn [_CapacidadEn];

		for(int iEn = 0; iEn < _NoActualItemsEn; iEn++)
			this->_DbApGn[iEn] = DerCsVector._DbApGn[iEn];
	}

	return *this;			// habilita xCsVector = yCsVector = zCsVector;
}
//	>|<--------------   Inicio de Funciones accesorias   ----------------------------------->|<
float *(*CreaFnApApFo( void ))[2] {				// CreaFnGn
	float *(*pApApFo)[2] = (float *(*)[2])new (float *[2]);
	(*pApApFo)[0] = new float;
	(*pApApFo)[1] = new float;
	*(*pApApFo)[0] = 10;
	*(*pApApFo)[1] = 20;
	
	return pApApFo;	
}
//
template <class Gn>
void ExhibeAlfaCsVector_Fn( CsVector<Gn> &ElCsVector ) {
	cout << "         +---+\n";
	cout << "pApApEn->| * |->| *->" << *(*ElCsVector[0])[0] << " | *->" << *(*ElCsVector[0])[1] << " |" << endl;
	cout << "         +---+\n";
	for(int iEn = 1; iEn < 10; iEn++) {
		cout << "         | * |->| *->" << *(*ElCsVector[iEn])[0] << " | *->" << *(*ElCsVector[iEn])[1] << " |" << endl;
		cout << "         +---+\n"; 
	}
}
//	>|<----------------   Fin de Funciones accesorias   ------------------------------------->|<
/*
  Gn *DbFaApGn( void );
  const Gn *DbFaApGn( void ) const;
*/
template <class Gn>
Gn *CsVector<Gn>::DbFaApGn(void) {
return _DbApGn;
}
//
template <class Gn>
const Gn *CsVector<Gn>::DbFaApGn(void) const {
return _DbApGn;
}
/*
	bool VacioFaBo() const;
*/
template <class Gn>
bool CsVector<Gn>::EsVacioFaBo( void ) const {
	return _NoActualItemsEn == 0;
} 
//
main( void ) {
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    CsVector<float> El0CsVector( 10 );
    CsVector<float> ElCsVector( 10 );
    CsVector<float> *pApCsVector = new CsVector< float >( 10 );
    
    cout << "Ingresa 10 valores enteros para el vector El0CsVector\n";
    cin >> El0CsVector;
    
    cout << "ElCsVector: " << ElCsVector;
    ElCsVector = El0CsVector;
    cout << "ElCsVector = El0CsVector: " << ElCsVector << endl;
	cout << "pApCsVector: " << *pApCsVector << endl;
	
	cout << "Suma de vectores\n";
	cout << El0CsVector + ElCsVector << endl;

	*pApCsVector = ElCsVector;  
	cout << "pApCsVector: " << *pApCsVector << endl;
	ElCsVector = ElCsVector;

	
	CsVector<float> El1CsVector( 10 );
	
	El1CsVector = El0CsVector = ElCsVector;
	
	cout << "ElCsVector: " << ElCsVector << endl;
	cout << "El1CsVector: " << El1CsVector << endl;
	cout << "El0CsVector: " << El0CsVector << endl;
//	+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
	CsVector<float * (*)[ 2 ]> AlfaCsVector;			//	* (*AlfaCsVector.at(0))[0]
	AlfaCsVector.AsignaFa( 10, CreaFnApApFo( ) );
	ExhibeAlfaCsVector_Fn( AlfaCsVector );
	
	cout << *(*AlfaCsVector.at(0))[1] << endl;
	cout << *(*AlfaCsVector[0])[1] << endl;
//	+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
	vector<int> myvector;
	cout << "capacity: " << (int) myvector.capacity() << '\n';
	// set some content in the vector:
	for (int iEn = 0; iEn < 100; iEn++) myvector.push_back(iEn);
	
	cout << "size: " << (int) myvector.size() << '\n';
	cout << "capacity: " << (int) myvector.capacity() << '\n';
	cout << "max_size: " << (int) myvector.max_size() << '\n';
	
	int PotenciaEn = 0;
	for (int iEn = 0; iEn < 5; iEn++) {
		cout << pow(2, PotenciaEn++) << endl;
	}
	
	float *pApFo = ElCsVector.DbFaApGn();
	for (int iEn = 0; iEn < 10; iEn++) 
		cout << pApFo[iEn] << endl;
		
	if(!ElCsVector.EsVacioFaBo())
		cout << "No es vacio\n";

	// CsVector<float> ResCsVector = ;
}
//	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

