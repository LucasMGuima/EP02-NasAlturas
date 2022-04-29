#ifndef AVL_DOT_H
#define AVL_DOT_H

typedef struct no{
    int valor;
    int h;
    struct no * filhoEsq;
    struct no * filhoDir;
}No;
typedef No* AVL;

/*
    @brief Adiciona um elemento na arvore
    @param No Elemento a ser adicionado
    @param Raiz Arvore a ser adicionado o no
*/
AVL avlAddElemento(AVL No, AVL Raiz);
/*
    @brief Cria um novo No com o numero entrado
    @param Num Valor a ser colocado no novo no
    @return O novo No criado
*/
AVL avlCriarNo(int Num);
/*
    @brief Rotaciona o elemento da arvore para a esquerda
    @param No Elemento a ser rotacionado
    @param Raiz Arvore que possui o elemento
    @return Nova arvore
*/
AVL avlRotacionaEsquerda(AVL No, AVL Raiz);

#endif