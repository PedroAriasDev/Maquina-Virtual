#include <stdio.h>
#include <stdlib.h>
#include "operandos.h"
#include "mVTipos.h"
#include "mVfuncionesTiposProtos.h"
#include "funcionesAdicionales.h"

void MOV(TMV *mv,TOoperando op){
    setOp(*mv,op[0],getOp(*mv,op[1]));
}

void ADD(TMV *mv,TOoperando op){
    int aux;
    aux=getOp(*mv,op[0])+getOp(*mv,op[1]);
    setOp(*mv,op[0],aux);
    setCC(mv,aux);
}

void SUB(TMV *mv,TOoperando op){
    int aux;
    aux=getOp(*mv,op[0])-getOp(*mv,op[1]);
    setOp(*mv,op[0],aux);
    setCC(mv,aux);
}

void SWAP(TMV *mv,TOoperando op){
    int aux;
    aux=getOp(*mv,op[0])
    setOp(*mv,*op[0],getOp(*mv,op[1]));
    setOp(*mv,op[1],aux);
}

void MUL(TMV *mv,TOoperando op){
    int aux;
    aux=getOp(*mv,op[0])*getOp(*mv,op[1]);
    setOp(*mv,op[0],aux);
    setCC(mv,aux);
}

void DIV(TMV *mv,TOoperando op){
    int aux;
    if(getOp(*mv,op[1])){
        aux=getOp(*mv,op[0])/getOp(*mv,op[1]);
        *mv.registros[9]=getOp(*mv,op[0])%getOp(*mv,op[1]);
        setOp(*mv,op[0],aux);
        setCC(mv,aux);
    }else{
        printf("Error fatal, esta intentando dividir por 0\n");
        printf("El programa se detendra");
        STOP(mv);
    }
}

void CMP(TMV *mv,TOoperando op){
    int aux;
    aux=getOp(*mv,op[0])-getOp(*mv,op[1]);
    setCC(mv,aux);
}

void SHL(TMV *mv,TOoperando op){
    setOp(*mv,op[0],getOp(*mv,op[0]<<getOp(*mv,op[1])));
}

void SHR(TMV *mv,TOoperando op){
    int aux;
    aux=getOp(*mv,op[0]>>getOp(*mv,op[1]));
    setOp(*mv,op[0],aux);
    setCC(mv,aux);
}

void AND(TMV *mv,TOoperando op){
    int aux;
    aux=getOp(*mv,op[0] & getOp(*mv,op[1]));
    setOp(*mv,op[0],aux);
    setCC(mv,aux);
}

void OR(TMV *mv,TOoperando op){
    int aux;
    aux=getOp(*mv,op[0] | getOp(*mv,op[1]));
    setOp(*mv,op[0],aux);
    setCC(mv,aux);
}

void XOR(TMV *mv,TOoperando op){
    int aux;
    aux=getOp(*mv,op[0] ^ getOp(*mv,op[1]));
    setOp(*mv,op[0],aux);
    setCC(mv,aux);
}

void SYS(TMV *mv,TOoperando op){
    if()
}

void JMP(TMV *mv,TOoperando op){
    *mv.registros[5]=getOp(*mv,op[0]);
}
void JZ(TMV *mv,TOoperando op){
    if((*mv.registros[8] & 0x4000)!=0){
       *mv.registros[5]=getOp(*mv,op[0]);
    }
}
void JP(TMV *mv,TOoperando op){
    if((*mv.registros[8] & 0xc000)==0)
        *mv.registros[5]=getOp(*mv,op[0]);
}
void JN(TMV *mv,TOoperando op){
    if((*mv.registros[8] & 0x8000)!=0)
        *mv.registros[5]=getOp(*mv,op[0]);
}
void JNZ(TMV *mv,TOoperando op){
    if(((*mv.registros[8] & 0x8000)!=0)||((*mv.registros[8] & 0xc000)==0))
        *mv.registros[5]=getOp(*mv,op[0]);
}
void JNP(TMV *mv,TOoperando op){
    if((*mv.registros[8] & 0x8000)!=0 ||(*mv.registros[8] & 0xc000)==0)
        *mv.registros[5]=getOp(*mv,op[0]);

}
void JNN(TMV *mv,TOoperando op){
    if((*mv.registros[8] & 0x4000)!=0 || (*mv.registros[8] & 0xc000)==0)
        *mv.registros[5]=getOp(*mv,op[0]);
}

void LDL(TMV *mv,TOoperando op){
    *mv.registros&=0xFF00;
    *mv.registros[9]=(getOp(*mv,op[0])&0x00FF) | *mv.registros[9];
}
void LDH(TMV *mv,TOoperando op){
    *mv.registros&=0x00FF;
    *mv.registros[9]=(getOp(*mv,op[0])<<16) | *mv.registros[9];
}
void RND(TMV *mv,TOoperando op){
    *mv.registros[9]=rand() % (getOp(*mv,op[0])-1)
}

void NOT(TMV *mv,TOoperando op){
    int aux;
    aux=gatOp(*mv,op[0]);
    setOp(*mv,op[0],aux);
    setCC(mv,aux);
}
void STOP(TMV *mv){
    *mv.registros[5]=mv.TDD[1];
}
