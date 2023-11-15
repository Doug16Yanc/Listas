#include "listas.h"

int main(void){
    int opcao;
    
    printf("*********************************************************************\n");
    printf("Bem-vindo ao nosso programa C para manipulação de listas encadeadas.\n");
    printf("*********************************************************************\n");
    printf("                    SIGA BEM                                        \n");
    printf("            (1) - Listas duplamente encadeadas                      \n");
    printf("            (2) - Listas circulares                                 \n");
    printf("            (3) - Sair do programa                                  \n");
    printf("*********************************************************************\n");
    
    scanf("%d", &opcao);
    
    switch(opcao){
        case 1:
            interageListaDupla();
            break;
        case 2:
            interageListaCircular();
            break;
        case 3:
            printf("Obrigado por sua interação comigo. Até logo!\n");
            exit(1);
        default:
            printf("Alternativa inexistente!\n");
            break;
    }
    return 0;
}