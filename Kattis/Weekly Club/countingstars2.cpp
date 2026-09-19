#include <bits/stdc++.h>
using namespace std;

void clearStar(int row, int col, vector<string>& grid,
               vector<vector<bool>>& visited) {
  int dx[] = {1, -1, 0, 0};
  int dy[] = {0, 0, 1, -1};
  for (int i = 0; i < 4; i++) {
    int r = row + dx[i];
    int c = col + dy[i];
    if (r < (int)grid.size() && r >= 0 && c < (int)grid[0].size() && c >= 0 &&
        (grid[r][c] == '-')) {
      grid[r][c] = '.';
      clearStar(r, c, grid, visited);
    }
  }
}

void solution(int height, int width) {
  vector<string> grid(height);
  vector<vector<bool>> visited(height, vector<bool>(width, false));
  int ans = 0;
  for (auto& it : grid) cin >> it;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if (grid[i][j] == '-') {
        ans++;
        clearStar(i, j, grid, visited);
      }
    }
  }
  cout << ans << endl;
}

int main() {
  int a, b;
  while (cin >> a >> b) {
    solution(a, b);
  }
  return 0;
}