#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>> &grid, vector<vector<int>> &visited, int &ans,
         int row, int col) {
  visited[row][col] = 1;
  int dx[] = {0, 0, 1, -1};
  int dy[] = {1, -1, 0, 0};
  int isLand = grid[row][col];
  int coastNum = 0;
  int isLake = 1;

  // check 4 sides
  for (int i = 0; i < 4; i++) {
    int r = row + dx[i];
    int c = col + dy[i];
    if (isLand) {
      if (r > -1 && r < grid.size() && c > -1 && c < grid[0].size() &&
          !visited[r][c] && grid[r][c])
        dfs(grid, visited, ans, r, c);
      else {
        ans++;
        dfs(grid, visited, ans, row, col);  // check if lake
      }

    } else {
      // lake check
      if (r > -1 && r < grid.size() && c > -1 && c < grid[0].size() &&
          grid[r][c])
        isLake = 0;
    }
  }
  if (!isLand && isLake) ans--;
}

int main() {
  int r, c;
  cin >> r >> c;
  vector<int> temp(c, 0);
  vector<vector<int>> grid(r, temp), visited(r, temp);

  for (auto &row : grid) {
    for (auto &i : row) cin >> i;
  }
  int ans = 0;
  cout << "TEST" << endl;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (grid[i][j] == 1 && !visited[i][j]) {
        dfs(grid, visited, ans, i, j);
      }
    }
  }
  cout << ans << endl;
  return 0;
}