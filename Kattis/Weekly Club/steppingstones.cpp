#include <bits/stdc++.h>
using namespace std;

int main() {
  int r, c;
  cin >> r >> c;

  vector<vector<int>> grid(r, vector<int>(c, 0));
  vector<vector<bool>> visited(r, vector<bool>(c, false));
  queue<tuple<int, int, int>> q;
  int dr[] = {0, 0, 1, -1};
  int dc[] = {1, -1, 0, 0};

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      int input;
      cin >> input;
      grid[i][j] = input;
    }
  }
  cerr << 1 << endl;

  for (int i = 0; i < c; i++) {
    if (grid[0][i] == 1) q.emplace(0, i, 0);
  }
  cerr << 2 << endl;

  while (!q.empty()) {
    auto [row, col, moves] = q.front();
    int nextRow, nextCol;
    cerr << row << ' ' << col << "=========" << moves << endl;

    visited[row][col] = true;
    q.pop();
    moves++;
    for (int i = 0; i < 4; i++) {
      nextRow = row + (dr[i] * grid[row][col]);
      nextCol = col + (dc[i] * grid[row][col]);
      if (nextRow >= 0 && nextRow < r && nextCol >= 0 && nextCol < c &&
          !visited[nextRow][nextCol] &&
          grid[nextRow][nextCol] != 0) {  // traverse
        q.emplace(nextRow, nextCol, moves);
        cerr << nextRow << ' ' << nextCol << endl;
      }

      if (nextRow >= r && nextCol >= 0 &&
          nextCol < c)  // check if we hit bottom
      {
        cout << moves << endl;
        return 0;
      }
      //   cerr << nextRow << ' ' << nextCol << endl;
    }
  }
  cout << -1 << endl;
  return 0;
}