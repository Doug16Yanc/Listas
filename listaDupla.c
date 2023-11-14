#include "listas.h"

void interageListaDupla(){

    int opcao;
    double valor, anterior;
    No *removido, *buscado, *lista = NULL;
    printf("**************************************************************\n");
    printf("Você selecionou a alternativa para lista duplamente encadeada.\n");
    printf("**************************************************************\n");

    do{
        printf("        Selecione uma opção             \n");
        printf("        0 - Retornar ao início          \n");
        printf("        1 - Inserir no início           \n");
        printf("        2 - Inserir no meio             \n");
        printf("        3 - Inserir no final            \n");
        printf("        4 - Remover nó                  \n");
        printf("        5 - Buscar nó                   \n");
        printf("        6 - Listar nós na ordem direta  \n");
        printf("        7 - Listar nós na ordem inversa \n");

        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                printf("Digite um valor a ser inserido:\n");
                scanf("%lf", &valor);
                inserirInicio(&lista, valor);
                break;
            case 2:
                printf("Digite um valor a ser inserido e o valor de referência:\n");
                scanf("%lf%lf", &valor, &anterior);
                inserirMeio(&lista, valor, anterior);
                break;
            case 3:
                printf("Digite um valor a ser inserido:\n");
                scanf("%lf", &valor);
                inserirFim(&lista, valor);
                break;
            case 4:
                printf("Digite um valor a ser removido:\n");
                scanf("%lf", &valor);
                removido = removerNo(&lista, valor);
                if(remover){
                    printf("Elemento a ser removido com sucesso: %.2f\n", removido -> valor);
                    free(removido);
                }
                else{
                    printf("Elemento não encontrado.\n");
                }
                break;
            case 5:
                printf("Digite um elemento a ser buscado:\n");
                scanf("%lf", &valor);
                buscado = buscarNo(&lista, valor);
                if(buscado){
                    printf("Elemento encontrado com sucesso: %.2f", buscado -> valor);
                }
                else{
                    printf("Elemento não encontrado.\n");
                }
                break;
            case 6:
                listarDireto(lista);
                break;
            case 7:
                listarInverso(&lista);
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


void inserirInicio(No** lista, int elemento){
    No *novoNo = malloc(sizeof(No));

    if (novoNo){
        novoNo -> valor = elemento;
        novoNo -> proximo = *lista;
        novoNo -> anterior = NULL;
        if(*lista){
            (*lista) -> anterior = novoNo;
        }
        *lista = novoNo;
    }
    else{
        printf("Não há memória disponível para tal alocação.\n");
        exit(1);
    }
}
void inserirMeio(No** lista, int elemento, int anterior){

}
void inserirFim(No ** lista, int elemento){

}
void removerNo(No** lista, int elemento){

}
No* buscarNo(No** lista, int elemento){

}
void listarDireto(No *no){

}
void listarInverso(No *lista){

}