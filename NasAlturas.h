#ifndef NasAlturas_DOT_H
#define NasAlturas_DOT_H

/*
    @brief Incere no array valores gerados aleatoriamenteo
    @param vetor Ponteiro do vetor a ser populado
    @param temanho Quantidade de elementos dentro do array
*/
void popularVetor(int * vetor, int tamanho);

/*
    @brief Imprime na tela os valores contidos no vetor
    @param vetor Ponteiro do vetor a ser impresso
    @param tamanho Tamanho do vetro a ser impresso
*/
void imprimeVetor(int * vetor, int tamanho);

/*
    @brief Cria uma BST AVL com os valores entrados
    @param valores Ponteiro do array contendo os valores dos nos
    @param quantidade Quantidade de elementos no array
    @return Retorna a raiz da arvore
*/
AVL criarAVL(int * valores, int quantidade);

/*
    @brief Cria uma BST com os valores entrados
    @param valores Ponteiro do array contendo os valores dos nos
    @param quantidade Quantidade de elementos no array
    @return Retorna a raiz da arvore
*/
BST criarBST(int * valores, int quantidade);

#endif