bool game_over(char board[3][3]) {

    // Horizontal
    if (board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][0] != '_') {
        return true;
    } else if (board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][0] != '_') {
        return true;
    } else if (board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][0] != '_') {
        return true;
    }

    // Vertical
    else if (board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[0][0] != '_') {
        return true;
    } else if (board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[0][1] != '_') {
        return true;
    } else if (board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[0][2] != '_') {
        return true;
    }

    // Diagonal
    else if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '_') {
        return true;
    } else if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '_') {
        return true;
    }

    // Not over yet, continue
    else {
        return false;
    }

}
