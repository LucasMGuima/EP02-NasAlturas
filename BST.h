#ifndef BST_DOT_H
#define BST_DOT_H

typedef struct no{
    int valor;
    int h;
    struct no * filhoEsq;
    struct no * filhoDir;
}No;
typedef No* BST;
/*
    @brief  Função que acrescente um novo elemento na BST
    @param  No Novo elemento a ser adicionado na arvore
    @param  Raiz Elemento que representa a arvore a ser incerido o elemento
*/
BST bstAddElemento(BST No, BST Raiz);
/*
    @brief Função que cria um novo no com o valor entrado
    @param num valor a ser atrbuido ao novo no
    @return O novo no criado
*/
BST bstCriarNo(int Num);
/*
    @brief Função que cria um novo no com o valor entrado
    @param num valor a ser atrbuido ao novo no
    @return O novo no criado
*/
BST bstBusca(BST Raiz, int N);
/*
    @brief Procura pelo menor elementos incerido na arvore
    @param Raiz Elemento que representa a arvore a ser usada
    @return Retorna o menor elemento da arvore
*/
BST bstMinimo(BST Raiz);
/*
    @brief Procura pelo maior elementos incerido na arvore
    @param Raiz Elemento que representa a arvore a ser usada
    @return Retorna o menor elemento da arvore
*/
BST bstMaximo(BST Raiz);
/*
    @brief Imprime a arvore seguindo a logica de PreOrdem
    @param Raiz Elemento que representa a arvore a ser impressa
*/
void bstPreOrdem(BST Raiz);
/*
    @brief Imprime a arvore seguindo a logica de InOrdem
    @para Raiz Elemento que representa a arvore a ser impressa
*/
void bstInOrdem(BST Raiz);
/*
    @brief Imprime a arvore seguindo a logica de PosOrdem
    @para Raiz Elemento que representa a arvore a ser impressa
*/
void bstPosOrdem(BST RAiz);
/*
    @brief Imprime a arvore seguindo a logica de InOrdem e com identação para representar visualmente a arvore.
    @para Raiz Elemento que representa a arvore a ser impressa
*/
void bstIdentImprime(BST Raiz, int espaco);
/*
    @brief Calcula a altura do No
    @param No no a ser calculado a altura
*/
int bstCalculaAltura(BST No);

#endif