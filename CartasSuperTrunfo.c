#include <stdio.h>
#include <string.h>

struct Cidade {
    char estado[3];
    char codigo[4];
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidade_populacional;
    float pib_per_capita;
};

void calcular_atributos(struct Cidade* cidade) {
    cidade->densidade_populacional = (float)cidade->populacao / cidade->area;
    cidade->pib_per_capita = cidade->pib / cidade->populacao;
}

void exibirCarta(struct Cidade cidade) {
    printf("\nCarta da Cidade:\n\n");
    printf("Estado: %s\nCódigo: %s\nNome: %s\n", cidade.estado, cidade.codigo, cidade.nome);
    printf("População: %d\nÁrea: %.2f km²\nPIB: %.2f bilhões de reais\n", cidade.populacao, cidade.area, cidade.pib);
    printf("Pontos Turísticos: %d\nDensidade Populacional: %.2f hab/km²\nPIB per capita: %.2f\n", cidade.pontosTuristicos, cidade.densidade_populacional, cidade.pib_per_capita);
}

void comparar_cartas(struct Cidade cidade1, struct Cidade cidade2) {
    printf("\nComparando Cartas...\n");
    printf("Atributo: População\n");
    printf("Carta 1 - %s: %d\n", cidade1.nome, cidade1.populacao);
    printf("Carta 2 - %s: %d\n", cidade2.nome, cidade2.populacao);
    if (cidade1.populacao > cidade2.populacao) {
        printf("Carta 1 (%s) venceu!\n", cidade1.nome);
    } else if (cidade2.populacao > cidade1.populacao) {
        printf("Carta 2 (%s) venceu!\n", cidade2.nome);
    } else {
        printf("Empate!\n");
    }
}

int main() {
    struct Cidade cidade1;
    struct Cidade cidade2;

    // Dados da Carta 1
    strcpy(cidade1.estado, "A");
    strcpy(cidade1.codigo, "A01");
    strcpy(cidade1.nome, "São Paulo");
    cidade1.populacao = 12325000;
    cidade1.area = 1521.11;
    cidade1.pib = 699.28;
    cidade1.pontosTuristicos = 50;

    // Dados da Carta 2
    strcpy(cidade2.estado, "B");
    strcpy(cidade2.codigo, "B02");
    strcpy(cidade2.nome, "Rio de Janeiro");
    cidade2.populacao = 6748000;
    cidade2.area = 1200.25;
    cidade2.pib = 300.50;
    cidade2.pontosTuristicos = 30;

    calcular_atributos(&cidade1);
    calcular_atributos(&cidade2);

    printf("\nCarta da Cidade 1:\n");
    exibirCarta(cidade1);

    printf("\nCarta da Cidade 2:\n");
    exibirCarta(cidade2);

    comparar_cartas(cidade1, cidade2);

    return 0;
}
