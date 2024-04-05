#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

#define MAX 3

typedef struct pilha{
    int n;
    int vet[MAX]
}Pilha;


Pilha* pilha_cria(void){
    Pilha *p = malloc(sizeof(Pilha));

    if(p==NULL){
        printf("Memoria insuficiente!!!\n");
        exit(1);
    }

    p->n = 0;

    return p;
}

void pilha_push(Pilha *p, int info){
    if(p->n==MAX){
        printf("Capacidade da Pilha Estourou!!!\n");
        exit(1);
    }
    p->vet[p->n]= info;
    p->n = p->n + 1;
}

void pilha_imprime(Pilha *p){
    int i;

    for(i = p->n-1; i>=0;i--){
        printf("%d\n",p->vet[i]);
    }

}

void pilha_libera(Pilha *p){
    free(p);
}

int pilha_vazia(Pilha *p){
    return p->n==0;
}

int pilha_pop(Pilha *p){
    int a;

    if(pilha_vazia(p)){
        printf("Pilha Vazia!!!\n");
        exit(1);
    }
    
    a = p->vet[p->n-1];
    p->n--;

    return a;
}   

int topo(Pilha *p){
    return p->vet[p->n - 1];
}

int impares(Pilha *p){

    int count = 0;

    for(int i = 0; i < p->n;i++){
        if(p->vet[i] % 2 != 0){
            count++;
        }
    }

    return count;
}

Pilha* empilha_pares(Pilha *p1, Pilha *p2){
    Pilha *p3 = pilha_cria();

    for(int i = 0; i < p1->n; i++){
        if(p1->vet[i] % 2 == 0){
            pilha_push(p3,p1->vet[i]);
        }
    }

    for(int i = 0; i < p2->n; i++){
        if(p2->vet[i] % 2 == 0){
            pilha_push(p3,p2->vet[i]);
        }
    }

    pilha_libera(p1);
    pilha_libera(p2);

    return p3;
}



