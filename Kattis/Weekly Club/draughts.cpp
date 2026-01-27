#include <bits/stdc++.h>
using namespace std;
int dr[] = {1, -1, -1, 1};
int dc[] = {-1, -1, 1, 1};

bool inGrid(int row, int col, vector<string>& grid, int dir) {
  int finalRow = row;
  int finalCol = col;
  int opponentRow = row;
  int opponentCol = col;

  finalRow += (dr[dir] * 2);
  finalCol += (dc[dir] * 2);
  opponentRow += dr[dir];
  opponentCol += dc[dir];

  // //cerr << endl;
  if (finalRow < (int)grid.size() && finalRow > -1 &&
      finalCol < (int)grid[0].size() && finalCol > -1 &&
      grid[finalRow][finalCol] == '#' &&
      grid[opponentRow][opponentCol] == 'B') {
    // cerr << "Opponent:" << ' ' << opponentRow << ' ' << opponentCol << endl;
    // cerr << "FINAL:" << ' ' << finalRow << ' ' << finalCol << endl;
    return true;
  }
  // ////cerr << "False" << endl;
  return false;
}

void traverse(int row, int col, vector<string> grid, int score, int& ans) {
  // //cerr << score << ' ' << row << ' ' << col << endl;
  ans = max(ans, score);
  for (int i = 0; i < 4; i++) {
    if (inGrid(row, col, grid, i)) {
      // cerr << "PASS" << endl;
      vector<string> tempGrid = grid;

      int r = row + (dr[i]);
      int c = col + (dc[i]);
      tempGrid[r][c] = '#';
      r += dr[i];
      c += dc[i];

      traverse(r, c, tempGrid, score + 1, ans);
    }
  }
}

void solution() {
  vector<string> board(10);
  int ans = 0;
  for (auto& it : board) {
    cin >> it;
  }
  for (int i = 0; i < (int)board.size(); i++) {
    for (int j = 0; j < (int)board[0].size(); j++) {
      if (board[i][j] == 'W') {
        vector<string> tempGrid = board;
        tempGrid[i][j] = '#';
        int newAns = 0;

        traverse(i, j, tempGrid, 0, newAns);
        ans = max(ans, newAns);
      }
    }
  }
  cout << ans << endl;
}

int main() {
  int n;
  cin >> n;
  string str;
  while (n--) {
    solution();
  }
}