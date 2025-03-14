// 200
#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<char>>& grid, int row, int col) {
  if (grid[row][col] != '1') return;
  grid[row][col] = '2';
  int dx[] = {1, -1, 0, 0};
  int dy[] = {0, 0, 1, -1};
  for (int i = 0; i < 4; i++) {
    int newRow = row;
    int newCol = col;
    newRow += dx[i];
    newCol += dy[i];
    if (newRow >= 0 && newRow < grid.size() && newCol >= 0 &&
        newCol < grid[0].size())
      dfs(grid, newRow, newCol);
  }
}

int numIslands(vector<vector<char>>& grid) {
  int row = grid.size();
  int col = grid[0].size();
  int ans = 0;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (grid[i][j] == '1') {
        dfs(grid, i, j);
        ans++;
      }
    }
  }
  return ans;
}