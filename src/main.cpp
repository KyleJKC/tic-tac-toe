#include "lib.hpp"

int main() {

    //Select Game Mode
    std::cout << "Tic-Tac-Toe game, do you want to play this yourself or with your friend?" << std::endl;
    std::cout << "1) Single Player    2) Multiplayer" << std::endl;

    std::cin >> game_mode;

    // Clear the screen before get started
    system("clear");

    // Main loop
    if (game_mode == 1) {
        single_player();
    } else if (game_mode == 2) {
        multi_player();
    } else {
        std::cout << "Invalid game mode, type your choice again" << std::endl;
    }

    // Re-render game board
    board_render();

    print_winner();

    return 0;

}