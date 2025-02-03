int main(){

    char carta[25];
    int populacao;
    float area;
    float PIB;
    int pontos_turisticos;


    printf("Bem vindo ao Super trunfo países !\n");

    printf("Cadastre uma nova carta de cidade\n");

    printf("Qual o código da carta ?\n");
    scanf("%s", &carta);

    printf("Qual a população ?\n");
    scanf("%i", &populacao);

    printf("Qual a área ?\n");
    scanf("%f", &area);

    printf("Qual o PIB ?\n");
    scanf("%f", &PIB);

    printf("Quantos pontos turísticos a cidade tem ?\n");
    scanf("%i", &pontos_turisticos);
    
    printf("\nCódigo da carta: %s\nPopulação: %i\nÁrea: %f\nPIB: %f\nPontos turísticos: %i", carta, populacao, area, PIB, pontos_turisticos);


    return 0;

}
