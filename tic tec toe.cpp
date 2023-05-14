#include <stdio.h>
#include <stdlib.h>

void printBoard(char board[3][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }
}

int isWinner(char board[3][3], char player) {
  // Check for horizontal wins.
  for (int i = 0; i < 3; i++) {
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] == player) {
      return 1;
    }
  }

  // Check for vertical wins.
  for (int j = 0; j < 3; j++) {
    if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] == player) {
      return 1;
    }
  }

  // Check for diagonal wins.
  if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] == player) {
    return 1;
  }

  if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] == player) {
    return 1;
  }

  return 0;
}

int main() {
  // Initialize the board.
  char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

  // Declare variables.
  char player1 = 'X';
  char player2 = 'O';
  char currentPlayer = player1;
  int winner = 0;

  // Play the game.
  while (!winner) {
    // Print the board.
    printBoard(board);

    // Get the player's move.
    int row, col;
    printf("Player %c, enter your move (1-9): ", currentPlayer);
    scanf("%d", &row);
    row--;
    col = row % 3;

    // Check if the move is valid.
    if (board[row][col] != ' ') {
      printf("Invalid move.\n");
      continue;
    }

    // Make the move.
    board[row][col] = currentPlayer;

    // Check for a winner.
    winner = isWinner(board, currentPlayer);

    // Switch players.
    if (currentPlayer == player1) {
      currentPlayer = player2;
    } else {
      currentPlayer = player1;
    }
  }

  // Print the winner.
  if (winner) {
    printf("Player %c wins!\n", winner);
  } else {
    printf("Tie game!\n");
  }

  return 0;
}
