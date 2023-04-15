#include <stdlib.h>
#include "funcionesAdicionales.h"
#include "mVTipos.h"

void complentoA2(char *operando){
    *operando = (*operando) + 0x00000001;
}

void complementoA1(char *operando){
    *operando = !(*operando);
}

void sumaIP(unsigned int *ip,char operando1,char operando2){
    *ip += 1 + !operando1 + !operando2;
}

void mascarasAInstruccuion(char instruccion,char *operando1,char *operando2,char *operacion){

    if((instruccion & 0xF0) == 0xF0)
        stop(TMV instruccion);
    else{
        *operando1 = (instruccion & 0xc0);
        *operando2 = instruccion & 0x30;

        if(*operando2 == 0x30)
            *operacion=instruccion & 0x3F;
        else{
            *operacion=instruccion & 0x0F;
            *operando2 = *operando2 >> 6;
        }
    }
}

void setCC(TMV *mv,int numero){
    if(aux==0)
        *mv.registros[8] &=0x80;
    if(aux<0)
        *mv.registros[8] &=0x40;
}










