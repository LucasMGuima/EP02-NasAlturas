#include "AVL.h"
#include <stdio.h>
#include <stdlib.h>



int main(){

}

AVL avlAddElemento(AVL No, AVL Raiz){
    if(Raiz == NULL){
        Raiz = No;
        return;
    }
    if(Raiz->valor > No->valor){
        //adiciona ao filho esquerdo se o elemento for menor
        Raiz->filhoEsq = bstAddElemento(No, Raiz->filhoEsq);
    }else{
        //adiciona ao filho direito
        Raiz->filhoDir = bstAddElemento(No, Raiz->filhoDir);
    }
    return Raiz;
}

AVL avlCriarNo(int Num){
    AVL novo = (AVL)malloc(sizeof(AVL));
    novo->valor = 0;
    novo->h = 1;
    novo->filhoDir = NULL;
    novo->filhoEsq = NULL;
    return novo;
}