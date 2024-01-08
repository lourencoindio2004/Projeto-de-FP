#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_COMPUTADORES 100 // definir o numero máximo de computadores
#define MAX_INTERVENCOES 100 //definir o numero máximo de intervencoes

    //-----------------------------------------------------------------------------------------------------------------------------------//


    typedef struct {
        int id;
        char designacao[50];
        char colaborador[50];
        char dataAtribuicao[20];
        char estado[20];
        float valor;
    } Computador;


    typedef struct {
        int codigoIntervencao;
        int numIdentificacaoComputador;
        char dataRegisto[20];
        char descricaoProblema[100];
    } SolicitacaoIntervencao;



    typedef struct {
        int codigoIntervencao;
        int numIdentificacaoComputador;
        char dataRegisto[20];
        char descricaoProblema[100];
        char dataIntervencao[20];
        char descricaoIntervencao[100];
        float custoIntervencao;
        int intervencaoEfetuada;
    } EfetuarIntervencao;

    Computador computadores[MAX_COMPUTADORES]; // array para armazenar os computadores
    int numComputadores = 0; // computadores atuais registrados

    SolicitacaoIntervencao intervencoes[MAX_INTERVENCOES]; // Array para armazenar solicitações de intervenções
    int numIntervencoes = 0;


    EfetuarIntervencao efetuarIntervencoes[MAX_INTERVENCOES];
    int numEfetuarIntervencoes = 0;


    //-----------------------------------------------------------------------------------------------------------------------------------//


    void gravarDados() {
        FILE *arquivo = fopen("dados.bin", "wb"); // Abre o arquivo para escrita binária

        if (arquivo == NULL) {
            printf("Erro ao abrir o arquivo para escrita.\n");
            return;
        }

        // Grava os dados dos computadores no arquivo
        fwrite(computadores, sizeof(Computador), numComputadores, arquivo);

        // Grava os dados das solicitações de intervenções no arquivo
        fwrite(intervencoes, sizeof(SolicitacaoIntervencao), numIntervencoes, arquivo);

        // Grava os dados das intervenções efetuadas no arquivo
        fwrite(efetuarIntervencoes, sizeof(EfetuarIntervencao), numEfetuarIntervencoes, arquivo);

        fclose(arquivo); // Fecha o arquivo após a gravação
        printf("Dados gravados com sucesso no arquivo 'dados.bin'.\n");

    }

    //-----------------------------------------------------------------------------------------------------------------------------------//


    void registarNovoComputador() {
        if (numComputadores < MAX_COMPUTADORES) {
            printf("Introduza o numero de identificacao: ");
            scanf("%d", &computadores[numComputadores].id);

            printf("Introduza a designacao: ");
            scanf(" %s", computadores[numComputadores].designacao);

            printf("Introduza o nome do colaborador: ");
            scanf(" %s", computadores[numComputadores].colaborador);

            printf("Introduza a data de atribuicao (dd/mm/aaaa): ");
            scanf(" %s", computadores[numComputadores].dataAtribuicao);

            // variavel para garantir que o estado inserido é válido
            int estadoValido = 0;
            do {
                printf("Introduza o estado do computador (operacional, por intervencionar ou avariado): ");
                scanf(" %s", computadores[numComputadores].estado);

                // Verifica se o estado inserido corresponde a uma das opções permitidas
                if (strcmp(computadores[numComputadores].estado, "operacional") == 0 ||
                    strcmp(computadores[numComputadores].estado, "por intervencionar") == 0 ||
                    strcmp(computadores[numComputadores].estado, "avariado") == 0) {
                    estadoValido = 1;
                } else {
                    printf("Opcao de estado invalida. Por favor, insira novamente.\n");
                }
            } while (!estadoValido);

            printf("Introduza o valor do equipamento: ");
            scanf("%f", &computadores[numComputadores].valor);

            numComputadores++; //incrementa os computadores
            printf("Computador registado com sucesso!\n");
        } else {
            printf("Limite maximo de computadores.\n");
        }
    }


    //-----------------------------------------------------------------------------------------------------------------------------------//


    void solicitarIntervencao() {
        if (numIntervencoes < MAX_INTERVENCOES) {
            printf("Introduza o código da intervenção: ");
            scanf("%d", &intervencoes[numIntervencoes].codigoIntervencao);
            printf("Introduza o número de identificação do computador: ");
            scanf("%d", &intervencoes[numIntervencoes].numIdentificacaoComputador);
            printf("Introduza a data do registo da solicitação (dd/mm/aaaa): ");
            scanf(" %[^\n]s", intervencoes[numIntervencoes].dataRegisto);
            printf("Introduza uma breve descrição do problema: ");
            scanf(" %[^\n]s", intervencoes[numIntervencoes].descricaoProblema);

            numIntervencoes++; // incrementa o contador
            printf("Intervenção registada com sucesso!\n");
        } else {
            printf("Limite máximo de intervenções atingido.\n");
        }
    }


    //-----------------------------------------------------------------------------------------------------------------------------------//


    void efetuarIntervencao() {
        int codigo;

        printf("Introduza o código da intervenção a ser efetuada: ");
        scanf("%d", &codigo);

        int encontrado = 0;
        for (int i = 0; i < numIntervencoes; ++i) {
            if (intervencoes[i].codigoIntervencao == codigo) {
                printf("Introduza a data da intervenção (dd/mm/aaaa): ");
                scanf(" %19[^\n]%*c", efetuarIntervencoes[numEfetuarIntervencoes].dataIntervencao);

                printf("Introduza a descrição da intervenção: ");
                scanf(" %99[^\n]%*c", efetuarIntervencoes[numEfetuarIntervencoes].descricaoIntervencao);

                printf("Introduza o custo da intervenção: ");
                scanf("%f", &efetuarIntervencoes[numEfetuarIntervencoes].custoIntervencao);

                efetuarIntervencoes[numEfetuarIntervencoes].intervencaoEfetuada = 1;
                printf("Intervenção efetuada registada com sucesso!\n");

                encontrado = 1;
                numEfetuarIntervencoes++; // incrementa o contador
                break;
            }
        }

        if (!encontrado) {
            printf("Intervenção não encontrada.\n");
        }
    }


    //-----------------------------------------------------------------------------------------------------------------------------------//


    void lista()
    {
        printf("\nListagem de Computadores:\n");
        if (numComputadores > 0) {
        printf("\nListagem de Computadores:\n");
            for (int i = 0; i < numComputadores; i++) {
                printf("\nComputador %d:\n", i + 1);
                printf("ID: %d\n", computadores[i].id);
                printf("Designacao: %s\n", computadores[i].designacao);
                printf("Colaborador: %s\n", computadores[i].colaborador);
                printf("Data de Atribuicao: %s\n", computadores[i].dataAtribuicao);
                printf("Estado: %s\n", computadores[i].estado);
                printf("Valor: %.2f\n", computadores[i].valor);
                printf("-------------------------------\n");
                }
        }else{ printf("Nenhum computador registrado.\n");
     }

    printf("\nListagem de Intervencoes Solicitadas:\n");
        if (numIntervencoes > 0) {
            for (int i = 0; i < numIntervencoes; i++) {
                printf("\nIntervencao %d:\n", i + 1);
                printf("Codigo: %d\n", intervencoes[i].codigoIntervencao);
                printf("Num. Identificacao Computador: %d\n", intervencoes[i].numIdentificacaoComputador);
                printf("Data de Registo: %s\n", intervencoes[i].dataRegisto);
                printf("Descricao do Problema: %s\n", intervencoes[i].descricaoProblema);
                printf("-------------------------------\n");
        }
        }else{
            printf("Nenhuma intervencao solicitada.\n");
        }

        printf("\nListagem de Intervencoes Efetuadas:\n");
        if (numEfetuarIntervencoes > 0) {
            for (int i = 0; i < numEfetuarIntervencoes; i++) {
                printf("\nIntervencao Efetuada %d:\n", i + 1);
                printf("Codigo: %d\n", efetuarIntervencoes[i].codigoIntervencao);
                printf("Num. Identificacao Computador: %d\n", efetuarIntervencoes[i].numIdentificacaoComputador);
                printf("Data de Registo: %s\n", efetuarIntervencoes[i].dataRegisto);
                printf("Descricao do Problema: %s\n", efetuarIntervencoes[i].descricaoProblema);
                printf("Data de Intervencao: %s\n", efetuarIntervencoes[i].dataIntervencao);
                printf("Descricao da Intervencao: %s\n", efetuarIntervencoes[i].descricaoIntervencao);
                printf("Custo da Intervencao: %.2f\n", efetuarIntervencoes[i].custoIntervencao);
                printf("Intervencao Efetuada: %s\n", efetuarIntervencoes[i].intervencaoEfetuada ? "Sim" : "Nao");
                printf("-------------------------------\n");
        }
       }else{
     printf("Nenhuma intervencao efetuada.\n");
    }
    }


    //-----------------------------------------------------------------------------------------------------------------------------------//


    void mostrarInformacoes() {
        // quantidade de cada computadores
        int qtdOperacional = 0, qtdPorIntervencionar = 0, qtdAvariado = 0;

        for (int i = 0; i < numComputadores; i++) {
            if (strcmp(computadores[i].estado, "operacional") == 0) {
                qtdOperacional++;
            } else if (strcmp(computadores[i].estado, "por intervencionar") == 0) {
                qtdPorIntervencionar++;
            } else if (strcmp(computadores[i].estado, "avariado") == 0) {
                qtdAvariado++;
            }
        }

        printf("\nQuantidade de computadores em cada estado:\n");
        printf("Operacional: %d\n", qtdOperacional);
        printf("Por Intervencionar: %d\n", qtdPorIntervencionar);
        printf("Avariado: %d\n", qtdAvariado);

        // custo medio de cada intervencao
        if (numEfetuarIntervencoes > 0) {
            float custoTotal = 0.0;

            for (int i = 0; i < numEfetuarIntervencoes; i++) {
                custoTotal += efetuarIntervencoes[i].custoIntervencao;
            }

            float custoMedio = custoTotal / numEfetuarIntervencoes;
            printf("\nCusto medio por intervenção efetuada nos computadores: %.2f\n", custoMedio);
        } else {
            printf("\nNenhuma intervencao efetuada nos computadores ainda\n");
        }
    }


    //-----------------------------------------------------------------------------------------------------------------------------------//


    void mostrarMenu() {
        printf("\t\t\tGestao de Computadores Portateis");
        printf("\n\n\tTotal de Computadores: %d\t\tValor dos Computadores(€): ",numComputadores);
        printf("\n\tIntervencoes solicitadas:%d  \t\tIntervencoes efetuadas: %d\n",numIntervencoes, numEfetuarIntervencoes);
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
        FILE *arquivo = fopen("dados.bin", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return 1;
    }

        int opcao;

        do {
            mostrarMenu(); // Mostra o menu
            scanf("%d", &opcao); // Le a opcao do utilizador

            switch (opcao) {
                case 1:
                        system("cls");
                        registarNovoComputador(); // funcao e chamada para o menu
                        system("cls");
                        break;

                case 2:
                    system("cls");
                    solicitarIntervencao(); // funcao e chamada para o menu
                    system("cls");
                    break;

                case 3:
                        system("cls");
                        efetuarIntervencao(); // funcao e chamada para o menu
                        printf("\nPressione Enter para continuar...");
                        getchar();
                        system("cls");
                        break;
                case 4:
                        system("cls");
                        lista();
                        printf("\nPressione Enter para continuar...");
                        getchar();
                        getchar();
                        system("cls"); // funcao e chamada para o menu
                        break;
                case 5:
                        system("cls");
                        mostrarInformacoes(); // funcao e chamada para o menu
                        printf("\nPressione qualquer tecla para continuar...");
                        getch();
                        system("cls");
                        break;
                case 6:
                        system("cls");
                        gravarDados();
                        system("cls");
                        break;
                case 0:
                        printf("A sair do programa. Adeus!\n");
                        fclose(arquivo);
                        break;
                default:
                        printf("Opcao invalida. Tente novamente.\n");
            }
        } while (opcao != 0);

        return 0;
    }
