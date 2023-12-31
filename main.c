#include <stdio.h>
#include <stdlib.h>

// Funcao para mostrar o menu
void mostrarMenu() {
    printf("\t\t\tGestao de Computadores Portateis");
    printf("\n\n\tTotal de Computadores:  \t\tValor dos Computadores(�):  \n\tIntervencoes solicitadas:  \t\tIntervencoes efetuadas: \n");
    printf("\n\t\t1 Novo Computador\n");
    printf("\t\t2 Solicitar interven��o\n");
    printf("\t\t3 Registar interven��o\n");
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
                printf("Op��o 1 selecionada: Novo Computador\n");
                // Adicionar o codigo
                break;
            case 2:
                printf("Op��o 2 selecionada: Solicitar interven��o\n");
                // Adicionar o codigo
                break;
            case 3:
                printf("Op��o 3 selecionada: Registar interven��o\n");
                // Adicionar o codigo
                break;
            case 4:
                printf("Op��o 4 selecionada: Listar\n");
                // Adicionar o codigo
                break;
            case 5:
                printf("Op��o 5 selecionada: Informacoes\n");
                // Adicionar o codigo
                break;
            case 6:
                printf("Op��o 6 selecionada: Gravar\n");
                // Adicionar o codigo
                break;
            case 0:
                printf("A sair do Programa!\n");
                break;
            default:
                printf("Opcao inv�lida\n");
        }
    } while (opcao != 0);

    return 0;
}
