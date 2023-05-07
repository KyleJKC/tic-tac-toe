#import <iostream>
#import "game.hpp"

int main() {
    char board[3][3] = {{'_', '_', '_'},
                        {'_', '_', '_'},
                        {'_', '_', '_'}};

    int input;

    // Main loop
    while (!game_over(board)) {
        for (auto i: board) {
            for (int j = 0; j < 3; j++) {
                std::cout << i[j] << " ";
            }
            std::cout << "\n";
        }

        std::cin >> input;
    }

    return 0;
}