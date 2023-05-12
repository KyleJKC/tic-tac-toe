#ifndef TIC_TAC_TOE_OPPONENT_HPP
#define TIC_TAC_TOE_OPPONENT_HPP

int opponent(char board[3][3]) {

    // Horizontal
    if (board[0][0] == board[0][1] || board[0][1] == board[0][2] && (board[0][0] != 'O' || board[0][1] != 'O')) {
        if (board[0][0] == '_') {
            return 11;
        } else if (board[0][1] == '_') {
            return 12;
        } else {
            return 13;
        }
    } else if (board[1][0] == board[1][1] || board[1][1] == board[1][2] && (board[1][0] != 'O' || board[1][1] != 'O')) {
        if (board[1][0] == '_') {
            return 21;
        } else if (board[1][1] == '_') {
            return 22;
        } else {
            return 23;
        }
    } else if (board[2][0] == board[2][1] || board[2][1] == board[2][2] && (board[2][0] != 'O' || board[2][1] != 'O')) {
        if (board[2][0] == '_') {
            return 31;
        } else if (board[2][1] == '_') {
            return 32;
        } else {
            return 23;
        }
    }

        // Vertical
    else if (board[0][0] == board[1][0] || board[1][0] == board[2][0] && (board[0][0] != 'O' || board[1][0] != 'O')) {
        if (board[0][0] == '_') {
            return 11;
        } else if (board[1][0] == '_') {
            return 21;
        } else {
            return 31;
        }
    } else if (board[0][1] == board[1][1] || board[1][1] == board[2][1] && (board[0][1] != 'O' || board[1][1] != 'O')) {
        if (board[0][1] == '_') {
            return 12;
        } else if (board[1][1] == '_') {
            return 22;
        } else {
            return 32;
        }
    } else if (board[0][2] == board[1][2] || board[1][2] == board[2][2] && (board[0][2] != 'O' || board[1][2] != 'O')) {
        if (board[0][2] == '_') {
            return 13;
        } else if (board[1][2] == '_') {
            return 23;
        } else {
            return 33;
        }
    }

        // Diagonal
    else if (board[0][0] == board[1][1] || board[1][1] == board[2][2] && (board[0][0] != 'O' || board[1][1] != 'O')) {
        if (board[0][0] == '_') {
            return 11;
        } else if (board[1][1] == '_') {
            return 22;
        } else {
            return 33;
        }
    } else if (board[0][2] == board[1][1] || board[1][1] == board[2][0] && (board[0][2] != 'O' || board[1][1] != 'O')) {
        if (board[0][2] == '_') {
            return 13;
        } else if (board[1][1] == '_') {
            return 22;
        } else {
            return 31;
        }
    }



}

#endif //TIC_TAC_TOE_OPPONENT_HPP
