#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // Pour la fonction sleep
#include <time.h>   // Pour la fonction time
#include "display.h"
#include "rules.h"

#define SIZE 3

int main() {
    // Initialiser le générateur de nombres aléatoires
    srand(time(NULL));

    char board[SIZE][SIZE] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int choice;
    int row, col;

    printf("Bienvenue dans le Tic-Tac-Toe !\n");

    while (1) {
        // Afficher le plateau
        display_board(board);

        // Demander au joueur de choisir une case
        printf("Choisissez une case (1-9) : ");
        scanf("%d", &choice);

        // Convertir le choix en indices de tableau
        if (choice < 1 || choice > 9) {
            printf("Choix invalide. Veuillez entrer un nombre entre 1 et 9.\n");
            continue;
        }

        row = (choice - 1) / SIZE;
        col = (choice - 1) % SIZE;

        // Vérifier si la case est déjà occupée
        if (board[row][col] != ' ') {
            printf("Case déjà occupée. Essayez encore.\n");
            continue;
        }

        // Placer le symbole du joueur
        board[row][col] = 'X';

        // Vérifier si le joueur a gagné
        if (check_winner(board)) {
            display_board(board);
            printf("Félicitations ! Vous avez gagné !\n");
            break;
        }

        // Vérifier si le plateau est plein
        if (is_board_full(board)) {
            display_board(board);
            printf("C'est une partie nulle !\n");
            break;
        }

        // Tour de l'ordinateur (choix aléatoire)
        int computer_choice;
        do {
            computer_choice = rand() % 9 + 1; // Choisir un nombre aléatoire entre 1 et 9
            row = (computer_choice - 1) / SIZE;
            col = (computer_choice - 1) % SIZE;
        } while (board[row][col] != ' '); // Répéter tant que la case est occupée

        // Placer le symbole de l'ordinateur
        board[row][col] = 'O';
        printf("L'ordinateur a choisi la case %d.\n", computer_choice);

        // Vérifier si l'ordinateur a gagné
        if (check_winner(board)) {
            display_board(board);
            printf("L'ordinateur a gagné !\n");
            break;
        }

        // Vérifier si le plateau est plein
        if (is_board_full(board)) {
            display_board(board);
            printf("C'est une partie nulle !\n");
            break;
        }

        // Pause pour rendre le jeu plus agréable
        sleep(1);
    }

    return 0;
}
