#include "BST.h"
#include "AVL.h"
#include <stdio.h>

int main(){
    BST bst = bstCriarNo(4);
    bstAddElemento(bstCriarNo(2),bst);
    bstAddElemento(bstCriarNo(7),bst);
    bstAddElemento(bstCriarNo(1),bst);
    bstAddElemento(bstCriarNo(3),bst);
    bstAddElemento(bstCriarNo(5),bst);
    bstAddElemento(bstCriarNo(9),bst);
    bstAddElemento(bstCriarNo(6),bst);
    bstAddElemento(bstCriarNo(8),bst);
    bstAddElemento(bstCriarNo(10),bst);

    bstPreOrdem(bst);
    printf("\n");
    bstInOrdem(bst);
    printf("\n");
    bstPosOrdem(bst);
    printf("\n");
    bstIdentImprime(bst, 1);
}