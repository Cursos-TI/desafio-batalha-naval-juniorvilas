#include <stdio.h>
//Tema 4 - Jogo de Batalha Naval
#define TAMANHO 10
#define TAM_HAB 5  // Tamanho fixo para as habilidades

// Função para inicializar o tabuleiro com 0 (água)
void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para posicionar os navios
void posicionarNavios(int tabuleiro[TAMANHO][TAMANHO]) {
    // Navio horizontal (começando em 2,2)
    for (int i = 2; i < 5; i++) {
        tabuleiro[2][i] = 3;
    }
    
    // Navio vertical (começando em 6,5)
    for (int i = 6; i < 9; i++) {
        tabuleiro[i][5] = 3;
    }
}

// Função para sobrepor matriz de habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[TAMANHO][TAMANHO], int habilidade[TAM_HAB][TAM_HAB], int x, int y) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            int tabX = x + i - TAM_HAB / 2;
            int tabY = y + j - TAM_HAB / 2;
            
            if (tabX >= 0 && tabX < TAMANHO && tabY >= 0 && tabY < TAMANHO && habilidade[i][j] == 1) {
                tabuleiro[tabX][tabY] = 5;
            }
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    inicializarTabuleiro(tabuleiro);
    posicionarNavios(tabuleiro);
    
    // Matriz de habilidade - Cone
    int cone[TAM_HAB][TAM_HAB] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };
    
    // Matriz de habilidade - Cruz
    int cruz[TAM_HAB][TAM_HAB] = {
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0}
    };
    
    // Matriz de habilidade - Octaedro
    int octaedro[TAM_HAB][TAM_HAB] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };
    
    // Aplicando habilidades ao tabuleiro
    aplicarHabilidade(tabuleiro, cone, 4, 4);
    aplicarHabilidade(tabuleiro, cruz, 6, 6);
    aplicarHabilidade(tabuleiro, octaedro, 8, 2);
    
    // Exibir tabuleiro final
    exibirTabuleiro(tabuleiro);
    
    return 0;
}