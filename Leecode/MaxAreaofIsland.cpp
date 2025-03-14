// 695
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& grid, int row, int col, int& ans) {
  if (grid[row][col] == 0) return;

  grid[row][col] = 0;
  int dx[] = {1, -1, 0, 0};
  int dy[] = {0, 0, 1, -1};
  ans++;
  for (int i = 0; i < 4; i++) {
    int newRow = row;
    newRow += dx[i];
    int newCol = col;
    newCol += dy[i];
    if (newRow < grid.size() && newRow >= 0 && newCol < grid[0].size() &&
        newCol >= 0)
      dfs(grid, newRow, newCol, ans);
  }
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
  int row = grid.size();
  int col = grid[0].size();
  int ans = 0;
  int temp = 0;

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (grid[i][j] == 1) dfs(grid, i, j, temp);
      if (temp > ans) ans = temp;
      temp = 0;
    }
  }
  return ans;
}