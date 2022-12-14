#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

unsigned int **malloc_matric(int n, int m) {
  unsigned int **matric = malloc(sizeof(int *) * n);
  for (int row = 0; row < n; row++) {
    matric[row] = malloc(sizeof(int) * m);
  }

  for (int row = 0; row < n; row++) {
    for (int col = 0; col < m; col++) {
      matric[row][col] = 0;
    }
  }
  return matric;
}

bool validate_row(unsigned int *row) {
  int check_map[10] = {0};
  for (int i = 0; i < 9; i++) {
    if (++check_map[row[i]] > 1) {
      return false;
    }
  }
  if (check_map[0] > 0) {
    return false;
  }
  return true;
}

bool validate_col(unsigned int **board, int col) {
  int check_map[10] = {0};
  for (int i = 0; i < 9; i++) {
    if (++check_map[board[i][col]] > 1) {
      return false;
    }
  }
  if (check_map[0] > 0) {
    return false;
  }
  return true;
}

bool validate_block(unsigned int **board, int start_row, int start_col) {
  int check_map[10] = {0};
  for (int i = start_row; i <= start_row + 2; i++) {
    for (int j = start_col; j <= start_col + 2; j++) {
      if (++check_map[board[i][j]] > 1) {
        return false;
      }
    }    
  }
  if (check_map[0] > 0) {
    return false;
  }
  return true;
}

bool validSolution(unsigned int **board){
  for (int row = 0; row < 9; row++) {
    if (validate_row(board[row]) == false) {
      return false;
    }
  }

  for (int col = 0; col < 9; col++) {
    if (validate_col(board, col) == false) {
      return false;
    }
  }

  for (int row = 0; row < 9; row += 3) {
    for (int col = 0; col < 9; col += 3) {
      if (validate_block(board, row, col) == false) {
        return false;
      }      
    }
  }

  return true;
}

int main() {
  unsigned int **board = malloc_matric(9, 9);

  int row1[9] = {5, 3, 4, 6, 7, 8, 9, 1, 2};
  int row2[9] = {6, 7, 2, 1, 9, 5, 3, 4, 8};
  int row3[9] = {1, 9, 8, 3, 4, 2, 5, 6, 7};

  int row4[9] = {8, 5, 9, 7, 6, 1, 4, 2, 3};
  int row5[9] = {4, 2, 6, 8, 5, 3, 7, 9, 1};
  int row6[9] = {7, 1, 3, 9, 2, 4, 8, 5, 6};

  int row7[9] = {9, 6, 1, 5, 3, 7, 2, 8, 4};
  int row8[9] = {2, 8, 7, 4, 1, 9, 6, 3, 5};
  int row9[9] = {3, 4, 5, 2, 8, 6, 1, 7, 9};

  for (int j = 0; j < 9; j++) {
    board[0][j] = row1[j];
    board[1][j] = row2[j];
    board[2][j] = row3[j];
    board[3][j] = row4[j];
    board[4][j] = row5[j];
    board[5][j] = row6[j];
    board[6][j] = row7[j];
    board[7][j] = row8[j];
    board[8][j] = row9[j];
  }

  printf("%d\n", validSolution(board));

  int row10[9] = {5, 3, 4, 6, 7, 8, 9, 1, 2};
  int row11[9] = {6, 7, 2, 1, 9, 0, 3, 4, 8};
  int row12[9] = {1, 0, 0, 3, 4, 2, 5, 6, 0};

  int row13[9] = {8, 5, 9, 7, 6, 1, 0, 2, 0};
  int row14[9] = {4, 2, 6, 8, 5, 3, 7, 9, 1};
  int row15[9] = {7, 1, 3, 9, 2, 4, 8, 5, 6};

  int row16[9] = {9, 0, 1, 5, 3, 7, 2, 1, 4};
  int row17[9] = {2, 8, 7, 4, 1, 9, 6, 3, 5};
  int row18[9] = {3, 0, 0, 4, 8, 1, 1, 7, 9};

  for (int j = 0; j < 9; j++) {
    board[0][j] = row10[j];
    board[1][j] = row11[j];
    board[2][j] = row12[j];
    board[3][j] = row13[j];
    board[4][j] = row14[j];
    board[5][j] = row15[j];
    board[6][j] = row16[j];
    board[7][j] = row17[j];
    board[8][j] = row18[j];
  }

  printf("%d", validSolution(board));

  free(board);
  return 0;
}