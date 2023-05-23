#ifndef TIC_TAC_TOE_GAME_MODE_HPP
#define TIC_TAC_TOE_GAME_MODE_HPP

#include "lib.hpp"

auto single_player = []() {
    while (strcmp(game_ending(), "false") == 0) {

        //Render game board
        board_render();

        // Player's turn
        while(input(player1) != 0);

        last_move = "player1";
        system("clear");
        if (strcmp(game_ending(), "true") == 0) {
            break;
        }

        // Re-render game board
        board_render();

        // Wait 2 sec
        std::cout << "My turn, thinking..." << "\n";
        sleep(2);
        system("clear");

        // Computer's turn
        opponent comp;
        int comp_x, comp_y;

        do {
            comp_x = opponent::x();
            comp_y = opponent::y();
        } while (board[comp_x][comp_y] != '_');

        board[comp_x][comp_y] = computer;
        last_move = "computer";

    }
};

auto multi_player = []() {
    while (strcmp(game_ending(), "false") == 0) {

        //Render game board
        board_render();

        // Player 1's turn
        while(input(player1) != 0);
        last_move = "player1";
        system("clear");

        // Check if Player 1 wins;
        if (strcmp(game_ending(), "true") == 0) {
            break;
        }

        // Clear Screen
        system("clear");

        // Re-render game board
        board_render();

        // Player 2's turn
        while(input(player2) != 0);
        last_move = "player2";

        // Clear Screen
        system("clear");

    }
};

#endif //TIC_TAC_TOE_GAME_MODE_HPP
