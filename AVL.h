#ifndef AVL_DOT_H
#define AVL_DOT_H

typedef struct celula{
    int valor;
    int h;
    struct celula * filhoEsq;
    struct celula * filhoDir;
}Celula;
typedef Celula* AVL;

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
    @return Nova Raiz da nova sub-arvore
*/
AVL avlRotacionaEsquerda(AVL Raiz);
/*
    @brief Rotaciona o elemento da arvore para a direira
    @param No Elemento a ser rotacionado
    @param Raiz Arvore que possui o elemento
    @return Nova Raiz da nova sub-arvore
*/
AVL avlRotacionaDireita(AVL Raiz);
/*
    @brief Imprime a arvore seguindo a logica de PreOrdem
    @param Raiz Elemento que representa a arvore a ser impressa
*/
void avlPreOrdem(AVL Raiz);
/*
    @brief Imprime a arvore seguindo a logica de InOrdem
    @para Raiz Elemento que representa a arvore a ser impressa
*/
void avlInOrdem(AVL Raiz);
/*
    @brief Imprime a arvore seguindo a logica de PosOrdem
    @para Raiz Elemento que representa a arvore a ser impressa
*/
void avlPosOrdem(AVL RAiz);
/*
    @brief Imprime a arvore seguindo a logica de InOrdem "desenhando" uma arvore
    @param Raiz Elemento que representa a arvore a ser impressa
    @param espac Quantidade de espaço a ser dado
*/
void avlIdentImprime(AVL Raiz, int espaco);
/*
    @brief Calcula o fator de balanceamento do No entrado
    @param No no a ser recalculado o FB
    @return Retona o FB calculado
*/
int avlCalculaFatorBalanceamento(AVL No);
/*
    @brief Calcula a altura do No
    @param No no a ser calculado a altura
*/
int avlCalculaAltura(AVL No);


#endif