#include <stdbool.h>
#include <stdio.h>
/* This is a cool comment! */
// Cool beans!

enum BoxState { P1, P2, UNFILLED };
enum Turn { Player1, Player2 };

void renderBoard(enum BoxState data[3][3]) {
  printf("==============\n");
  for (int i = 0; i < 3; i++) {
    for (int k = 0; k < 3; k++) {
      switch (data[i][k]) {
      case (P1):
        printf("X\t");
        break;
      case (P2):
        printf("O\t");
        break;
      case (UNFILLED):
        printf(" \t");
        break;
      }
      if (k < 2) {
        printf("|");
      }
    }
    if (i < 2) {
      printf("\n-------------");
    }
    printf("\n");
  }
  printf("==============\n");
  return;
}

void nextTurn(enum Turn player, enum BoxState data[3][3]) {
  int row;
  int column;
  switch (player) {
  case (Player1):
    printf("Player 1, it is now your turn:");
    scanf("%d %d", &row, &column);
    printf("\n");
    data[row][column] = P1;
    break;
  case (Player2):
    printf("Player 2, it is now your turn:");
    scanf("%d %d", &row, &column);
    printf("\n");
    data[row][column] = P2;
    break;
  }
}

bool checkWinRow(enum BoxState data[3][3]) {
  int p1Score = 0;
  int p2Score = 0;
  for (int row = 0; row < 3; row++) {
    for (int column = 0; column < 3; column++) {
      if (p1Score == 3 || p2Score == 3) {
        return true;
      }
      switch (data[row][column]) {
      case P1:
        p1Score++;
        p2Score = 0;
        break;
      case P2:
        p2Score++;
        p1Score = 0;
        break;
      default:;
      }
    }
  }
  return false;
}
bool checkWinColumn(enum BoxState data[3][3]) {
  int p1Score = 0;
  int p2Score = 0;
  for (int column = 0; column < 3; column++) {
    for (int row = 0; row < 3; row++) {
      if (p1Score == 3 || p2Score == 3) {
        return true;
      }
      switch (data[row][column]) {
      case P1:
        p1Score++;
        p2Score = 0;
        break;
      case P2:
        p2Score++;
        p1Score = 0;
        break;
      default:;
      }
    }
  }
  return false;
}

bool checkWinDiagonal(enum BoxState data[3][3]) {
  if (data[0][0] == data[1][1] == data[2][2] ||
      data[0][2] == data[1][1] == data[2][0]) {
    return true;
  }
  return false;
}

bool checkWin(enum BoxState data[3][3]) {
  if (checkWinRow(data)) {
    return true;
  } else if (checkWinColumn(data)) {
    return true;
  } else if (checkWinDiagonal(data)) {
    return true;
  }
  return false;
}

int main(int argc, char *argv[]) {
  // Tic tac toe game
  enum Turn currentTurn = Player1;
  enum BoxState data[3][3] = {
      {P1, P2, P2},
      {UNFILLED, P1, UNFILLED},
      {UNFILLED, UNFILLED, UNFILLED},
  };

  renderBoard(data);
  while (!checkWin(data)) {
    if (checkWin(data)) {
      
    }
    nextTurn(currentTurn, data);
    switch (currentTurn) {
    case Player1:
      currentTurn = Player2;
      break;
    case Player2:
      currentTurn = Player1;
      break;
    }
    renderBoard(data);
  }
  printf("Congrats %d, you won!", currentTurn);
}
