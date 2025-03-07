#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para calcular os atributos derivados
void calcular_atributos(unsigned long int populacao, float area, double PIB, double *densidade_populacional, double *PIB_per_capita) {
    *densidade_populacional = populacao / area;
    *PIB_per_capita = PIB / populacao;
}

// Função para exibir o menu e obter a escolha do jogador
typedef enum {POPULACAO = 2, AREA, PIB, PONTOS_TURISTICOS, DENSIDADE} Atributo;

int escolher_atributo(int escolhido) {
    int opcao;
    do {
        printf("\nEscolha um atributo:\n");
        if (escolhido != POPULACAO) printf("2 - Populacao\n");
        if (escolhido != AREA) printf("3 - Area\n");
        if (escolhido != PIB) printf("4 - PIB\n");
        if (escolhido != PONTOS_TURISTICOS) printf("5 - Pontos Turisticos\n");
        if (escolhido != DENSIDADE) printf("6 - Densidade Demografica\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
    } while (opcao == escolhido || opcao < 2 || opcao > 6);
    return opcao;
}

// Função para comparar e exibir o vencedor com dois atributos
void comparar_cartas(int atributo1, int atributo2, unsigned long int populacao1, unsigned long int populacao2,
                     float area1, float area2, double PIB1, double PIB2,
                     int pontos_turisticos1, int pontos_turisticos2,
                     double densidade1, double densidade2, char *nome1, char *nome2) {
    double val1, val2, soma1, soma2;
    double valores1[5] = {populacao1, area1, PIB1, pontos_turisticos1, densidade1};
    double valores2[5] = {populacao2, area2, PIB2, pontos_turisticos2, densidade2};

    atributo1 -= 2;
    atributo2 -= 2;
    val1 = valores1[atributo1];
    val2 = valores2[atributo1];
    soma1 = val1 + valores1[atributo2];
    soma2 = val2 + valores2[atributo2];

    printf("\nComparacao das cartas:\n");
    printf("%s - %s: %.2f, %s: %.2f | Soma: %.2f\n", nome1, atributo1 == 4 ? "Densidade" : "", val1, atributo2 == 4 ? "Densidade" : "", valores1[atributo2], soma1);
    printf("%s - %s: %.2f, %s: %.2f | Soma: %.2f\n", nome2, atributo1 == 4 ? "Densidade" : "", val2, atributo2 == 4 ? "Densidade" : "", valores2[atributo2], soma2);

    if (soma1 > soma2)
        printf("Vencedor: %s!\n", nome1);
    else if (soma2 > soma1)
        printf("Vencedor: %s!\n", nome2);
    else
        printf("Empate!\n");
}

int main() {
    // Dados das cidades
    char nome1[] = "CidadeA", nome2[] = "CidadeB";
    unsigned long int populacao1 = 12000000, populacao2 = 6000000;
    float area1 = 1500.5, area2 = 800.5;
    double PIB1 = 300000000000.0, PIB2 = 150000000000.0;
    double densidade1, densidade2, PIB_per_capita1, PIB_per_capita2;
    int pontos_turisticos1 = 10, pontos_turisticos2 = 15;

    // Calcular atributos derivados
    calcular_atributos(populacao1, area1, PIB1, &densidade1, &PIB_per_capita1);
    calcular_atributos(populacao2, area2, PIB2, &densidade2, &PIB_per_capita2);

    int atributo1 = escolher_atributo(-1);
    int atributo2 = escolher_atributo(atributo1);
    comparar_cartas(atributo1, atributo2, populacao1, populacao2, area1, area2, PIB1, PIB2, pontos_turisticos1, pontos_turisticos2, densidade1, densidade2, nome1, nome2);

    return 0;
}