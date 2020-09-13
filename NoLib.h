/*Letícia dos Santos

Aprendizado de Máquina
Exercício sobre Validação Cruzada

Biblioteca da lista duplamente encadeada que:
-> guarda o arquivo fonte com instâncias de NUM_CLASSES(incluindo a alvo);
-> guarda os maiores e menores valores;
-> separa a lista em K_FOLDS de forma estratificada.
*/

#include "NoLib.c"

/*cria lista vazia*/
No *criar_lista(void);

/*imprime a lista*/
void imprime_lista(No* lista);

/*insere na raiz*/
void insere_comeco(No** lista, float dados[NUM_CLASSES]);

/*insere os dados do arquivo na lista, obtem menores e maiores*/
void insere_dados(No **lista, FILE *fonte);

/*separa a lista em K_FOLDS de forma estratificada*/
void divideKfolds(No **lista, No *fold[K_FOLDS]);
