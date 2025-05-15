#include <stdio.h>

typedef struct {
    char carta[25];
    int populacao;
    float area;
    float PIB;
    int pontos_turisticos;
    float densidade_populacional;
    float PIB_per_capita;
    float super_poder;
} CARTA;

void cadastro(CARTA *cidade) {
    printf("\nCadastre uma nova carta de cidade\n");

    printf("Qual o código da carta?\n");
    scanf("%s", &cidade->carta);

    printf("Qual a população?\n");
    scanf("%i", &cidade->populacao);

    printf("Qual a área?\n");
    scanf("%f", &cidade->area);

    printf("Qual o PIB?\n");
    scanf("%f", &cidade->PIB);

    printf("Quantos pontos turísticos a cidade tem?\n");
    scanf("%i", &cidade->pontos_turisticos);

    cidade->densidade_populacional = (float) cidade->populacao / cidade->area;
    cidade->PIB_per_capita = (float) cidade->PIB / cidade->populacao;
    cidade->super_poder = (float) cidade->area + cidade->PIB + 
        cidade->pontos_turisticos + cidade->populacao + cidade->PIB_per_capita;


}

void imprimir(CARTA cidade) {
    printf("\nCódigo da carta: %s\nPopulação: %i\nÁrea(Km²): %.2f\nPIB: %.2f\nPontos turísticos: %i\nDensidade populacional(Hab/Km²): %.2f\nPIB per capita: %.2f\nSuper poder: %.2f\n",
        cidade.carta, cidade.populacao, cidade.area, cidade.PIB, cidade.pontos_turisticos,
        cidade.densidade_populacional, cidade.PIB_per_capita, cidade.super_poder);
}

void carta_vencedora_densidade_populacional(CARTA cidade1, CARTA cidade2) {
    if (cidade1.densidade_populacional < cidade2.densidade_populacional) {
        printf("\nCidade %s venceu em DENSIDADE POPULACIONAL\n", cidade1.carta);
    } else if (cidade2.densidade_populacional < cidade1.densidade_populacional) {
        printf("\nCidade %s venceu em DENSIDADE POPULACIONAL\n", cidade2.carta);
    } else {
        printf("\nOcorreu algum erro");
    }
}


void carta_vencedora_outras_propriedades(CARTA cidade1, CARTA cidade2) {
    if (cidade1.super_poder > cidade2.super_poder) {
        printf("\nCidade %s venceu em SUPER PODER", cidade1.carta);
    } else if (cidade2.super_poder > cidade1.super_poder) {
        printf("\nCidade %s venceu em SUPER PODER", cidade2.carta);
    } else {
        printf("\nOcorreu algum erro");
    }
}

int main() {
    printf("Bem vindo ao Super Trunfo Países!\n");
    
    CARTA cidade[1];
    

    cadastro(&cidade[0]);
    cadastro(&cidade[1]);


    imprimir(cidade[0]);
    imprimir(cidade[1]);

    carta_vencedora_densidade_populacional(cidade[0], cidade[1]);
    
    carta_vencedora_outras_propriedadesA(cidade[0], cidade[1]);

    return 0;
}
