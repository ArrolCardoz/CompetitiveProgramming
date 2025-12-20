#include <bits/stdc++.h>
using namespace std;

bool checkRow(vector<vector<char>>& board) {
  for (int i = 0; i < board.size(); i++) {
    unordered_map<char, int> total;

    for (int j = 0; j < board[0].size(); j++) {
      if (board[i][j] != '.' && board[i][j] != ',') {
        total[board[i][j]]++;
        if (total[board[i][j]] > 1) return false;
      }
    }
  }
  return true;
}
bool checkCol(vector<vector<char>>& board) {
  for (int i = 0; i < board.size(); i++) {
    unordered_map<char, int> total;

    for (int j = 0; j < board[0].size(); j++) {
      if (board[j][i] != '.' && board[j][i] != ',') {
        total[board[j][i]]++;
        if (total[board[j][i]] > 1) return false;
      }
    }
  }
  return true;
}
bool checkBox(vector<vector<char>>& board, int row, int col) {
  unordered_map<char, int> total;

  for (int i = row; i < row + 3; i++) {
    // cerr << i << ' ';

    for (int j = col; j < col + 3; j++) {
      cerr << board[i][j] << ',';
      if (board[i][j] != '.' && board[i][j] != ',') {
        total[board[i][j]]++;
        // cerr << total[board[j][i]] << ',';

        if (total[board[i][j]] > 1) return false;
      }
    }
    // cerr << endl;
  }
  //   cerr << endl;
  //   cerr << endl;
  //   cerr << endl;

  bool finalAns = true;
  if (row < 6) finalAns &= checkBox(board, row + 3, col);
  if (col < 6) finalAns &= checkBox(board, row, col + 3);

  return finalAns;
}

bool isValidSudoku(vector<vector<char>>& board) {
  bool finalAns = true;

  // check rows
  finalAns &= checkRow(board);
  // check cols
  finalAns &= checkCol(board);
  // check box
  finalAns &= checkBox(board, 0, 0);
  return finalAns;
}

int main() {
  vector<vector<char>> board = {{'.', '.', '.', '.', '5', '.', '.', '1', '.'},
                                {'.', '4', '.', '3', '.', '.', '.', '.', '.'},
                                {'.', '.', '.', '.', '.', '3', '.', '.', '1'},
                                {'8', '.', '.', '.', '.', '.', '.', '2', '.'},
                                {'.', '.', '2', '.', '7', '.', '.', '.', '.'},
                                {'.', '1', '5', '.', '.', '.', '.', '.', '.'},
                                {'.', '.', '.', '.', '.', '2', '.', '.', '.'},
                                {'.', '2', '.', '9', '.', '.', '.', '.', '.'},
                                {'.', '.', '4', '.', '.', '.', '.', '.', '.'}};

  cout << (isValidSudoku(board) ? "Valid Sudoku\n" : "Invalid Sudoku\n");
  return 0;
}