#pragma once

struct EsNodo{
    char DatoCa;
    EsNodo * SigApEsNodo;
};

void ExibeListaFn(EsNodo *);
EsNodo * CreaListaFnApEsNodo(int);