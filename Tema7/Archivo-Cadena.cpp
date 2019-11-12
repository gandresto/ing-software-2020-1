#include <stdio.h>
//#include <conio.h>
//#include <iostream>
#include <cstdlib>
//#include <string.h>
/*
+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
|   Los valores permitidos para Modo
+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
|   Modo            Significado
+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
    "r"             Abre un archivo de texto para lectura
    "w"             Abre un archivo de texto para escritura
    "a"             Agrega (al final) a un archivo de texto
    "rb"            Abre un archivo binario para lectura
    "wb"            Crea un archivo binario para escritura
    "ab"            Agrega (al final) a un archivo binario
    "r+"            Abre un archivo de texto para lectura/escritura
    "w+"            Crea un archivo de texto para lectura/escritura
    "a+"            Abre o crea un archivo de texto para lectura/escritura
    "r+b"           Abre un archivo binario para lectura/escritura
    "w+b"           Crea un archivo binario para lectura/escritura
    "a+b"           Abre o crea un archivo binario para lectura/escritura
    "rt"            Abre un archivo de texto para lectura
    "wt"            Crea un archivo de texto para escritura
    "at"            Agrega (al fnal) a un archivo de texto
    "r+t"           Abre un archivo de texto para lectura/escritura
    "w+t"           Crea un archivo de texto para lectura/escritura
    "a+t"           Abre o crea un archivo de texto para lectura/escritura
+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
*/
//using namespace std;
//
void AbreArchivoFn(FILE **TxtAlfaApFILE, char ModoCd[6], char NomArchiovCd[20]){
    if((*TxtAlfaApFILE = fopen(NomArchiovCd, ModoCd)) == NULL){
        printf("No se puede abrir el archivo");
        //return 1;
    }
}
//
void Txt_DeMonitor_aDiscoFn(FILE *TxtAlfaApFILE){
    char CaraCa;
    CaraCa = getchar();
    while(CaraCa != '$'){
        putc(CaraCa, TxtAlfaApFILE);
        CaraCa = getchar();
    }
}
//
void Txt_DeDisco_aMonitorFn(FILE *TxtAlfaApFILE){
    char CaraCa;
    CaraCa = getc(TxtAlfaApFILE);
    while(CaraCa != EOF){
        putchar(CaraCa);
        CaraCa = getc(TxtAlfaApFILE);
    }
}
//
void Copia_de_ArchivoA_a_ArchivoBFn(FILE *TxtAlfaApFILE, FILE *AvoTxtBetaApFILE){
    char CaraCa;
    CaraCa = getc(TxtAlfaApFILE);
    while(CaraCa != EOF){
        putc(CaraCa, AvoTxtBetaApFILE);
        CaraCa = getc(TxtAlfaApFILE);
    }
}
//
int main(int argc, const char** argv) {
	system("color F0");
//  Ejercicio Previo
    FILE *TxtAlfaApFILE, *AvoTxtBetaApFILE;
    //char ModoEscCd1[6] = {"w+"};
    char ModoEscCd[6] = {"w+"};
    char ModoLecCd[6] = {"r"}; 
    char ArchivoACd[20] = {"ArchivoA.txt"};
    char ArchivoCCd[20] = {"ArchivoC.txt"};

    char CaraCa;
    
    // Se crea archivo para escritura
    if((TxtAlfaApFILE = fopen(ArchivoACd, ModoEscCd)) == NULL){
        printf("No se puede abrir el archivo");
        return 1;
    }

    puts(">>> Ingresa datos, segmento de codigo sin funciones <<<\n");
    // Se lee de teclado y se escribe a disco
    CaraCa = getchar();
    while(CaraCa != '$'){
        putc(CaraCa, TxtAlfaApFILE);
        CaraCa = getchar();
    }
    fclose(TxtAlfaApFILE);
    
    // Se abre archivo para lectura
    if((TxtAlfaApFILE = fopen(ArchivoACd, ModoLecCd)) == NULL){
        printf("No se puede abrir el archivo");
        return 1;
    }
    
    //rewind(TxtAlfaApFILE);
    // Se lee de archivo y se exhibe a monitor
    CaraCa = getc(TxtAlfaApFILE);

    while(CaraCa != EOF){
        putchar(CaraCa);
        CaraCa = getc(TxtAlfaApFILE);
    }
    fclose(TxtAlfaApFILE);  //TxtAlfaApFILE = NULL;
    puts("\n");
//  Fin ejercicio previo
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    puts(">>> Ingresa datos. Segmento de codigo con funciones <<<\n");
    char ArchivoBCd[20] = {"ArchivoB.txt"};
    
    AbreArchivoFn(&TxtAlfaApFILE, ModoEscCd, ArchivoCCd);
    Txt_DeMonitor_aDiscoFn(TxtAlfaApFILE);
    fclose(TxtAlfaApFILE);
    
    AbreArchivoFn(&TxtAlfaApFILE, ModoLecCd, ArchivoCCd);
    Txt_DeDisco_aMonitorFn(TxtAlfaApFILE);
    fclose(TxtAlfaApFILE);
    
    puts("\n>>> Copia del archivoA al ArchivoB <<<\n");
    AbreArchivoFn(&TxtAlfaApFILE, ModoLecCd, ArchivoCCd);
    AbreArchivoFn(&AvoTxtBetaApFILE, ModoEscCd, ArchivoBCd);
    
    Copia_de_ArchivoA_a_ArchivoBFn(TxtAlfaApFILE, AvoTxtBetaApFILE);
    fclose(TxtAlfaApFILE);
    fclose(AvoTxtBetaApFILE);
    
    puts("\n>>> ArchivoB copiado <<<\n");
    AbreArchivoFn(&AvoTxtBetaApFILE, ModoLecCd, ArchivoBCd);
    Txt_DeDisco_aMonitorFn(AvoTxtBetaApFILE);
    fclose(AvoTxtBetaApFILE);
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    puts("\n");
    
    system("pause");
    return 0;
}
