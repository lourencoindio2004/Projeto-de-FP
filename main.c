#include <stdio.h>
#include <stdlib.h>
#define MAX_COMPUTADORES 100
#define MAX_INTERVENCOES 15

    struct Intervencao {
        int codigo;
        char data_registro[20];
        char descricao_problema[100];
    };
    struct Computador {
        int id;
        char designacao[50];
        char nome_colaborador[50];
        char dataAtribuicao[20];
        char estado[20];
        char data_registro[20];
        char descricao_problema[100];
        float valor;
        int intervencoes_solicitadas;
        struct Intervencao *intervencoes;

    };

    // Funcao para mostrar o menu
    void mostrarMenu(int numComputadores) {
        printf("\t\t\tGestao de Computadores Portateis");
        printf("\n\n\tTotal de Computadores: %d\t\tValor dos Computadores(€):  \n\tIntervencoes solicitadas:  \t\tIntervencoes efetuadas: \n", numComputadores);
        printf("\n\t\t1 Novo Computador\n");
        printf("\t\t2 Solicitar intervencao\n");
        printf("\t\t3 Registar intervencao\n");
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
        int indiceComputador = -1, idComputador;


        mostrarMenu(numComputadores); // Mostra o menu inicial

        do {
            scanf("%d", &opcao);

            switch (opcao) {
                case 1:
                    system("cls");
                    printf("Opção 1 selecionada: Novo Computador\n");

                    if (numComputadores < MAX_COMPUTADORES)
                    {
                        printf("Número de Identificacao: ");
                        scanf("%d", &computadores[numComputadores].id);

                        printf("Designacao: ");
                        scanf("%s", computadores[numComputadores].designacao);

                        printf("Nome do Colaborador: ");
                        scanf("%s", computadores[numComputadores].nome_colaborador);

                        printf("Data de Atribuicao: ");
                        scanf("%s", computadores[numComputadores].dataAtribuicao);

                        printf("Estado do Computador: ");
                        scanf("%s", computadores[numComputadores].estado);

                        printf("Valor do Equipamento: ");
                        scanf("%f", &computadores[numComputadores].valor);

                        numComputadores++;

                        getchar(); // Aguarda a entrada do usuário antes de limpar a tela e voltar ao menu

                        system("cls"); // Limpa o ecrã
                        mostrarMenu(numComputadores);
                    } else
                    {
                        printf("Limite maximo de computadores atingido!\n");
                    }
                    break;
                case 2:
                    system("cls");
                    printf("Opção 2 selecionada: Solicitar intervencao\n");

                    if (numComputadores > 0)
                    {
                        printf("Número de Identificaçao do Computador: ");
                        scanf("%d", &idComputador);

                        // Verifica se o ID do computador existe
                        for (int i = 0; i < numComputadores; i++)
                        {
                    if (computadores[i].id == idComputador)
                    {
                        indiceComputador = i;
                        break;
                        }
                        }

                    if (indiceComputador != -1)
                    {
                    if (computadores[indiceComputador].intervencoes_solicitadas < MAX_INTERVENCOES)
                    {
                        printf("Codigo da Intervencao: ");
                        scanf("%d", &computadores[indiceComputador].intervencoes[computadores[indiceComputador].intervencoes_solicitadas].codigo);

                        printf("Data do Registro da Solicitacao: ");
                        scanf("%s", computadores[indiceComputador].intervencoes[computadores[indiceComputador].intervencoes_solicitadas].data_registro);

                        printf("Breve Descrição do Problema: ");
                        scanf("%s", computadores[indiceComputador].intervencoes[computadores[indiceComputador].intervencoes_solicitadas].descricao_problema);

                        // Incrementa o número de intervencoes solicitadas
                        computadores[indiceComputador].intervencoes_solicitadas++;

                        getchar(); // Aguarda a entrada do usuário antes de limpar a tela e voltar ao menu

                        system("cls"); // Limpa o ecra
                        mostrarMenu(numComputadores);
                    }else{
                        printf("Limite maximo de intervencoes solicitadas atingido para este computador!\n");
                        }
                    }else{
                        printf("Computador nao encontrado!\n");
                        }
                    }else{
                        printf("Nao existem computadores registrados para solicitar intervencao!\n");
                    }
                    break;


                case 0:
                    printf("A sair do Programa!\n");
                    break;

                default:
                    printf("Opcao invalida\n");
            }
    } while (opcao != 0);

    return 0;
}
