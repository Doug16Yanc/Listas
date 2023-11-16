#include "listas.h"

/*Gera interação com o usuário após selecionar a opção de lista circular*/
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
                if(removido){
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
                    printf("Elemento encontrado com sucesso: %.2f\n", buscado -> numero);
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

/*Diferente da função de criar a lista dupla, essa precisa ter um fim também com NULL*/
/*Há alocação dinâmica em todas as opções de inserção.*/
void criarListaCir(ListaCir *listaCir) {
    listaCir->inicio = NULL;
    listaCir->fim = NULL;
    listaCir->tamanho = 0;
}

void inserirInicioCir(ListaCir *listaCir, double num) {
    Node *novoNode = malloc(sizeof(Node));

    if (novoNode == NULL) {
        printf("Não há memória disponível.");
        return;
    }

    novoNode->numero = num;
    novoNode->prox = listaCir->inicio;      /*O início é preenchido com o novoNode que é apontado para o*/
    listaCir->inicio = novoNode;            /*número recebido*/

    if (listaCir->fim == NULL) {            /*De tal modo, se for a primeira inserção, o fim também é preenchido com*/
        listaCir->fim = novoNode;           /*novoNode e o início se torna igual ao fim*/
    }
    listaCir->fim->prox = listaCir->inicio;
    listaCir->tamanho++;
}

void inserirFimCir(ListaCir *listaCir, double num) {
    Node *auxiliar, *novoNode = malloc(sizeof(Node));

    if (novoNode == NULL) {
        printf("Não há memória disponível.\n");
        return;
    }

    novoNode->numero = num;

    if (listaCir->inicio == NULL) {         /*O novoNode que aponta para o número recebido preenche tanto o iníco quanto*/
        listaCir->inicio = novoNode;        /*o fim em caso de primeira interação*/
        listaCir->fim = novoNode;
        listaCir->fim->prox = listaCir->inicio;
    }
     else {
        listaCir->fim->prox = novoNode;      /*Mas como num círculo, início e fim são os mesmos, se já tiver havido*/
        listaCir->fim = novoNode;            /*inserção antes, o início também recebe o novoNode inserido no fim*/
        listaCir->fim->prox = listaCir->inicio;
    }
    listaCir->tamanho++;
}
/*Lamento pelas chamadas recursivas*/
Node* removerNoCir(ListaCir *listaCir, double numero) {
    Node *auxiliar, *removerNode = NULL;

    if (listaCir->inicio) {         /*Verifica se lista não está vazia*/
        if (listaCir->inicio == listaCir->fim && listaCir->inicio->numero == numero) {  /*Se houver apenas um nó*/
            removerNode = listaCir->inicio;         
            listaCir->inicio = NULL;
            listaCir->fim = NULL;
            listaCir->tamanho--;
        } 
        else if (listaCir->inicio->numero == numero) {  /*Se estiver no início com uma lista com mais de um nó*/
            removerNode = listaCir->inicio;
            listaCir->inicio = removerNode->prox;
            listaCir->fim->prox = listaCir->inicio;
            listaCir->tamanho--;
        } 
        else {
            auxiliar = listaCir->inicio;
            /*Se não estiver, procura-o no restante da lista*/
            while (auxiliar->prox != listaCir->inicio && auxiliar->prox->numero != numero) {
                auxiliar = auxiliar->prox;
            }
            if (auxiliar->prox->numero == numero) {     /*Caso em que o encontra*/
                if (listaCir->fim == auxiliar->prox) {  /*Está no meio ou no fim da lista*/
                    removerNode = auxiliar->prox;
                    auxiliar->prox = removerNode->prox;
                    listaCir->fim = auxiliar;
                }
                 else {
                    removerNode = auxiliar->prox;
                    auxiliar->prox = removerNode->prox;
                }
                listaCir->tamanho--;
            }
        }
    }
    return removerNode;     /*Após remoção e diminuição da lista, retorna o nó, pode ser NULL se não for encontrado*/
}

Node* buscarNoCir(ListaCir *listaCir, double num) {
    Node *auxiliar = listaCir->inicio;      /*A variável (ponteiro, no caso) é atribuída do início da lista*/

    if (auxiliar) {         /*Se a lista não estiver vazia, então...*/
        do{             
            if (auxiliar->numero == num) {      /*auxiliar aponta para o número e caso o encontre, retorna-o*/
                return auxiliar;
            }
            auxiliar = auxiliar->prox;      /*Caso não, continua*/
        }   
        while(auxiliar != listaCir->inicio); /*Até que auxiliar seja diferente do início, ou seja, enquanto a lista não for vazia*/
    }
    return NULL;    /*Nó não encontrado*/
}

void listarCir(ListaCir *listaCir) {
    Node *node = listaCir->inicio;      /*Variável (ponteiro) recebe o início da lista*/

    printf("        LISTA           \n");

    if (node) {             /*Se a lista não está vazia, então, percorre a lista e imprime-a*/
        do {
            printf("%.2f\t", node->numero);
            node = node->prox;
        } 
        while (node != listaCir->inicio);   /*Até que a lista não esteja vazia*/
        printf("\n");
    }
}

