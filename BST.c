#include "BST.h"
#include <stdio.h>
#include <stdlib.h>

/*
    @brief  Função que acrescente um novo elemento na BST
    @param  No Novo elemento a ser adicionado na arvore
    @param  Raiz Elemento que representa a arvore a ser incerido o elemento
*/
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
    return Raiz;
}

/*
    @brief Função que cria um novo no com o valor entrado
    @param num valor a ser atrbuido ao novo no
    @return O novo no criado
*/
BST bstCriarNo(int Num){
    BST aux = (BST)malloc(sizeof(BST));
    aux->valor = Num;
    aux->filhoDir = NULL;
    aux->filhoEsq = NULL;
}

/*
    @brief Busca um elemento especificado na arvore BST
    @param raiz Elemento que representa a arvore a se buscar
    @param n Elemento a se buscar na arvore
    @return NULL se não encontro ou o No desse elemento se o encontrol
*/
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

/*
    @brief Procura pelo menor elementos incerido na arvore
    @param Raiz Elemento que representa a arvore a ser usada
    @return Retorna o menor elemento da arvore
*/
BST bstMinimo(BST Raiz){
    if(Raiz->filhoEsq == NULL){
        return Raiz;
    }

    return bstMinimo(Raiz->filhoEsq);
}

/*
    @brief Procura pelo maior elementos incerido na arvore
    @param Raiz Elemento que representa a arvore a ser usada
    @return Retorna o menor elemento da arvore
*/
BST bstMaximo(BST Raiz){
    if(Raiz->filhoDir == NULL){
        return Raiz;
    }

    return bstMaximo(Raiz->filhoDir);
}

/*
    @brief Imprime a arvore seguindo a logica de PreOrdem
    @param Raiz Elemento que representa a arvore a ser impressa
*/
void bstPreOrdem(BST Raiz){
    if(Raiz != NULL){
        printf("%d ", Raiz->valor);
        bstPreOrdem(Raiz->filhoEsq);
        bstPreOrdem(Raiz->filhoDir);
    }
}

/*
    @brief Imprime a arvore seguindo a logica de InOrdem
    @para Raiz Elemento que representa a arvore a ser impressa
*/
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