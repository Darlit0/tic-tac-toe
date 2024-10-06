#include "rules.h"

// Fonction pour vérifier les conditions de victoire
int check_winner(char board[SIZE][SIZE]) {
    // Vérifier les lignes et les colonnes
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') return 1; // Lignes
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') return 1; // Colonnes
    }
    // Vérifier les diagonales
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') return 1;

    return 0; // Pas de gagnant
}

// Fonction pour vérifier si le plateau est plein
int is_board_full(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (board[i][j] == ' ') return 0; // Il y a encore des cases vides
    return 1; // Le plateau est plein
}
