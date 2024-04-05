#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

typedef struct lista{
    int info;
    struct lista *prox;
}Lista;

// Função que cria uma lista vazia
Lista* lst_cria(){
    Lista *l = malloc(sizeof(Lista));

    if(l != NULL){
        l = NULL;
    }

    return l;
}

Lista* lst_insere_inicio(Lista* l, int i){
    Lista *new = malloc(sizeof(Lista));

    if(new){
        new->info = i;
        if(l == NULL){
            new->prox = NULL;
            return new;
        }

        new->prox = l;

        return new;
    } else {
        printf("Erro ao alocar memória\n");

        return l;
    }
}

Lista* lst_insere(Lista* l, int i){
    Lista* new = malloc(sizeof(Lista));

    if(new){
        new->info = i;
        new->prox = NULL;

        if(l ==NULL){
            return new;
        }

        Lista* aux = l;

        while(aux->prox != NULL){
            aux = aux->prox;
        }

        aux->prox = new;

        return l;

    }else{
        printf("Erro ao alocar memória\n");

        return l;
    }
}

Lista* lst_remove_rec(Lista* l, int v){
    if(l == NULL){
        return NULL;
    }

    if(l->info == v){
        Lista* aux = l->prox;
        free(l);
        return aux;
    }

    l->prox = lst_remove_rec(l->prox, v);

    return l;
}

void lst_imprime_invertida_rec(Lista* l){
    if(l == NULL){
        return;
    }

    lst_imprime_invertida_rec(l->prox);
    printf("%d ", l->info);
}

Lista* lst_imprime(Lista* l){
    Lista* aux = l;

    while(aux != NULL){
        printf("%d ", aux->info);
        aux = aux->prox;
    }

    printf("\n");

    return l;
}

Lista* lst_libera(Lista* l){
    Lista* aux = l;

    while(aux != NULL){
        Lista* aux2 = aux->prox;
        free(aux);
        aux = aux2;
    }

    return NULL;
}

Lista* lst_retira(Lista* l, int v){
    Lista* ant = NULL;
    Lista* aux = l;
    
     if (aux != NULL && aux->info == v) {
        l = aux->prox; 
        free(aux); 
        return l; 
    }

    while(aux != NULL && aux->info != v){
        ant = aux;
        aux = aux->prox;
    }

     if (aux != NULL) {
        ant->prox = aux->prox; 
        free(aux); 
    } else {
        printf("Elemento nao encontrado\n");
    }

    return l;
}

Lista* lst_busca(Lista* l, int v){
    Lista* aux = l;
    
    while(aux != NULL && aux->info != v){
        aux = aux->prox;
    }

    if(aux != NULL){
        return aux;
    } else {
        printf("Elemento nao encontrado\n");
        return NULL;
    }

}

int comprimento(Lista* l){
    Lista* aux = l;
    int count = 0;

    while(aux != NULL){
        count++;
        aux = aux->prox;
    }

    return count;
}

int menores(Lista* l, int v){
    Lista* aux = l;
    int count = 0;

    while(aux != NULL){
        if(aux->info < v){
            count++;
        }
        aux = aux->prox;
    }

    return count;
}

int soma(Lista* l){
    Lista* aux = l;
    int sum = 0;

    while(aux != NULL){
        sum += aux->info;
        aux = aux->prox;
    }

    return sum;
}

int primos(Lista* l){
    Lista* aux = l;
    int count = 0;

    while(aux != NULL){
        int i;
        for(i = 2; i < aux->info; i++){
            if(aux->info % i == 0){
                break;
            }
        }

        if(i == aux->info){
            count++;
        }

        aux = aux->prox;
    }

    return count;
}

Lista* lst_conc(Lista* l1, Lista* l2){
    Lista* aux = l1;

    while(aux->prox != NULL){
        aux = aux->prox;
    }

    aux->prox = l2;

    return l1;
}

Lista* lst_diferenca(Lista* l1, Lista* l2){
    Lista* aux = l1;

    while(aux != NULL){
        Lista* aux2 = l2;
        while(aux2 != NULL){
            if(aux->info == aux2->info){
                l1 = lst_retira(l1, aux->info);
            }
            aux2 = aux2->prox;
        }
        aux = aux->prox;
    }

    return l1;
}

