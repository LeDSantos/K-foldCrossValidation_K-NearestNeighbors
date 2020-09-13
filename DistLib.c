/*Letícia dos Santos    275604

INF01017 - Aprendizado de Máquina (2020/1)
Exercício sobre Validação Cruzada

Biblioteca da lista duplamente encadeada que guarda:
-> DISTÂNCIA ENTRE A INSTÂNCIA E SEU VIZINHO;
-> SAÍDA(ATRIBUTO ALVO) DO VIZINHO.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct dist{
    float distancia;    //entre a instância e seu vizinho
    int saida;          //atributo alvo
    struct dist* ant;
    struct dist* prox;
}Dist;

Dist *dist_criar_lista(void){
    return NULL;
}

void dist_imprime_lista(Dist* lista){
    printf("----------INÍCIO----------\n");
    while (lista != NULL) {
        printf("\t%f\t%d", lista->distancia, lista->saida);
        printf("\n");
        lista = lista->prox;
    }
    printf("--------FIM DA LISTA------\n");
}

void dist_imprime_listaFIM(Dist* lista){
    //fiz isso para conferir se o ant tava encadeado certo
    while (lista!=NULL && lista->prox != NULL) {
        lista = lista->prox;
    }//chega até o final da lista

    printf("--------FIM DA LISTA------\n");
    while (lista != NULL) {
        printf("\t%f\t%d", lista->distancia, lista->saida);
        printf("\n");
        lista=lista->ant;
    }
    printf("----------INÍCIO----------\n");
}

void dist_insere_comeco(Dist** lista, float distancia, int saida){
    Dist* no;

    no = (Dist*) malloc(sizeof(Dist));
    no->distancia=distancia;
    no->saida=saida;
    no->ant = NULL;
    no->prox = *lista;

    if(*lista != NULL)
        (*lista)->ant=no;
    *lista = no;
}

int dist_pop_lista(Dist** lista){
    int saida;
    Dist *escolhido;

    escolhido=*lista;
    //printf("dist de %f com saida %d\n", escolhido->distancia, escolhido->saida);
    saida=escolhido->saida;

    if(escolhido-> ant == NULL){//primeiro elemento
        escolhido->prox->ant = NULL;
        *lista = escolhido->prox;
    }else{
        escolhido->ant->prox = escolhido->prox;
    }

    if (escolhido->prox != NULL)//ultimo elemento
        escolhido->prox->ant = escolhido->ant;

    free(escolhido);

    return saida;
}


void dist_destroi_lista(Dist** lista){
    Dist *aux1;
    Dist *aux2;

    aux1 = *lista;
    while (aux1 != NULL){
        aux2 = (Dist *)aux1->prox;
        free(aux1);
        aux1 =aux2;
    }
    *lista = NULL;
    return;
}