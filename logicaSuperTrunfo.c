#include <stdio.h>
#include <string.h>

// Estrutura da carta de uma cidade
typedef struct {
    char estado[30];
    char codigo[10];
    char cidade[30];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade;       // Calculado 
    float pib_per_capita;  // Calculado 
} Carta;

// O menu de atributos
int menuAtributos(char *mensagem, int atributo_bloqueado) {
    int opcao;
    printf("\n%s\n", mensagem);
    if (atributo_bloqueado != 1) printf("1. População\n");
    if (atributo_bloqueado != 2) printf("2. Área\n");
    if (atributo_bloqueado != 3) printf("3. PIB\n");
    if (atributo_bloqueado != 4) printf("4. Pontos Turísticos\n");
    if (atributo_bloqueado != 5) printf("5. Densidade Demográfica\n");
    printf("Escolha (1-5): ");
    scanf("%d", &opcao);

    // Validação simples
    if (opcao < 1 || opcao > 5 || opcao == atributo_bloqueado) {
        printf("Opção inválida! Tente novamente.\n");
        return menuAtributos(mensagem, atributo_bloqueado);
    }

    return opcao;
}

// O retorna do valor a atributo escolhido
float valorAtributo(Carta c, int atributo) {
    switch (atributo) {
        case 1: return (float)c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return (float)c.pontos_turisticos;
        case 5: return c.densidade;
        default: return 0.0;
    }
}

    // Comparação de um único atributo
int compararAtributo(float val1, float val2, int atributo) {
    // Densidade: menor valor vence.
    return (atributo == 5)
        ? (val1 < val2 ? 1 : (val2 < val1 ? 2 : 0))
        : (val1 > val2 ? 1 : (val2 > val1 ? 2 : 0));
}

// Exibir nome do atributo
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
    // Cadastro manual das cartas Nivel Novato
    Carta c1 = {"Amazonas", "AM01", "Manaus", 2200000, 11400.0, 52.0, 12, 0, 0};
    Carta c2 = {"Roraima", "RR01", "Boa Vista", 400000, 5700.0, 7.5, 5, 0, 0};

    // Cálculo do densidade e PIB por capita
    c1.densidade = c1.populacao / c1.area;
    c2.densidade = c2.populacao / c2.area;
    c1.pib_per_capita = (c1.pib * 1000000000) / c1.populacao;
    c2.pib_per_capita = (c2.pib * 1000000000) / c2.populacao;

    // Informações básicas das cartas
    printf("=== Super Trunfo - Cidades ===\n");
    printf("Carta 1: %s (%s)\n", c1.cidade, c1.estado);
    printf("Carta 2: %s (%s)\n", c2.cidade, c2.estado);

    // Menu para o jogador escolher os dois atributos nivel Aventureiro
    int atributo1 = menuAtributos("Escolha o primeiro atributo para comparar:", -1);
    int atributo2 = menuAtributos("Escolha o segundo atributo (diferente do primeiro):", atributo1);

    // Os valores dos atributos para cada carta
    float valor1_c1 = valorAtributo(c1, atributo1);
    float valor1_c2 = valorAtributo(c2, atributo1);

    float valor2_c1 = valorAtributo(c1, atributo2);
    float valor2_c2 = valorAtributo(c2, atributo2);

    // Comparação dos dois atributos
    int resultado1 = compararAtributo(valor1_c1, valor1_c2, atributo1);
    int resultado2 = compararAtributo(valor2_c1, valor2_c2, atributo2);

    // Soma dos valores para comparação final
    float soma_c1 = valor1_c1 + valor2_c1;
    float soma_c2 = valor1_c2 + valor2_c2;

    int vencedor = (soma_c1 > soma_c2) ? 1 : (soma_c2 > soma_c1 ? 2 : 0);

    // Exibição dos resultados
    printf("\n--- Resultado da Comparação ---\n");
    printf("Atributo 1: %s\n", nomeAtributo(atributo1));
    printf("  %s: %.2f\n", c1.cidade, valor1_c1);
    printf("  %s: %.2f\n", c2.cidade, valor1_c2);

    printf("Atributo 2: %s\n", nomeAtributo(atributo2));
    printf("  %s: %.2f\n", c1.cidade, valor2_c1);
    printf("  %s: %.2f\n", c2.cidade, valor2_c2);

    printf("\nSoma dos Atributos:\n");
    printf("  %s: %.2f\n", c1.cidade, soma_c1);
    printf("  %s: %.2f\n", c2.cidade, soma_c2);

    // Resultado final
    if (vencedor == 1)
        printf("\nResultado Final: %s venceu!\n", c1.cidade);
    else if (vencedor == 2)
        printf("\nResultado Final: %s venceu!\n", c2.cidade);
    else
        printf("\nResultado Final: Empate!\n");

    return 0;
}
