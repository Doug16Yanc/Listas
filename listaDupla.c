#include "listas.h"

/*Gera interação com o usuário após escolher a opção de lista duplamente encadeada*/

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
                inserirMeioDup(&lista, valor, anterior);    /*Necessita ser um valor anterior válido, no caso de a lista não estar vazia*/
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
                if(removido){
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

/*Em todas as funções de inserção, há tratamento para alocação dinâmica*/
void criarListaDup(Lista *lista){
    lista -> ini = NULL;
    lista -> tam = 0;
}

void inserirInicioDup(No** lista, double elemento){
    No *novoNo = malloc(sizeof(No)); 
    
    if (novoNo == NULL){
        printf("Não há memória disponível para esta alocação.\n");
        return;
    }

    novoNo -> valor = elemento;     /*O novoNo aponta para o valor recebido*/
    novoNo -> proximo = *lista;     /*De tal modo, que o novoNo apontado para o próximo valor é atribuído ao ponteiro da lista*/
    novoNo -> anterior = NULL;      /*Sendo assim, o valor anterior que estava no início é atribuído de valor NULL*/
    if(*lista){
        (*lista) -> anterior = novoNo;
    }                   /*Dessa maneira, o ponteiro lista aponta para o valor anterior (início) que é atribuído do novoNo*/
    *lista = novoNo;

}
void inserirMeioDup(No** lista, double elemento, double anterior){
    No *auxiliar, *novoNo = malloc(sizeof(No));
    
    if (novoNo == NULL){
        printf("Não há memória disponível para esta alocação.\n");
        return;
    }
    
    novoNo -> valor = elemento;     /*O novoNo aponta para o valor recebido*/
        
    if (*lista == NULL){            /*Se a lista estiver vazia, o elemento então aponta para próximo*/
        novoNo -> proximo = NULL;   /*e anterior atribuídos de NULL e a lista é preenchida somente com ele*/
        novoNo -> anterior = NULL;
        *lista = novoNo;
    }
    else{                           /*Caso contrário, a variável auxiliar então trata de percorrer a lista para encontrar*/
        auxiliar = *lista;          /*o valor anterior e então inserí-lo entre o valor anterior de referência e o próximo*/
        
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
        return;
    }
    
    novoNo -> valor = elemento;         /*Dessa vez, também há o tratamento para fazer com quê o novoNo aponte para um*/
    novoNo -> proximo = NULL;           /*próximo atribuído de NULL, claramente o final*/
    
    if (*lista == NULL){                /*Se a lista estiver vazia, logo, é preenchida somente com o novoNo*/
        *lista =  novoNo;
    }
    else{                               /*Caso contrário, a variável nó percorre a lista até chegar no próximo*/
        auxiliar = *lista;              /*atribuído de NULL*/
        while(auxiliar -> proximo){
            auxiliar = auxiliar -> proximo;
        }
        auxiliar -> proximo = novoNo;       /*E então, o atribui do novoNo.*/
    }
}
/*Para remoção, em vez de selecionar exclusão no início, meio ou fim, preferi fazer*/
/*uma função ponteiro para remover um elemento que esteja na lista*/
/*e eu confesso que há muitas chamadas recursivas aqui*/
No* removerNoDup(No** lista, double elemento){
    No *auxiliar, *removerNoDup = NULL;
    
    if (*lista){                    /*Se estiver no início, remove-o e ajusta o início*/
        if((*lista)->valor == elemento){
            removerNoDup = *lista;
            *lista = removerNoDup->proximo;
            
            if (*lista){
                (*lista)->anterior = NULL;
            }
        }
        else {                      /*Se não, a variável auxiliar percorre a lista para encontrar o elemento*/
            auxiliar = *lista;      /*se ele existir, remove-o e ajusta a lista*/
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
    return removerNoDup;        /*Retorna o nó ou NULL se ele não existir, a mensagem de inexistência está nas*/
                                /*opções de execuções condicionais em interageListaDupla()*/
}

No* buscarNoDup(No** lista, double elemento){
    No *auxiliar, *no = NULL;
    
    auxiliar = *lista;      /*O início da lista*/
    
    while(auxiliar && auxiliar -> valor != elemento){      /*A variável auxiliar percorre a lista até encontrar o elemento*/
        auxiliar = auxiliar -> proximo;
    }
    
    if (auxiliar){
        no = auxiliar;          /*Se o encontrar, o elemento é atribuído de auxiliar*/
    }
    return no;          /*Retorna-o*/
}
void listarDiretoDup(No *no){

    if (no == NULL){
        printf("Lista vazia.\n");
    }
    printf("\n              LISTA DIRETA        \n");
    while(no){
        printf("%.2f ", no -> valor);       /*Lista da forma direta, com nó apontando para os próximos*/
        no = no -> proximo;
    }
    printf("\n");
}

void listarInversoDup(No *no){
    No *ultimo = NULL;
                                /*Lista de forma inversa, com nós sendo ajustados para apontar na direção contrária*/
    if (no == NULL){
        printf("Lista vazia.\n");
    }
    while(no){
        ultimo = no;                /*A variável ultimo com valor NULL recebe no que aponta para os próximos*/
        no = no -> proximo; 
       
    } 
    printf("       LISTA INVERSA        \n ");

    while(ultimo){                          /*Então, enquanto ultimo não chegar ao fim (início da ordem direta)*/
        printf("%.2f\t", ultimo -> valor);  /*ele aponta para os valores anteriores*/
        ultimo = ultimo -> anterior;
    }
    printf("\n");
   
}