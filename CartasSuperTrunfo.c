#include <stdio.h>
#include <string.h>

// Estrutura para armazenar os dados das cidades
typedef struct {
    char estado[3];
    char codigo[10];
    char nome[50];
    unsigned long int populacao;
    float area;
    double PIB;
    int pontos_turisticos;
    double densidade_populacional;
    double PIB_per_capita;
} Cidade;

// Função para calcular os atributos derivados
void calcular_atributos(Cidade *c) {
    c->densidade_populacional = c->populacao / c->area;
    c->PIB_per_capita = c->PIB / c->populacao;
}

// Função para comparar um atributo específico e exibir o vencedor
void comparar_atributo(char *atributo, double val1, double val2, Cidade c1, Cidade c2, int inverso) {
    printf("\nComparação de cartas (Atributo: %s):\n", atributo);
    printf("Carta 1 - %s (%s): %.2f\n", c1.nome, c1.estado, val1);
    printf("Carta 2 - %s (%s): %.2f\n", c2.nome, c2.estado, val2);
    
    if ((inverso && val1 < val2) || (!inverso && val1 > val2)) {
        printf("Resultado: Carta 1 (%s) venceu!\n", c1.nome);
    } else {
        printf("Resultado: Carta 2 (%s) venceu!\n", c2.nome);
    }
}

int main() {
    Cidade cidade1, cidade2;

    // Entrada de dados para a primeira cidade
    printf("Digite o estado da primeira cidade (sigla): ");
    scanf("%s", cidade1.estado);
    printf("Digite o código da primeira cidade: ");
    scanf("%s", cidade1.codigo);
    printf("Digite o nome da primeira cidade: ");
    scanf("%s", cidade1.nome);
    printf("Digite a população da primeira cidade: ");
    scanf("%lu", &cidade1.populacao);
    printf("Digite a área da primeira cidade: ");
    scanf("%f", &cidade1.area);
    printf("Digite o PIB da primeira cidade: ");
    scanf("%lf", &cidade1.PIB);
    printf("Digite o número de pontos turísticos da primeira cidade: ");
    scanf("%d", &cidade1.pontos_turisticos);
    calcular_atributos(&cidade1);

    // Entrada de dados para a segunda cidade
    printf("Digite o estado da segunda cidade (sigla): ");
    scanf("%s", cidade2.estado);
    printf("Digite o código da segunda cidade: ");
    scanf("%s", cidade2.codigo);
    printf("Digite o nome da segunda cidade: ");
    scanf("%s", cidade2.nome);
    printf("Digite a população da segunda cidade: ");
    scanf("%lu", &cidade2.populacao);
    printf("Digite a área da segunda cidade: ");
    scanf("%f", &cidade2.area);
    printf("Digite o PIB da segunda cidade: ");
    scanf("%lf", &cidade2.PIB);
    printf("Digite o número de pontos turísticos da segunda cidade: ");
    scanf("%d", &cidade2.pontos_turisticos);
    calcular_atributos(&cidade2);

    // Comparação de um atributo escolhido no código
    comparar_atributo("População", cidade1.populacao, cidade2.populacao, cidade1, cidade2, 0);
    
    return 0;
}
