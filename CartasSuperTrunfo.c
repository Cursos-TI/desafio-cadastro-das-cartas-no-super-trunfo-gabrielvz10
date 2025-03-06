#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para calcular os atributos derivados
int calcular_atributos(unsigned long int populacao, float area, double PIB, double *densidade_populacional, double *PIB_per_capita) {
    *densidade_populacional = populacao / area;
    *PIB_per_capita = PIB / populacao;
    return 0; // Retorna 0 para indicar que a operação foi concluída com sucesso
}

// Função para comparar e exibir o vencedor de um atributo
int comparar_atributo(int opcao, unsigned long int populacao1, unsigned long int populacao2, float area1, float area2, 
                      double PIB1, double PIB2, int pontos_turisticos1, int pontos_turisticos2, 
                      double densidade_populacional1, double densidade_populacional2, char *nome1, char *nome2) {
    // Variáveis para armazenar os valores a serem comparados
    double val1, val2;

    switch (opcao) {
        case 1: // Nome do país
            printf("\nComparação de cartas (Atributo: Nome do País):\n");
            printf("Carta 1 - %s\n", nome1);
            printf("Carta 2 - %s\n", nome2);
            printf("Resultado: Não há vencedor, apenas a exibição do nome.\n");
            return 0;

        case 2: // População
            printf("\nComparação de cartas (Atributo: População):\n");
            val1 = populacao1;
            val2 = populacao2;
            break;

        case 3: // Área
            printf("\nComparação de cartas (Atributo: Área):\n");
            val1 = area1;
            val2 = area2;
            break;

        case 4: // PIB
            printf("\nComparação de cartas (Atributo: PIB):\n");
            val1 = PIB1;
            val2 = PIB2;
            break;

        case 5: // Número de pontos turísticos
            printf("\nComparação de cartas (Atributo: Pontos Turísticos):\n");
            val1 = pontos_turisticos1;
            val2 = pontos_turisticos2;
            break;

        case 6: // Densidade demográfica
            printf("\nComparação de cartas (Atributo: Densidade Demográfica):\n");
            val1 = densidade_populacional1;
            val2 = densidade_populacional2;
            break;

        default:
            printf("Opção inválida.\n");
            return -1;
    }

    // Exibindo as informações dos dois países
    printf("Carta 1 - %s: %.2f\n", nome1, val1);
    printf("Carta 2 - %s: %.2f\n", nome2, val2);

    // Regras de comparação com if-else aninhado
    if (opcao == 6) { // Para a Densidade Demográfica, vence quem tem menor valor
        if (val1 < val2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", nome1);
        } else if (val1 > val2) {
            printf("Resultado: Carta 2 (%s) venceu!\n", nome2);
        } else {
            printf("Empate!\n");
        }
    } else { // Para os demais atributos, vence quem tem maior valor
        if (val1 > val2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", nome1);
        } else if (val1 < val2) {
            printf("Resultado: Carta 2 (%s) venceu!\n", nome2);
        } else {
            printf("Empate!\n");
        }
    }

    return 0;
}

int main() {
    // Dados da primeira cidade
    char nome1[50] = "CidadeA", estado1[3] = "SP", codigo1[10] = "001";
    unsigned long int populacao1 = 12000000;
    float area1 = 1500.5;
    double PIB1 = 300000000000.0, densidade_populacional1, PIB_per_capita1;
    int pontos_turisticos1 = 10;

    // Dados da segunda cidade
    char nome2[50] = "CidadeB", estado2[3] = "RJ", codigo2[10] = "002";
    unsigned long int populacao2 = 6000000;
    float area2 = 800.5;
    double PIB2 = 150000000000.0, densidade_populacional2, PIB_per_capita2;
    int pontos_turisticos2 = 15;

    // Calculando os atributos derivados
    calcular_atributos(populacao1, area1, PIB1, &densidade_populacional1, &PIB_per_capita1);
    calcular_atributos(populacao2, area2, PIB2, &densidade_populacional2, &PIB_per_capita2);

    int opcao;

    // Inicializando a semente para o gerador de números aleatórios
    srand(time(NULL));

    do {
        // Menu interativo
        printf("\nEscolha o atributo para comparar:\n");
        printf("1 - Nome do País\n");
        printf("2 - População\n");
        printf("3 - Área\n");
        printf("4 - PIB\n");
        printf("5 - Pontos Turísticos\n");
        printf("6 - Densidade Demográfica\n");
        printf("0 - Sair\n");
        printf("Digite a opção: ");
        scanf("%d", &opcao);

        if (opcao != 0) {
            comparar_atributo(opcao, populacao1, populacao2, area1, area2, PIB1, PIB2, pontos_turisticos1, pontos_turisticos2, 
                               densidade_populacional1, densidade_populacional2, nome1, nome2);
        }
    } while (opcao != 0);

    return 0;
}