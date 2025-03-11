#include <stdio.h>

#define LINHA 10
#define COLUNA 10
#define LINHAH 3
#define COLUNAH 5


//função para imprimir o tabuleiro.
void exibir_tabuleiro(int tabuleiro[LINHA][COLUNA]) {
    printf("TABULEIRO BATALHA NAVAL:\n");
    for (int i = 0; i < LINHA; i++) {
        for (int j = 0; j < COLUNA; j++) {
            printf("%d ", tabuleiro[i][j]); // Exibe células do tabuleiro.
        }
        printf("\n");
    }
    
}


//função para exibir formato das habilidades
void exibir_habilidade(int habilidade[LINHAH][COLUNAH]) {
    for (int i = 0; i < LINHAH; i++) {
        for (int j = 0; j < COLUNAH; j++) {
            printf("%d ", habilidade[i][j]); // Exibe células da habilidade.
        }
        printf("\n");
    }
    
}
//adiciona habilidade no tabuleiro, variaveis linha e coluna determinam onde inicia a habilidade
void add_habilidade(int tabuleiro[LINHA][COLUNA], int habilidade[LINHAH][COLUNAH], int linha, int coluna) {
    if (linha < 0 || linha + LINHAH > LINHA || coluna < 0 || coluna + COLUNAH > COLUNA) { //verifica se esta dentro dos limites do tabuleiro
        printf("Posição fora dos limites do tabuleiro.\n");
        return;
    }
    for (int i = 0; i < LINHAH; i++) {
        for (int j = 0; j < COLUNAH; j++) {
            if (habilidade[i][j] != 0) { // Apenas copia valores diferentes de 0.
                tabuleiro[linha + i][coluna + j] = habilidade[i][j];
            }
        }
    }
}

// Função para adicionar navio na horizontal.
void add_navio_horiz(int tabuleiro[LINHA][COLUNA], int navio[3], int linha) {
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
void add_navio_vert(int tabuleiro[LINHA][COLUNA], int navio[3], int coluna) {
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

void add_navio_diag(int tabuleiro[LINHA][COLUNA], int navio[3], int coluna, char direcao) {
    // Verifica se a coluna é válida.
    if (coluna < 0 || coluna > 9) {
        printf("Posição fora dos limites do tabuleiro.\n");
        return;
    }
    // Valida a posição do navio no tabuleiro.
    for (int i = 0; i < 3; i++) {
        int y;

        if (direcao == 'e') {
            y = coluna - i; // Diagonal para a esquerda.
        } else if (direcao == 'd') {
            y = coluna + i; // Diagonal para a direita.
        } else {
            printf("Direção inválida. Use 'e' para esquerda ou 'd' para direita.\n");
            return;
        }

        // Verifica se a posição está dentro dos limites e disponível.
        if (navio[i] < 0 || navio[i] > 9 || y < 0 || y > 9 || tabuleiro[navio[i]][y] != 0) {
            printf("Posição inválida ou já ocupada.\n");
            return;
        }
    }
    
    
    // Adiciona o navio ao tabuleiro de acordo com a direção escolhida.
    for (int i = 0; i < 3; i++) {
        int y = (direcao == 'e') ? coluna - i : coluna + i; // atribui a direção.
        tabuleiro[navio[i]][y] = 3;
    }    
}

int main() {

    // inicia tabuleiro 10x10
    int tabuleiro[LINHA][COLUNA];
    for (int i = 0; i < LINHA; i++) {      
        for (int j = 0; j < COLUNA; j++) {
            tabuleiro[i][j] = 0;
        }
    }


    // inicia habilidades
    int cone[LINHAH][COLUNAH];
    for (int i = 0; i < LINHAH; i++) {
        for (int j = 0; j < COLUNAH; j++) {
            if (j >= (LINHAH - 1 - i) && j <= (COLUNAH - LINHAH + i)) {
                cone[i][j] = 5;
            } else {cone[i][j] = 0;}
            
        }
    }

    int cruz[LINHAH][COLUNAH];
    for (int i = 0; i < LINHAH; i++) {
        for (int j = 0; j < COLUNAH; j++) {
            if (j == COLUNAH / 2 || i == LINHAH / 2) {
                cruz[i][j] = 5;
            } else {cruz[i][j] = 0;}
        }
    }

    int octaedro[LINHAH][COLUNAH];
    for (int i = 0; i < LINHAH; i++) {
        for (int j = 0; j < COLUNAH; j++) {
            if (j == 0 || j == COLUNAH - 1) {
                octaedro[i][j] = 0;
            } else if (j == COLUNAH / 2 || i == LINHAH / 2) {
                octaedro[i][j] = 5;
            } else {octaedro[i][j] = 0;}
        }
    }

    // inicia a posição dos navios
    int navio1[3] = {1,2,3};
    int navio2[3] = {6,7,8};
    int navio3[3] = {6,7,8};
    int navio4[3] = {3,4,5};
    

    // add_navio_horiz(tabuleiro, navio1, 2);
    // add_navio_vert(tabuleiro, navio2, 8);
    // add_navio_diag(tabuleiro, navio3, 3, 'e');
    // add_navio_diag(tabuleiro, navio4, 7, 'd');
    // exibir_tabuleiro(tabuleiro);
    // printf("\n");
    // exibir_habilidade(cone);
    // printf("\n");
    // exibir_habilidade(cruz);
    // printf("\n");
    // exibir_habilidade(octaedro);
    // printf("\n");
    add_habilidade(tabuleiro, cone, 2, 2);
    exibir_tabuleiro(tabuleiro);

    return 0;

}
