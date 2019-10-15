struct EsNodo{
    char DatoCa;
    EsNodo * AntApEsNodo;
    EsNodo * SigApEsNodo;
};

void ExibeListaFn(EsNodo *);
EsNodo * CreaListaFnApEsNodo(int);