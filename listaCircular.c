#include "listas.h"

void interageListaCircular(){
    int opcao;
    double numero;
    ListaCir listaCir;
    Node *removido, *buscado;

    criarListaCir(&listaCir);

    printf("**************************************************************\n");
    printf("Você selecionou a alternativa para lista circular.\n");
    printf("**************************************************************\n");

    do{
        printf("        Selecione uma opção             \n");
        printf("        0 - Encerrar operação           \n");
        printf("        1 - Inserir no início           \n");
        printf("        2 - Inserir no final            \n");
        printf("        3 - Remover nó                  \n");
        printf("        4 - Buscar nó                   \n");
        printf("        5 - Listar nós                  \n");

        scanf("%d", &opcao);

        switch(opcao){
            case 0:
                printf("Obrigado por sua interação comigo. Até logo!\n");
                exit(1);
            case 1:
                printf("Digite um valor a ser inserido:\n");
                scanf("%lf", &numero);
                inserirInicioCir(&listaCir, numero);
                break;
            case 2:
                printf("Digite um valor a ser inserido:\n");
                scanf("%lf", &numero);
                inserirFimCir(&listaCir, numero);
                break;
            case 3:
                printf("Digite um valor a ser removido:\n");
                scanf("%lf", &numero);
                removido = removerNoCir(&listaCir, numero);
                if(removerNoDup){
                    printf("Elemento a ser removido com sucesso: %.2f\n", removido -> numero);
                    free(removido);
                }
                else{
                    printf("Elemento não encontrado.\n");
                }
                break;
            case 4:
                printf("Digite um elemento a ser buscado:\n");
                scanf("%lf", &numero);
                buscado = buscarNoCir(&listaCir, numero);
                if(buscado){
                    printf("Elemento encontrado com sucesso: %.2f", buscado -> numero);
                }
                else{
                    printf("Elemento não encontrado.\n");
                }
                break;
            case 5:
                listarCir(&listaCir);
                break;
            default:
                if (opcao != 0){
                    printf("Alternativa inválida.\n");
                }
                break;
        }
    }
    while(opcao != 0);
}


void criarListaCir(ListaCir *listaCir) {
    listaCir->inicio = NULL;
    listaCir->fim = NULL;
    listaCir->tamanho = 0;
}

void inserirInicioCir(ListaCir *listaCir, double num) {
    Node *novoNode = malloc(sizeof(Node));

    if (novoNode == NULL) {
        printf("Não há memória disponível.");
        exit(1);
    }

    novoNode->numero = num;
    novoNode->prox = listaCir->inicio;
    listaCir->inicio = novoNode;

    if (listaCir->fim == NULL) {
        listaCir->fim = novoNode;
    }
    listaCir->fim->prox = listaCir->inicio;
    listaCir->tamanho++;
}

void inserirFimCir(ListaCir *listaCir, double num) {
    Node *auxiliar, *novoNode = malloc(sizeof(Node));

    if (novoNode == NULL) {
        printf("Não há memória disponível.\n");
        exit(1);
    }

    novoNode->numero = num;

    if (listaCir->inicio == NULL) {
        listaCir->inicio = novoNode;
        listaCir->fim = novoNode;
        listaCir->fim->prox = listaCir->inicio;
    } else {
        listaCir->fim->prox = novoNode;
        listaCir->fim = novoNode;
        listaCir->fim->prox = listaCir->inicio;
    }
    listaCir->tamanho++;
}

Node* removerNoCir(ListaCir *listaCir, double numero) {
    Node *auxiliar, *removerNode = NULL;

    if (listaCir->inicio) {
        if (listaCir->inicio == listaCir->fim && listaCir->inicio->numero == numero) {
            removerNode = listaCir->inicio;
            listaCir->inicio = NULL;
            listaCir->fim = NULL;
            listaCir->tamanho--;
        } else if (listaCir->inicio->numero == numero) {
            removerNode = listaCir->inicio;
            listaCir->inicio = removerNode->prox;
            listaCir->fim->prox = listaCir->inicio;
            listaCir->tamanho--;
        } else {
            auxiliar = listaCir->inicio;

            while (auxiliar->prox != listaCir->inicio && auxiliar->prox->numero != numero) {
                auxiliar = auxiliar->prox;
            }
            if (auxiliar->prox->numero == numero) {
                if (listaCir->fim == auxiliar->prox) {
                    removerNode = auxiliar->prox;
                    auxiliar->prox = removerNode->prox;
                    listaCir->fim = auxiliar;
                } else {
                    removerNode = auxiliar->prox;
                    auxiliar->prox = removerNode->prox;
                }
                listaCir->tamanho--;
            }
        }
    }
    return removerNode;
}

Node* buscarNoCir(ListaCir *listaCir, double num) {
    Node *auxiliar = listaCir->inicio;

    if (auxiliar) {
        while (auxiliar != listaCir->inicio) {
            if (auxiliar->numero == num) {
                return auxiliar;
            }
            auxiliar = auxiliar->prox;
        }
    }
    return NULL;
}

void listarCir(ListaCir *listaCir) {
    Node *node = listaCir->inicio;

    printf("        LISTA           \n");

    if (node) {
        do {
            printf("%.2f\t", node->numero);
            node = node->prox;
        } while (node != listaCir->inicio);
        printf("\n");
    }
}

