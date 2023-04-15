
typedef struct{
    char tipo;
    char registro; //eax ds
    char segmentoReg; //AH AL ó cantidad de bytes que vamos a leer
    char memoria[4];
    int ip;
    int desplazamiento;}TOperando;

int getOp(TMV *mv,operando o);
