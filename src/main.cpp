#include <iostream>
#include <unistd.h>
#include "game_end.hpp"
#include "opponent.hpp"

int main() {
    char player = 'O', computer = 'X', board[3][3] = {{'X', '_', '_'},
                                                      {'_', 'X', '_'},
                                                      {'_', '_', '_'}};

    int input_h, input_v;

    // Main loop
    while (!game_end(board)) {
        for (auto i: board) {
            for (int j = 0; j < 3; j++) {
                std::cout << i[j] << " ";
            }
            std::cout << "\n";
        }

        std::cin >> input_h >> input_v;
        board[input_h - 1][input_v - 1] = player;
        system("clear");
        for (auto i: board) {
            for (int j = 0; j < 3; j++) {
                std::cout << i[j] << " ";
            }
            std::cout << "\n";
        }

        // Wait 2 sec
        std::cout<<"My turn, thinking..."<<"\n";
        sleep(2);

        // Still bug here
        int h, v;
        h = opponent(board) / 10 - 1;
        v = opponent(board) % 10 - 1;
        board[h][v] = computer;
        system("clear");
        for (auto i: board) {
            for (int j = 0; j < 3; j++) {
                std::cout << i[j] << " ";
            }
            std::cout << "\n";
        }
    }

    return 0;
}