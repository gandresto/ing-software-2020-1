#pragma once
struct EsNodo{
    char DatoCa;
    EsNodo * SigApEsNodo;
};
void ExibeListaFn(EsNodo *);
void CreaListaFnApEsNodo(int);