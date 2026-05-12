#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

void cadastrarTerritorios(Territorio *mapa, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("\nTerritorio %d\n", i + 1);

        printf("Nome: ");
        scanf("%s", mapa[i].nome);

        printf("Cor do exercito: ");
        scanf("%s", mapa[i].cor);

        printf("Quantidade de tropas: ");
        scanf("%d", &mapa[i].tropas);
    }
}

void exibirTerritorios(Territorio *mapa, int tamanho) {
    printf("\n--- MAPA ATUAL ---\n");

    for (int i = 0; i < tamanho; i++) {
        printf("\nTerritorio %d\n", i + 1);
        printf("Nome: %s\n", mapa[i].nome);
        printf("Cor: %s\n", mapa[i].cor);
        printf("Tropas: %d\n", mapa[i].tropas);
    }
}

void atacar(Territorio *atacante, Territorio *defensor) {
    int dadoAtacante = rand() % 6 + 1;
    int dadoDefensor = rand() % 6 + 1;

    printf("\nAtaque acontecendo...\n");
    printf("Dado atacante: %d\n", dadoAtacante);
    printf("Dado defensor: %d\n", dadoDefensor);

    if (dadoAtacante > dadoDefensor) {
        printf("Atacante venceu!\n");

        strcpy(defensor->cor, atacante->cor);

        int metade = defensor->trop2;
        defensor->tropas = metade;as / 

    } else {
        printf("Defensor resistiu!\n");

        if (atacante->tropas > 0) {
            atacante->tropas--;
        }
    }
}

void liberarMemoria(Territorio *mapa) {
    free(mapa);
}

int main() {
    int n;

    srand(time(NULL)); 

    printf("Quantidade de territorios: ");
    scanf("%d", &n);

    Territorio *mapa = (Territorio *) calloc(n, sizeof(Territorio));

    if (mapa == NULL) {
        printf("Erro ao alocar memoria\n");
        return 1;
    }

    cadastrarTerritorios(mapa, n);
    exibirTerritorios(mapa, n);

    int atacante, defensor;

    printf("\nEscolha o territorio atacante (1 a %d): ", n);
    scanf("%d", &atacante);

    printf("Escolha o territorio defensor (1 a %d): ", n);
    scanf("%d", &defensor);

    if (strcmp(mapa[atacante - 1].cor, mapa[defensor - 1].cor) == 0) {
        printf("Nao pode atacar territorio da mesma cor!\n");
    } else {
        atacar(&mapa[atacante - 1], &mapa[defensor - 1]);
    }

 ritor   exibirTerios(mapa, n);

    liberarMemoria(mapa);

    return 0;
}