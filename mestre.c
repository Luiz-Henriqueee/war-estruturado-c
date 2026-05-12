#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

void cadastrar(Territorio *mapa, int n) {
    for (int i = 0; i < n; i++) {
        printf("\nTerritorio %d\n", i + 1);

        printf("Nome: ");
        scanf("%s", mapa[i].nome);

        printf("Cor: ");
        scanf("%s", mapa[i].cor);

        printf("Tropas: ");
        scanf("%d", &mapa[i].tropas);
    }
}

void exibirMapa(Territorio *mapa, int n) {
    printf("\nMapa atual:\n");

    for (int i = 0; i < n; i++) {
        printf("\n[%d] %s | Cor: %s | Tropas: %d",
            i + 1,
            mapa[i].nome,
            mapa[i].cor,
            mapa[i].tropas);
    }
}

void atacar(Territorio *atacante, Territorio *defensor) {
    int dadoA = rand() % 6 + 1;
    int dadoD = rand() % 6 + 1;

    printf("\nDados -> Atacante: %d | Defensor: %d\n", dadoA, dadoD);

    if (dadoA > dadoD) {
        printf("Ataque venceu!\n");

        strcpy(defensor->cor, atacante->cor);
        defensor->tropas = defensor->tropas / 2;

    } else {
        printf("Defesa venceu!\n");

        if (atacante->tropas > 0)
            atacante->tropas--;
    }
}

void atribuirMissao(char *destino, char *missoes[], int total) {
    int sorteio = rand() % total;
    strcpy(destino, missoes[sorteio]);
}

void exibirMissao(char *missao) {
    printf("\nSua missão: %s\n", missao);
}

int verificarMissao(char *missao, Territorio *mapa, int n) {
    
    if (strstr(missao, "vermelha") != NULL) {
        for (int i = 0; i < n; i++) {
            if (strcmp(mapa[i].cor, "vermelha") == 0)
                return 0;
        }
        return 1;
    }

    if (strstr(missao, "dominar") != NULL) {
        char corBase[10];
        strcpy(corBase, mapa[0].cor);

        for (int i = 1; i < n; i++) {
            if (strcmp(mapa[i].cor, corBase) != 0)
                return 0;
        }
        return 1;
    }

    return 0;
}

void liberar(Territorio *mapa, char *missao) {
    free(mapa);
    free(missao);
}

int main() {
    int n;

    srand(time(NULL));

    printf("Quantidade de territorios: ");
    scanf("%d", &n);

    Territorio *mapa = (Territorio *) calloc(n, sizeof(Territorio));

    char *missoes[] = {
        "Eliminar todas as tropas da cor vermelha",
        "Dominar todos os territorios",
        "Conquistar territórios inimigos",
        "Expandir seu exercito ao maximo",
        "Controlar o mapa inteiro"
    };

    char *missao = (char *) malloc(100 * sizeof(char));

    cadastrar(mapa, n);

    atribuirMissao(missao, missoes, 5);

    exibirMissao(missao);

    exibirMapa(mapa, n);

    int a, d;

    printf("\nEscolha atacante: ");
    scanf("%d", &a);

    printf("Escolha defensor: ");
    scanf("%d", &d);

    if (strcmp(mapa[a-1].cor, mapa[d-1].cor) != 0) {
        atacar(&mapa[a-1], &mapa[d-1]);
    } else {
        printf("Nao pode atacar mesma cor!\n");
    }

    exibirMapa(mapa, n);

    if (verificarMissao(missao, mapa, n)) {
        printf("\nMissao cumprida! Vitoria!\n");
    }

    liberar(mapa, missao);

    return 0;
}