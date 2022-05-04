#include "AVL.h"
#include <stdio.h>
#include <stdlib.h>

//Utilitarios
#pragma region
int avlMax(int num1, int num2){
    if(num1 >= num2) return num1;
    if(num1 < num2) return num2;
}
#pragma endregion

AVL avlAddElemento(AVL No, AVL Raiz){
    if(Raiz == NULL){
        Raiz = No;
        return Raiz;
    }
    if(Raiz->valor > No->valor){
        //adiciona ao filho esquerdo se o elemento for menor
        Raiz->filhoEsq = avlAddElemento(No, Raiz->filhoEsq);
    }else{
        //adiciona ao filho direito
        Raiz->filhoDir = avlAddElemento(No, Raiz->filhoDir);
    }
    //Recalcula a altura do No
    Raiz->h = avlCalculaAltura(Raiz);

    //Rebalancear a arvorre se for preciso
    if(avlCalculaFatorBalanceamento(Raiz) == -2){
        if(avlCalculaFatorBalanceamento(Raiz->filhoDir) == +1){
            Raiz->filhoDir = avlRotacionaDireita(Raiz->filhoDir);
        }
        Raiz = avlRotacionaEsquerda(Raiz);
    }else if(avlCalculaFatorBalanceamento(Raiz) == +2){
        if(avlCalculaFatorBalanceamento(Raiz->filhoEsq) == -1){
            Raiz->filhoEsq = avlRotacionaEsquerda(Raiz->filhoEsq);
        }
        Raiz = avlRotacionaDireita(Raiz);
    }
    return Raiz;
}

AVL avlRotacionaDireita(AVL Raiz){
    AVL novaRaiz = Raiz->filhoEsq;
    Raiz->filhoEsq = novaRaiz->filhoDir;
    novaRaiz->filhoDir = Raiz;
    return novaRaiz;
}

AVL avlRotacionaEsquerda(AVL Raiz){
    AVL novaRaiz = Raiz->filhoDir;
    Raiz->filhoDir = novaRaiz->filhoEsq;
    novaRaiz->filhoEsq = Raiz;
    return novaRaiz;
}

AVL avlCriarNo(int Num){
    AVL novo = (AVL)malloc(sizeof(AVL));
    novo->valor = Num;
    novo->h = 1;
    novo->filhoDir = NULL;
    novo->filhoEsq = NULL;
    return novo;
}

void avlPreOrdem(AVL Raiz){
    if(Raiz != NULL){
        printf("%d ", Raiz->valor);
        avlPreOrdem(Raiz->filhoEsq);
        avlPreOrdem(Raiz->filhoDir);
    }
}

void avlInOrdem(AVL Raiz){
    if(Raiz != NULL){
        avlInOrdem(Raiz->filhoEsq);
        printf("%d ", Raiz->valor);
        avlInOrdem(Raiz->filhoDir);
    }
}

void avlPosOrdem(AVL Raiz){
    if(Raiz != NULL){
        avlPosOrdem(Raiz->filhoEsq);
        avlPosOrdem(Raiz->filhoDir);
        printf("%d ", Raiz->valor);
    }
}

void avlIdentImprime(AVL Raiz, int espaco){
    if(Raiz != NULL){
        avlIdentImprime(Raiz->filhoDir, espaco + 1);
        for(int i = 0; i < espaco; i++){
            printf("\t");
        }
        printf("%d\n",Raiz->valor);
        avlIdentImprime(Raiz->filhoEsq, espaco + 1);
    }
}

int avlCalculaAltura(AVL No){
    if(No == NULL){
        return 0;
    }

    return avlMax(avlCalculaAltura(No->filhoEsq), avlCalculaAltura(No->filhoDir))+1;
}

int avlCalculaFatorBalanceamento(AVL No){
    return avlCalculaAltura(No->filhoEsq) - avlCalculaAltura(No->filhoDir);
}