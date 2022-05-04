#ifndef BST_DOT_H
#define BST_DOT_H

typedef struct no{
    int valor;
    int h;
    struct no * filhoEsq;
    struct no * filhoDir;
}No;
typedef No* BST;

BST bstAddElemento(BST No, BST Raiz);
BST bstCriarNo(int Num);
BST bstBusca(BST Raiz, int N);
BST bstMinimo(BST Raiz);
BST bstMaximo(BST Raiz);
void bstPreOrdem(BST Raiz);
void bstInOrdem(BST Raiz);
void bstPosOrdem(BST RAiz);
void bstIdentImprime(BST Raiz, int espaco);
/*
    @brief Calcula a altura do No
    @param No no a ser calculado a altura
*/
int bstCalculaAltura(BST No);

#endif