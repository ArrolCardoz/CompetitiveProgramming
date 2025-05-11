#include <bits/stdc++.h>
using namespace std;
void dfs(vector<string>& grid, int row, int col) {
  grid[row][col] = '#';
  int dx[] = {0, 0, 1, -1};
  int dy[] = {1, -1, 0, 0};
  for (int i = 0; i < 4; i++) {
    int r = row;
    int c = col;
    r += dx[i];
    c += dy[i];
    if (r < grid.size() && r > -1 && c < grid[0].size() && c > -1 &&
        grid[r][c] == '-')
      dfs(grid, r, c);
  }
}

int main() {
  int n = 1;
  int row, col;
  while (cin >> row >> col) {
    int ans = 0;
    vector<string> grid(row);
    for (auto& it : grid) cin >> it;
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if (grid[i][j] == '-') {
          ans++;
          dfs(grid, i, j);
        }
      }
    }
    cout << "Case " << n << ": " << ans << endl;
    n++;
  }
  return 0;
}