#include "BST.c"
#include "AVL.c"
#include "NasAlturas.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void separador(){
    printf("-------------------------------------- \n");
}

void simulacao(){
    int amostras;
    int qtdNos;
    int somaTamanhoBST = 0;
    int somaTamanhoAVL = 0;

    printf("Emtre com a qunatidade de amostras: ");
    scanf("%d", &amostras);
    printf("Entre com a quantidade de elementos para cada amostra: ");
    scanf("%d", &qtdNos);
    printf("\nExperimento com A = %d e N = %d \n", amostras, qtdNos);
    separador();
    int arrValores[qtdNos];
    int cont = 0;
    while(cont < amostras){
        //Atribui novos valores ao array
        popularVetor(arrValores, qtdNos);
        //Cria as arvores com os novos valores
        AVL avl = criarAVL(arrValores, qtdNos);
        BST bst = criarBST(arrValores, qtdNos);

        //soma a altura da BST criada ao total de altura da BST
        somaTamanhoBST += bst->h;
        //soma a altura da AVL criada ao total de altura da AVL
        somaTamanhoAVL += avl->h;
        cont += 1;
    }
    //CORRIGIR VIRGULA 
    int alturaMediaAVl = somaTamanhoAVL / amostras;
    int alturaMediaBST = somaTamanhoBST / amostras;
    int alturaMediaGeral = (alturaMediaAVl + alturaMediaBST) / amostras;

    printf("Altura media geral: %d \n", alturaMediaGeral);
    printf("Altura media da BST comum: %d \n", alturaMediaBST);
    printf("Altura media da AVL: %d \n", alturaMediaAVl);
    separador();
}

void menu(){
    printf("EP2 - Nas Alturas \n");
    separador();
    int op;
    do{
        printf("Menu: \n");
        printf("1) Nova simulacao. \n");
        printf("2) Sair. \n");

        scanf("%d", &op);

        switch (op)
        {  
            //Sai do programa
            case 2:
                printf("Tchau! \n");
                break;
            //Chama a simulacao
            case 1:
                simulacao();     
                break;
            //Valore não validos
            default:
                printf("Opcao invalida");
                break;
        }
    }while(op != 2);
}

int main(){
    //Pega uma nova seed para gerar os numeros aleatorios
    time_t hora;
    srand((unsigned) time(&hora));

    //Chama o menu que "controla" o fluxo do programa
    menu();
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