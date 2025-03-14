#include <bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
  int row = grid.size();
  int col = grid[0].size();
  int ans = -1;
  queue<tuple<int, int, int>> stk;  // row,col,depth  //i was using a stack T.T
  int dx[] = {1, -1, 0, 0};
  int dy[] = {0, 0, 1, -1};
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (grid[i][j] == 2) {
        stk.push(make_tuple(i, j, -1));
        grid[i][j] = 1;
      }
    }
  }

  while (!stk.empty()) {
    auto [r, c, d] = stk.front();

    stk.pop();
    if (grid[r][c] != 1) continue;
    // if (ans < d) {
    //   cout << d << endl;
    //   for (int i = 0; i < row; i++) {
    //     for (int j = 0; j < col; j++) {
    //       cout << grid[i][j] << ' ';
    //     }
    //     cout << endl;
    //   }
    //   cout << endl << endl;
    // }
    grid[r][c] = 2;

    ans = max(ans, d);

    for (int i = 0; i < 4; i++) {
      int newRow = r;
      int newCol = c;
      int newDepth = d;
      newRow += dx[i];
      newCol += dy[i];
      if (newRow >= 0 && newRow < row && newCol >= 0 && newCol < col)
        stk.push(make_tuple(newRow, newCol, ++newDepth));
    }
  }
  //   // test
  //   for (int i = 0; i < row; i++) {
  //     for (int j = 0; j < col; j++) {
  //       cout << grid[i][j] << ' ';
  //     }
  //     cout << endl;
  //   }
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (grid[i][j] == 1) return -1;
    }
  }
  return ans + 1;
}
int main() {
  vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
  cout << orangesRotting(grid);
}