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
    clock_t timer;

    int amostras;
    int qtdNos;
    int somaTamanhoBST = 0;
    float tempoTotalBST = 0;
    int somaTamanhoAVL = 0;
    float tempoTotalAVL = 0;

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
        timer = clock(); //"inicia" o timer
        AVL avl = criarAVL(arrValores, qtdNos);
        timer = clock() - timer; //"termina" o timer
        tempoTotalAVL += ((float)timer)/CLOCKS_PER_SEC; //calcula o tempo passado em segundos

        timer = clock(); //"inicia" o timer
        BST bst = criarBST(arrValores, qtdNos);
        timer = clock() - timer; //"termina" o timer
        tempoTotalBST += ((float)timer)/CLOCKS_PER_SEC; //calcula o tempo passado em segundos

        //soma a altura da BST criada ao total de altura da BST
        somaTamanhoBST += bst->h;
        //soma a altura da AVL criada ao total de altura da AVL
        somaTamanhoAVL += avl->h;
        cont += 1;
    }

    float alturaMediaAVL = somaTamanhoAVL / amostras;
    float tempoMedioAVL = tempoTotalAVL / amostras;

    float alturaMediaBST = somaTamanhoBST / amostras;
    float tempoMedioBST = tempoTotalBST / amostras;

    float alturaMediaGeral = (alturaMediaAVL + alturaMediaBST) / amostras;
    float tempoMedioGeral = (tempoMedioAVL + tempoMedioBST) / amostras;

    printf("Altura media geral: %.2f \n", alturaMediaGeral);
    printf("Tempo medio de construcao geral: %f segundos.\n", tempoMedioGeral);
    printf("--- \n");
    printf("Altura media da BST comum: %.2f \n", alturaMediaBST);
    printf("Tempo medio de construcao BST: %f segundos.\n", tempoMedioBST);
    printf("--- \n");
    printf("Altura media da AVL: %.2f \n", alturaMediaAVL);
    printf("Tempo medio de construcao AVL: %f segundos.\n", tempoMedioAVL);
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
    srand(time(&hora));

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