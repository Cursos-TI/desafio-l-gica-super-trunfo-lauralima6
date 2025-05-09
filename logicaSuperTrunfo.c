#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade;
} Carta;

void calcularDensidade(Carta *c) {
    c->densidade = (c->area > 0) ? (c->populacao / c->area) : 0.0;
}

void exibirMenuAtributos(int ignorar) {
    printf("Escolha um atributo:\n");
    if (ignorar != 1) printf("1. População\n");
    if (ignorar != 2) printf("2. Área\n");
    if (ignorar != 3) printf("3. PIB\n");
    if (ignorar != 4) printf("4. Pontos Turísticos\n");
    if (ignorar != 5) printf("5. Densidade Demográfica\n");
    printf("Digite o número correspondente: ");
}

// Função para retornar o valor do atributo selecionado
float obterValorAtributo(Carta c, int atributo) {
    switch (atributo) {
        case 1: return (float)c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return (float)c.pontos_turisticos;
        case 5: return c.densidade;
        default: return 0.0;
    }
}

// Função para exibir o nome do atributo
const char* nomeAtributo(int atributo) {
    switch (atributo) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Demográfica";
        default: return "Desconhecido";
    }
}

int main() {
    // Cartas fixas
    Carta pais1 = {"Brasil", 214000000, 8515767.0, 22000.0, 25, 0.0};
    Carta pais2 = {"Canadá", 38000000, 9984670.0, 19000.0, 15, 0.0};

    calcularDensidade(&pais1);
    calcularDensidade(&pais2);

    int atributo1 = 0, atributo2 = 0;

    // Escolha do primeiro atributo
    do {
        printf("\n=== SUPER TRUNFO: ESCOLHA DO 1º ATRIBUTO ===\n");
        exibirMenuAtributos(0);
        scanf("%d", &atributo1);
        if (atributo1 < 1 || atributo1 > 5) {
            printf("[Erro] Atributo inválido. Tente novamente.\n");
            atributo1 = 0;
        }
    } while (atributo1 == 0);

    // Escolha do segundo atributo
    do {
        printf("\n=== ESCOLHA DO 2º ATRIBUTO ===\n");
        exibirMenuAtributos(atributo1);
        scanf("%d", &atributo2);
        if (atributo2 < 1 || atributo2 > 5 || atributo2 == atributo1) {
            printf("[Erro] Atributo inválido ou repetido. Tente novamente.\n");
            atributo2 = 0;
        }
    } while (atributo2 == 0);

    // Obtem valores dos atributos
    float valor1_c1 = obterValorAtributo(pais1, atributo1);
    float valor1_c2 = obterValorAtributo(pais2, atributo1);
    float valor2_c1 = obterValorAtributo(pais1, atributo2);
    float valor2_c2 = obterValorAtributo(pais2, atributo2);

    // Lógica de comparação com regras
    int pontos_c1 = 0, pontos_c2 = 0;

    // Regra especial para densidade (menor vence)
    if (atributo1 == 5) {
        (valor1_c1 < valor1_c2) ? pontos_c1++ : (valor1_c2 < valor1_c1) ? pontos_c2++ : 0;
    } else {
        (valor1_c1 > valor1_c2) ? pontos_c1++ : (valor1_c2 > valor1_c1) ? pontos_c2++ : 0;
    }

    if (atributo2 == 5) {
        (valor2_c1 < valor2_c2) ? pontos_c1++ : (valor2_c2 < valor2_c1) ? pontos_c2++ : 0;
    } else {
        (valor2_c1 > valor2_c2) ? pontos_c1++ : (valor2_c2 > valor2_c1) ? pontos_c2++ : 0;
    }

    float soma1 = valor1_c1 + valor2_c1;
    float soma2 = valor1_c2 + valor2_c2;

    printf("\n=== RESULTADO DA RODADA ===\n");
    printf("País 1: %s\n", pais1.nome);
    printf("  %s: %.2f\n", nomeAtributo(atributo1), valor1_c1);
    printf("  %s: %.2f\n", nomeAtributo(atributo2), valor2_c1);
    printf("  Soma: %.2f\n", soma1);

    printf("\nPaís 2: %s\n", pais2.nome);
    printf("  %s: %.2f\n", nomeAtributo(atributo1), valor1_c2);
    printf("  %s: %.2f\n", nomeAtributo(atributo2), valor2_c2);
    printf("  Soma: %.2f\n", soma2);

    printf("\nResultado Final: ");
    if (soma1 > soma2) {
        printf("%s venceu!\n", pais1.nome);
    } else if (soma2 > soma1) {
        printf("%s venceu!\n", pais2.nome);
    } else {
        printf("Empate!\n");
    }

    return 0;
}
