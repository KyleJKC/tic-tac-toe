#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include "game_end.hpp"

struct opponent {
    int x() {
        return rand() % 3;
    };

    int y() {
        return rand() % 3;
    };
};

int main() {
    char player = 'O', computer = 'X', board[3][3] = {{'_', '_', '_'},
                                                      {'_', '_', '_'},
                                                      {'_', '_', '_'}};

    int input_x, input_y;
    std::string last_move;

    // Seed the rand num generator
    srand(time(nullptr));

    // Main loop
    while (game_ending(board) == "false") {

        //Render game board
        for (auto &i: board) {
            for (auto &j: i) {
                std::cout << j << " ";
            }
            std::cout << "\n";
        }

        // Player's turn
        std::cout<<"Enter your move (row column): ";
        std::cin >> input_x >> input_y;
        board[input_x - 1][input_y - 1] = player;
        last_move = "player";
        system("clear");
        if (game_ending(board) == "true") {
            break;
        }

        // Re-render game board
        for (auto &i: board) {
            for (auto &j: i) {
                std::cout << j << " ";
            }
            std::cout << "\n";
        }

        // Wait 2 sec
        std::cout << "My turn, thinking..." << "\n";
        sleep(2);
        system("clear");

        // Computer's turn
        opponent comp;
        int comp_x, comp_y;

        do {
            comp_x = comp.x();
            comp_y = comp.y();
        } while (board[comp_x][comp_y] != '_');

        board[comp_x][comp_y] = computer;
        last_move = "computer";

    }

    // Check who wins
    for (auto &i: board) {
        for (auto &j: i) {
            std::cout << j << " ";
        }
        std::cout << "\n";
    }
    if (game_ending(board) == "true") {
        if (last_move == "player") {
            std::cout << "You Win!";
            return 0;
        } else {
            std::cout << "You Lose!";
            return 0;
        }
    } else {
        std::cout << "Draw!";
        return 0;
    }

}