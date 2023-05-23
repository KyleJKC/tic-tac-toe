#ifndef TIC_TAC_TOE_GAME_UTILS_HPP
#define TIC_TAC_TOE_GAME_UTILS_HPP

#include "lib.hpp"

// Seed the random num generator
std::random_device seed;
std::mt19937 rand_num(seed());

struct opponent {
    static int x() {
        return rand_num() % 3;
    };

    static int y() {
        return rand_num() % 3;
    };
};

char player1 = 'O', player2 = 'X', computer = 'X', board[3][3] = {{'_', '_', '_'},
                                                                  {'_', '_', '_'},
                                                                  {'_', '_', '_'}};

int input_x, input_y, game_mode;
std::string last_move;

auto board_render = []() {
    for (auto &i: board) {
        for (auto &j: i) {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
};

auto game_ending = []() {
    bool draw = true;

    // Horizontal
    if (board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][0] != '_') {
        return "true";
    } else if (board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][0] != '_') {
        return "true";
    } else if (board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][0] != '_') {
        return "true";
    }

        // Vertical
    else if (board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[0][0] != '_') {
        return "true";
    } else if (board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[0][1] != '_') {
        return "true";
    } else if (board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[0][2] != '_') {
        return "true";
    }

        // Diagonal
    else if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '_') {
        return "true";
    } else if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '_') {
        return "true";
    }

    // Deal with draw
    for (auto &i: board) {
        for (auto &j: i) {
            if (j == '_') {
                draw = false;
                break;
            }
        }
    }

    if (draw) {
        return "draw";
    }

    // Not over yet, continue
    return "false";

};

auto print_winner = []() {
    // Single Player
    if (game_mode == 1) {
        if (strcmp(game_ending(), "true") == 0) {
            if (last_move == "player1") {
                std::cout << "You Win!";
            } else {
                std::cout << "You Lose!";
            }
        } else {
            std::cout << "Draw!";
        }
    }
    // Multiplayer
    else {
        if (strcmp(game_ending(), "true") == 0) {
            if (last_move == "player1") {
                std::cout << "Player 1 Wins!";
            } else {
                std::cout << "Player 2 Wins!";
            }
        } else {
            std::cout << "Draw!";
        }
    }
};

auto is_empty = [](int x, int y){
    if(board[x - 1][y - 1]=='_'){
        return true;
    } else {
        return false;
    }
};


auto input = [](char player){
    if(game_mode==1) {
        std::cout << "Enter your move (row column): ";
    } else {
        if(player == player1){
            std::cout << "Player 1, Enter your move (row column): ";
        } else {
            std::cout << "Player 2, Enter your move (row column): ";
        }
    }
    std::cin >> input_x >> input_y;
    if(is_empty(input_x, input_y)) {
        board[input_x - 1][input_y - 1] = player;
        return 0;
    } else{
        std::cout << "Invalid Move" << std::endl;
        return -1;
    }
};

#endif //TIC_TAC_TOE_GAME_UTILS_HPP
