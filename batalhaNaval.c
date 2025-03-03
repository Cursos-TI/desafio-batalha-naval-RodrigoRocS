#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

//função para imprimir o tabuleiro.
void exibir_tabuleiro(int tabuleiro[10][10]) {
    printf("TABULEIRO BATALHA NAVAL:\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]); // Exibe células do tabuleiro.
        }
        printf("\n");
    }   
}
// Função para adicionar navio na horizontal.
void add_navio_horiz(int tabuleiro[10][10], int navio[3], int linha) {
    // Verifica se a linha é válida.
    if (linha < 0 || linha > 9) {
        printf("Posição fora dos limites do tabuleiro.\n");
        return;
    }
    // Valida a posição do navio no tabuleiro.
    for (int i = 0; i < 3; i++) {
        if (navio[i] < 0 || navio[i] > 9 || tabuleiro[linha][navio[i]] != 0) {
            printf("Posição inválida ou já ocupada.\n");
            return;
        }
    }

    // Adiciona o navio ao tabuleiro.
    for (int i = 0; i < 3; i++) {
        tabuleiro[linha][navio[i]] = 3; // Marca a posição do navio.
    }
}

// Função para adicionar navio na vertical.
void add_navio_vert(int tabuleiro[10][10], int navio[3], int coluna) {
    // Verifica se a coluna é válida.
    if (coluna < 0 || coluna > 9) {
        printf("Posição fora dos limites do tabuleiro.\n");
        return;
    }
    // Valida a posição do navio no tabuleiro.
    for (int i = 0; i < 3; i++) {
        if (navio[i] < 0 || navio[i] > 9 || tabuleiro[navio[i]][coluna] != 0) {
            printf("Posição inválida ou já ocupada.\n");
            return;
        }
    }

    // Adiciona o navio ao tabuleiro.
    for (int i = 0; i < 3; i++) {
        tabuleiro[navio[i]][coluna] = 3; // Marca a posição do navio.
    }
}

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // inicia tabuleiro 10x10
    int tabuleiro[10][10] = {
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},  
    };
    // inicia a posição dos navios
    int navio1[3] = {1,2,3};
    int navio2[3] = {6,7,8};

    add_navio_horiz(tabuleiro, navio1, 2);
    add_navio_vert(tabuleiro, navio2, 8);
    exibir_tabuleiro(tabuleiro);

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
