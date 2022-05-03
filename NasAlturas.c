#include "BST.c"
#include "AVL.c"
#include "NasAlturas.h"

#include <stdio.h>
#include <stdlib.h>

int main(){
    time_t hora;
    srand((unsigned) time(&hora));

    int amostras = 2;
    int qtdNos = 6;
    int arrValores[qtdNos];
    popularVetor(arrValores, qtdNos);
    printf("Array: ");
    imprimeVetor(arrValores, qtdNos);
    printf("\n----------------------------------\n");

    printf("AVL: \n");
    AVL avl = criarAVL(arrValores, qtdNos);
    avlIdentImprime(avl, 0);
    
    printf("\nBST: \n");
    BST bst = criarBST(arrValores, qtdNos);
    bstIdentImprime(bst, 0);
    
}

AVL criarAVL(int * valores, int quantidade){
    AVL avl = avlCriarNo(valores[0]);
    for(int i = 1; i < quantidade; i++){
        avl = avlAddElemento(avlCriarNo(valores[i]), avl);
    }
    return avl;
}

BST criarBST(int * valores, int quantidade){
    BST bst = bstCriarNo(valores[0]);
    for(int i = 1; i < quantidade; i++){
        bstAddElemento(bstCriarNo(valores[i]),bst);
    }
    return bst;
}

void popularVetor(int * vetor, int tamanho){
    for(int i = 0; i < tamanho; i++){
        vetor[i] = rand() % 100; //gera um numero aleatório entre 0 e 100
    }
}

void imprimeVetor(int * vetor, int tamanho){
    for(int i = 0; i < tamanho; i++){
        printf(">%d ",vetor[i]);
    }
}