#ifndef TIC_TAC_TOE_GAME_END_HPP
#define TIC_TAC_TOE_GAME_END_HPP

std::string game_ending(char board[3][3]) {
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
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == '_') {
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

}

#endif //TIC_TAC_TOE_GAME_END_HPP
