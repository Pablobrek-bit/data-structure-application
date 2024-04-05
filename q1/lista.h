#include <stdio.h>
#include <stdlib.h>

typedef struct lista Lista;

Lista* lst_cria();
Lista* lst_insere(Lista* l, int i);
Lista* lst_insere_inicio(Lista* l, int i);
Lista* lst_insere_fim(Lista* l, int i);
Lista* lst_imprime(Lista* l);
Lista* lst_libera(Lista* l);
Lista* lst_retira(Lista* l, int v);
Lista* lst_busca(Lista* l, int v);
Lista* lst_remove_rec(Lista* l, int v);
void lst_imprime_invertida_rec(Lista* l);
int comprimento(Lista* l);
int menores(Lista* l, int v);
int soma(Lista* l);
int primos(Lista* l);
Lista* lst_conc(Lista* l1, Lista* l2);
Lista* lst_diferenca(Lista* l1, Lista* l2);