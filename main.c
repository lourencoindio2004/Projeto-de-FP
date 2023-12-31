#include <stdio.h>
#include <stdlib.h>

// Funcao para mostrar o menu
void mostrarMenu() {
    printf("\t\t\tGestao de Computadores Portateis");
    printf("\n\n\tTotal de Computadores:  \t\tValor dos Computadores(€):  \n\tIntervencoes solicitadas:  \t\tIntervencoes efetuadas: \n");
    printf("\n\t\t1 Novo Computador\n");
    printf("\t\t2 Solicitar intervenção\n");
    printf("\t\t3 Registar intervenção\n");
    printf("\t\t4 Listar\n");
    printf("\t\t5 Informacoes\n");
    printf("\t\t6 Gravar\n");
    printf("\t\t0 Sair\n");
    printf("\t\t\tSelecione a opcao: ");
}

int main() {
    int opcao;

    do {
        mostrarMenu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Opção 1 selecionada: Novo Computador\n");
                // Adicionar o codigo
                break;
            case 2:
                printf("Opção 2 selecionada: Solicitar intervenção\n");
                // Adicionar o codigo
                break;
            case 3:
                printf("Opção 3 selecionada: Registar intervenção\n");
                // Adicionar o codigo
                break;
            case 4:
                printf("Opção 4 selecionada: Listar\n");
                // Adicionar o codigo
                break;
            case 5:
                printf("Opção 5 selecionada: Informacoes\n");
                // Adicionar o codigo
                break;
            case 6:
                printf("Opção 6 selecionada: Gravar\n");
                // Adicionar o codigo
                break;
            case 0:
                printf("A sair do Programa!\n");
                break;
            default:
                printf("Opcao inválida\n");
        }
    } while (opcao != 0);

    return 0;
}
