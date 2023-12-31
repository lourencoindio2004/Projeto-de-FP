#include <stdio.h>
#include <stdlib.h>
#define MAX_COMPUTADORES 100

    struct Computador {
        int id;
        char designacao[50];
        char nome_colaborador[50];
        char dataAtribuicao[20];
        char estado[20];
        float valor;
    };

    // Funcao para mostrar o menu
    void mostrarMenu(int numComputadores) {
        printf("\t\t\tGestao de Computadores Portateis");
        printf("\n\n\tTotal de Computadores: %d\t\tValor dos Computadores(�):  \n\tIntervencoes solicitadas:  \t\tIntervencoes efetuadas: \n", numComputadores);
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
        struct Computador computadores[MAX_COMPUTADORES];
        int numComputadores = 0;
        int opcao = -1;

        mostrarMenu(numComputadores); // Mostra o menu inicial

        do {
            scanf("%d", &opcao);

            switch (opcao) {
                case 1:
                    system("cls");
                    printf("Op��o 1 selecionada: Novo Computador\n");

                    if (numComputadores < MAX_COMPUTADORES)
                    {
                        printf("N�mero de Identifica��o: ");
                        scanf("%d", &computadores[numComputadores].id);

                        printf("Designa��o: ");
                        scanf("%s", computadores[numComputadores].designacao);

                        printf("Nome do Colaborador: ");
                        scanf("%s", computadores[numComputadores].nome_colaborador);

                        printf("Data de Atribui��o: ");
                        scanf("%s", computadores[numComputadores].dataAtribuicao);

                        printf("Estado do Computador: ");
                        scanf("%s", computadores[numComputadores].estado);

                        printf("Valor do Equipamento: ");
                        scanf("%f", &computadores[numComputadores].valor);

                        numComputadores++;

                        getchar(); // Aguarda a entrada do usu�rio antes de limpar a tela e voltar ao menu

                        system("cls"); // Limpa o ecra
                        mostrarMenu(numComputadores);
                    } else
                    {
                        printf("Limite m�ximo de computadores atingido!\n");
                    }
                    break;
                case 2:


                case 0:
                    printf("A sair do Programa!\n");
                    break;

                default:
                    printf("Opcao inv�lida\n");
            }
    } while (opcao != 0);

    return 0;
}
