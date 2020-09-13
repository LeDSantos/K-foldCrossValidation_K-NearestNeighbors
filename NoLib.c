/*Letícia dos Santos    275604

INF01017 - Aprendizado de Máquina (2020/1)
Exercício sobre Validação Cruzada

Biblioteca da lista duplamente encadeada que:
-> guarda o arquivo fonte com instâncias de NUM_CLASSES(incluindo a alvo);
-> guarda os maiores e menores valores;
-> separa a lista em K_FOLDS de forma estratificada.
*/

#include <stdio.h>
#include <stdlib.h>

#define NUM_CLASSES 9
#define TAM_LINHA 100
#define K_FOLDS 10

///usa para normalizar os valores
float menores[NUM_CLASSES-1] = {1000000.0, 1000000.0, 1000000.0, 1000000.0, 1000000.0, 1000000.0, 1000000.0, 1000000.0};///usa para normalizar os valores
float maiores[NUM_CLASSES-1] = {0.0};

typedef struct no{
    float classe[NUM_CLASSES];
    struct no* prox;
}No;

No *criar_lista(void){
    return NULL;
}

void imprime_lista(No* lista){
    printf("-------------------\n");
    while (lista != NULL) {
        for(int i=0; i<NUM_CLASSES; i++)
            printf("\t%.3f", lista->classe[i]);
        printf("\n");
        lista = lista->prox;
    }
    printf("FIM DA LISTA\n");
}

void insere_comeco(No** lista, float dados[NUM_CLASSES]){
    No* no;

    no = (No*) malloc(sizeof(No));
    for(int i=0; i<NUM_CLASSES; i++)
        no->classe[i] = dados[i];
    no->prox = *lista;
    *lista = no;
}

void insere_dados(No **lista, FILE *fonte){
    char linha[TAM_LINHA], num_ext[TAM_LINHA];

    int classe, i, i_linha, i_num_ext;
    float num[NUM_CLASSES];

    while (!feof(fonte)){//analisa o arquivo fonte
        linha[0]='\0';
        if( fgets(linha, sizeof(linha), fonte) == NULL ){//lê linha
            printf("ERRO AO LER A LINHA");
            return;
        }

        i_num_ext=0;
        num_ext[0] = '\0';//zera o numero por extenso

        for(i_linha=0, classe = 0; classe < NUM_CLASSES; classe++){
            while(linha[i_linha] != ','){
                num_ext[i_num_ext] = linha[i_linha];
                i_num_ext++;
                i_linha++;
            }
            i_linha++;
            num_ext[i_num_ext]='\0';
            num[classe] = atof(num_ext);//coleta cada numero
            
            i_num_ext=0;
            num_ext[0]='\0';
        }
        for(i=0; i<NUM_CLASSES-1; i++){//encontra maiores e menores de cada classe
            if(num[i] < menores[i]) menores[i] = num[i];
            if(num[i] > maiores[i]) maiores[i] = num[i];
        }
        insere_comeco(lista, num);//coloca na lista
    }
    return;
}

void divideKfolds(No **lista, No *fold[K_FOLDS]){
    No* no;
    No* diabetico;
    No* no_diabetico;
    No* n_diabetico;
    No* no_n_diabetico;
    //poderia ter feito vetores de lista, mas escolhi fazer listas separadas
    //para ficar mais legível e evitar problemas com ponteiros
    
    diabetico = criar_lista();
    n_diabetico = criar_lista();
    no=*lista;

    while (no != NULL){//divide a lista de acordo com o atributo alvo
        if(no->classe[8] == 1.0){
            insere_comeco(&diabetico, no->classe);            
        }else{
            insere_comeco(&n_diabetico, no->classe);
        }
        no=no->prox;
    }

    no_n_diabetico=n_diabetico;//distribui não diabeticos em K_FOLDS
    while(no_n_diabetico != NULL){
        for(int i=0; (i < K_FOLDS) && (no_n_diabetico != NULL); i++, no_n_diabetico=no_n_diabetico->prox){
            insere_comeco(&fold[i], no_n_diabetico->classe);
        }
    }

    no_diabetico=diabetico;//distribui diabeticos em K_FOLDS
    while(no_diabetico != NULL){
        for(int i=0; (i < K_FOLDS) && (no_diabetico != NULL); i++, no_diabetico=no_diabetico->prox){
            insere_comeco(&fold[i], no_diabetico->classe);
        }
    }
    return;
}