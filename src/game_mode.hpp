#ifndef TIC_TAC_TOE_GAME_MODE_HPP
#define TIC_TAC_TOE_GAME_MODE_HPP

#include <bits/stdc++.h>
#include <unistd.h>
#include "game_utils.hpp";

auto single_player = [](){
    while (game_ending() == "false") {

        //Render game board
        board_render();

        // Player's turn
        std::cout << "Enter your move (row column): ";
        std::cin >> input_x >> input_y;
        board[input_x - 1][input_y - 1] = player;
        last_move = "player";
        system("clear");
        if (game_ending() == "true") {
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

auto multi_player = [](){

};

#endif //TIC_TAC_TOE_GAME_MODE_HPP
