#include <stdio.h>
#include <stdlib.h>
#define MAX_COMPUTADORES 100 // Definir o número máximo de computadores
#define MAX_INTERVENCOES 100

typedef struct {
    int id;
    char designacao[50];
    char colaborador[50];
    char dataAtribuicao[20];
    char estado[20];
    float valor;
} Computador;
Computador computadores[MAX_COMPUTADORES]; // Array para armazenar os computadores
int numComputadores = 0; // Número atual de computadores registados

void registarNovoComputador() {
    if (numComputadores < MAX_COMPUTADORES) {
        printf("Introduza o numero de identificação: ");
        scanf("%d", &computadores[numComputadores].id);
        printf("Introduza a designacao: ");
        scanf(" %[^\n]s", computadores[numComputadores].designacao);
        printf("Introduza o nome do colaborador: ");
        scanf(" %[^\n]s", computadores[numComputadores].colaborador);
        printf("Introduza a data de atribuicao (dd/mm/aaaa): ");
        scanf(" %[^\n]s", computadores[numComputadores].dataAtribuicao);
        printf("Introduza o estado do computador: ");
        scanf(" %[^\n]s", computadores[numComputadores].estado);
        printf("Introduza o valor do equipamento: ");
        scanf("%f", &computadores[numComputadores].valor);

        numComputadores++; // Incrementar o número de computadores registados
        printf("Computador registado com sucesso!\n");
    } else {
        printf("Limite máximo de computadores atingido.\n");
    }
}


typedef struct {
    int codigoIntervencao;
    int numIdentificacaoComputador;
    char dataRegisto[20];
    char descricaoProblema[100];
} SolicitacaoIntervencao;

SolicitacaoIntervencao intervencoes[MAX_INTERVENCOES]; // Array para armazenar solicitações de intervenções
int numIntervencoes = 0;

typedef struct {
    int codigoIntervencao;
    int numIdentificacaoComputador;
    char dataRegisto[20];
    char descricaoProblema[100];
    char dataIntervencao[20];
    char descricaoIntervencao[100];
    float custoIntervencao;
    int intervencaoEfetuada; // Flag para identificar se a intervenção foi efetuada
} EfetuarIntervencao;

EfetuarIntervencao efetuarIntervencoes[MAX_INTERVENCOES]; // Correção no nome da variável
int numEfetuarIntervencoes = 0;






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

        numIntervencoes++; // Incrementar o número de intervenções registadas
        printf("Intervenção registada com sucesso!\n");
    } else {
        printf("Limite máximo de intervenções atingido.\n");
    }
}

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
            numEfetuarIntervencoes++; // Incrementa o contador
            break;
        }
    }

    if (!encontrado) {
        printf("Intervenção não encontrada.\n");
    }
}

void mostrarMenu() {
    printf("\t\t\tGestao de Computadores Portateis");
    printf("\n\n\tTotal de Computadores: %d\t\tValor dos Computadores(€):  ",numComputadores);
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
    int opcao;

    do {
        mostrarMenu(); // Mostra o menu
        scanf("%d", &opcao); // Lê a opção do utilizador

        switch (opcao) {
            case 1:
                system("cls");
                registarNovoComputador();
                system("cls");
                break;
            // Adiciona casos para outras opções do menu, se necessário
            case 2:
                system("cls");
                solicitarIntervencao();
                system("cls");
                break;
            case 3:
                system("cls");
                efetuarIntervencao();
                system("cls");
                break;
            case 0:
                printf("A sair do programa. Adeus!\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}
