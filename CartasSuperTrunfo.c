#include <stdio.h>

// Função para calcular os atributos derivados
int calcular_atributos(unsigned long int populacao, float area, double PIB, double *densidade_populacional, double *PIB_per_capita) {
    *densidade_populacional = populacao / area;
    *PIB_per_capita = PIB / populacao;
    return 0; // Retorna 0 para indicar que a operação foi concluída com sucesso
}

// Função para comparar e exibir o vencedor de um atributo
int comparar_atributo(char *atributo, double val1, double val2, char *nome1, char *nome2, char *estado1, char *estado2, int inverso) {
    printf("\nComparação de cartas (Atributo: %s):\n", atributo);
    printf("Carta 1 - %s (%s): %.2f\n", nome1, estado1, val1);
    printf("Carta 2 - %s (%s): %.2f\n", nome2, estado2, val2);
    
    // Inverso significa que o valor maior é o perdedor
    if ((inverso && val1 < val2) || (!inverso && val1 > val2)) {
        printf("Resultado: Carta 1 (%s) venceu!\n", nome1);
    } else {
        printf("Resultado: Carta 2 (%s) venceu!\n", nome2);
    }
    return 0; // Retorna 0 para indicar que a operação foi concluída com sucesso
}

int main() {
    // Dados da primeira cidade
    char estado1[3], codigo1[10], nome1[50];
    unsigned long int populacao1;
    float area1;
    double PIB1, densidade_populacional1, PIB_per_capita1;
    int pontos_turisticos1;

    // Entrada de dados para a primeira cidade
    printf("Digite o estado da primeira cidade (sigla): ");
    scanf("%s", estado1);
    printf("Digite o código da primeira cidade: ");
    scanf("%s", codigo1);
    printf("Digite o nome da primeira cidade: ");
    scanf("%s", nome1);
    printf("Digite a população da primeira cidade: ");
    scanf("%lu", &populacao1);
    printf("Digite a área da primeira cidade: ");
    scanf("%f", &area1);
    printf("Digite o PIB da primeira cidade: ");
    scanf("%lf", &PIB1);
    printf("Digite o número de pontos turísticos da primeira cidade: ");
    scanf("%d", &pontos_turisticos1);

    calcular_atributos(populacao1, area1, PIB1, &densidade_populacional1, &PIB_per_capita1);

    // Dados da segunda cidade
    char estado2[3], codigo2[10], nome2[50];
    unsigned long int populacao2;
    float area2;
    double PIB2, densidade_populacional2, PIB_per_capita2;
    int pontos_turisticos2;

    // Entrada de dados para a segunda cidade
    printf("Digite o estado da segunda cidade (sigla): ");
    scanf("%s", estado2);
    printf("Digite o código da segunda cidade: ");
    scanf("%s", codigo2);
    printf("Digite o nome da segunda cidade: ");
    scanf("%s", nome2);
    printf("Digite a população da segunda cidade: ");
    scanf("%lu", &populacao2);
    printf("Digite a área da segunda cidade: ");
    scanf("%f", &area2);
    printf("Digite o PIB da segunda cidade: ");
    scanf("%lf", &PIB2);
    printf("Digite o número de pontos turísticos da segunda cidade: ");
    scanf("%d", &pontos_turisticos2);

    calcular_atributos(populacao2, area2, PIB2, &densidade_populacional2, &PIB_per_capita2);

    // Comparação de um atributo escolhido no código
    comparar_atributo("População", populacao1, populacao2, nome1, nome2, estado1, estado2, 0);
    
    return 0;
}