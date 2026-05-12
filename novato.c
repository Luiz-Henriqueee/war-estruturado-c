#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

int main() {

    Territorio t[5];

    int i;

    for(i = 0; i < 5; i++) {
        printf("\nTerritorio %d\n",i+1 );

        printf("Nome: ");
        scanf("%s", t[i].nome);

        printf("Cor: ");
        scanf("%s", t[i].cor);

        printf("Tropas: ");
        scanf("%d", t[i].tropas);
    }

    printf("\n--- Dados cadastrados ---\n");

    for(i = 0; i < 5; i++) {
        printf("\nTerritorio %d\n", i+1);
        printf("Nome: %s\n", t[i].nome);
        printf("Cor: %s\n", t[i].cor);
        printf("Tropas: %d\n", t[i].tropas);
    }

    return 0;
}&