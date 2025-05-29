#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de comparação de cartas de cidades. 

int main() {
    // Definição das variáveis para armazenar as propriedades das cidades
   
 // Estrutura da carta
typedef struct {
    char estado[30];
    char codigo[10];
    char cidade[30];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade;
    float pib_per_capita;
} Carta;

// os atributos das cartas
int menuAtributos(char *mensagem) { 
    int opcao;
    printf("\n%s\n", mensagem);
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Pontos Turísticos\n");
    printf("5. Densidade Demográfica\n");
    printf("Escolha (1-5): ");
    scanf("%d", &opcao);
    return opcao;
}

// Função que retorna o valor de um atributo específico
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
// Função que compara dois valores considerando regra da densidade
int compararAtributo(float val1, float val2, int atributo) {
    if (atributo == 5) {
        // Menor valor vence para densidade
        return (val1 < val2) ? 1 : (val2 < val1 ? 2 : 0);
    } else {
        // Maior valor vence para os demais
        return (val1 > val2) ? 1 : (val2 > val1 ? 2 : 0);
    }
}
   int main() {
    // Criando as cartas manualmente
    Carta c1 = {"Amazonas", "AM01", "Manaus", 2200000, 11400.0, 52.0, 12, 0};
    Carta c2 = {"Roraima", "RR01", "Boa Vista", 400000, 5700.0, 7.5, 5, 0};

    // Calculando densidade
    c1.densidade = c1.populacao / c1.area;
    c2.densidade = c2.populacao / c2.area;

    int attr1 = menuAtributos("Escolha o primeiro atributo para comparar:");

    // Cálculo automático da densidade e PIB per capita
    c1.densidade = c1.populacao / c1.area;
    c2.densidade = c2.populacao / c2.area;
    c1.pib_per_capita = (c1.pib * 1000000000) / c1.populacao;
    c2.pib_per_capita = (c2.pib * 1000000000) / c2.populacao;

    // Exibe informações básicas das cartas
    printf("=== Super Trunfo - Cidades ===\n");
    printf("Carta 1: %s (%s)\n", c1.cidade, c1.estado);
    printf("Carta 2: %s (%s)\n", c2.cidade, c2.estado);
    
    // Exemplo:
    // printf("A cidade vencedora é: %s\n", cidadeVencedora);

    return 0;
}
