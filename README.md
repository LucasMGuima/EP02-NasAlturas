
# EP02-NasAlturas

  Atividade para comparação de arvores binarias de busca comuns e AVL.

## Descrição das Estruturas

 O programa está dividido em 6 arquivos 3 são .c e 3 são seus respectivos headers.
 Nos headers se encontra a assinatura e a descrição das funções que serão implementadas no código.

### Funções principais

- BST
  - bstCalculaAltura(BST No) -> Função que recebe um nó e recalcula sua altura, utilizada sempre que ocorre uma inserção de nó na BST. Criada para facilitar o calculo da altura da BST na execução do projeto.
- NasAlturas
  - criarBST(int * valores, int quantidade)/criarAVL(int * valores, int quantidade) -> Ambas as função criam as respectivas arvores já adicionando os elementos enviados como valores. Foram feitas com o intuito de facilitar correções e deixar o código mais limpo.
  - void popularVetor(int * vetor, int tamanho) -> Responsável por gerar os valores que serão adicionados as BSTs, guardando em um vetor de inteiros.

### Geração dos Elementos

  Para gerar os elementos a serem inseridos dentro da arvore, utilizei da biblioteca stdlib junto com a time.
  A stdlib entra com a função rand() que gera um valor aleatório entre 0 e RAND_MAX, pegando esse valor e multiplicando por 100 mantemos o intervalo entre 0 e 100, porem sempre que rodamos o programa voltara sempre os mesmos valores.
  Para corrigir esse problema que a time entra em uso, ao se passar para a função srand() o tempo atual do computador (contando com os milissegundos) se gera uma seed diferente em cada interação do programa, essa que é usada para a geração dos valores no rand().
  Assim fazendo conque sempre que se chama a função de popular o vetor a sequencia dos valores gerados sera diferente.

```c
  void popularVetor(int * vetor, int tamanho){
    //Pega uma nova seed para gerar os numeros aleatorios
    time_t hora;
    srand(time(&hora));

    for(int i = 0; i < tamanho; i++){
        vetor[i] = rand() % 100; //gera um numero aleatório entre 0 e 100
    }
}
```

## Interpretação