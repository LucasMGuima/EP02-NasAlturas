#include "BST.h"
#include <stdio.h>
#include <stdlib.h>

//Utilitarios
#pragma region
int max(int num1, int num2){
    if(num1 >= num2) return num1;
    if(num1 < num2) return num2;
}
#pragma endregion

BST bstAddElemento(BST No, BST Raiz){
    if(Raiz == NULL){
        Raiz = No;
        return No;
    }
    if(Raiz->valor > No->valor){
        //adiciona ao filho esquerdo se o elemento for menor
        Raiz->filhoEsq = bstAddElemento(No, Raiz->filhoEsq);
    }else{
        //adiciona ao filho direito
        Raiz->filhoDir = bstAddElemento(No, Raiz->filhoDir);
    }
    //atualiza a altura do no
    Raiz->h = bstCalculaAltura(Raiz);
    
    return Raiz;
}

BST bstCriarNo(int Num){
    BST aux = (BST)malloc(sizeof(BST));
    aux->valor = Num;
    aux->h = 0;
    aux->filhoDir = NULL;
    aux->filhoEsq = NULL;
}


BST bstBusca(BST Raiz, int N){
    if(Raiz->valor == N || Raiz == NULL){
        return Raiz;
    }

    if(N > Raiz->valor){
        return bstBusca(Raiz->filhoDir, N);
    }else{
        return bstBusca(Raiz->filhoEsq, N);
    }
}

BST bstMinimo(BST Raiz){
    if(Raiz->filhoEsq == NULL){
        return Raiz;
    }

    return bstMinimo(Raiz->filhoEsq);
}

BST bstMaximo(BST Raiz){
    if(Raiz->filhoDir == NULL){
        return Raiz;
    }

    return bstMaximo(Raiz->filhoDir);
}

void bstPreOrdem(BST Raiz){
    if(Raiz != NULL){
        printf("%d ", Raiz->valor);
        bstPreOrdem(Raiz->filhoEsq);
        bstPreOrdem(Raiz->filhoDir);
    }
}

void bstInOrdem(BST Raiz){
    if(Raiz != NULL){
        bstInOrdem(Raiz->filhoEsq);
        printf("%d ", Raiz->valor);
        bstInOrdem(Raiz->filhoDir);
    }
}

void bstPosOrdem(BST Raiz){
    if(Raiz != NULL){
        bstPosOrdem(Raiz->filhoEsq);
        bstPosOrdem(Raiz->filhoDir);
        printf("%d ", Raiz->valor);
    }
}

void bstIdentImprime(BST Raiz, int espaco){
    if(Raiz != NULL){
        bstIdentImprime(Raiz->filhoDir, espaco + 1);
        for(int i = 0; i < espaco; i++){
            printf("\t");
        }
        printf("%d\n",Raiz->valor);
        bstIdentImprime(Raiz->filhoEsq, espaco + 1);
    }
}

int bstCalculaAltura(BST No){
    if(No == NULL){
        return 0;
    }

    return max(bstCalculaAltura(No->filhoEsq), bstCalculaAltura(No->filhoDir))+1;
}