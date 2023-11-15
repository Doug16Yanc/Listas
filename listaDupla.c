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
        printf("        0 - Encerrar operação           \n");
        printf("        1 - Inserir no início           \n");
        printf("        2 - Inserir no meio             \n");
        printf("        3 - Inserir no final            \n");
        printf("        4 - Remover nó                  \n");
        printf("        5 - Buscar nó                   \n");
        printf("        6 - Listar nós na ordem direta  \n");
        printf("        7 - Listar nós na ordem inversa \n");

        scanf("%d", &opcao);

        switch(opcao){
            case 0:
                printf("Obrigado por sua interação comigo. Até logo!\n");
                exit(1);
            case 1:
                printf("Digite um valor a ser inserido:\n");
                scanf("%lf", &valor);
                inserirInicioDup(&lista, valor);
                break;
            case 2:
                printf("Digite um valor a ser inserido e o valor de referência:\n");
                scanf("%lf%lf", &valor, &anterior);
                inserirMeioDup(&lista, valor, anterior);
                break;
            case 3:
                printf("Digite um valor a ser inserido:\n");
                scanf("%lf", &valor);
                inserirFimDup(&lista, valor);
                break;
            case 4:
                printf("Digite um valor a ser removido:\n");
                scanf("%lf", &valor);
                removido = removerNoDup(&lista, valor);
                if(removerNoDup){
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
                buscado = buscarNoDup(&lista, valor);
                if(buscado){
                    printf("Elemento encontrado com sucesso: %.2f\n", buscado -> valor);
                }
                else{
                    printf("Elemento não encontrado.\n");
                }
                break;
            case 6:
                listarDiretoDup(lista);
                break;
            case 7:
                listarInversoDup(lista);
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

void criarListaDup(Lista *lista){
    lista -> ini = NULL;
    lista -> tam = 0;
}

void inserirInicioDup(No** lista, double elemento){
    No *novoNo = malloc(sizeof(No)); 
    
    if (novoNo == NULL){
        printf("Não há memória disponível para esta alocação.\n");
        exit(1);
    }

    novoNo -> valor = elemento;
    novoNo -> proximo = *lista;
    novoNo -> anterior = NULL;
    if(*lista){
        (*lista) -> anterior = novoNo;
    }
    *lista = novoNo;

}
void inserirMeioDup(No** lista, double elemento, double anterior){
    No *auxiliar, *novoNo = malloc(sizeof(No));
    
    if (novoNo == NULL){
        printf("Não há memória disponível para esta alocação.\n");
        exit(1);
    }
    
    novoNo -> valor = elemento;
        
    if (*lista == NULL){
        novoNo -> proximo = NULL;
        novoNo -> anterior = NULL;
        *lista = novoNo;
    }
    else{
        auxiliar = *lista;
        
        while(auxiliar -> valor != anterior && auxiliar -> proximo){
            auxiliar = auxiliar -> proximo;
        }
        novoNo -> proximo = auxiliar -> proximo;
        auxiliar -> proximo = novoNo;
    }
}
void inserirFimDup(No ** lista, double elemento){
    No *auxiliar, *novoNo = malloc(sizeof(No));
    
    if (novoNo == NULL){
        printf("Não há memória disponível para esta alocação.\n");
        exit(1);
    }
    
    novoNo -> valor = elemento;
    novoNo -> proximo = NULL;
    
    if (*lista == NULL){
        *lista =  novoNo;
    }
    else{
        auxiliar = *lista;
        while(auxiliar -> proximo){
            auxiliar = auxiliar -> proximo;
        }
        auxiliar -> proximo = novoNo;
    }
}

No* removerNoDup(No** lista, double elemento){
    No *auxiliar, *removerNoDup = NULL;
    
    if (*lista){
        if((*lista)->valor == elemento){
            removerNoDup = *lista;
            *lista = removerNoDup->proximo;
            
            if (*lista){
                (*lista)->anterior = NULL;
            }
        }
        else {
            auxiliar = *lista;
            while (auxiliar->proximo && auxiliar->proximo->valor != elemento) {
                auxiliar = auxiliar->proximo;
            }
            
            if (auxiliar->proximo) {
                removerNoDup = auxiliar->proximo;
                auxiliar->proximo = removerNoDup->proximo;
                
                if (removerNoDup->proximo) {
                    removerNoDup->proximo->anterior = auxiliar;
                }
            }
        }
    }
    
    return removerNoDup;
}

No* buscarNoDup(No** lista, double elemento){
    No *auxiliar, *no = NULL;
    
    auxiliar = *lista;
    
    while(auxiliar && auxiliar -> valor != elemento){
        auxiliar = auxiliar -> proximo;
    }
    
    if (auxiliar){
        no = auxiliar;
    }
    return no;
}
void listarDiretoDup(No *no){
    printf("\n              LISTA DIRETA        \n");
    while(no){
        printf("%.2f ", no -> valor);
        no = no -> proximo;
    }
    printf("\n");
}

void listarInversoDup(No *no){
    No *ultimo = NULL;

    while(no){
        ultimo = no;
        no = no -> proximo; 
       
    } 
    printf("       LISTA INVERSA        \n ");

    while(ultimo){
        printf("%.2f\t", ultimo -> valor);
        ultimo = ultimo -> anterior;
    }
    printf("\n");
   
}