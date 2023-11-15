
#ifndef LISTAS_H
#define LISTAS_H

#include <stdio.h>
#include <stdlib.h>

/*Estrutura para lista duplamente encadeada*/
typedef struct no{
    double valor;
    struct no *proximo;
    struct no *anterior;
} No;

typedef struct lista{
    No *ini;
    int tam;
} Lista;

/*Estrutura para lista circular*/
typedef struct node{
    double numero;
    struct node *prox;
} Node;

typedef struct listaCir{
    Node *inicio;
    Node *fim;
    int tamanho;
} ListaCir;

/*Protótipos de funções para interação pioneira*/
void interageListaDupla();
void interageListaCircular();

/*Protótipos de funções para lista duplamente encadeada*/
void criarListaDup(Lista *lista);
void inserirInicioDup(No** lista, double elemento);
void inserirMeioDup(No** lista, double elemento, double anterior);
void inserirFimDup(No** lista, double elemento);
No* removerNoDup(No** lista, double elemento);
No* buscarNoDup(No** lista, double elemento);
void listarDiretoDup(No *no);

/*Protótipos de funções para lista circular*/
void criarListaCir(ListaCir *listaCir);
void inserirInicioCir(ListaCir *lista, double num);
void inserirFimCir(ListaCir *listaCir, double num);
Node* removerNoCir(ListaCir *listaCir, double num);
Node* buscarNoCir(ListaCir *listaCir, double num);
void listarCir(ListaCir *listaCir);

#endif