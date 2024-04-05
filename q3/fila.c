#include <stdio.h>
#include <stdlib.h>
#include "fila.h"


struct lista{
    int info;
    Lista *prox;
};
struct fila{
    Lista *ini;
    Lista *fim;
}; 

Fila* fila_cria(void){
    Fila *f = (Fila*)malloc(sizeof(Fila));

    if(f==NULL){
        printf("Memoria insuficiente!!!\n");
        exit(1);
    }

    f->ini = NULL;
    f->fim = NULL;

    return f;
}

void fila_insere(Fila *f, int info){
    Lista *l = (Lista*)malloc(sizeof(Lista));
    if(l==NULL){
        printf("Memoria insuficiente!!!\n");
        exit(1);
    }

    l->info = info;
    l->prox = NULL;

    if(!fila_vazia(f))
        f->fim->prox = l;
    else
        f->ini = l;
    f->fim = l;
}

int fila_vazia(Fila *f){
    return f->ini==NULL;
}

int fila_remove(Fila *f){
    Lista *l; int a;
    if(fila_vazia(f)){
        printf("Fila Vazia!!!\n");
        exit(1);
    }

    a = f->ini->info;
    l = f->ini;
    f->ini = f->ini->prox;
    free(l);

    if(fila_vazia(f))
        f->fim = NULL;

    return a;

}

void fila_imprime(Fila *f){
    Lista *lAux = f->ini;
    while(lAux!=NULL){
        printf("%d\n",lAux->info);
        lAux = lAux->prox;
    }
}

void fila_libera(Fila *f){
    Lista* l = f->ini;
    Lista* lAux;

    while(l!=NULL){
        lAux = l->prox;
        free(l);
        l = lAux;
    }

    free(f);
}

int qtd_maior(Fila *f, int n){
    Lista *aux = f->ini;

    if(fila_vazia(f)){
        printf("Fila Vazia!!!\n");
        exit(1);    
    } else {
        int qtd = 0;
        
        while(aux!=NULL){
            if(aux->info > n)
                qtd++;
            aux = aux->prox;
        }
        return qtd;
    }
}

Fila* inverte(Fila *f){
    Lista *aux = f->fim;
    Fila *newFila = malloc(sizeof(Fila));

    if(newFila){
        if(fila_vazia(f)){
            printf("Fila Vazia!!!\n");
            exit(1);    
        } else {
            newFila->ini = aux;
            while(aux->prox != NULL){
                fila_insere(newFila, aux->prox->info);
                aux = aux->prox;
            }

            newFila->fim = aux;
        }
    } else {
        printf("Erro na alocação de memoria");
        exit(1);
    }

    return newFila;
}

int pares(Fila *f){
    int count = 0;

    if(fila_vazia(f)){
        printf("Fila Vazia!!!\n");
        exit(1); 
    } else {
        Lista *aux = f->ini;

        while(aux != NULL){
            if(aux->info % 2 == 0){
                count++;
            }

            aux = aux->prox;
        }
    }
}

