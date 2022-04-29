#ifndef BST_DOT_H
#define BST_DOT_H

typedef struct no{
    int valor;
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

#endif