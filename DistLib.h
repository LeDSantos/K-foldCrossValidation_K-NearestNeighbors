/*Letícia dos Santos

Aprendizado de Máquina
Exercício sobre Validação Cruzada

Biblioteca da lista duplamente encadeada que guarda:
-> DISTÂNCIA ENTRE A INSTÂNCIA E SEU VIZINHO;
-> SAÍDA(ATRIBUTO ALVO) DO VIZINHO.
*/

#include "DistLib.c"

/*cria nova lista vazia*/
Dist *dist_criar_lista(void);

/*imprime a lista*/
void dist_imprime_lista(Dist* lista);

/*imprime a lista do final até o início*/
void dist_imprime_listaFIM(Dist* lista);

/*insere na raiz*/
void dist_insere_comeco(Dist** lista, float distancia, int saida);

/*retira elemento e retorna o valor do atributo alvo*/
int dist_pop_lista(Dist** lista);

/*destroi a lista inteira*/
void dist_destroi_lista(Dist** lista);
