#include <stdio.h>

// Estrutura para armazenar os dados das cidades
typedef struct {
    int codigo;
    char nome[50];
    unsigned long int populacao;
    int area;
    double PIB;
    int pontos_turisticos;
    double densidade_populacional;
    double PIB_per_capita;
    float super_poder;
} Cidade;

// Função para calcular os atributos derivados
void calcular_atributos(Cidade *c) {
    c->densidade_populacional = (double) c->populacao / c->area;
    c->PIB_per_capita = c->PIB / c->populacao;
    c->super_poder = c->populacao + c->area + c->PIB + c->pontos_turisticos + c->PIB_per_capita + (1 / c->densidade_populacional);
}

// Função para comparar atributos e exibir o vencedor
void comparar_e_exibir(char *atributo, double val1, double val2, int inverso) {
    int resultado = inverso ? (val1 < val2) : (val1 > val2);
    printf("%s: Carta %d venceu (%d)\n", atributo, resultado ? 1 : 2, resultado);
}

int main() {
    Cidade cidade1, cidade2;

    // Entrada de dados para a primeira cidade
    printf("Digite o código da primeira cidade: ");
    scanf("%d", &cidade1.codigo);
    printf("Digite o nome da primeira cidade: ");
    scanf("%s", cidade1.nome);
    printf("Digite a população da primeira cidade: ");
    scanf("%lu", &cidade1.populacao);
    printf("Digite a área da primeira cidade: ");
    scanf("%d", &cidade1.area);
    printf("Digite o PIB da primeira cidade: ");
    scanf("%lf", &cidade1.PIB);
    printf("Digite o número de pontos turísticos da primeira cidade: ");
    scanf("%d", &cidade1.pontos_turisticos);
    calcular_atributos(&cidade1);

    // Entrada de dados para a segunda cidade
    printf("Digite o código da segunda cidade: ");
    scanf("%d", &cidade2.codigo);
    printf("Digite o nome da segunda cidade: ");
    scanf("%s", cidade2.nome);
    printf("Digite a população da segunda cidade: ");
    scanf("%lu", &cidade2.populacao);
    printf("Digite a área da segunda cidade: ");
    scanf("%d", &cidade2.area);
    printf("Digite o PIB da segunda cidade: ");
    scanf("%lf", &cidade2.PIB);
    printf("Digite o número de pontos turísticos da segunda cidade: ");
    scanf("%d", &cidade2.pontos_turisticos);
    calcular_atributos(&cidade2);

    // Comparação dos atributos e exibição dos resultados
    printf("\nComparação de Cartas:\n");
    comparar_e_exibir("População", cidade1.populacao, cidade2.populacao, 0);
    comparar_e_exibir("Área", cidade1.area, cidade2.area, 0);
    comparar_e_exibir("PIB", cidade1.PIB, cidade2.PIB, 0);
    comparar_e_exibir("Pontos Turísticos", cidade1.pontos_turisticos, cidade2.pontos_turisticos, 0);
    comparar_e_exibir("Densidade Populacional", cidade1.densidade_populacional, cidade2.densidade_populacional, 1);
    comparar_e_exibir("PIB per Capita", cidade1.PIB_per_capita, cidade2.PIB_per_capita, 0);
    comparar_e_exibir("Super Poder", cidade1.super_poder, cidade2.super_poder, 0);

    return 0;
}
