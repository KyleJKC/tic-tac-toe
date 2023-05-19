#ifndef TIC_TAC_TOE_GAME_UTILS_HPP
#define TIC_TAC_TOE_GAME_UTILS_HPP

#include <bits/stdc++.h>

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

char player = 'O', computer = 'X', board[3][3] = {{'_', '_', '_'},
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

auto winner = []() {
    if (game_ending() == "true") {
        if (last_move == "player") {
            return "player";
        } else {
            return "computer";
        }
    } else {
        return "draw";
    }
};

#endif //TIC_TAC_TOE_GAME_UTILS_HPP
