#include <stdio.h>

// Definição da estrutura CARTA para armazenar informações de uma cidade
typedef struct {
    char carta[25];  // Nome ou código da cidade
    int populacao;   // Número de habitantes
    float area;      // Área total da cidade em km²
    float PIB;       // Produto Interno Bruto da cidade
    int pontos_turisticos;  // Número de pontos turísticos
    float densidade_populacional; // População por área
    float PIB_per_capita; // Renda média por habitante
    float super_poder; // Valor agregado com diversas propriedades
} CARTA;

// Função para cadastrar uma cidade e preencher seus atributos
void cadastro(CARTA *cidade) {
    printf("\nCadastre uma nova carta de cidade\n");

    printf("Qual o código da carta?\n");
    scanf("%s", cidade->carta);

    printf("Qual a população?\n");
    scanf("%i", &cidade->populacao);

    printf("Qual a área?\n");
    scanf("%f", &cidade->area);

    printf("Qual o PIB?\n");
    scanf("%f", &cidade->PIB);

    printf("Quantos pontos turísticos a cidade tem?\n");
    scanf("%i", &cidade->pontos_turisticos);

    // Calcula a densidade populacional
    cidade->densidade_populacional = (float) cidade->populacao / cidade->area;
    
    // Calcula o PIB per capita
    cidade->PIB_per_capita = (float) cidade->PIB / cidade->populacao;

    // Super poder é a soma de todas as propriedades da cidade
    cidade->super_poder = (float) cidade->area + cidade->PIB +
        cidade->pontos_turisticos + cidade->populacao + cidade->PIB_per_capita;
}

// Função para imprimir os atributos de uma cidade
void imprimir(CARTA cidade) {
    printf("\nCódigo da carta: %s\nPopulação: %i\nÁrea(Km²): %.2f\nPIB: %.2f\nPontos turísticos: %i\nDensidade populacional(Hab/Km²): %.2f\nPIB per capita: %.2f\nSuper poder: %.2f\n",
        cidade.carta, cidade.populacao, cidade.area, cidade.PIB, cidade.pontos_turisticos,
        cidade.densidade_populacional, cidade.PIB_per_capita, cidade.super_poder);
}

// Função para comparar a densidade populacional entre duas cidades
void carta_vencedora_densidade_populacional(CARTA cidade1, CARTA cidade2) {
    if (cidade1.densidade_populacional < cidade2.densidade_populacional) {
        printf("\nCidade %s venceu em DENSIDADE POPULACIONAL\n", cidade1.carta);
    } else if (cidade2.densidade_populacional < cidade1.densidade_populacional) {
        printf("\nCidade %s venceu em DENSIDADE POPULACIONAL\n", cidade2.carta);
    } else {
        printf("\nEmpate !!!"); 
    }
}

// Função para comparar a soma das propriedades entre duas cidades
void carta_vencedora_outras_propriedades(CARTA cidade1, CARTA cidade2) {
    if (cidade1.super_poder > cidade2.super_poder) {
        printf("\nCidade %s venceu em SUPER PODER", cidade1.carta);
    } else if (cidade2.super_poder > cidade1.super_poder) {
        printf("\nCidade %s venceu em SUPER PODER", cidade2.carta);
    } else {
        printf("\nEmpate !!!"); 
    }
}

int main() {
    printf("Bem vindo ao Super Trunfo Países!\n");

    
    CARTA cidade[2]; 

    // Cadastro das duas cidades
    cadastro(&cidade[0]);
    cadastro(&cidade[1]);

    // Impressão dos atributos das cidades
    imprimir(cidade[0]);
    imprimir(cidade[1]);

    // Comparação entre as cidades com base na densidade populacional
    carta_vencedora_densidade_populacional(cidade[0], cidade[1]);

    
    carta_vencedora_outras_propriedades(cidade[0], cidade[1]);

    return 0;
}
