#include "AVL.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    AVL avl = avlCriarNo(1);
    avlAddElemento(avlCriarNo(2), avl);
    avlAddElemento(avlCriarNo(3), avl);
    printf(">%d",avlCalculaFatorBalanceamento(avl));
}

AVL avlAddElemento(AVL No, AVL Raiz){
    if(Raiz == NULL){
        Raiz = No;
        return;
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

    return Raiz;
}

AVL avlRotacionaDireita(AVL No, AVL Raiz){

}

AVL avlRotacionaEsquerda(AVL No, AVL Raiz){
    
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

    return max(avlCalculaAltura(No->filhoEsq), avlCalculaAltura(No->filhoDir))+1;
}

int avlCalculaFatorBalanceamento(AVL No){
    return avlCalculaAltura(No->filhoEsq) - avlCalculaAltura(No->filhoDir);
}

//Utilitarios
#pragma region
int max(int num1, int num2){
    if(num1 == NULL) num1 = 0;
    if(num2 == NULL) num2 = 0;
    if(num1 >= num2) return num1;
    if(num1 < num2) return num2;
}
#pragma endregion